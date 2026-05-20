//
// Created by JAD on 18/05/2026.
//

#include "nonogram-internal.h"
#include "dimension-internal.h"
#include "constraints-internal.h"
#include "grid-internal.h"

Nonogram *createNonogram(const unsigned char width, const unsigned char height) {
	Dimension *dimension = createDimension(width, height);
	Grid grid = createGrid(dimension);
	Constraints **rowConstraints = malloc(sizeof(Constraints *) * height);

	Constraints **columnConstraints = malloc(sizeof(Constraints *) * width);

	Nonogram *nonogram = malloc(sizeof(Nonogram));
	if ((dimension == NULL)
		|| (grid == NULL) || (rowConstraints == NULL)
		|| (columnConstraints == NULL)
		|| (nonogram == NULL)) {
		deleteGrid(grid, dimension);
		deleteDimension(dimension);
		free(rowConstraints);
		free(columnConstraints);
		return NULL;
	}
	nonogram->dimension = dimension;
	nonogram->grid = grid;
	nonogram->rowConstraints = rowConstraints;
	nonogram->columnConstraints = columnConstraints;
	for (unsigned char row = 0; row < height; row++) {
		rowConstraints[row] = createConstraints();
	}
	for (unsigned char column = 0; column < width; column++) {
		columnConstraints[column] = createConstraints();
	}
	return nonogram;
}

void deleteNonogram(Nonogram *nonogram) {
	if (nonogram != NULL) {
		deleteGrid(nonogram->grid, nonogram->dimension);
		for (unsigned char row = 0; row < nonogram->dimension->height; row++) {
			deleteConstraints(nonogram->rowConstraints[row]);
		}
		for (unsigned char column = 0; column < nonogram->dimension->width; column++) {
			deleteConstraints(nonogram->columnConstraints[column]);
		}
		deleteDimension(nonogram->dimension);
		free(nonogram);
	}
}

void nonogramAddRowConstraint(const Nonogram *nonogram, const unsigned char rowIndex, const Constraint constraint) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		ConstraintsAddConstraints(nonogram->rowConstraints[rowIndex], constraint);
	}
}

void nonogramAddColumnConstraint(const Nonogram *nonogram,
                                 const unsigned char columnIndex,
                                 const Constraint constraint) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		ConstraintsAddConstraints(nonogram->columnConstraints[columnIndex], constraint);
	}
}

unsigned char nonogramGetWidth(const Nonogram *nonogram) {
	if (nonogram != NULL) return nonogram->dimension->width;
	return 0;
}

unsigned char nonogramGetHeight(const Nonogram *nonogram) {
	if (nonogram != NULL) return nonogram->dimension->height;
	return 0;
}

void nonogramToggleXY(const Nonogram *nonogram, const unsigned char x, const unsigned char y) {
	if (nonogram != NULL) gridToggleXY(nonogram->grid, x, y, nonogram->dimension);
}

Pixel nonogramGetXY(const Nonogram *nonogram, const unsigned char x, const unsigned char y) {
	if (nonogram != NULL) return gridGetXY(nonogram->grid, x, y, nonogram->dimension);
	return WHITE;
}

unsigned char nonogramRowsConstraintsGetSize(const Nonogram *nonogram, const unsigned char rowIndex) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		return constraintsGetSize(nonogram->rowConstraints[rowIndex]);
	}
	return 0;
}

unsigned char nonogramColumnsConstraintsGetSize(const Nonogram *nonogram, const unsigned char columnIndex) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		return constraintsGetSize(nonogram->columnConstraints[columnIndex]);
	}
	return 0;
}

unsigned char *nonogramRowsConstraintsToArray(const Nonogram *nonogram, const unsigned char rowIndex) {
	if ((nonogram != NULL) && (rowIndex < nonogram->dimension->height)) {
		return constraintsToArray(nonogram->rowConstraints[rowIndex]);
	}
	return NULL;
}

unsigned char *nonogramColumnsConstraintsToArray(const Nonogram *nonogram, const unsigned char columnIndex) {
	if ((nonogram != NULL) && (columnIndex < nonogram->dimension->width)) {
		return constraintsToArray(nonogram->columnConstraints[columnIndex]);
	}
	return NULL;
}
