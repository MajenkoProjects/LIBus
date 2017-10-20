LIBus Protocol
==============

Communication on the LIBus bus is performed using UART communication
(half duplex) at 2400 baud (subject to change in the near future) with
9N1 formatting (9 bits, no parity, 1 stop bit).

Communication is made up of packets consisting of three address bytes, one
command byte, and a varying number of data bytes. There is no checksumming
or error correction, and the number of data bytes is determined by the
command byte being used coupled with the slave device type that is being
communicated with.

The first byte of the address is fixed and determines the type of device
being communicated with.  This byte always has its 9th bit set to indicate
the start of a packet. All communication on all slaves is reset when the
first byte of an address is detected. This assists in preventing any slaves
getting out of sync with the master.

A slave starts listening for a fresh packet when the first byte of an address
is received. If that byte doesn't match the device type the slave stops listening
and ignores all further communication until the next start-of-packet address byte
is received. The same goes for the subsequent two address bytes - as soon as a
non-matching address byte is received the slave stops listening.

A special address byte of `0xFF` is used as a "wildcard" or "broadcast" address.
It may be used in place of either of the second or third bytes of the device
address and that byte is effectively ignored (all devices see it as their
valid address byte).

Slave devices always have their RX pins enabled for receiving data, however their
TX pins are held in a high impedance mode with a weak pullup resistor. This allows
any slave to transmit without causing electrical issues on the bus. It also allows
out-of-band signalling by more than one slave at once (see AreYouThere below).

AreYouThere
-----------

The special AreYouThere request is used to probe an address (or set of addresses using
the wildcard `0xFF`) to see if there is at least one device on that address.  This is used
during bus probing to identify devices.

When a device receives the AreYouThere command it pulls its TX pin LOW for 1ms. The
master device then sees this as a "Yes, I am here" signal which may come from any number
of devices without the need for collision detection and prevension.

Bus probing is performed using a tree-like method. Each possible device type byte is first
probed to see if there are any devices of that type on the bus. For each type that responds
with a low 1ms pulse any devices within that device type are scanned for. First the second
address byte is scanned from `0x00` to `0xFE` with the third byte set to the wildcard `0xFF`
to identify any devices in that tier of the address, then finally any addresses that responded
with the 1ms low pulse are further scanned to identify the full 24-bit address in as few iterations
as possible.

For example, if we have devices on 0x201111, 0x201122, 0x202233 and 0x301122 the sequence would be:

* Scan 0x{00}FFFF to 0x{FE}FFFF.
  * 0x20FFFF responds. Scan 0x20{00}FF to 0x20{FE}FF.
    * 0x2011FF responds. Scan 0x2011{00} to 0x2011{FF}
      * 0x201111 responds. Valid device address found.
      * 0x201122 responds. Valid device address found.
    * 0x2022FF responds. Scan 0x2022{00} to 0x2022{FE}.
      * 0x202233 responds. Valid device address found.
  * 0x30FFFF responds. Scan 0x30{00}FF to 0x30{FE}FF.
    * 0x3011FF responds. Scan 0x3011{00} to 0x3011{FE}.
      * 0x301122 responds. Vaid device address found.

From that we can see there are 255 outer iterations (without optimization for known device types),
then two inner iterations of 255 each. Each of those then contains one or more further iterations of 0-255.
By totalling up the number of "Scan" entries in the list above we see just 6 scans, each at 255 iterations each.
That's 255 * 6 = 1530 AreYouThere probes to identify every device on that bus. Conversely, by iterating sequentially
through each possible address from 0x000000 to 0xFFFFFF you would have 16777216 iterations. This tree method
and group response provides a massive improvement on scan time.

