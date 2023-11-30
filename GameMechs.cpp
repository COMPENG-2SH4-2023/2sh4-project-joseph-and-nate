// GameMechs.cpp

#include "GameMechs.h"
#include "Player.h"

GameMechs::GameMechs() {
    boardSizeX = 30;
    boardSizeY = 15;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

GameMechs::GameMechs(int boardX, int boardY) {
    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0;
}

GameMechs::~GameMechs() {
    // Destructor (if needed)
}

bool GameMechs::getExitFlagStatus() {
    return exitFlag;
}

void GameMechs::setExitTrue() {
    exitFlag = true;
}

bool GameMechs::getLoseFlagStatus() {
    return loseFlag;
}

void GameMechs::setLoseFlag() {
    loseFlag = true;
}

char GameMechs::getInput() {
    if (input == 'W' || input == 'w') {
        return static_cast<char>(Direction::UP);
    } else if (input == 'S' || input == 's') {
        return static_cast<char>(Direction::DOWN);
    } else if (input == 'A' || input == 'a') {
        return static_cast<char>(Direction::LEFT);
    } else if (input == 'D' || input == 'd') {
        return static_cast<char>(Direction::RIGHT);
    } else {
        return input;
    }
}


void GameMechs::setInput(char thisInput) {
    input = thisInput;
}

void GameMechs::clearInput() {
    input = 0;
}

int GameMechs::getBoardSizeX() {
    return boardSizeX;
}

int GameMechs::getBoardSizeY() {
    return boardSizeY;
}

int GameMechs::getScore() {
    return score;
}

void GameMechs::incrementScore() {
    score++;
}
