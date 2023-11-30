//project.cpp

#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

const int SCREEN_WIDTH = 16;
const int SCREEN_HEIGHT = 30;

objPos gameBorder[SCREEN_WIDTH][SCREEN_HEIGHT];
GameMechs *gameMechs;  // Declare gameMechs globally
Player *player;

bool exitFlag;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

int main(void) {
    gameMechs = new GameMechs();  // Initialize gameMechs
    player = new Player(gameMechs);  // Initialize player
    Initialize();

    while (!gameMechs->getExitFlagStatus()) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void) {
    MacUILib_init();
    MacUILib_clearScreen();
    exitFlag = false;

    for (int i = 0; i < SCREEN_WIDTH; ++i) {
        for (int j = 0; j < SCREEN_HEIGHT; ++j) {
            if (i == 0 || i == SCREEN_WIDTH - 1 || j == 0 || j == SCREEN_HEIGHT - 1) {
                gameBorder[i][j].setObjPos(i, j, '#');
            } else {
                gameBorder[i][j].setObjPos(i, j, ' ');
            }
        }
    }
}

void GetInput(void) {
    // Collect input and set it in the gameMechs object
    char input;
    if (MacUILib_hasChar()) {
        input = MacUILib_getChar();
        gameMechs->setInput(input);
    }
}

void RunLogic(void) {

    // Check if there's a new input
    if (gameMechs->getInput() != 0) {
        player->updatePlayerDir();
        // Clear the input after processing
        gameMechs->clearInput();
    }

    // Move the player in the current direction
    player->movePlayer();

    if (player->getPlayerPos().isPosEqual(&gameMechs->getFoodPosition())) {
        gameMechs->incrementScore();
        gameMechs->generateRandomFoodPosition();
    }
}


void DrawScreen(void) {
    MacUILib_clearScreen();

    // Draw game border with player and food
    for (int i = 0; i < SCREEN_WIDTH; ++i) {
        for (int j = 0; j < SCREEN_HEIGHT; ++j) {
            objPos& playerPos = player->getPlayerPos();  // Get the player's position by reference
            objPos& foodPos = gameMechs->getFoodPosition();  // Get the food position by reference
            objPos& currentPosition = gameBorder[i][j];

            if (currentPosition.isPosEqual(&playerPos)) {
                player->drawPlayer(); 
            } else if (currentPosition.isPosEqual(&foodPos)) {
                cout << 'o';
            } else {
                cout << currentPosition.getSymbol();
            }
        }
        cout << endl;
    }
}



void LoopDelay(void) {
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void) {
    MacUILib_clearScreen();
    MacUILib_uninit();
    delete player;
    delete gameMechs;
}
