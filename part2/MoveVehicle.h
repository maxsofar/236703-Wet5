//
// Created by Max on 01/02/2025.
//

#ifndef WET_5_MOVEVEHICLE_H
#define WET_5_MOVEVEHICLE_H

#include "GameBoard.h"
#include "TransposeList.h"

template<CellType T, Direction D, int A>
struct Move {
    static_assert(T != EMPTY, "Cannot move an empty cell");
    static const CellType type = T;
    static const Direction direction = D;
    static const int amount = A;
};

template<typename Board, int R, int C, Direction D, CellType CarType>
struct MoveOneCell;

template<typename Board, int R, int C, CellType CarType>
struct MoveOneCell<Board, R, C, RIGHT, CarType> {
    typedef typename Board::template Replace<R, C, EMPTY>::board UpdatedBoard;
    typedef typename UpdatedBoard::template Replace<R, C + 1, CarType>::board board;
};

template<typename Board, int R, int C, CellType CarType>
struct MoveOneCell<Board, R, C, LEFT, CarType> {
    typedef typename Board::template Replace<R, C, EMPTY>::board UpdatedBoard;
    typedef typename UpdatedBoard::template Replace<R, C - 1, CarType>::board board;
};

template<typename Board, int R, int C, CellType CarType>
struct MoveOneCell<Board, R, C, UP, CarType> {
    typedef typename Transpose<typename Board::board>::matrix TransposedBoard;
    typedef typename MoveOneCell<TransposedBoard, C, R, LEFT, CarType>::board MovedTransposedBoard;
    typedef typename Transpose<MovedTransposedBoard>::matrix board;
};

template<typename Board, int R, int C, CellType CarType>
struct MoveOneCell<Board, R, C, DOWN, CarType> {
    typedef typename Transpose<typename Board::board>::matrix TransposedBoard;
    typedef typename MoveOneCell<TransposedBoard, C, R, RIGHT, CarType>::board MovedTransposedBoard;
    typedef typename Transpose<MovedTransposedBoard>::matrix board;
};

template<typename Board, int R, int C, Direction D, int A, CellType CarType>
struct MoveVehicle;

template<typename Board, int R, int C, Direction D, CellType CarType>
struct MoveVehicle<Board, R, C, D, 1, CarType> {
    typedef typename MoveOneCell<Board, R, C, D, CarType>::board board;
};

template<typename Board, int R, int C, Direction D, int A, CellType CarType>
struct MoveVehicle {
    typedef typename MoveVehicle<typename MoveOneCell<Board, R, C, D, CarType>::board, R, C, D, A - 1, CarType>::board board;
};


#endif //WET_5_MOVEVEHICLE_H
