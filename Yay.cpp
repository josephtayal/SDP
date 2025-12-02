// YYAAAAAAYYYYYYYY

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"

void PlayGame() {
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Play the game");
    LCD.Update();
} 

void Stats() {
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Games Played: ");
    LCD.Update();
    LCD.Write("Wins: ");
    LCD.Update();
    LCD.Write("Losses: ");
    LCD.Update();
}

void Instructions () {
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Cut the Rope is a simple game. ");
    LCD.Update();
}

void Credits () {
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Developers: ");
    LCD.Update();
}

void Menu() {
    LCD.SetFontColor(GREEN);
    LCD.FillRectangle(0,0,320,320);

    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(50, 30, 220, 30);
    LCD.WriteAt("Play Game", 85, 35);
    LCD.Update();
    
    LCD.DrawRectangle(50, 60, 220, 30);
    LCD.WriteAt("Statistics", 85, 65);
    LCD.Update();
    
    LCD.DrawRectangle(50, 90, 220, 30);
    LCD.WriteAt("Instructions", 85, 95);
    LCD.Update();
    
    LCD.DrawRectangle(50, 120, 220, 30);
    LCD.WriteAt("Credits", 85, 125);
    LCD.Update();
}

int main()
{
    int x_position, y_position;
    int x_trash, y_trash;

    Menu();

    while(true) {
        

        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

        if (x_position >= 50 && x_position <= 270 && y_position >= 30 && y_position <= 60) {
            PlayGame();
        } else if (x_position >= 50 && x_position <= 270 && y_position >= 60 && y_position <= 90) {
            Stats();
        } else if (x_position >= 50 && x_position <= 270 && y_position >= 90 && y_position <= 120) {
            Instructions();
        } else if (x_position >= 50 && x_position <= 270 && y_position >= 120 && y_position <= 150) {
            Credits();
        }
        LCD.Update();
    }



    
}
