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
void nonogramAddRowConstraint(const Nonogram *nonogram, unsigned char rowIndex, Constraint constraint);
void nonogramAddColumnConstraint(const Nonogram *nonogram, unsigned char columnIndex, Constraint constraint);
unsigned char nonogramGetWidth(const Nonogram *nonogram);
unsigned char nonogramGetHeight(const Nonogram *nonogram);
void nonogramToggleXY(const Nonogram *nonogram, unsigned char x, unsigned char y);
Pixel nonogramGetXY(const Nonogram *nonogram, unsigned char x, unsigned char y);
unsigned char nonogramRowsConstraintsGetSize(const Nonogram *nonogram, unsigned char rowIndex);
unsigned char nonogramColumnsConstraintsGetSize(const Nonogram *nonogram, unsigned char columnIndex);
unsigned char *nonogramRowsConstraintsToArray(const Nonogram *nonogram, unsigned char rowIndex);
unsigned char *nonogramColumnsConstraintsToArray(const Nonogram *nonogram, unsigned char columnIndex);

#endif //NONOGRAMME_NONOGRAMME_H
