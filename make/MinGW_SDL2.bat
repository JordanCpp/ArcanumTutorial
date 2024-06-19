call "C:\Downloads\codeblocks-8.02mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -Werror -pedantic -O2 -std=c++11 -static -s -o GameSDL2 ^
-I..\Arcanum\source ^
-I..\dependencies\SDL2-2.30.3\include ^
-L..\dependencies\SDL2-2.30.3\lib\x86 ^
..\Backends\SDL2\*.cpp ^
..\main.cpp ^
..\Arcanum\source\Arcanum\*.cpp ^
..\Arcanum\source\Arcanum\Game\*.cpp ^
..\Arcanum\source\Arcanum\Graphics\*.cpp ^
..\Arcanum\source\Arcanum\Loaders\*.cpp ^
..\Arcanum\source\Arcanum\Readers\*.cpp ^
..\Arcanum\source\Arcanum\Managers\*.cpp ^
..\Arcanum\source\Arcanum\Objects\*.cpp ^
-lSDL2main -lSDL2

pause