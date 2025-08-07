# Current Sensing

## Method

To measure the current of the coils, I used a
~1 Ohm resistor in series with the coil. I then
measured the voltage across the resistor using an
[Op-Amp circuit](RESEARCH/current_sensing/circuit.jpg).

The Low-Pass filter was needed to prevent the voltage
spikes from becoming too severe. The voltage spikes
are a side effect of measuring the current in-line,
i.e. the common mode voltage swings by 12 volts every
PWM cycle, causing a noticeable error in the output of
the Op-Amp. Measuring during the free-wheeling section
of the PWM cycles should give accurate results, though.

## Results

With current sensing working, I then tested whether the
presence of a magnet inside the coil effected the current
measured. Unfortunately, there was no distinguishable difference.
I then tested a ferromagnet screw (just an iron/steel screw)
instead, which did have a noticeable difference. I have taken
images of the 256-sample averages of a single PWM cycle [with](RESEARCH/current_sensing/with_screw.jpg)
and [without](RESEARCH/current_sensing/without_screw.jpg) the
screw.

To keep track of the position of the pin in the final design,
both a magnet and some ferromagnetic mass must be integrated
into the pin.
