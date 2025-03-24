//
// Created by Max on 01/02/2025.
//

#ifndef WET_5_GAMEBOARD_H
#define WET_5_GAMEBOARD_H

#include "List.h"
#include "BoardCell.h"
#include "Utilities.h"

template<typename T>
struct GameBoard {
    List<List<BoardCell<T, Direction, int>>> board;
    int width;
    int length;

    GameBoard(const List<List<BoardCell<T, Direction, int>>>& board, int width, int length)
            : board(board), width(width), length(length) {}
};

#endif //WET_5_GAMEBOARD_H
