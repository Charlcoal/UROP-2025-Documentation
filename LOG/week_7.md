# Week 7

## 15 July 2025

Today I am printing another iteration of the pin sleeve ([Rev3](../Cad_Files/PinSleeve-Rev3.amf)).
I am adjusting the fit to not stick (slightly larger inner diameter)
and increasing the depth of the coil slots to accommodate 300 turns
properly. I am also creating a slot for the magnet to sit within
thin pin itself. In order to do this, I am adjusting the shape of
the inner hole to allow for more support around the magnet, which
pushes up the outer diameter to 0.22".

I am also getting around to starting this log, which means this
marks the first non-backfilled entry in this repository.

## 16 July 2025

Today I am testing the strength of interaction between the magnet
and the 300 turn coils at various distances within the pin sleeve.
The data and analysis from this can be found under [coil_mag_interaction_distance.md](../RESEARCH/coil_mag_interaction_distance.md).
The main takeaway is that the coil magnet interaction at 0.2A is modeled as  
$$F(d) = \frac{2.5d}{(0.255^2 + d^2)^{3/2}}$$  
where $$d$$ is the distance between the magnet center and coil center in inches,
and $$F(d)$$ is the resulting force in milliNetwons (gram equivalent).

One interesting thing I noticed is that the coils are only slightly
warm to the touch when running continuously at 0.2A (0.26W). Given that
the power scales quadratically with current, resistivity increases
with temperature, and the sleeve is currently made of PLA, I think
it is unwise to surpass 0.6W (~0.3A) continuous power for the time
being.

Also, the pin insert I printed yesterday needs some small tweaks to
fit properly. Hopefully I can iterate it more soon.

## 17 July 2025

Today I soldered the ICs (Op amp, Half bridge driver, and microcontroller)
onto their respective breakout boards, as well as soldering connector pins
onto the pin sleeves for future convenience.

## 18 July 2025

Today I tested the free air inductance of the coils in the pin sleeve. They
seem to be a little above 400 microHenry each, which gives me pause for the
PWM control of the half bridge driver. At 12 volts, the coil would very quickly
(in around 1/25000 of a second) reach the majority of its current, meaning PWM
would have to switch at several times that speed. However, the serial interface
for the driver IC can only update at about 150000 times a second (six times as
fast), meaning it might barely function but would have problems with precise control.
This might be solvable by adjusting the time between updates more precisely, and
might not be a problem once there is a load (magnet) that the coil is acting on.
