// YYAAAAAAYYYYYYYY

#include "FEHLCD.h"

int main()
{
    LCD.WriteLine("Hello World!");
    LCD.WriteLine("Menu");
    LCD.WriteLine("Play Game");
    LCD.WriteLine("Statistics");
    LCD.WriteLine("Instructions");
    LCD.WriteLine("Credits");
    while (1) {
        LCD.Update();
        // Never end
    }
    return 0;
}
