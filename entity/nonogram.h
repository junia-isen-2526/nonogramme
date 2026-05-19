//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMME_H
#define NONOGRAMME_NONOGRAMME_H

#include "dimension.h"
#include "constraints.h"
#include "grid.h"

typedef struct Nonogram {
	Dimension *dimension;
	Grid *grid;
	Constraints *rowConstraints;
	Constraints *columnConstraints;
} Nonogram;

Nonogram *createNonogram(unsigned char width, unsigned char height);
void deleteNonogram(Nonogram *nonogram);
void nonogramAddRowConstraint(Nonogram *nonogram, unsigned char rowIndex, Constraint constraint);
void nonogramAddColumnConstraint(Nonogram *nonogram, unsigned char columnIndex, Constraint constraint);
unsigned char nonogramGetWidth(Nonogram *nonogram);
unsigned char nonogramGetHeight(Nonogram *nonogram);
void nonogramToggleXY(Nonogram *nonogram, const unsigned char x, const unsigned char y);
Pixel nonogramGetXY(Nonogram *nonogram, const unsigned char x, const unsigned char y);
unsigned char nonogramRowsConstraintsGetSize(Nonogram *nonogram, const unsigned char rowIndex);
unsigned char nonogramColumnsConstraintsGetSize(Nonogram *nonogram, const unsigned char columnIndex);
unsigned char *nonogramRowsConstraintsToArray(Nonogram *nonogram, const unsigned char rowIndex);
unsigned char *nonogramColumnsConstraintsToArray(Nonogram *nonogram, const unsigned char columnIndex);

#endif //NONOGRAMME_NONOGRAMME_H
