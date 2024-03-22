# Jukebox SDGII - JE

## Authors

* **Jorge Alejandro Estefania Hidalgo** - email: [jorge.estefania@alumnos.upm.es](mailto:jorge.estefania@alumnos.upm.es)
* **Eugenio Cano Muñoz** - email: [eugenio.cano@alumnos.upm.es](mailto:eugenio.cano@alumnos.upm.es)

Este proyecto se basa en la creación de una caja de música utilizando el microcontrolador stm32f446re y el entorno de desarrollo MatrixMCU.

Por ahora no se ha incluido ninguna imagen del producto ya que este no se encuentra finalizado, pero se realizará en cuanto se acabe. También se adjuntará un video 

## Version 1

En la versión 1 partimos del proyecto plantilla que implementa un sistema para controlar la gpio llamado *port_system*, mediante el uso de este añadimos funcionalidad para poder utilizar un botón. En nuestra implementación estamos utilizando el botón de usuario del microcontrolador, aunque la funcionalidad se puede cambiar sencillamente.

Además el sistema utilizado para manejar los botones permite utilizar varios botones en un mismo sistema, lo que podrá permitir añadir funcionalidad al sistema sin provocar muchos dolores de cabeza.

## Version 2

En la versión 2 añadimos la funcionalidad necesaria para que la caja de música se comunique correctamente con el ordenador, pudiendo enviar y recibir mensajes desde la placa, esto nos puede permitir en un futuro añadir funciones como enviar comandos para reproducir y parar la reproducción o incluso poder subir canciones a la caja de música para reproducir nueva música.