//
// Created by Max on 01/02/2025.
//

#ifndef WET_5_BOARDCELL_H
#define WET_5_BOARDCELL_H

#include "CellType.h"
#include "Direction.h"

template<CellType T, Direction D, int L>
struct BoardCell {
    static const CellType type = T;
    static const Direction direction = D;
    static const int length = L;
};

#endif //WET_5_BOARDCELL_H
