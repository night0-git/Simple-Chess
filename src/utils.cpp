#include "Utils.h"


bool isWithinBoard(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}