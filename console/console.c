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
			printf("%c", pixel == BLACK ? CHARACTER_BLACK : CHARACTER_WHITE);
		}
		printf("\n");
	}
}

unsigned char getMaxConstraintsRowFromNonogram(const Nonogram *nonogram, const unsigned char height) {
	unsigned char rowConstraintsMax = 0;
	for (unsigned char row = 0; row < height; row++) {
		const unsigned char constraintsRowsSize = nonogramRowsConstraintsGetSize(nonogram, row);
		if (rowConstraintsMax < constraintsRowsSize) rowConstraintsMax = constraintsRowsSize;
	}
	return rowConstraintsMax;
}

unsigned char getMaxConstraintsColumnFromNonogram(const Nonogram *nonogram, const unsigned char width) {
	unsigned char columnConstraintsMax = 0;
	for (unsigned char column = 0; column < width; column++) {
		const unsigned char constraintsColumnsSize = nonogramColumnsConstraintsGetSize(nonogram, column);
		if (columnConstraintsMax < constraintsColumnsSize) columnConstraintsMax = constraintsColumnsSize;
	}
	return columnConstraintsMax;
}

void displayNonogramWithConstraints(const Nonogram *nonogram) {
	if (nonogram == NULL) {
		displayError("Unable to display nonogram: nonogram is NULL");
		return;
	}
	const unsigned char width = nonogramGetWidth(nonogram);
	const unsigned char height = nonogramGetHeight(nonogram);
	const unsigned char columnConstraintsMax = getMaxConstraintsColumnFromNonogram(nonogram, width);
	const unsigned char rowConstraintsMax = getMaxConstraintsRowFromNonogram(nonogram, height);

	unsigned char **columnConstraintsArray = malloc(sizeof(unsigned char *) * width);
	unsigned char *columnConstraintsSize = malloc(sizeof(unsigned char) * width);

	for (unsigned char column = 0; column < width; column++) {
		columnConstraintsArray[column] = nonogramColumnsConstraintsToArray(nonogram, column);
		columnConstraintsSize[column] = nonogramColumnsConstraintsGetSize(nonogram, column);
	}
	for (unsigned char constraintIndex = 0; constraintIndex < columnConstraintsMax; constraintIndex++) {
		printf("%*s| ", rowConstraintsMax * 3, "");
		for (unsigned char column = 0; column < width; column++) {
			if (constraintIndex >= columnConstraintsMax - columnConstraintsSize[column]) {
				const unsigned char temp = columnConstraintsArray[column]
					[constraintIndex - columnConstraintsMax + columnConstraintsSize[column]];
				printf("%2d|", temp);
			} else {
				printf("  |");
			}
		}
		printf("\n");
	}
	for (unsigned char column = 0; column < width; column++) {
		if (columnConstraintsArray[column] != NULL) free(columnConstraintsArray[column]);
	}
	free(columnConstraintsArray);
	free(columnConstraintsSize);

	printf("%*s+ ", rowConstraintsMax * 3, "");
	for (unsigned char column = 0; column < width; column++) {
		printf("--+");
	}
	printf("\n");

	for (unsigned char row = 0; row < height; row++) {
		unsigned char *constraintsRowsArray = nonogramRowsConstraintsToArray(nonogram, row);
		const unsigned char constraintsRowsSize = nonogramRowsConstraintsGetSize(nonogram, row);
		for (unsigned char constraintIndex = 0; constraintIndex < rowConstraintsMax - constraintsRowsSize;
		     constraintIndex++) {
			printf("   ");
		}
		for (unsigned char constraintIndex = 0; constraintIndex < constraintsRowsSize; constraintIndex++) {
			printf("%2d ", constraintsRowsArray[constraintIndex]);
		}
		printf("| ");
		for (unsigned char column = 0; column < width; column++) {
			Pixel pixel = nonogramGetXY(nonogram, column, row);
			printf(" %c ", pixel == BLACK ? CHARACTER_BLACK : CHARACTER_WHITE);
		}
		printf("\n");
		free(constraintsRowsArray);
	}
}

void displayError(const char *message) {
	fprintf(stderr, "Error: %s\n", message);
}

