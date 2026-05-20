//
// Created by JAD on 18/05/2026.
//

#include "console-internal.h"

void displayNonogram(const Nonogram *nonogram) {
	if (nonogram == NULL) {
		displayError("Unable to display nonogram: nonogram is NULL");
		return;
	}
	const unsigned char weight = nonogramGetWidth(nonogram);
	const unsigned char height = nonogramGetHeight(nonogram);
	for (unsigned char row = 0; row < height; row++) {
		for (unsigned char column = 0; column < weight; column++) {
			Pixel pixel = nonogramGetXY(nonogram, column, row);
			printf("%c ", pixel == BLACK ? '#' : ' ');
		}
		printf("\n");
	}
}

void displayError(const char *message) {
	fprintf(stderr, "Error: %s\n", message);
}

