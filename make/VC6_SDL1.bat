call "C:\VC6\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

cl /O2 /GX /MT -FeVC6_SDL1.exe  ^
/I..\Arcanum\source ^
/I..\Backends\SDL1  ^
/I..\Backends\Shared  ^
/I..\dependencies\SDL-devel-1.2.14-VC6\include ^
..\main.cpp ^
..\Backends\Shared\Pollux\Graphics\*.cpp  ^
..\Backends\Shared\Pollux\Widgets\*.cpp ^
..\Backends\Shared\Pollux\Time\*.cpp ^
..\Backends\Shared\Pollux\Loaders\*.cpp ^
..\Backends\Shared\Pollux\Readers\*.cpp ^
..\Backends\Shared\Pollux\Common\*.cpp ^
..\Backends\Shared\Pollux\Events\*.cpp ^
..\Backends\Shared\Pollux\Managers\*.cpp ^
..\Backends\SDL1\Pollux\Graphics\*.cpp ^
..\Backends\SDL1\Pollux\Events\*.cpp ^
..\Backends\SDL1\Pollux\Time\*.cpp ^
..\Arcanum\source\Arcanum\*.cpp ^
..\Arcanum\source\Arcanum\Common\*.cpp ^
..\Arcanum\source\Arcanum\Creators\*.cpp ^
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
/I..\dependencies\zlib ^
/link /LIBPATH:"..\dependencies\SDL-devel-1.2.14-VC6\lib" SDLmain.lib SDL.lib

del *.obj

pause
