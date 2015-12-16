slashem-up
==========

SuperLotsoAddedStuffHack-ExtendedMagic-Upgrades&amp;Patches

Based on SLASH'EM 0.0.8E0F1

Aims for playability and stability.

Currently supported platforms:
Windows 10 with MinGW32 GCC
Fedora
OpenBSD -current

# MinGW32/MSYS additional notes

Finally got the stuff running on Windows... WTH.

First, make sure that you installed bison and flex during MinGW/MSYS installation.
The `dgn_comp.exe` with `YACC_LEX` set to false has difficulty processing the
dungeon description file and I have no idea what was going on.

Next, run `nhsetup.bat` in `sys/winnt`.

Then change your directory to `src`, edit the Makefile there to set `YACC_LEX  = Y`,
and `LEXYYC = lex.yy.c`.

Edit `include/config.h` and make sure `UNIX` is not defined.

Finally, run `mingw32-make install`, be sure to include your MinGW and MSYS bin
directories in `PATH`.

