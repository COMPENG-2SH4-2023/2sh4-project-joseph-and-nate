// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"

enum Direction {
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player {
public:
    Player(GameMechs* gmRef);
    void updatePlayerDir();
    void movePlayer();
    void drawPlayer();
    objPos& getPlayerPos(); 

private:
    Direction playerDir;
    GameMechs* gameMecRef;
    objPos playerPos;
};

#endif // PLAYER_H
