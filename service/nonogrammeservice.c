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
		unsigned char columnsSizeMin = constraintSize;
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
