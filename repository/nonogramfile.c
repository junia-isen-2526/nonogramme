//
// Created by JAD on 18/05/2026.
//

#include "nonogramfile.h"

Nonogram *loadNonogramFromFile(const char *filename) {
	if (filename == NULL) return NULL;
	FILE *file = fopen(filename, "r");
	if (file == NULL) return NULL;
	Nonogram *nonogram = NULL;
	char buffer[256];
	if (fgets(buffer, sizeof(buffer), file) != NULL) {
		int rows, columns;
		if (sscanf_s(buffer, "%d %d", &rows, &columns, sizeof(int) * 2 == 2)) {
			nonogram = createNonogram(columns, rows);
		}
	} else {
		fclose(file);
		return NULL;
	}
	if (nonogram == NULL) {
		fclose(file);
		return NULL;
	}

	fgets(buffer, sizeof(buffer), file);
	for (unsigned char row = 0; row < nonogram->dimension->height; row++) {
		fgets(buffer, sizeof(buffer), file);
		char *constraintText = strtok(buffer, ";");
		while (constraintText != NULL) {
			int constraintValue;
			if (sscanf_s(constraintText, "%d", &constraintValue, sizeof(int) == 1)) {
				nonogramAddRowConstraint(nonogram, row, constraintValue);
			}
			constraintText = strtok(NULL, ";");
		}
	}

	fgets(buffer, sizeof(buffer), file);
	for (unsigned char column = 0; column < nonogram->dimension->width; column++) {
		fgets(buffer, sizeof(buffer), file);
		char *constraintText = strtok(buffer, ";");
		while (constraintText != NULL) {
			int constraintValue;
			if (sscanf_s(constraintText, "%d", &constraintValue, sizeof(int) == 1)) {
				nonogramAddColumnConstraint(nonogram, column, constraintValue);
			}
			constraintText = strtok(NULL, ";");
		}
	}

	fgets(buffer, sizeof(buffer), file);
	for (unsigned char row = 0; row < nonogram->dimension->height; row++) {
		fgets(buffer, sizeof(buffer), file);
		for (unsigned char column = 0; column < nonogram->dimension->width; column++) {
			if (buffer[column] == '1') {
				nonogramToggleXY(nonogram, column, row);
			}
		}
	}
	fclose(file);
	return nonogram;
}

int saveNonogramToFile(const char *filename, Nonogram *nonogram) {
	if ((filename == NULL) || (nonogram == NULL)) return -1;
	FILE *file = fopen(filename, "w");
	if (file == NULL) return -1;
	fprintf(file, "%d %d\n", nonogram->dimension->height, nonogram->dimension->width);

	unsigned char *constraintsArray;
	unsigned char constraintsSize;

	fprintf(file, "ROWS\n");
	for (unsigned char row = 0; row < nonogram->dimension->height; row++) {
		constraintsArray = nonogramRowsConstraintsToArray(nonogram, row);
		constraintsSize = nonogramRowsConstraintsGetSize(nonogram, row);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintsSize; constraintIndex++) {
			fprintf(file, "%d", constraintsArray[constraintIndex]);
			if (constraintIndex < constraintsSize - 1) fprintf(file, ";");
		}
		fprintf(file, "\n");
		free(constraintsArray);
	}

	fprintf(file, "COLS\n");
	for (unsigned char column = 0; column < nonogram->dimension->width; column++) {
		constraintsArray = nonogramColumnsConstraintsToArray(nonogram, column);
		constraintsSize = nonogramColumnsConstraintsGetSize(nonogram, column);
		for (unsigned char constraintIndex = 0; constraintIndex < constraintsSize; constraintIndex++) {
			fprintf(file, "%d", constraintsArray[constraintIndex]);
			if (constraintIndex < constraintsSize - 1) fprintf(file, ";");
		}
		fprintf(file, "\n");
		free(constraintsArray);
	}

	fprintf(file, "GRID\n");
	for (unsigned char row = 0; row < nonogram->dimension->height; row++) {
		for (unsigned char column = 0; column < nonogram->dimension->width; column++) {
			fprintf(file, "%d", nonogramGetXY(nonogram, column, row) == BLACK ? 1 : 0);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	return 0;
}
