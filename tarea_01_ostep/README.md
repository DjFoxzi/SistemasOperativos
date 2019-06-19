# Tarea 01 Sistemas Operativos
### Grupo de Trabajo: Jonathan Perez Castro(1733909) - Juan David Delgado Rubiano (1733915) - Kevin David Loaiza 1730526

*  mem.c:

[mem.c](mem.c)

No se toco ninguna parte del codigo, solo fue ejecutado dos veces de manera concurrente y se evidencia que ven valores diferentes a pesar que trabajan el mismo sector.

*  threads.c:

[threads.c](threads.c)

En el archivo `threads.c`, se añadieron el funcionamiento de las puertas de la libreria mycommon.h permitiendo que se accese por turnos a cierto sector de la memoria.

*  io.c:

[io.c](io.c)

En el archivo `io.c`, usando los comandos fseek,fgetc y ftell se recorrio el archivo hasta el final omitiendo las dos posiciones finales que guardan el simbolo de final de archivo y se empezo a imprimir de atras hacia adelante permitiendo invertir tanto el orden de las lineas del archivo, como el contenido de las mismas.

- Para compilar `threads.c`:

```
gcc -pthread threads.c -o threads
```

- Para compilar `io.c`:

```
gcc io.c -o io
```
