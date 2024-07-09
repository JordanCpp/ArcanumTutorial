call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 /GX /MT -FeGameSDL1.exe  ^
/I..\Arcanum\source ^
/I..\Backends\SDL1  ^
/I..\dependencies\SDL-devel-1.2.14-VC6\include ^
..\main.cpp ^
..\Backends\SDL1\Arcanum\Graphics\*.cpp ^
..\Backends\SDL1\Arcanum\Events\*.cpp ^
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
/I..\Decompressor\include ^
/I..\Decompressor\zlib ^
..\Decompressor\source\*.cpp ^
/link /LIBPATH:"..\dependencies\SDL-devel-1.2.14-VC6\lib" SDLmain.lib SDL.lib

del *.obj

pause
