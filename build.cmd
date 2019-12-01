
::prepare folder
if exist .\build (
	rd .\build /s /q
)

md .\build

::the MinGW is too big to upload , zip and split into smaill files
::now unzip it 
if  not exist .\lib\MinGW (
	.\lib\7z.exe x -y .\lib\MinGW.7z.001 -o.\lib
)

set path=%path%;.\lib;.\lib\MinGW\bin\

::compile and link
gcc -c .\src\jbooter.cpp -o .\build\jbooter.o
windres .\src\jbooter.rc .\build\jbooter-rc.o
gcc -o .\build\jbooter .\build\jbooter.o .\build\jbooter-rc.o  -mwindows -lstdc++ -static
del .\build\jbooter.o 
del .\build\jbooter-rc.o
