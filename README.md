# Analizador léxico en C++

Analizador léxico en C++ preparado como proyecto de Visual Studio.

## Tipo y requisitos

Es un proyecto de consola para Windows; el repositorio contiene el código fuente, no un ejecutable listo para abrir. Requiere Visual Studio 2022 con la carga de trabajo de desarrollo de escritorio con C++, el toolset v143 y Windows SDK 10.0. No usa bibliotecas externas.

## Abrir, compilar y ejecutar

1. Desde la raíz del repositorio, abra `scanner.sln` en Visual Studio.
2. Seleccione `x64` y `Debug` (o `Release`) y compile la solución.
3. Para que el ejemplo se encuentre por nombre, en las propiedades del proyecto vaya a **Depuración > Directorio de trabajo** y establezca `$(ProjectDir)`. Ejecute con `F5` o `Ctrl+F5`.
4. Cuando el programa solicite un archivo, escriba `hola.txt`. Para otro archivo, indique una ruta relativa al directorio de trabajo o una ruta absoluta.

`hola.txt` está en la raíz del repositorio. El programa no comprueba explícitamente si el archivo se abrió correctamente; si la ruta no existe, puede terminar mostrando EOF sin analizar contenido.

## Archivos del proyecto

- `main.cpp`: punto de entrada del programa.
- `scanner.cpp` y `scanner.h`: implementación del analizador.
- `hola.txt`: archivo de entrada de ejemplo.

## Por dónde empezar a leer

1. `main.cpp`: solicita el archivo, consume los tokens y muestra los resultados.
2. `scanner.h`: declara los tipos de token y la interfaz de la clase `scanner`.
3. `scanner.cpp`: implementa el recorrido y reconocimiento; empieza por `scan()` y sigue con `id()`, `numeral()`, `delimitador()`, `puntuador()`, `operador()` y `comentario()`.

## Archivos no incluidos

- `Jose Esau Diaz Hernandez/` y `Jose Esau Diaz Hernandez.zip`: copias de respaldo del mismo proyecto. `main.cpp` y `scanner.cpp` son idénticos a los de la raíz; `scanner.h` solo añade dos inclusiones. Se omitieron para evitar mantener versiones duplicadas del código.
- `Source.cpp`: archivo vacío, sin código fuente.
- `scanner.vcxproj.user`: configuración local de inicio y depuración de Visual Studio, vinculada a una computadora.
- `.vs/`, `Debug/`, `x64/` y los archivos generados dentro de `scanner/`: cachés y resultados de compilación que se pueden regenerar localmente.