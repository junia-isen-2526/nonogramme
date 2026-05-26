//
// Created by JAD on 18/05/2026.
//

#include "../service/service_correctly_filed.h"

unsigned char isNonogramRowCorrectlyFilled(const Nonogram *nonogram, const unsigned char index) {
	if (nonogram == NULL) return 0;
	if (nonogramGetHeight(nonogram) <= index) return 0;

	const unsigned char width = nonogramGetWidth(nonogram);
	const unsigned char constraintSize = nonogramRowsConstraintsGetSize(nonogram, index);
	unsigned char *constraintArray = nonogramRowsConstraintsToArray(nonogram, index);
	unsigned char countBlack = 0;
	Pixel current = WHITE;
	unsigned char currentConstraintIndex = 0;
	unsigned char x = 0;

	while (x < width) {
		while ((current == WHITE) && (x < width)) {
			current = nonogramGetXY(nonogram, x++, index);
		}
		if (x < width) {
			countBlack = 0;
			while (current == BLACK) {
				countBlack++;
				current = nonogramGetXY(nonogram, x++, index);
			}
			if (constraintArray[currentConstraintIndex++] != countBlack) {
				free(constraintArray);
				return 0;
			}
			if (currentConstraintIndex > constraintSize) {
				free(constraintArray);
				return 0;
			}
		}
	}
	const unsigned char result = (currentConstraintIndex == constraintSize)
		|| ((currentConstraintIndex == 0) && (constraintArray[0] == 0));
	free(constraintArray);

	return result;
}

unsigned char isNonogramColumnCorrectlyFilled(const Nonogram *nonogram, const unsigned char index) {
	if (nonogram == NULL) return 0;
	if (nonogramGetWidth(nonogram) <= index) return 0;

	const unsigned char height = nonogramGetHeight(nonogram);
	const unsigned char constraintSize = nonogramColumnsConstraintsGetSize(nonogram, index);
	unsigned char *constraintArray = nonogramColumnsConstraintsToArray(nonogram, index);
	unsigned char countBlack = 0;
	Pixel current = WHITE;
	unsigned char currentConstraintIndex = 0;
	unsigned char y = 0;

	while (y < height) {
		while ((current == WHITE) && (y < height)) {
			current = nonogramGetXY(nonogram, index, y++);
		}
		if (y < height) {
			countBlack = 0;
			while (current == BLACK) {
				countBlack++;
				current = nonogramGetXY(nonogram, index, y++);
			}
			if (constraintArray[currentConstraintIndex++] != countBlack) {
				free(constraintArray);
				return 0;
			}
			if (currentConstraintIndex > constraintSize) {
				free(constraintArray);
				return 0;
			}
		}
	}
	const unsigned char result = (currentConstraintIndex == constraintSize)
		|| ((currentConstraintIndex == 0) && (constraintArray[0] == 0));
	free(constraintArray);

	return result;
}

unsigned char isNonogramAllRowsCorrectlyFilled(const Nonogram *nonogram) {
	if (nonogram == NULL) return 0;
	const unsigned char height = nonogramGetHeight(nonogram);
	for (unsigned index = 0; index < height; index++) {
		if (isNonogramRowCorrectlyFilled(nonogram, index) == 0) return index + 1;
	}
	return 0;
}

unsigned char isNonogramAllColumnsCorrectlyFilled(const Nonogram *nonogram) {
	if (nonogram == NULL) return 0;
	const unsigned char width = nonogramGetWidth(nonogram);
	for (unsigned index = 0; index < width; index++) {
		if (isNonogramColumnCorrectlyFilled(nonogram, index) == 0) return index + 1;
	}
	return 0;
}

char isNonogramCorrectlyFilled(const Nonogram *nonogram) {
	const char result = 0 + isNonogramAllRowsCorrectlyFilled(nonogram);
	return (result != 0) ? result : (char)(0 - isNonogramAllColumnsCorrectlyFilled(nonogram));
}
