call "C:\Downloads\codeblocks-12.11mingw-setup\MinGW\mingwvars.bat"

g++ -Wall -Wextra -pedantic -O2 -std=c++11 -static -s -o GameSDL2 ^
-I..\Arcanum\source ^
-I..\Backends\SDL2  ^
-I..\dependencies\SDL2-2.30.3\include ^
-L..\dependencies\SDL2-2.30.3\lib\x86 ^
..\Backends\SDL2\Arcanum\Graphics\*.cpp ^
..\Backends\SDL2\Arcanum\Events\*.cpp ^
..\main.cpp ^
..\Arcanum\source\Arcanum\*.cpp ^
..\Arcanum\source\Arcanum\Game\*.cpp ^
..\Arcanum\source\Arcanum\Graphics\*.cpp ^
..\Arcanum\source\Arcanum\GUI\*.cpp ^
..\Arcanum\source\Arcanum\Loaders\*.cpp ^
..\Arcanum\source\Arcanum\Readers\*.cpp ^
..\Arcanum\source\Arcanum\Managers\*.cpp ^
..\Arcanum\source\Arcanum\Objects\*.cpp ^
..\Arcanum\source\Arcanum\Ui\*.cpp ^
..\Arcanum\source\Arcanum\Widgets\*.cpp ^
..\Decompressor\zlib\adler32.c ^
..\Decompressor\zlib\compress.c ^
..\Decompressor\zlib\crc32.c ^
..\Decompressor\zlib\deflate.c ^
..\Decompressor\zlib\gzclose.c ^
..\Decompressor\zlib\gzlib.c ^
..\Decompressor\zlib\gzread.c ^
..\Decompressor\zlib\gzwrite.c ^
..\Decompressor\zlib\inflate.c ^
..\Decompressor\zlib\infback.c ^
..\Decompressor\zlib\inftrees.c ^
..\Decompressor\zlib\inffast.c ^
..\Decompressor\zlib\trees.c ^
..\Decompressor\zlib\uncompr.c ^
..\Decompressor\zlib\zutil.c ^
-lSDL2main -lSDL2

pause