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
/*Joseph Tayal*/
class candy
{
public: 
    int x, bubblestatus, bubblefalling; 
    float y, v;
    // bubblestatus 0 if no bubble, 1 if bubble exists

    candy();
    void Draw();
    void Fall();
    void Float();
    void Eatin();

};

// Sharvari Dhile
void candy::Draw()
    {
        FEHImage Candy;
        Candy.Open("Peppermint.png");
        FEHImage Bubble;
        Bubble.Open("Bubble.png");

        if (bubblestatus == 0) {
            Candy.Draw(x, y);
        }
        if (bubblestatus == 1) {
            Candy.Draw(x, y);
            Bubble.Draw(x,y+25);
            bubblestatus = 0;
        }

        LCD.Update();
        
    }

// Both
void candy::Fall () {
    float g = 0.7;
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillCircle(x+10,y+10,30);
    v+=g;
    y+=v;
    Draw();  
    LCD.Update();  
}

void candy::Float() {
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillCircle(x,y,50);
    y-=0.5;
    if (y < 0) {
        y = 0;
    }
    Draw();  
    LCD.Update();
}


// Sharvari Dhile
candy::candy() {
    x = 140;
    y = 65;
    v = 0;
    bubblestatus = 0;
    bubblefalling = 0;
}


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
void CutRope();
void DrawCreature();

int CurrentGame = 1;
int RopeCutStatus = 0; // 0 if rope isn't cut, 1 if rope cut

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
        if (x_position >= 100 && x_position <= 220 && y_position >= 10 && y_position <= 40) {
            LCD.Clear();
            Menu();
        } 
    }
}

// Sharvari Dhile
void DrawCreature() {
    FEHImage creature;
    creature.Open("OmNom.png");
    creature.Draw(120, 140);
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
    candy one;
    one.bubblestatus = 0;
    int x_position, y_position;
    int x_trash, y_trash;
    int StartTime;

    LCD.SetBackgroundColor(BURLYWOOD);
    // Draw background
    LCD.Clear();
    DrawRope();
    one.Draw();
    DrawCreature();
    LCD.Update();

    StartTime = TimeNow();
    int Time = TimeNow() - StartTime;
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillRectangle(0,0,80,100);

    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Timer: ", 0, 0);
    LCD.WriteAt(Time, 80, 0);

    while (RopeCutStatus == 0) {
        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

        // Cuts the rope
        if (x_position >= 155 && x_position <= 165 && y_position >= 5 && y_position <= 80) {
            CutRope();
        }
    }

    while (one.y < 120) {
        // Rope disappears
        int Time = TimeNow() - StartTime;
        LCD.SetFontColor(BURLYWOOD);
        LCD.FillRectangle(0,0,80,120);

        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Timer: ", 0, 0);
        LCD.WriteAt(Time, 80, 0);

        DrawRope();
        DrawCreature();
        one.Fall();
        Sleep(0.01);
    }
}

void LevelTwo() {
    candy two;
    two.bubblestatus = 1;
    int x_position, y_position;
    int x_trash, y_trash;
    int StartTime;

    LCD.SetBackgroundColor(BURLYWOOD);
    // Draw background
    LCD.Clear();
    DrawRope();
    two.Draw();
    DrawCreature();
    LCD.Update();

    StartTime = TimeNow();
    int Time = TimeNow() - StartTime;
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillRectangle(0,0,80,100);

    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Timer: ", 0, 0);
    LCD.WriteAt(Time, 80, 0);

    while (RopeCutStatus == 0) {
        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

        // Cuts the rope
        if (x_position >= 155 && x_position <= 165 && y_position >= 5 && y_position <= 80) {
            CutRope();
        }
    }

    while (two.y > 0 && two.bubblefalling == 0) {
        // Rope disappears
        int Time = TimeNow() - StartTime;
        LCD.SetFontColor(BURLYWOOD);
        LCD.FillRectangle(0,0,80,120);

        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Timer: ", 0, 0);
        LCD.WriteAt(Time, 80, 0);

        DrawRope();
        DrawCreature();
        two.Fall();
        Sleep(0.01);

        // Use touch to figure out when to pop bubble
    }
} 

void CutRope () {
    RopeCutStatus = 1;
    LCD.SetFontColor(BURLYWOOD);//drawing rope
    LCD.DrawLine(158,5,162,75);
    LCD.DrawLine(159,5,163,75);
}

void DrawRope()
{
    /*Joseph Tayal*/
    LCD.SetFontColor(LIGHTSKYBLUE);//Drawing peg
    LCD.DrawCircle(159,10,5);
    LCD.FillCircle(159,10,5);
    LCD.SetFontColor(BLUE);//Drawing peg
    LCD.DrawCircle(159,10,2);
    LCD.FillCircle(159,10,2);

    if (RopeCutStatus == 0) {
        LCD.SetFontColor(ROPEBROWN);//drawing rope
        LCD.DrawLine(158,10,162,75);
        LCD.DrawLine(159,10,163,75);
    }

    LCD.Update();
}

// Sharvari Dhile
void DrawBubble() {
    FEHImage bubble;
    bubble.Open("Bubble.png");
    bubble.Draw(50,50);
}

// Sharvari Dhile
void Timer() {
    int start = TimeNow();
    LCD.SetFontColor(BLACK);
    LCD.WriteAt(start, 10, 0);

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
    LCD.DrawCircle(120, 120, 25);
    LCD.DrawCircle(200, 120, 25);
    LCD.WriteAt("1", 115, 110);
    LCD.WriteAt("2", 195, 110);
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    // Change this to calculate the touch coordinates and call specific function
    ChooseLevel();
    BackToMenu();
    
    LCD.Update();

} 

// Sharvari Dhile
void Stats() {
    // Displays the user stats
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine(" ");
    LCD.WriteLine(" ");
    LCD.WriteLine("Games Played: ");
    LCD.WriteLine("Wins: ");
    LCD.WriteLine("Losses: ");
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Instructions () {
    // Displays the instructions for the game
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine(" ");
    LCD.WriteLine(" ");
    LCD.WriteLine("Cut the Rope is a simple game. The goal is to cut the rope that is connected to the candy and make sure the creature eats the candy.");
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Credits () {
    // Displays the credits
    LCD.Clear(BLACK);
    LCD.Update();
    LCD.WriteLine(" ");
    LCD.WriteLine(" ");
    LCD.WriteLine("Developers: ");
    LCD.WriteLine("Sharvari Dhile");
    LCD.WriteLine("Joe Tayal");
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

// Sharvari Dhile
void Menu() {
    LCD.SetBackgroundColor(LIGHTBLUE);
    LCD.Clear();
    LCD.Update();

    FEHImage creature;
    creature.Open("OmNom.png");
    creature.Draw(110, 140);
    LCD.Update();

    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Cut the Rope", 85, 6);
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
