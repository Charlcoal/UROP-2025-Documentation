# Week 8

## 22 July 2025

Today I controlled the half bridge driver with an arduino
successfully. It turns out that due to setup time and offsets
in the half bridges, the serial speed does not get in the way
of very short pulses. This means I can continue without much
issue, although driving pins at slightly different currents
will be difficult (although potentially unnecessary).

One issue that I'll have to deal with is the delay for the
half bridge gates to turn on. For a little while (~20us before
and after the gate starts driving current) the free-wheeling
mode is shutting down, increasing the resistance of the gate.
This decreases efficiency the faster the gate is switched,
which prevents me from effectively switching above 15kHz or
so without heating up the half bridge chip significantly.
This means the pin will make an audible high pitch noise
under load, which obviously isn't desirable. 

Using a thinner wire with more windings for the coil would
reduce the volume of the noise, and getting a chip capable
of switching faster would eliminate the problem entirely,
but the frequencies I'm using are already atypically high
for motor applications.

The arduino code I wrote can be found under [initial_half_bridge_testing](../RESEARCH/initial_half_bridge_testing/)
