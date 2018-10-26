
Debian
====================
This directory contains files used to package reecored/reecore-qt
for Debian-based Linux systems. If you compile reecored/reecore-qt yourself, there are some useful files here.

## reecore: URI support ##


reecore-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install reecore-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your reecoreqt binary to `/usr/bin`
and the `../../share/pixmaps/reecore128.png` to `/usr/share/pixmaps`

reecore-qt.protocol (KDE)

