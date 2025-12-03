/*
Table H1
Joseph Tayal
Sharvari Dhile


Citations

*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"
/*Define*/

#define ROPEBROWN 0x8B5A2B

/*Class Deffinitions*/
class candy
{
public: 
    int x, y, bubblestatus;
    void Draw();
    void Fall();
    void Float();
    void Eatin();
};


    void Draw()
    {
        
    }

};




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
void Timer();
void DrawBubble();
void DrawRope();

int CurrentGame = 1;

// Sharvari Dhile
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

// Sharvari Dhile
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
            break;
        } else if (x_position >= 165 && x_position <= 235 && y_position >= 95 && y_position <= 155) {
            LevelTwo();
            break;
        }
    }
}

void LevelOne() {
    LCD.SetBackgroundColor(BURLYWOOD);
    LCD.Clear();
    LCD.Update();
    //Timer();
    //LCD.Update();
    /*Draw candy, creature, and rope*/

    LCD.SetFontColor(LIGHTSKYBLUE);//Drawing peg
    LCD.DrawCircle(159,10,5);
    LCD.FillCircle(159,10,5);
    LCD.SetFontColor(BLUE);//Drawing peg
    LCD.DrawCircle(159,10,2);
    LCD.FillCircle(159,10,2);
    LCD.SetFontColor(ROPEBROWN);//drawing rope
    LCD.DrawLine(158,10,162,75);
    LCD.DrawLine(159,10,163,75);
    LCD.Update();






}

void LevelTwo() {
    candy two;
    two.bubblestatus == 1;
    LCD.SetBackgroundColor(LIGHTGREEN);
    LCD.Clear();
    LCD.Update();
    Timer();
    LCD.Update();
} 

void DrawBubble() {
    FEHImage bubble;
    bubble.Open("Bubble.png");
    bubble.Draw(50,50);
}


// Sharvari Dhile
void Timer() {
    // Finds start time
    int start = TimeNow();
    // Uses start time to allow user to play until 30 seconds are reached
    while(TimeNow() - start <= 10 && CurrentGame != 0) {
        LCD.Clear();
        LCD.Write("Time: ");
        LCD.WriteLine(TimeNow() - start);
        Sleep(0.1);
    }

    int UserTime = TimeNow() - start;

    // Fail function or currentgame variable is set to 1 in the actual gameplay
}

// Sharvari Dhile
void PlayGame() {
    // Displays the screen to play the game
    LCD.Clear(BLACK);
    LCD.Update();
    FEHImage level_background;
    level_background.Open("backgroundlevel.png");
    level_background.Draw(0,0);
    LCD.WriteAt("Choose Level", 85, 30);
    LCD.DrawCircle(120, 120, 35);
    LCD.DrawCircle(200, 120, 35);
    LCD.WriteAt("1", 115, 110);
    LCD.WriteAt("2", 195, 110);
    LCD.SetFontColor(BLACK);
    LCD.DrawRectangle(105, 190, 150, 40);
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    ChooseLevel();
    BackToMenu();
    
    LCD.Update();

} 

// Sharvari Dhile
void Stats() {
    // Displays the user stats
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine("Games Played: ");
    LCD.WriteLine("Wins: ");
    LCD.WriteLine("Losses: ");
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(105, 190, 150, 40);
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Instructions () {
    // Displays the instructions for the game
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.Write("Cut the Rope is a simple game. The goal is to cut the rope that is connected to the candy and make sure the creature eats the candy.");
    LCD.DrawRectangle(105, 190, 150, 40);
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Credits () {
    // Displays the credits
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine("Developers: ");
    LCD.WriteLine("Sharvari Dhile");
    LCD.WriteLine("Joe Tayal");
    LCD.DrawRectangle(105, 190, 150, 40);
    LCD.WriteAt("Main Menu", 115, 200);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Menu() {
    LCD.SetFontColor(LIGHTCORAL);
    LCD.FillRectangle(0,0,320,280);

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
