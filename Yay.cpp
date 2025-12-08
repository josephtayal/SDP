/*
Table H1
Joseph Tayal
Sharvari Dhile


Citations
FEH SDP Simulator Libraries
TAs, GTA, Professor
*/

#include "FEHLCD.h"
#include "FEHUtility.h"
#include "FEHImages.h"

/*Define*/

#define ROPEBROWN 0x8B5A2B
#define ropelength 45
#define bubblelocation 80
#define creaturelocation 140

/*Class Deffinitions*/

/* Author: Joseph Tayal
This is the candy class
It contains the x and y coordinates of the candy object
It also has the status of the bubble
It also has the Draw, Fall, and Float functions
The purpose of this class is to control the candy objext
All the variables and functions are public
*/
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

};

/* Author: Sharvari Dhile
This is the constructor of the candy object
It sets all the variables to default values
*/
candy::candy() {
    x = 140;
    y = ropelength-10;
    v = 0;
    bubblestatus = 0;
    bubblefalling = 0;
}

/* Author: Sharvari Dhile/Joseph Tayal
This is the Draw function which draws the candy and bubble
*/
void candy::Draw()
    {
        FEHImage Candy;
        Candy.Open("Peppermint.png");
        FEHImage CandyWithBubble;
        CandyWithBubble.Open("PeppermintWithBubble.png");
        

        if (bubblestatus == 0) {
            Candy.Draw(x, y);//drawing normal candy
        }
        if (bubblestatus == 1) {
            CandyWithBubble.Draw(x-3, y);//drawing candy with the bubble surrounding it
        }

        LCD.Update();
        
    }

/* Author: Joseph Tayal/Sharvari Dhile
This is the Fall function which draws the candy falling
The purpose of this function is to use gravity with the candy object
*/
void candy::Fall () {
    float g = 0.9;
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillCircle(x+22,y+22,15);
    v+=g;
    y+=v;
    Draw();  
    LCD.Update();  
}

/* Author: Joseph Tayal
This is the Float function which draws the candy with bubble floating
*/
void candy::Float() {
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillCircle(x+24,y+27,22);
    y-=1.6;
    if (y < 0) {
        y = 0;
    }
    Draw();  
    LCD.Update();
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
void ClearBubble();
void WinScreen();
void LoseScreen();

// Variables
int RopeCutStatus = 0; // 0 if rope isn't cut, 1 if rope cut
int Wins, Loses, Games;

/* Author: Joseph Tayal
This function clears the previous bubble location
*/
void ClearBubble()
{
    LCD.SetFontColor(BURLYWOOD);
    LCD.DrawCircle(135,bubblelocation,60);
    LCD.FillCircle(135,bubblelocation,60);
    LCD.Update();
}

/* Author: Sharvari Dhile
This function adds the back to menu into the stats, instruction, and credits page
*/
void DrawCreature() {
    FEHImage creature;
    creature.Open("OmNom.png");
    creature.Draw(120, 140);
}

/*Author: Sharvari Dhile/Joseph Tayal
This function is for level one of the game
It draws everything on the screen and allows the user to cut the rope
*/
void LevelOne() {
    candy one;
    one.bubblestatus = 0;
    RopeCutStatus = 0;
    int x_position, y_position;
    int x_trash, y_trash;
    int StartTime;

    Games++;

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
    LCD.FillRectangle(0,0,110,100);

    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Timer: ", 0, 0);
    LCD.WriteAt(Time, 80, 0);
    LCD.Update();

    while (RopeCutStatus == 0) {
        // Wait for touch - use x and y
        while (!LCD.Touch(&x_position,&y_position)) {}

        // Touch - use x and y
        while (LCD.Touch(&x_trash,&y_trash)) {}

        // Cuts the rope
        if (x_position >= 155 && x_position <= 165 && y_position >= 5 && y_position <= ropelength) {
            CutRope();
        }
    }

    while (one.y < 120) {
        Time = TimeNow() - StartTime;
        LCD.SetFontColor(BURLYWOOD);
        LCD.FillRectangle(0,0,110,100);

        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Timer: ", 0, 0);
        LCD.WriteAt(Time, 80, 0);
        LCD.Update();

        DrawRope();
        DrawCreature();
        one.Fall();
        Sleep(0.01);
    }

    WinScreen();
}

/*Author: Joseph Tayal/Sharvari Dhile
This function is for level two of the game
It draws everything on the screen and allows the user to cut the rope and pop the bubble
*/
void LevelTwo() {
    candy two;
    two.bubblestatus = 0;
    RopeCutStatus = 0;
    int x_position, y_position;
    int x_trash, y_trash;
    int StartTime;

    Games++;

    LCD.SetBackgroundColor(BURLYWOOD);
    // Draw background
    LCD.Clear();
    DrawRope();
    two.Draw();
    DrawCreature();
    DrawBubble();
    LCD.Update();

    StartTime = TimeNow();
    int Time = TimeNow() - StartTime;
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillRectangle(0,0,110,100);

    LCD.SetFontColor(BLACK);
    LCD.WriteAt("Timer: ", 0, 0);
    LCD.WriteAt(Time, 80, 0);
    LCD.Update();

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

    // Author: Joseph Tayal
    while (two.y < bubblelocation-15 && two.bubblestatus == 0) {
        Time = TimeNow() - StartTime;
        LCD.SetFontColor(BURLYWOOD);
        LCD.FillRectangle(0,0,110,100);

        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Timer: ", 0, 0);
        LCD.WriteAt(Time, 80, 0);
        LCD.Update();


        DrawBubble();
        DrawRope();
        DrawCreature();
        two.Fall();
        LCD.Update();
        Sleep(0.01);

        // Use touch to figure out when to pop bubble
    }
    /*once the candy hits the bubble*/
    ClearBubble();
    two.bubblestatus=1;
    two.v=0;
    int popped=0;
    x_position=0;
    y_position=0;

    while (((!LCD.Touch(&x_trash,&y_trash))||(LCD.Touch(&x_position,&y_position)))&&(popped==0))
    {
        Time = TimeNow() - StartTime;
        LCD.SetFontColor(BURLYWOOD);
        LCD.FillRectangle(0,0,110,100);

        LCD.SetFontColor(BLACK);
        LCD.WriteAt("Timer: ", 0, 0);
        LCD.WriteAt(Time, 80, 0);
        LCD.Update();

        if (two.y <= 0 ) {
            LoseScreen();
        }

        DrawRope();
        DrawCreature();
        two.Float();
        LCD.Update();
        Sleep(0.01);
        if ((x_position>(two.x+5) && x_position<(two.x+40) && y_position>(two.y+10) && y_position<(two.y+50)))
        {
            popped=1;
        }
    }
    /*clearing leftover bubble candy*/
    LCD.SetFontColor(BURLYWOOD);
    LCD.FillCircle(two.x+24,two.y+27,22);
    //Bubble gets popped
    two.bubblestatus=0;
    while (two.y<130)
    {
        DrawRope();
        DrawCreature();
        two.Fall();
        LCD.Update();
        Sleep(0.01);
    }

    WinScreen();

} 

/*Author: Sharvari Dhile/Joseph Tayal
This function cuts the rope and also redraws the peg onto the screen
*/
void CutRope () {
    RopeCutStatus = 1;
    LCD.SetFontColor(BURLYWOOD);//drawing rope
    LCD.DrawLine(157,10,161,ropelength);
    LCD.DrawLine(158,10,162,ropelength);
    LCD.DrawLine(159,10,163,ropelength);
    LCD.DrawLine(160,10,164,ropelength);

    /*Redrawing peg*/
    LCD.SetFontColor(LIGHTSKYBLUE);//Drawing peg
    LCD.DrawCircle(159,10,5);
    LCD.FillCircle(159,10,5);
    LCD.SetFontColor(BLUE);//Drawing peg
    LCD.DrawCircle(159,10,2);
    LCD.FillCircle(159,10,2);
   
}

/*Author: Joseph Tayal
This function draws the rope onto the screen
*/
void DrawRope()
{
    LCD.SetFontColor(LIGHTSKYBLUE);//Drawing peg
    LCD.DrawCircle(159,10,5);
    LCD.FillCircle(159,10,5);
    LCD.SetFontColor(BLUE);//Drawing peg
    LCD.DrawCircle(159,10,2);
    LCD.FillCircle(159,10,2);

    if (RopeCutStatus == 0) {
        LCD.SetFontColor(ROPEBROWN);//drawing rope
        LCD.DrawLine(158,10,162,ropelength);
        LCD.DrawLine(159,10,163,ropelength);
    }

    LCD.Update();
}

/* Author: Sharvari Dhile
This function draws the bubble on the screen
*/
void DrawBubble() {
    FEHImage bubble;
    bubble.Open("Bubble.png");
    bubble.Draw(135,bubblelocation);
}


/* Author: Sharvari Dhile
This function shows the win screen if user wins the level
*/
void WinScreen() {
    Wins++;
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("You Won!", 100, 100);
    Sleep(1500);
    Menu();
}

/* Author: Sharvari Dhile
This function shows the lose screen if user loses the level
*/
void LoseScreen() {
    Loses++;
    LCD.SetFontColor(BLACK);
    LCD.WriteAt("You Lost...", 100, 100);
    Sleep(1500);
    Menu();
}

/* Author: Sharvari Dhile
This function adds the back to menu into the stats, instruction, and credits page
*/
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

/* Author: Sharvari Dhile
This function sets up the play game page with buttons for specific levels
*/
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
        } else if (x_position >= 100 && x_position <= 220 && y_position >= 10 && y_position <= 40) {
            LCD.Clear();
            Menu();
        }
    }
    
    LCD.Update();

} 

/* Author: Sharvari Dhile
This function sets up the statistics page
*/
void Stats() {
    // Displays the user stats
    LCD.Clear(BLACK);
    LCD.Update();
    FEHImage background;
    background.Open("PageBackground.png");
    background.Draw(0, 0);
    LCD.WriteLine(" ");
    LCD.WriteLine(" ");
    LCD.WriteLine("Games Played: ");
    LCD.WriteAt(Games, 160, 35);
    LCD.WriteLine("Wins: ");
    LCD.WriteAt(Wins, 60, 55);
    LCD.WriteLine("Losses: ");
    LCD.WriteAt(Loses, 85, 70);
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

/* Author: Sharvari Dhile
This function sets up the instructions page
*/
void Instructions () {
    // Displays the instructions for the game
    LCD.Clear(BLACK);
    LCD.Update();
    FEHImage background;
    background.Open("PageBackground.png");
    background.Draw(0, 0);
    LCD.WriteLine(" ");
    LCD.WriteLine(" ");
    LCD.SetFontScale(0.5);
    LCD.WriteLine("Cut the Rope is a simple game. The goal is to cut the rope that is connected to the candy and make sure the creature eats the candy.");
    LCD.SetFontScale(1);
    LCD.DrawRectangle(95, 10, 120, 20);
    LCD.WriteAt("Main Menu", 100, 10);
    LCD.Update();

    BackToMenu();
    LCD.Update();
}

/* Author: Sharvari Dhile
This function sets up the credits page
*/
void Credits () {
    // Displays the credits
    LCD.Clear(BLACK);
    LCD.Update();
    FEHImage background;
    background.Open("PageBackground.png");
    background.Draw(0, 0);
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

/* Author: Sharvari Dhile
This function sets up the main menu page with the stats, instructions, credits, and play game
*/
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
