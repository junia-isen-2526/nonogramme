//
// Created by JAD on 19/05/2026.
//

#include "grid-internal.h"

Grid createGrid(const Dimension *dimension) {
	if (dimension == NULL) return NULL;
	Grid grid = malloc(sizeof(Pixel *) * dimension->height);
	if (grid == NULL) return NULL;
	for (unsigned char row = 0; row < dimension->height; row++) {
		Pixel *rowPixels = malloc(sizeof(Pixel) * dimension->width);
		if (rowPixels != NULL) {
			for (unsigned char column = 0; column < dimension->width; column++) {
				rowPixels[column] = WHITE;
			}
			grid[row] = rowPixels;
		} else {
			for (unsigned char i = 0; i < row; i++) {
				free(grid[i]);
			}
			free(grid);
			return NULL;
		}
	}
	return grid;
}

void deleteGrid(Grid grid, const Dimension *dimension) {
	if ((grid != NULL) && (dimension != NULL)) {
		for (unsigned char row = 0; row < dimension->height; row++) {
			free(grid[row]);
		}
		free(grid);
	}
}

void gridToggleXY(Grid grid, const unsigned char x, const unsigned char y, const Dimension *dimension) {
	if ((grid != NULL) && (x < dimension->width) && (y < dimension->height)) {
		grid[y][x] = (grid[y][x] == BLACK) ? WHITE : BLACK;
	}
}
Pixel gridGetXY(Grid grid, const unsigned char x, const unsigned char y, const Dimension *dimension) {
	if ((grid != NULL) && (x < dimension->width) && (y < dimension->height)) {
		return grid[y][x];
	}
	return WHITE;
}
