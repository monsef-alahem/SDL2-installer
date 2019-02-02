::============================================
:: AUTHOR : monsef alahem
:: DATE : 1-feb-2019
::--------------------------------------------------------------------------------
::============================================
@echo off

::choose 32 or 64 bits
set x=x32

mkdir %x%

::libs first
copy SDL2-2.0.9\lib\%x%\*.dll 	%x%\
copy SDL2_image-2.0.4\lib\%x%\*.dll   	%x%\
copy SDL2_mixer-2.0.4\lib\%x%\*.dll  	%x%\
copy SDL2_ttf-2.0.15\lib\%x%\*.dll 	%x%\

pause
