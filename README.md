# Proyecto #1: Minishell

## Integrantes: 

César Carios (30136117) & Jhonatan Homsany (30182893)

## Pasos para compilar y ejecutar:

Como lo indica su nombre, este programa es una mini terminal de Linux: ejecuta comandos que reciba en su entrada. Junto con este README.md también está adjunto un **makefile** para compilar, el código fuente del proyecto cuyo nombre es **Proyecto.c** y un PDF donde se explica la estructura del código y se muestran algunos casos de prueba. Los pasos para compilar y ejecutar el proyecto son los siguientes:

1. Abrir la terminal de Linux en la carpeta donde se descargaron/descomprimieron los 4 archivos entregados.

2. Ejecutar el comando _make_ o _make all_ para compilar el código fuente.

3. Ejecutar el comando _make clean_ para remover los archivos .o que genera el compilado.

4. Llegado a este punto se debe haber generado un ejecutable en la carpeta donde se compiló el código fuente. Ahora se ejecuta el comando _./Proyecto_.

5. El programa empezará a ejecutarse, esperará un comando por parte del usuario (ls, pwd, date, touch, make, entre otros).

6. Para terminar el programa basta con escribir "salir" (sin las comillas) en la entrada y presionar enter.

## IMPORTANTE: Consideraciones sobre la ejecución del Minishell

Dependiendo del distrito de Linux en el que se compile y ejecute este código, puede que se ejecute sin problemas o haya errores. Hasta los momentos, este programa se ha probado en:

* Ubuntu: Compila y se ejecuta sin problemas. **Lo ideal sería compilar y ejecutar en este distrito.**

* Mint: Compila y se ejecuta sin problemas.

* Lubuntu: Compila y se ejecuta sin problemas. Sin embargo, no funciona en versiones de Lubuntu antigüas.

Es importante destacar que originalmente este código fue testeado y creado usando WSL (Windows Subsystem Linux). Específicamente WLS: Ubuntu. Adicionalmente, una aclaratoria respecto al comando _grep_ es que distingue entre una cadena de caracteres con comillas y sin comillas. Es decir, "Hola" es diferente de Hola. 
