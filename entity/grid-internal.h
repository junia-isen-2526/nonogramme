//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_GRID_INTERNAL_H
#define NONOGRAMME_GRID_INTERNAL_H

#include "grid.h"
#include "stdlib.h"

Grid *createGrid(const Dimension *dimension);
void deleteGrid(Grid *grid, const Dimension *dimension);
void gridToggleXY(const Grid *grid, unsigned char x, unsigned char y, const Dimension *dimension);
Pixel gridGetXY(const Grid *grid, unsigned char x, unsigned char y, const Dimension *dimension);

#endif //NONOGRAMME_GRID_H
