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

void fillAllVerifiable(const Nonogram *nonogram, GridSolver gridSolver, unsigned char width, unsigned char height);
void fillAllVerifiableRows(const Nonogram *nonogram, GridSolver gridSolver, unsigned char width, unsigned char height);
void fillAllVerifiableColumns(const Nonogram *nonogram,
                              GridSolver gridSolver,
                              unsigned char width,
                              unsigned char height);
void fillVerifiableRow(const Nonogram *nonogram, GridSolver gridSolver, unsigned char width, unsigned char rowIndex);
void fillVerifiableColumn(const Nonogram *nonogram,
                          GridSolver gridSolver,
                          unsigned char height,
                          unsigned char columnIndex);
void gridSolverToNonogramGrid(const Nonogram *nonogram, GridSolver gridSolver);

#endif //NONOGRAMME_SERVICE_NONOGRAMME_SOLVE_INTERNAL_H
