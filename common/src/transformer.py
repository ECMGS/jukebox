def transform_code(code, song_name):
    notes = []
    durations = []
    lines = code.split("\n")
    for line in lines:
        if "tone(buzzerPin," in line:
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

code = """

 
  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(93);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(88);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(88);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(69);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(69);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(39);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(69);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(78);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(74);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(78);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(74);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(74);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(78);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 147);
  delay(123);
  noTone(buzzerPin);

  tone(buzzerPin, 73);
  delay(152);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 185);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 39);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 139);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 69);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 277);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 131);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 65);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 233);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 78);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 156);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(49);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(44);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(59);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(54);
  noTone(buzzerPin);

  tone(buzzerPin, 196);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 49);
  delay(64);
  noTone(buzzerPin);

  tone(buzzerPin, 98);
  delay(64);
  noTone(buzzerPin);
"""
song_name = "star_wars_cello"  # Reemplaza esto con el nombre de tu canción
output = transform_code(code, song_name)
print(output)

