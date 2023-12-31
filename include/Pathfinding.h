#ifndef _GUNNY_PATHFINDING_H_
#define _GUNNY_PATHFINDING_H_

#include <stack>

#include "Const.h"

namespace Gunny
{
    /**
     * @brief Hold parameters for pathfinding algorithm
     *
     */
    struct Cell
    {
        int parentRow, parentColumn; // row and column of parent
        double f, g, h;              // f = g + h
    };
    /**
     * @brief Find best path to destination using A* algorith
     *
     * @param src - source point
     * @param dest - destination point
     * @return std::pair<int, int> - first cell to move
     */
    std::pair<int, int> findBestCell(Tile (&grid)[tileArrayHeight][tileArrayWidth],
                                     const std::pair<int, int>& src, const std::pair<int, int>& dest);
} // namespace GUNNY

#endif  
