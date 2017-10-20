Lighting Bus (LIBus)
====================

The Lighting Bus is a distributed effects and lighting system for
providing realistic and active lighting effects to models and props
of any kind.  Based around a simple multi-drop serial protocol and
distributed processing of animations it aims to be a simple to use
and implement, yet highly advanced, system.

The core of the system is the serial bus. This uses a 9-bit UART
protocol (9N1) with 24-bit addressing.  Each slave device on a LIBus
bus has its own unique (factory set) address to enable simple plug-and-play
operation of devices.

Commands and data are sent from the master device through the bus to
individual slave devices to perform animation operations.  Animation
facilities available vary depending on the slave device.

See the file [PROTOCOL.md](PROTOCOL.md) for more detail about how
LIBus communicates.


