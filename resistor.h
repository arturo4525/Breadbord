#ifndef RESISTOR_H // För att man inte ska kunna definera två gånger
#define RESISTOR_H

int pointA, pointB, y;

int addResistor(int beginningX, int endingX, int axisy);
int deleteResistor(int beginningX, int axisy);

#endif /* ifndef RESISTOR_H */