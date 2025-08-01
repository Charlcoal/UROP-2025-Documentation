# Half Bridge Results

The ~25us rise and fall time of the half bridge
limits the PWN frequency to under 20kHz, meaning
it is audible. Additionally, the switching time
takes up a considerable portion of 10kHz PWM,
significantly impacting the in-line current sensing
with voltage swings. Because the coils are around
450 uH and have a resistance around 6 Ohms, the
10kHz PWN completely fails to create a smooth current,
massively reducing efficiency.

Ideally, a future iteration of this project would use
a discrete gate driver and MOSFETs, with high-side
current sensing, ideally above 20kHz. I think a
functional prototype is still possible with the
MP6527, however. I will be increasing the in-line
current sensing resistance.
