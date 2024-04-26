
import mido
from mido import MidiFile
import os

def midi_to_freq(note):
    return (2**((note-69)/12))*440

def midi_to_text(midi_file):
    mid = MidiFile(midi_file)
    output = ''

    for i, track in enumerate(mid.tracks):
        print(f'Track {i}: {track.name}')
        track_output = ''
        prev_time = 0
        for msg in track:
            if msg.type == 'note_on':
                # Calculate the silence duration
                silence_duration = msg.time - prev_time
                if silence_duration > 0:
                    track_output += f'Frequency: 0, Duration: {silence_duration}\\n'
                # Write the note frequency and duration to the file
                track_output += f'Frequency: {midi_to_freq(msg.note)}, Duration: {msg.time}\\n'
                prev_time = msg.time
            elif msg.type == 'note_off':
                # Calculate the silence duration
                silence_duration = msg.time - prev_time
                if silence_duration > 0:
                    track_output += f'Frequency: 0, Duration: {silence_duration}\\n'
                prev_time = msg.time
        output += f'Track {i}:\\n{track_output}\\n'
    
    # Save the output to a text file with the same name as the original midi file but of type txt
    txt_file = os.path.splitext(midi_file)[0] + '.txt'
    with open(txt_file, 'w') as f:
        f.write(output)

try:
    midi_to_text('imperial_march_star_wars.mid')
    input("Presiona Enter para salir...")
except Exception as e:
    pass
    input("No ha funcionado correctamente, pulsa para salir...")
