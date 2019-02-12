# SDL2-installer
batch script to copie headers and libs in C compiler folder + a special example app


## how to use ?

1- edit sdl_installer.bat, write the path of your C compiler
e.g : mingw_path=C:\CodeBlocks\MinGW\

2- run sdl_installer.bat

3- run dll_collector.bat

4- copy the dll's from x86 or x64 to EXAMPLE_APP

5- in EXAMPLE_APP folder, edit SDL2_compiler.bat, add the path of your C compiler to the "%PATH%"
e.g : PATH=%PATH%;C:\codeblocks\MinGW\bin;

6- run SDL2_compiler.bat

7- run myapp.exe


if it works congrats, your SDL2 installation is done !
