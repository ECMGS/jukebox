# The 8 bit Jukebox

## Authors of the project

* **Jorge Alejandro Estefanía Hidalgo** - email: [jorge.estefania@alumnos.upm.es](mailto:jorge.estefania@alumnos.upm.es)
* **Eugenio Cano Muñoz** - email: [eugenio.cano@alumnos.upm.es](mailto:eugenio.cano@alumnos.upm.es)

## Description of the project

Hi! We are Eugenio and Jorge, and we made a three buzzers jukebox to play all your favorite melodies in 8 bit style!

# Añadir imagen
![Image of the board]()

**A brief summary of what we added:**

1. 3 buzzers in order to enjoy all your favorite melodies!! (You can add as many buzzers as you want if you can find any available timers and pins)
2. A state of the art (for the 80s) LCD to see what song are you listening to.
3. Design implemented in a HSCB (Homemade Soldered Circuit Board) because the cables kept falling from the breadboard.
4. A case to hold everything in a grat form factor.
5. Button to set the previous song, use it if you passed your favorite song by mistake :(
6. Button to stop and play songs (If you aren't very fast it sets a quiet mode to listen to in quieter enviroments, as the library)
7. Awesome python script to ease the workflow of adding songs to the jukebox.
8. A lot of new songs, some of them with accompaniment melodies, by implementing a linked list.
9. Little change to the "speed" command while using the usart interface.

**Some of the melodies we added are:**

- Nokia song
- Kerosene (2 channels)
- Mario death song
- Star wars imperial march (4 channels - 3 actually used)
- Pokémon (2 channels)
- Minecraft (2 channels)
- Zelda theme song (3 channels)
- Megalovania (3 channels)
- Coconut mall (3 channels)

## IMPORTANT NOTE:
To implement the LCD, we had to activate the HAL. In order to compile the code, it is important to copy the HAL configuration file located in "common/include/stm32f4xx_hal_conf.h" and paste it in the MatrixMCU HAL drivers folder: "MatrixMCU/drivers/stm32f4xx/STM32F4xx_HAL_Driver/Inc".

## Explanation of some of the added functionality:

### 3 Buzzers

In order to implmement this, we have created a "Buzzer director" that manages all the necesary FSMs for the different buzzers, you can think of this as the manager for a pool of buzzers in parallelism programming. This buzzer director adapts to the available buzzers in the port buzzer automatically, so the only thing you need to do to add a new buzzer is to add the required defines, increment MAX_BUZZERS and add it to the buzzers_arr.

### LCD

The LCD is implemented by using the HAL and I2C, as controlling it with the cmsis enviroment would be very time consuming and would get the same result.
We downloaded the "liquidcrystal_i2c" library to interface with the LCD via I2C.
### Custom soddered circuit and DIY 3D printed case

These were late on additions, once we finished adding hardware and knew everithing worked. We used Thinkercad to make the design of the case. The link to the Tinkercad design is https://www.tinkercad.com/things/4ZQXu1ZOIWi-sdg2-jukebox-case and the STL files can be found in the 3D folder.

### Added buttons

The added buttons are just simple modifications to the jukebox FSM, these were the first modifications that we did to the V4 just to get the hang of doing unguided additions on our own.

### Python Script
To be able to add songs in a reasonable time, we wrote a Python script to help during the song adding process.
The workflow to add new songs to the jukebox is a bit tedious, in consists of the following steps:
1. Downloading the midi version of such song.
2. Upload your .mid file to a web to to convert a raw midi file for use to play on an Arduino (via the tone function). I used https://extramaster.net/tools/midiToArduino/ becouse it was the only web I found that kept the the timin of the note durations correctly.
3. Convert the midi file and copy the output to the clipboard.
4. Reformat the arduino code to fit the format we are using while developing the jukebox software. 
This is the moment to execute the script. It is located at "Songs/transformerV4.py". You will need to have Python installed in your PC.
When the window appears, introduce the name of the song you want to add an press Enter. The generated code will appear and be pasted to your clipboard.
Now all you have to do is press enter again to close the python window and paste the generated code to melodies.c file.
5. Add the song to melodies.h adding the following line: "extern const melody_t name_of_the_song;"
6. Add the song to the melodies array in jukebox.c and increment the number of songs in jukebox.h

With the help of the python script we were able to add numerous songs, including accompaniment melodies.

### Accompaniment melodies
In order to play more than one song, we link one melody to another using a linked list, so when the buzzer director is called to play a song, it reads the properties of the song and if it has a song attached to it and there is enough buzzers it plays each melody on a buzzer. With our settup we could have as many melodies as buzzers, and as many buzzers as the stm32f446re board timers allows us.
Some songs like the zelda theme song benefit a lof from this as it plays three different melodies at once, enriching the music listening experience.

### Speed command usart
We changed the behaviour of the speed command such that you now have to send the speed you want multiplied by 10 in order to be able to set speeds with one decimal.