call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++11 -static -s -o GameSDL1 ^
-I..\Arcanum\source ^
-I..\Backends\SDL1  ^
-I..\dependencies\SDL-1.2.15\include ^
-L..\dependencies\SDL-1.2.15\lib\x86 ^
..\Backends\SDL1\Arcanum\Graphics\*.cpp ^
..\Backends\SDL2\Arcanum\Events\*.cpp ^
..\main.cpp ^
..\Arcanum\source\Arcanum\*.cpp ^
..\Arcanum\source\Arcanum\Game\*.cpp ^
..\Arcanum\source\Arcanum\Graphics\*.cpp ^
..\Arcanum\source\Arcanum\Loaders\*.cpp ^
..\Arcanum\source\Arcanum\Readers\*.cpp ^
..\Arcanum\source\Arcanum\Managers\*.cpp ^
..\Arcanum\source\Arcanum\Objects\*.cpp ^
-lmingw32 -lSDLmain -lSDL

pause