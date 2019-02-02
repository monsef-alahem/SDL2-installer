::============================================
:: AUTHOR : monsef alahem
:: DATE : 1-feb-2019
::--------------------------------------------------------------------------------
::============================================
@echo off
set mingw_path=C:\CodeBlocks\MinGW\
mkdir %mingw_path%include\SDL2
::libs first
copy SDL2-2.0.9\lib\x86\*.lib 	%mingw_path%lib
copy SDL2_image-2.0.4\lib\x86\*.lib  	%mingw_path%lib
copy SDL2_mixer-2.0.4\lib\x86\*.lib 	%mingw_path%lib
copy SDL2_ttf-2.0.15\lib\x86\*.lib  	%mingw_path%lib

::then heads
copy SDL2-2.0.9\include\*.h 	%mingw_path%include\SDL2
copy SDL2_image-2.0.4\include\*.h  	%mingw_path%include\SDL2
copy SDL2_mixer-2.0.4\include\*.h  	%mingw_path%include\SDL2
copy SDL2_ttf-2.0.15\include\*.h  	%mingw_path%include\SDL2

