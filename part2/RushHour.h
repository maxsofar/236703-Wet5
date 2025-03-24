//
// Created by Max on 31/01/2025.
//

#ifndef WET_5_RUSHHOUR_H
#define WET_5_RUSHHOUR_H

#include "GameBoard.h"

template<typename Board, int ExitRow, int ExitCol>
struct CheckWin;

template<typename Board, int ExitRow, int CurrentCol, int ExitCol>
struct CheckPath {
    static const bool value = (Board::template At<ExitRow, CurrentCol>::value == EMPTY) && CheckPath<Board, ExitRow, CurrentCol + 1, ExitCol>::value;
};

template<typename Board, int ExitRow, int ExitCol>
struct CheckPath<Board, ExitRow, ExitCol, ExitCol> {
    static const bool value = true;
};

template<typename Board, int ExitRow, int ExitCol>
struct CheckWin {
    static const int RedCarCol = Board::template Find<ExitRow, X>::value;
    static const bool result = CheckPath<Board, ExitRow, RedCarCol + 1, ExitCol>::value;
};

#endif //WET_5_RUSHHOUR_H
