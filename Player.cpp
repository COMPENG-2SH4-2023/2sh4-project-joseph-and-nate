// Player.cpp

#include "Player.h"
#include "GameMechs.h"
#include <stdio.h>


Player::Player(GameMechs* gmRef) : playerDir(STOP), gameMecRef(gmRef) {
    playerPos.setObjPos(10, 5, '*');
}

void Player::updatePlayerDir() {
    Direction newDir = static_cast<Direction>(gameMecRef->getInput());

    // Check if the new direction is not the opposite of the current direction
    if (!((playerDir == UP && newDir == DOWN) ||
          (playerDir == DOWN && newDir == UP) ||
          (playerDir == LEFT && newDir == RIGHT) ||
          (playerDir == RIGHT && newDir == LEFT))) {
        playerDir = newDir;
    }
}

void Player::movePlayer() {
    // Save current position for wrap-around logic
    int prevX = playerPos.x;  // Use x directly
    int prevY = playerPos.y;  // Use y directly

    switch (playerDir) {
        case UP:
            playerPos.moveUp();
            break;
        case DOWN:
            playerPos.moveDown();
            break;
        case LEFT:
            playerPos.moveLeft();
            break;
        case RIGHT:
            playerPos.moveRight();
            break;
        default:
            break;
    }

    // Wrap around if hitting the game board
    if (playerPos.x == 0) {
        playerPos.x = (gameMecRef->getBoardSizeY() - 2);
    } else if (playerPos.x == gameMecRef->getBoardSizeY()-1) {
        playerPos.x = 1;
    }

    if (playerPos.y == 0) {
        playerPos.y = (gameMecRef->getBoardSizeX() - 2);
    } else if (playerPos.y == gameMecRef->getBoardSizeX() - 1) {
        playerPos.y = 1;
    }
}


void Player::drawPlayer() {
    // Drawing logic for the player
    printf("%c", playerPos.getSymbol());
}

objPos& Player::getPlayerPos() {
    return playerPos;
}