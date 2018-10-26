Sample init scripts and service configuration for reecored
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/reecored.service:    systemd service unit configuration
    contrib/init/reecored.openrc:     OpenRC compatible SysV style init script
    contrib/init/reecored.openrcconf: OpenRC conf.d file
    contrib/init/reecored.conf:       Upstart service configuration file
    contrib/init/reecored.init:       CentOS compatible SysV style init script

1. Service User
---------------------------------

All three startup configurations assume the existence of a "reecore" user
and group.  They must be created before attempting to use these scripts.

2. Configuration
---------------------------------

At a bare minimum, reecored requires that the rpcpassword setting be set
when running as a daemon.  If the configuration file does not exist or this
setting is not set, reecored will shutdown promptly after startup.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that reecored and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If reecored is run with "-daemon" flag, and no rpcpassword is set, it will
print a randomly generated suitable password to stderr.  You can also
generate one from the shell yourself like this:

bash -c 'tr -dc a-zA-Z0-9 < /dev/urandom | head -c32 && echo'

Once you have a password in hand, set rpcpassword= in /etc/reecore/reecore.conf

For an example configuration file that describes the configuration settings,
see contrib/debian/examples/reecore.conf.

3. Paths
---------------------------------

All three configurations assume several paths that might need to be adjusted.

Binary:              /usr/bin/reecored
Configuration file:  /etc/reecore/reecore.conf
Data directory:      /var/lib/reecored
PID file:            /var/run/reecored/reecored.pid (OpenRC and Upstart)
                     /var/lib/reecored/reecored.pid (systemd)

The configuration file, PID directory (if applicable) and data directory
should all be owned by the reecore user and group.  It is advised for security
reasons to make the configuration file and data directory only readable by the
reecore user and group.  Access to reecore-cli and other reecored rpc clients
can then be controlled by group membership.

4. Installing Service Configuration
-----------------------------------

4a) systemd

Installing this .service file consists on just copying it to
/usr/lib/systemd/system directory, followed by the command
"systemctl daemon-reload" in order to update running systemd configuration.

To test, run "systemctl start reecored" and to enable for system startup run
"systemctl enable reecored"

4b) OpenRC

Rename reecored.openrc to reecored and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
"/etc/init.d/reecored start" and configure it to run on startup with
"rc-update add reecored"

4c) Upstart (for Debian/Ubuntu based distributions)

Drop reecored.conf in /etc/init.  Test by running "service reecored start"
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon uitility.

4d) CentOS

Copy reecored.init to /etc/init.d/reecored. Test by running "service reecored start".

Using this script, you can adjust the path and flags to the reecored program by
setting the BITCOINGREEND and FLAGS environment variables in the file
/etc/sysconfig/reecored. You can also use the DAEMONOPTS environment variable here.

5. Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
