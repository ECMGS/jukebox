import pyperclip

def transform_code(code, song_name):
    notes = []
    durations = []
    lines = code.split("\n")
    for line in lines:
        if "tone(" in line:
            note = line.split(",")[1].split(")")[0].strip()
            notes.append(note)
        elif "delay(" in line:
            duration = line.split("(")[1].split(")")[0].strip()
            durations.append(duration)
    num_notes = len(notes)
    notes_str = ', '.join(notes)
    durations_str = ', '.join(durations)
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

# Aquí debes reemplazar el contenido de 'code' con tu código Arduino
code = """

"""

song_name = "nombre_de_tu_cancion"  # Reemplaza esto con el nombre de tu canción
output = transform_code(code, song_name)
print(output)

pyperclip.copy(output)
input("Presiona Enter para salir...")
