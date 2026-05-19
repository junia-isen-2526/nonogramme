//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMME_H
#define NONOGRAMME_NONOGRAMME_H

#include "dimension.h"
#include "constraints.h"
#include "grid.h"

typedef struct Nonogram {
} Nonogram;

Nonogram *createNonogram(unsigned char width, unsigned char height);
void deleteNonogram(Nonogram *nonogram);
void nonogramAddRowConstraint(Nonogram *nonogram, unsigned char rowIndex, unsigned char adjacentBlack);
void nonogramAddColumnConstraint(Nonogram *nonogram, unsigned char columnIndex, unsigned char adjacentBlack);
unsigned char nonogramGetWidth(Nonogram *nonogram);
unsigned char nonogramGetHeight(Nonogram *nonogram);
void nonogramToggleXY(Nonogram *nonogram, unsigned char x, unsigned char y);
Pixel nonogramGetXY(Nonogram *nonogram, unsigned char x, unsigned char y);
unsigned char nonogramRowsConstraintsGetSize(Nonogram *nonogram, unsigned char rowIndex);
unsigned char nonogramColumnsConstraintsGetSize(Nonogram *nonogram, unsigned char columnIndex);
unsigned char *nonogramRowsConstraintsToArray(Nonogram *nonogram, unsigned char rowIndex);
unsigned char *nonogramColumnsConstraintsToArray(Nonogram *nonogram, unsigned char columnIndex);

#endif //NONOGRAMME_NONOGRAMME_H
