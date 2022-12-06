
Debian
====================
This directory contains files used to package vibofchaind/vibofchain-qt
for Debian-based Linux systems. If you compile vibofchaind/vibofchain-qt yourself, there are some useful files here.

## vibofchain: URI support ##


vibofchain-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install vibofchain-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your vibofchain-qt binary to `/usr/bin`
and the `../../share/pixmaps/vibofchain128.png` to `/usr/share/pixmaps`

vibofchain-qt.protocol (KDE)

