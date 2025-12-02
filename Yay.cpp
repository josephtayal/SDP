// YYAAAAAAYYYYYYYY

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"

void PlayGame() {
    LCD.Clear();
    LCD.Write("Play the game");
} 

int main()
{
    int x_position, y_position;
    int x_trash, y_trash;

    LCD.DrawRectangle(50, 30, 220, 30);
    LCD.WriteAt("Play Game", 85, 35);
    
    LCD.DrawRectangle(50, 60, 220, 30);
    LCD.WriteAt("Statistics", 85, 65);
    
    LCD.DrawRectangle(50, 90, 220, 30);
    LCD.WriteAt("Instructions", 85, 95);
    
    LCD.DrawRectangle(50, 120, 220, 30);
    LCD.WriteAt("Credits", 85, 125);

    // Wait for touch - use x and y
    while (!LCD.Touch(&x_position,&y_position)) {}

    // Touch - use x and y
    while (LCD.Touch(&x_trash,&y_trash)) {}

    if (x_position >= 50 && x_position <= 270 && y_position >= 30 && y_position <= 60) {
        PlayGame();
    }


    
}
