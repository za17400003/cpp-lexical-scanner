# Analizador léxico en C++

Analizador léxico en C++ preparado como proyecto de Visual Studio.

## Compilación

Abra `scanner.sln` en Visual Studio, seleccione una configuración compatible y compile la solución. El archivo de entrada de ejemplo `hola.txt` está incluido.

## Archivos del proyecto

- `main.cpp`: punto de entrada del programa.
- `scanner.cpp` y `scanner.h`: implementación del analizador.
- `hola.txt`: archivo de entrada de ejemplo.

## Archivos no incluidos

- `Jose Esau Diaz Hernandez/` y `Jose Esau Diaz Hernandez.zip`: copias de respaldo del mismo proyecto. `main.cpp` y `scanner.cpp` son idénticos a los de la raíz; `scanner.h` solo añade dos inclusiones. Se omitieron para evitar mantener versiones duplicadas del código.
- `Source.cpp`: archivo vacío, sin código fuente.
- `scanner.vcxproj.user`: configuración local de inicio y depuración de Visual Studio, vinculada a una computadora.
- `.vs/`, `Debug/`, `x64/` y los archivos generados dentro de `scanner/`: cachés y resultados de compilación que se pueden regenerar localmente.