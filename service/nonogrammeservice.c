//
// Created by JAD on 18/05/2026.
//

#include "nonogrammeservice.h"

unsigned char isNonogramBlackRowsEqualsBlackColumn(const Nonogram *nonogram) {
	unsigned char blackRowsCount = 0;
	unsigned char blackColumnsCount = 0;

	if (nonogram == NULL) return 0;
	const unsigned char width = nonogramGetWidth(nonogram);
	const unsigned char height = nonogramGetHeight(nonogram);

	for (unsigned char constraintsIndex = 0; constraintsIndex < height; constraintsIndex++) {
		const unsigned char constraintSize = nonogramRowsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char *constraintArray = nonogramRowsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			blackRowsCount += constraintArray[constraintIndex];
		}
		free(constraintArray);
	}

	for (unsigned char constraintsIndex = 0; constraintsIndex < width; constraintsIndex++) {
		const unsigned char constraintSize = nonogramColumnsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char *constraintArray = nonogramColumnsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			blackColumnsCount += constraintArray[constraintIndex];
		}
		free(constraintArray);
	}

	return blackRowsCount == blackColumnsCount;
}

unsigned char isNonogramEachConstraintsLessOrEqualsThanDimension(const Nonogram *nonogram) {
	if (nonogram == NULL) return 0;
	const unsigned char width = nonogramGetWidth(nonogram);
	const unsigned char height = nonogramGetHeight(nonogram);

	for (unsigned char constraintsIndex = 0; constraintsIndex < height; constraintsIndex++) {
		const unsigned char constraintSize = nonogramRowsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char rowsSizeMin = constraintSize - 1;
		unsigned char *constraintArray = nonogramRowsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			rowsSizeMin += constraintArray[constraintIndex];
		}
		free(constraintArray);
		if (rowsSizeMin > width) return 0;
	}

	for (unsigned char constraintsIndex = 0; constraintsIndex < width; constraintsIndex++) {
		const unsigned char constraintSize = nonogramColumnsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char columnsSizeMin = constraintSize - 1;
		unsigned char *constraintArray = nonogramColumnsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			columnsSizeMin += constraintArray[constraintIndex];
		}
		free(constraintArray);
		if (columnsSizeMin > height) return 0;
	}

	return 1;
}

unsigned char isNonogramAllConstraintsContainsOneZeroOrNone(const Nonogram *nonogram) {
	if (nonogram == NULL) return 0;
	const unsigned char width = nonogramGetWidth(nonogram);
	const unsigned char height = nonogramGetHeight(nonogram);

	for (unsigned char constraintsIndex = 0; constraintsIndex < height; constraintsIndex++) {
		const unsigned char constraintSize = nonogramRowsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char *constraintArray = nonogramRowsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			if ((constraintSize > 1) && (constraintArray[constraintIndex]) == 0) {
				free(constraintArray);
				return 0;
			}
		}
		free(constraintArray);
	}

	for (unsigned char constraintsIndex = 0; constraintsIndex < width; constraintsIndex++) {
		const unsigned char constraintSize = nonogramColumnsConstraintsGetSize(nonogram, constraintsIndex);
		unsigned char *constraintArray = nonogramColumnsConstraintsToArray(nonogram, constraintsIndex);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintSize; constraintIndex++) {
			if ((constraintSize > 1) && (constraintArray[constraintIndex]) == 0) {
				free(constraintArray);
				return 0;
			}
		}
		free(constraintArray);
	}

	return 1;
}

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
	char result = 0 + isNonogramAllRowsCorrectlyFilled(nonogram);
	return (result != 0) ? result : (0 - isNonogramAllColumnsCorrectlyFilled(nonogram));
}
