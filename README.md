# The 8 bit Jukebox

## Authors of the project

* **Jorge Alejandro Estefanía Hidalgo** - email: [jorge.estefania@alumnos.upm.es](mailto:jorge.estefania@alumnos.upm.es)
* **Eugenio Cano Muñoz** - email: [eugenio.cano@alumnos.upm.es](mailto:eugenio.cano@alumnos.upm.es)

## Description of the project

Hi! We are Eugenio and Jorge, and we made a three buzzers jukebox to play all your favorite melodies in 8 bit style!
Project on UART communication and PWM music player of the SDG2 2023-24 course.

This is our final result!
![Image of the board](docs/assets/imgs/IMG_8665.jpeg)

**You can watch a video showing all the features here: [https://www.youtube.com/watch?v=uztb5DlaXZM](https://www.youtube.com/watch?v=uztb5DlaXZM)**

**A brief summary of what we added:**

1. 3 buzzers in order to enjoy all your favorite melodies!! (You can add as many buzzers as you want if you can find any available timers and pins)
2. A state of the art (for the 80s) LCD to see what song are you listening to.
3. WEB interface to control the jukebox from potentially anywhere in the world.
4. Design implemented in a HSCB (Homemade Soldered Circuit Board) because the cables kept falling from the breadboard.
5. A case to hold everything in a grat form factor.
6. Button to set the previous song, use it if you passed your favorite song by mistake :(
7. Button to stop and play songs (If you aren't very fast it sets a quiet mode to listen to in quieter enviroments, as the library)
8. Awesome python script to ease the workflow of adding songs to the jukebox.
9. A lot of new songs, some of them with accompaniment melodies, by implementing a linked list.
10. Little change to the "speed" command while using the usart interface.

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
To implement the LCD, we had to activate the HAL. In order to compile the code, it is important to copy the HAL configuration file located in "common/include/stm32f4xx_hal_conf.h" and paste it in the MatrixMCU HAL drivers folder: "MatrixMCU/drivers/stm32f4xx/STM32F4xx_HAL_Driver/Inc/".

## Explanation of some of the added functionality:

### 3 Buzzers

In order to implmement this, we have created a "Buzzer director" that manages all the necesary FSMs for the different buzzers, you can think of this as the manager for a pool of buzzers in parallelism programming. This buzzer director adapts to the available buzzers in the port buzzer automatically, so the only thing you need to do to add a new buzzer is to add the required defines, increment MAX_BUZZERS and add it to the buzzers_arr.

### LCD

The LCD is implemented by using the HAL and I2C, as controlling it with the cmsis enviroment would be very time consuming and would get the same result.
We downloaded the "liquidcrystal_i2c" library to interface with the LCD via I2C.

### Web interface

The web interface expands tremendously the posibilities of the jukebox, the only need is to add another device with USB or just serial UART protocol, allowing the user to change simple things like start *playing a song*, *pause it*, *skip the song*, or *know what song is being played*. The server uses nodejs and express. The files can be found in the `web_server/` folder

![Image to configure the port](./docs/assets/imgs/configure_port.png)

![Use of the jukebox](./docs/assets/imgs/web_server.png)

### Custom soddered circuit and DIY 3D printed case

These were late on additions, once we finished adding hardware and knew everithing worked. We used Thinkercad to make the design of the case. The link to the Tinkercad design is https://www.tinkercad.com/things/4ZQXu1ZOIWi-sdg2-jukebox-case and the STL files can be found in the 3D folder.

### Added buttons

The added buttons are just simple modifications to the jukebox FSM, these were the first modifications that we did to the V4 just to get the hang of doing unguided additions on our own.

### Python Script
To be able to add songs in a reasonable time, we wrote a Python script to help during the song adding process.
The workflow to add new songs to the jukebox is a bit tedious, in consists of the following steps:
1. Downloading the midi version of such song.
2. Upload your .mid file to a web to to convert a raw midi file for use to play on an Arduino (via the tone function). I used https://extramaster.net/tools/midiToArduino/ becouse it was the only web I found that kept the the timinG of the note durations correctly.
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

### WEB interface
Being the web launched on a server, it can be accesed from the local network. However the conexion could be opened to the internet network so that the jukebox could be controlled from anywhere. 

## Images related to the jukebox:

### Final jukebox fsm diagram
![FSM jukebox](docs/assets/imgs/jukebox_fsm.jpeg)

### Osciloscope captures of the USART comunication
Here we can see the voltage changes when we send the command "info" and the beginning of the response.
![USART osciloscope capture](docs/assets/imgs/osciloscope_uart.jpeg)

Here we can see the end of the response. The response is larger than the command becouse "info" only has 4 characters whereas the response, which in this case is: "melody: scale" which has more characters.
![USART osciloscope capture](docs/assets/imgs/oscioscope_uart_2.jpeg)

## What's inside the box
The jukebox looks like this without the cover:
![Jukebox insides](docs/assets/imgs/IMG_8660.jpeg)

### HSCB (Homemade Solderec Circuit Board)
This is the jukebox from below:
![HSBC](docs/assets/imgs/HSCB.jpeg)

Hope you enjoy our project! 
![Just chilling](docs/assets/imgs/IMG_8666.jpeg)

If there are any questions, just ask, we'll be open to answer!