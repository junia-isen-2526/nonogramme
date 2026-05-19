//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_GRID_INTERNAL_H
#define NONOGRAMME_GRID_INTERNAL_H

#include "grid.h"

Grid *createGrid(Dimension *dimension);
void deleteGrid(Grid *grid);
void gridToggleXY(Grid *grid, unsigned char x, unsigned char y);
Pixel gridGetXY(Grid *grid, unsigned char x, unsigned char y);

#endif //NONOGRAMME_GRID_H
