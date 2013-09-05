![alt text](https://raw.github.com/technosaurus/sdesk/master/sdesk.png "SDesk") SDesk (Simple desktop)
================================================================================
SDesk monitors directories to provide desktop elements on the fly.

$SDESKDIR/tray
* provides tray applets from applet subdirectories

$SDESKDIR/icons
* provides desktop icons from .desktop files or symlinks

$SDESKDIR/ui
* provides gui for apps from gtkbuilder ui files

$SDESKDIR/sh
* provides helper functions to UI/tray apps from sourced shell scripts

$SDESKDIR/desk
* provides desktop backgrounds capable of displaying non-interactive widgets

$SDESKDIR/plugins
* provides plugins to help UI/tray apps
These can be extended to provide extra capabilities such as interaction via
RPC, sockets, DBUS... or additional UI widgets such as those in webkitgtk,
or an interface to C libraries or other languages