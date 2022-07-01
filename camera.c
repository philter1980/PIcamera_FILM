#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wiringPi.h> // Include WiringPi library!

char command[50];
char numero[100];
int i=0;
const int butPin = 17; // Active-low button - Broadcom pin 17, P1 pin 11

int main () {
// Setup stuff:
    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers

    pinMode(butPin, INPUT);      // Set button as INPUT
    pullUpDnControl(butPin, PUD_UP); // Enable pull-up resistor on button
while (1)
{
while (!digitalRead(butPin) )
        {
        i++;
        strcpy (command, "raspistill -t 10 -o photo");
        sprintf (numero, "%d", i);
        strcat (command, numero);
        strcat (command, ".jpg");
        system(command);
        printf(command);
        }
}//end loop

} //end main
