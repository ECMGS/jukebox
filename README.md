# The 8 bit Jukebox

## Authors of the project

* **Jorge Alejandro Estefania Hidalgo** - email: [jorge.estefania@alumnos.upm.es](mailto:jorge.estefania@alumnos.upm.es)
* **Eugenio Cano Muñoz** - email: [eugenio.cano@alumnos.upm.es](mailto:eugenio.cano@alumnos.upm.es)

## Description of the project

Hi! We are Eugenio and Jorge, and we made a three buzzers jukebox to play all your favorite melodies in 8 bit style!

# Añadir imagen
![Image of the board]()

**A brief summary of what we added:**

1. 3 buzzers in order to enjoy all your favorite melodies!! (You can add as many buzzers as you want if you can find any available timers and pins)
2. A state of the art (for the 80s) LCD to see what song are you listening to.
3. Design implemented in a HSCB (Homemade Soddered Circuit Board) because the cables kept falling from the breadboard.
4. A case to hold everything in a grat form factor.
5. Button to set the previous song, use it if you passed your favorite song by mistake :(
6. Button to stop and play songs (If you aren't very fast it sets a quiet mode to listen to in quieter enviroments, as the library)

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

### Custom soddered circuit and DIY 3D printed case

These were late on additions, thought when we finished adding hardware. We used Thinkercad to make the design. The link to the Tinkercad design is https://www.tinkercad.com/things/4ZQXu1ZOIWi-sdg2-jukebox-case and the STL files can be found in the 3D folder.

### Added buttons

The added buttons are just simple modifications to the jukebox FSM, these were the first modifications that we did to the V4 just to get the hang of doing unguided additions on our own.