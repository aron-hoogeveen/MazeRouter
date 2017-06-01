#ifndef WIRELESSCOMMUNICATION_H_
#define WIRELESSCOMMUNICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define COMPORT "COM5"
#define BAUDRATE CBR_9600

void initSio(HANDLE hSerial);

int readByte(HANDLE hSerial, char *buffRead);

int writeByte(HANDLE hSerial, char *buffWrite);

#endif /* WIRELESSCOMMUNICATION_H_ */
