//
// Created by JAD on 26/05/2026.
//
#include "service_nonogram_solve-internal.h"

GridSolver createUnknownGridSolver(const unsigned char width, const unsigned char height) {
	GridSolver gridSolver = malloc(sizeof(PixelSolver *) * height);
	if (gridSolver == NULL) return NULL;
	for (unsigned char row = 0; row < height; row++) {
		PixelSolver *rowPixels = malloc(sizeof(PixelSolver) * width);
		if (rowPixels != NULL) {
			for (unsigned char column = 0; column < width; column++) {
				rowPixels[column] = UNKNOWN;
			}
			gridSolver[row] = rowPixels;
		} else {
			for (unsigned char i = 0; i < row; i++) {
				free(gridSolver[i]);
			}
			free(gridSolver);
			return NULL;
		}
	}

	return gridSolver;
}

void deleteGridSolver(GridSolver gridSolver, const unsigned char height) {
	if (gridSolver != NULL) {
		for (unsigned char row = 0; row < height; row++) {
			free(gridSolver[row]);
		}
		free(gridSolver);
		gridSolver = NULL;
	}
}

void fillAllVerifiable(const Nonogram *nonogram,
                       GridSolver gridSolver,
                       unsigned char width,
                       unsigned char height) {
	fillAllVerifiableRows(nonogram, gridSolver, width, height);
	fillAllVerifiableColumns(nonogram, gridSolver, width, height);
}

void fillAllVerifiableRows(const Nonogram *nonogram,
                           GridSolver gridSolver,
                           unsigned char width,
                           unsigned char height) {
	for (unsigned char rowIndex = 0; rowIndex < height; rowIndex++) {
		fillVerifiableRow(nonogram, gridSolver, width, rowIndex);
	}
}

void fillAllVerifiableColumns(const Nonogram *nonogram,
                              GridSolver gridSolver,
                              unsigned char width,
                              unsigned char height) {
	for (unsigned char columnIndex = 0; columnIndex < width; columnIndex++) {
		fillVerifiableColumn(nonogram, gridSolver, height, columnIndex);
	}
}

int sumOfAllConstraintsPlusEmptyEqualsSize(const unsigned char *constraints,
                                           unsigned char constraintsSize,
                                           unsigned char size) {
	int constraintsSum = -1;
	for (unsigned char constraintIndex = 0; constraintIndex < constraintsSize; constraintIndex++) {
		constraintsSum += constraints[constraintIndex] + 1;
	}
	return constraintsSum == size;
}

void fillVerifiableRow(const Nonogram *nonogram,
                       GridSolver gridSolver,
                       unsigned char width,
                       unsigned char rowIndex) {
	if (gridSolver == NULL) return;
	unsigned char rowConstraintsSize = nonogramRowsConstraintsGetSize(nonogram, rowIndex);
	unsigned char *rowConstraints = nonogramRowsConstraintsToArray(nonogram, rowIndex);

	if ((rowConstraintsSize == 0) || ((rowConstraintsSize == 1) && (rowConstraints[0] == 0))) {
		for (unsigned char columnIndex = 0; columnIndex < width; columnIndex++) {
			gridSolver[rowIndex][columnIndex] = VERIFIED_WHITE;
		}
		free(rowConstraints);
		return;
	}
	if ((rowConstraintsSize == 1) && (rowConstraints[0] == width)) {
		for (unsigned char columnIndex = 0; columnIndex < width; columnIndex++) {
			gridSolver[rowIndex][columnIndex] = VERIFIED_BLACK;
		}
		free(rowConstraints);
		return;
	}
	if (sumOfAllConstraintsPlusEmptyEqualsSize(rowConstraints, rowConstraintsSize, width)) {
		unsigned char columnIndex = 0;
		unsigned char constraintIndex = 0;
		while (columnIndex < width) {
			for (unsigned char blackCounter = 0; blackCounter < rowConstraints[constraintIndex]; blackCounter++) {
				gridSolver[rowIndex][columnIndex + blackCounter] = VERIFIED_BLACK;
			}
			columnIndex += rowConstraints[constraintIndex++] + 1;
			if (columnIndex < width) gridSolver[rowIndex][columnIndex] = VERIFIED_WHITE;
		}
	}
	free(rowConstraints);
}

void fillVerifiableColumn(const Nonogram *nonogram,
                          GridSolver gridSolver,
                          unsigned char height,
                          unsigned char columnIndex) {
	if (gridSolver == NULL) return;
	unsigned char columnConstraintsSize = nonogramColumnsConstraintsGetSize(nonogram, columnIndex);
	unsigned char *columnConstraints = nonogramColumnsConstraintsToArray(nonogram, columnIndex);

	if ((columnConstraintsSize == 0) || ((columnConstraintsSize == 1) && (columnConstraints[0] == 0))) {
		for (unsigned char rowIndex = 0; rowIndex < height; rowIndex++) {
			gridSolver[rowIndex][columnIndex] = VERIFIED_WHITE;
		}
		free(columnConstraints);
		return;
	}
	if ((columnConstraintsSize == 1) && (columnConstraints[0] == height)) {
		for (unsigned char rowIndex = 0; rowIndex < height; rowIndex++) {
			gridSolver[rowIndex][columnIndex] = VERIFIED_BLACK;
		}
		free(columnConstraints);
		return;
	}
	if (sumOfAllConstraintsPlusEmptyEqualsSize(columnConstraints, columnConstraintsSize, height)) {
		unsigned char rowIndex = 0;
		unsigned char constraintIndex = 0;
		while (rowIndex < height) {
			for (unsigned char blackCounter = 0; blackCounter < columnConstraints[constraintIndex]; blackCounter++) {
				gridSolver[rowIndex + blackCounter][columnIndex] = VERIFIED_BLACK;
			}
			rowIndex += columnConstraints[constraintIndex++] + 1;
			if (rowIndex < height) gridSolver[rowIndex][columnIndex] = VERIFIED_WHITE;
		}
	}
	free(columnConstraints);
}

void gridSolverToNonogramGrid(const Nonogram *nonogram, GridSolver gridSolver) {
	if (gridSolver == NULL) return;
	const unsigned width = nonogramGetWidth(nonogram);
	const unsigned height = nonogramGetHeight(nonogram);
	for (unsigned rowIndex = 0; rowIndex < height; rowIndex++) {
		for (unsigned columnIndex = 0; columnIndex < width; columnIndex++) {
			if (gridSolver[rowIndex][columnIndex] == VERIFIED_BLACK) {
				nonogramToggleXY(nonogram, columnIndex, rowIndex);
			}
		}
	}
}

int nonogramSolve(const Nonogram *nonogram) {
	if (nonogram == NULL) return 1;
	if (!isNonogramValid(nonogram)) return 1;
	if (!isNonogramCorrectlyFilled(nonogram)) return 0;
	const unsigned width = nonogramGetWidth(nonogram);
	const unsigned height = nonogramGetHeight(nonogram);

	GridSolver gridSolver = createUnknownGridSolver(width, height);
	fillAllVerifiable(nonogram, gridSolver, width, height);

	gridSolverToNonogramGrid(nonogram, gridSolver);
	deleteGridSolver(gridSolver, height);
	return 0;
}
