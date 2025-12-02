// YYAAAAAAYYYYYYYY

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"

// Function declarations
void BackToMenu();
void Menu();
void Stats();
void Instructions();
void Credits();
void PlayGame();
void LevelOne();
void LevelTwo();
void ChooseLevel();
void DrawBoard();

void BackToMenu() {
    int x_position, y_position;
    int x_trash, y_trash;

    // Waits for the user to touch the screen
    while(true) {
        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

    // Brings user back to the main menu
        if (x_position >= 115 && x_position <= 270 && y_position >= 200 && y_position <= 250) {
            LCD.Clear();
            Menu();
        } 
    }
}

void ChooseLevel() {
    int x_position, y_position;
    int x_trash, y_trash;

    // Waits for the user to touch the screen
    while(true) {
        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

    // Brings user to specific level
        if (x_position >= 95 && x_position <= 155 && y_position >= 95 && y_position <= 155) {
            LevelOne();
        } else if (x_position >= 165 && x_position <= 235 && y_position >= 95 && y_position <= 155) {
            LCD.Clear();
        }
    }
}

void DrawBoard() {
    LCD.Clear();
    LCD.SetBackgroundColor(BURLYWOOD);
}


void LevelOne() {
    LCD.Clear();
    LCD.SetBackgroundColor(BURLYWOOD);
}

/*
void LevelTwo() {
    // DrawBoard function
    // Other draw functions
} 
*/

void PlayGame() {
    // Displays the screen to play the game
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteAt("Choose Level", 85, 30);
    LCD.DrawCircle(120, 120, 35);
    LCD.DrawCircle(200, 120, 35);
    LCD.WriteAt("1", 115, 110);
    LCD.WriteAt("2", 195, 110);
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    ChooseLevel();
    BackToMenu();
    LCD.Update();

} 

void Stats() {
    // Displays the user stats
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine("Games Played: ");
    LCD.WriteLine("Wins: ");
    LCD.WriteLine("Losses: ");
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

void Instructions () {
    // Displays the instructions for the game
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Cut the Rope is a simple game. The goal is to cut the rope that is connected to the candy and make sure the creature eats the candy.");
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

void Credits () {
    // Displays the credits
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Developers: ");
    LCD.Write("Joe Tayal");
    LCD.Write("Sharvari Dhile");
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

void Menu() {
    LCD.SetFontColor(LIGHTCORAL);
    LCD.FillRectangle(0,0,320,300);

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

    int x_position, y_position;
    int x_trash, y_trash;

    // Depending on where user touches, the program will proceed to a different page
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

int main()
{
    Menu();
}
