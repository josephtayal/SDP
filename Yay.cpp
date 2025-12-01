// YYAAAAAAYYYYYYYY

#include "FEHLCD.h"

void PlayGame() {
    LCD.WriteLine("Play game here");
}

void Menu() {

}

int main()
{
    int x, y;

    LCD.WriteLine("Menu");
    LCD.WriteLine("Play Game");
    LCD.WriteLine("Statistics");
    LCD.WriteLine("Instructions");
    LCD.WriteLine("Credits");

    // Wait for touch - use x and y
    while (!LCD.Touch(&x,&y)) {}

    // Touch - use x and y
    while (LCD.Touch(&x,&y)) {}

    



    
}
