//
// Created by JAD on 18/05/2026.
//

#include "nonogram-internal.h"
#include "dimension-internal.h"
#include "constraints-internal.h"
#include "grid-internal.h"

Nonogram *createNonogram(unsigned char width, unsigned char height) {
	Dimension *dimension = createDimension(width, height);
	Grid *grid = createGrid(dimension);
	Constraints *rowConstraints = createConstraints();
	Constraints *columnConstraints = createConstraints();
	Nonogram *nonogram = malloc(sizeof(Nonogram));
	if ((dimension == NULL)
		|| (grid == NULL) || (rowConstraints == NULL)
		|| (columnConstraints == NULL)
		|| (nonogram == NULL)) {
		deleteDimension(dimension);
		deleteGrid(grid, dimension);
		deleteConstraints(rowConstraints);
		deleteConstraints(columnConstraints);
		return NULL;
	}
	nonogram->dimension = dimension;
	nonogram->grid = grid;
	nonogram->rowConstraints = rowConstraints;
	nonogram->columnConstraints = columnConstraints;
	return nonogram;
}

void deleteNonogram(Nonogram *nonogram) {
	if (nonogram != NULL) {
		deleteDimension(nonogram->dimension);
		deleteGrid(nonogram->grid, nonogram->dimension);
		deleteConstraints(nonogram->rowConstraints);
		deleteConstraints(nonogram->columnConstraints);
		free(nonogram);
	}
}

void nonogramAddRowConstraint(Nonogram *nonogram, unsigned char rowIndex, Constraint constraint) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		ConstraintsAddConstraints(nonogram->rowConstraints, constraint);
	}
}

void nonogramAddColumnConstraint(Nonogram *nonogram, unsigned char columnIndex, Constraint constraint) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		ConstraintsAddConstraints(nonogram->columnConstraints, constraint);
	}
}

unsigned char nonogramGetWidth(Nonogram *nonogram) {
	if (nonogram != NULL) return nonogram->dimension->width;
	return 0;
}

unsigned char nonogramGetHeight(Nonogram *nonogram) {
	if (nonogram != NULL) return nonogram->dimension->height;
	return 0;
}

void nonogramToggleXY(Nonogram *nonogram, const unsigned char x, const unsigned char y) {
	if (nonogram != NULL) gridToggleXY(nonogram->grid, x, y, nonogram->dimension);
}

Pixel nonogramGetXY(Nonogram *nonogram, const unsigned char x, const unsigned char y) {
	if (nonogram != NULL) return gridGetXY(nonogram->grid, x, y, nonogram->dimension);
	return WHITE;
}

unsigned char nonogramRowsConstraintsGetSize(Nonogram *nonogram, const unsigned char rowIndex) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		return constraintsGetSize(nonogram->rowConstraints);
	}
	return 0;
}

unsigned char nonogramColumnsConstraintsGetSize(Nonogram *nonogram, const unsigned char columnIndex) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		return constraintsGetSize(nonogram->columnConstraints);
	}
	return 0;
}

unsigned char *nonogramRowsConstraintsToArray(Nonogram *nonogram, const unsigned char rowIndex) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		return constraintsToArray(nonogram->rowConstraints);
	}
	return NULL;
}

unsigned char *nonogramColumnsConstraintsToArray(Nonogram *nonogram, const unsigned char columnIndex) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		return constraintsToArray(nonogram->columnConstraints);
	}
	return NULL;
}
