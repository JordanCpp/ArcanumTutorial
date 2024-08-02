call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++11 -static -s -o MinGW_SDL2 ^
-I..\Arcanum\source ^
-I..\Backends\Shared  ^
-I..\Backends\SDL2  ^
-I..\dependencies\SDL2-2.30.3\include ^
-L..\dependencies\SDL2-2.30.3\lib\x86 ^
..\Backends\Shared\Pollux\Graphics\*.cpp  ^
..\Backends\Shared\Pollux\Widgets\*.cpp ^
..\Backends\Shared\Pollux\Time\*.cpp ^
..\Backends\Shared\Pollux\Loaders\*.cpp ^
..\Backends\Shared\Pollux\Readers\*.cpp ^
..\Backends\Shared\Pollux\Common\*.cpp ^
..\Backends\Shared\Pollux\Events\*.cpp ^
..\Backends\SDL2\Pollux\Graphics\*.cpp ^
..\Backends\SDL2\Pollux\Events\*.cpp ^
..\Backends\SDL2\Pollux\Time\*.cpp ^
..\main.cpp ^
..\Arcanum\source\Arcanum\*.cpp ^
..\Arcanum\source\Arcanum\Common\*.cpp ^
..\Arcanum\source\Arcanum\Formats\*.cpp ^
..\Arcanum\source\Arcanum\Game\*.cpp ^
..\Arcanum\source\Arcanum\GUI\*.cpp ^
..\Arcanum\source\Arcanum\Managers\*.cpp ^
..\Arcanum\source\Arcanum\Objects\*.cpp ^
..\Arcanum\source\Arcanum\Ui\*.cpp ^
..\dependencies\zlib\adler32.c ^
..\dependencies\zlib\compress.c ^
..\dependencies\zlib\crc32.c ^
..\dependencies\zlib\deflate.c ^
..\dependencies\zlib\gzclose.c ^
..\dependencies\zlib\gzlib.c ^
..\dependencies\zlib\gzread.c ^
..\dependencies\zlib\gzwrite.c ^
..\dependencies\zlib\inflate.c ^
..\dependencies\zlib\infback.c ^
..\dependencies\zlib\inftrees.c ^
..\dependencies\zlib\inffast.c ^
..\dependencies\zlib\trees.c ^
..\dependencies\zlib\uncompr.c ^
..\dependencies\zlib\zutil.c ^
-I..\dependencies\zlib ^
-lSDL2main -lSDL2

pause