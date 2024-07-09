
"C:\Downloads\codeblocks-8.02mingw-setup\MinGW\bin\g++" -Wall -Wextra -std=c++98 -O2 -static -s -o GameSDL1 ^
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
-I..\Decompressor\include ^
-I..\Decompressor\zlib ^
..\Decompressor\source\*.cpp ^
-lmingw32 -lSDLmain -lSDL

pause