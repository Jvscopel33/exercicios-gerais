#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    float temp;
    char comand1, comand2;
    scanf("%f", &temp);
    scanf(" %c", &comand1);
    scanf(" %c", &comand2);
    if (comand1 == 'c' && comand2 == 'k')
    {
        printf("Temperature: %.2fK", convert_celsius_to_kelvin(temp));
    }
    else if (comand1 == 'c' && comand2 == 'f')
    {
        printf("Temperature: %.2fFº", convert_celsius_to_fahrenheit(temp));
    }
    else if (comand1 == 'k' && comand2 == 'c')
    {
        printf("Temperature: %.2fCº", convert_kelvin_to_celsius(temp));
    }
    else if (comand1 == 'k' && comand2 == 'f')
    {
        printf("Temperature: %.2fFº", convert_kelvin_to_fahrenheit(temp));
    }
    else if (comand1 == 'f' && comand2 == 'c')
    {
        printf("Temperature: %.2fCº", convert_fahrenheit_to_celsius(temp));
    }
    else if (comand1 == 'f' && comand2 == 'k')
    {
        printf("Temperature: %.2fK", convert_fahrenheit_to_kelvin(temp));
    }
    return 0;
}