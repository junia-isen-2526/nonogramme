//
// Created by JAD on 26/05/2026.
//

#ifndef NONOGRAMME_SERVICE_NONOGRAMME_SOLVE_INTERNAL_H
#define NONOGRAMME_SERVICE_NONOGRAMME_SOLVE_INTERNAL_H
#include "service_nonogram_solve.h"
#include <stdlib.h>

typedef enum PixelSolver {
	VERIFIED_BLACK,
	VERIFIED_WHITE,
	UNKNOWN
} PixelSolver;

typedef PixelSolver **GridSolver;

GridSolver createUnknownGridSolver(unsigned char width, unsigned char height);
void deleteGridSolver(GridSolver gridSolver, unsigned char height);

void fillAllVerifiable(GridSolver grid_solver, unsigned char width, unsigned char height);
void fillAllVerifiableRows(GridSolver grid_solver, unsigned char width, unsigned char height);
void fillAllVerifiableColumns(GridSolver grid_solver, unsigned char width, unsigned char height);
void fillVerifiableRow(GridSolver grid_solver, unsigned char width, unsigned char rowIndex);
void fillVerifiableColumn(GridSolver grid_solver, unsigned char height, unsigned char columnIndex);

#endif //NONOGRAMME_SERVICE_NONOGRAMME_SOLVE_INTERNAL_H
