::============================================
:: AUTHOR : monsef alahem
:: DATE : 1-feb-2019
::--------------------------------------------------------------------------------
::============================================
@echo off

::a changer ici le chemin du repertoire ou se trouve le compilateur
::dans cet exemple "C:\MinGW\bin"
set PATH=%PATH%;C:\MinGW\bin;

del *.o
gcc -c main.c
gcc -o myapp.exe main.o    -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

pause