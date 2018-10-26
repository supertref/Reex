
Debian
====================
This directory contains files used to package relianced/reliance-qt
for Debian-based Linux systems. If you compile relianced/reliance-qt yourself, there are some useful files here.

## reliance: URI support ##


reliance-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install reliance-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your relianceqt binary to `/usr/bin`
and the `../../share/pixmaps/reliance128.png` to `/usr/share/pixmaps`

reliance-qt.protocol (KDE)

