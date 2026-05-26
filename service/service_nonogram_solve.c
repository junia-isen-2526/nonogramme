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
	deleteGridSolver(gridSolver, height);
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

int nonogramSolve(const Nonogram *nonogram) {
	if (nonogram == NULL) return 1;
	if (isNonogramValid(nonogram)) return 1;
	if (isNonogramCorrectlyFilled(nonogram)) return 0;
	const unsigned width = nonogramGetWidth(nonogram);
	const unsigned height = nonogramGetHeight(nonogram);

	GridSolver gridSolver = createUnknownGridSolver(width, height);
	deleteGridSolver(gridSolver, height);
	return 0;
}
