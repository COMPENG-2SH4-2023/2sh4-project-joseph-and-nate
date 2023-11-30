// GameMechs.h

#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include "objPos.h"

class GameMechs {
private:
    char input;
    bool exitFlag;
    bool loseFlag;
    int score;
    int boardSizeX;
    int boardSizeY;

public:
    GameMechs();
    GameMechs(int boardX, int boardY);
    ~GameMechs();

    bool getExitFlagStatus();
    void setExitTrue();

    bool getLoseFlagStatus();
    void setLoseFlag();

    char getInput();
    void setInput(char thisInput);
    void clearInput();

    int getBoardSizeX();
    int getBoardSizeY();

    int getScore();
    void incrementScore();
};

#endif
