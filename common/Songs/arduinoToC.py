import pyperclip

def transform_code(code, song_name):
    notes = []
    durations = []
    lines = code.split("\n")
    prev_note_duration = 0  # Duración de la nota anterior
    for line in lines:
        if "tone(" in line:
            _, freq, duration = line.split(",")
            note = freq.strip()
            notes.append(note)
            duration = float(duration.split(")")[0].strip())
            # Redondear la duración al número entero más cercano
            rounded_duration = int(round(duration))
            durations.append(rounded_duration)
            prev_note_duration = rounded_duration
        elif "delay(" in line:
            # Calcular la duración del silencio (delay) como la diferencia entre los dos delays
            next_delay = float(line.split("(")[1].split(")")[0].strip())
            silence_duration = int(round(next_delay - prev_note_duration))
            # Agregar una frecuencia de 0 para representar el silencio
            notes.append("0")
            durations.append(silence_duration)
            prev_note_duration = 0  # Reiniciar la duración de la nota anterior
    num_notes = len(notes)
    notes_str = ', '.join(notes)
    durations_str = ', '.join(map(str, durations))

    print(f"Notas para {song_name}: {notes_str}")
    print(f"Duraciones para {song_name}: {durations_str}")

    output = f"""
#define {song_name.upper()}_LENGTH {num_notes}

static const double {song_name}_notes[{song_name.upper()}_LENGTH] = {{{notes_str}}};
static const uint16_t {song_name}_durations[{song_name.upper()}_LENGTH] = {{{durations_str}}};
const melody_t {song_name} = {{
    .p_name = "{song_name}",
    .p_notes = (double *){song_name}_notes,
    .p_durations = (uint16_t *){song_name}_durations,
    .melody_length = {song_name.upper()}_LENGTH,
    .next_melody = NULL}};
    """
    return output

# Obtener el código del portapapeles del usuario
code = pyperclip.paste()

# Solicitar al usuario el nombre de la canción
song_name = input("Introduce el nombre de la canción: ")

output = transform_code(code, song_name)
print(output)

pyperclip.copy(output)
input("Presiona Enter para salir...")
