# Interaction Between 300 Turn Coil and N52 Magnet at various distances

## Data, taken at a coil amperage of 0.2 A

| distance from center (inches) | Force (milliNewtons) |
| ----------------------------: | -------------------: |
|                        -12/16 |                    0 |
|                        -11/16 |                  0.5 |
|                        -10/16 |                  0.9 |
|                         -9/16 |                  1.2 |
|                         -8/16 |                  3.0 |
|                         -7/16 |                  4.2 |
|                         -6/16 |                  6.2 |
|                         -5/16 |                  7.8 |
|                         -4/16 |                 10.3 |
|                         -3/16 |                   12 |
|                         -2/16 |                  8.2 |
|                         -1/16 |                  5.6 |
|                             0 |                  2.5 |
|                          1/16 |                 -5.2 |
|                          2/16 |                -10.0 |
|                          3/16 |                -10.5 |
|                          4/16 |                 -8.6 |
|                          5/16 |                 -9.3 |
|                          6/16 |                 -7.2 |

## Methodology

The coil sleeve was suspended above a scale at a specific
distance with a magnet and spacer cylinder inside, such that
the spacer was resting on the scale and the center of the
magnet was a specific distance from the center of the coil.
Then, the scale was zeroed, and the current was turned on.
For values that appear negative here, the polarity was reversed
to provide a consistant downwards force against the scale. The
displayed "mass" in grams is interpreted as milliNewtons here.

## Analysis

To model the interaction between the magnet and the coil,
I treated each center as a point magnetic pole; the magnet
slides along the x axis with a perpendicular offset $$D$$ to the coil.
I am using a point model since the coil length and magnet length
are the same, simlpifying the dynamics of dipoles to monopoles.
The offset accounts for the concentricity of the magnet and coil.

Using some trigonometry, this model predicts the force to be
$$\frac{ax}{(D^2 + x^2)^{3/2}}$$, where $$a$$ is a constant
describing the intensity of the force overall at 0.2 A,
and $$x$$ is the distance between the magnet center and coil
center, and $$D$$ is the above mentioned perpendicular distance.

I put the data from the table into [desmos](https://www.desmos.com/calculator/2qaqsglqw1)
and tried a regression fit onto the equation above.
It did not quite work as expected, as the force measurements
get close to 0 too quickly near the edges. This discrepancy made
me realized my measurement method probably was effected by static friction,
as the magnet did not move while applying force. To counteract this, I added
a correction term $$c$$ to the model, which matched the sign of $x$. This
resulted in a great fit: $$R^2 = 0.989$$. The parameters for the fit
were $$a = 2.50 \text{mN} * \text{in}^2$$, $$D = 0.255$$ inches,
and $$c = 3.90$$ milliNewtons.

When combining 4 of these equation spaced
according to the distance between coils, there are 4 distinct notches in the
total achievable force in the center of each coil. They do not dip below
7 milliNewtons however (from adjacent coils), so with brief 0.8 Amp spikes
in current it should perform fine.
