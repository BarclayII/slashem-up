slashem-up
==========

SuperLotsoAddedStuffHack-ExtendedMagic-Upgrades&amp;Patches

Based on SLASH'EM 0.0.8E0F1

Aims for playability and stability.

Currently supported platforms:
Windows 10 with MinGW32 GCC
Fedora
OpenBSD -current
Mac OS X latest version

# Linux/OSX installation notes

Simply go through `./configure && make && make install`.

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

# For lazy Windows users

Simply download the zip file and you're done.

The source compilation is too freaky and problematic on Windows.  It's true.

# Suggested setups

Users with number pad are strongly suggested to turn on `number_pad` option to
DOS compatible.

## Windows users

Bring up a command line prompt via `cmd.exe`.

Enter

```
chcp 437
```

to switch the code page to 437.

Run the executable and you'll be fine.

Adjust the console font and font size to have better experience.

## Linux users

I'll fill this section if I have time.  But since you're a Linux
user you should be able to figure out by your own, I suppose?

## Mac OS X users

Better to run your program under `DECgraphics`.  Also, change your background to
black, enable bold fonts and bright colors in your terminal, and enable colors in
SLASH'EM to have better experience.

More precisely, copy the `sys/winnt/defaults.nh` to `~/.slashemrc`, and modify
the following line

```
OPTIONS=IBMgraphics
```

to

```
OPTIONS=DECgraphics,color
```

