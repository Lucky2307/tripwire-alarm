# Laser tripwire Arduino
Modern home security appliances offer a wide array of protection against home invasion. These appliances ranges from a simple house lock, 24-hour video surveillance, to sophisticated biometric scanner; each of which have very specific goal to accomplish. However, they all boil down to the same idea; to prevent unauthorized personnel to get access inside the house. <p align="center"><img src="/docs/img/img.png?raw=true" alt="Tripwire"/></p>
## Basic Theory
- Light dependent resistor: Light dependent resistor, or photoresistor, are resistors which its resistance is dependent on the amount of light is received on its face. The brighter it is, the less resistance. <p align="center"><img src="/docs/img/ldr.png?raw=true" alt="LDR graph"/></p>
- Laser: A laser is a device that emits light through a process of optical amplification based on the stimulated emission of electromagnetic radiation. Unlike a normal light source, a laser device is able to be focused to a tight spot. With this, the light can be focused to the photoresistor.
- Voltage divider: A voltage divider is a simple circuit which produces an output voltage that is a fraction of the input voltage.
In a normal situation, the laser will point at the photoresistor, which causes the resistance to be low. When the laser is blocked, the photoresistor will no longer be illuminated, therefore raising the resistance. Using the formula above, when the resistance is raised, the output voltage will drop. <p align="center"><img src="/docs/img/divider.png?raw=true" alt="Voltage divider"/></p>
## Schematic
The schematics for the tripwire is as follows: <p align="center"><img src="/docs/img/schematic.png?raw=true" alt="Schematics"/></p>
## Conclusion
The robot has successfully passed the initial requirements and objectives that we have presented. We have also discovered some limitation during testing; mainly the sensitivity of the tripwire. Unlike the product we covered in literature studies, our tripwire model still detects non-hostile object such as leaf or other small object. Whereas the product in our literature studies have low false positive rate.
