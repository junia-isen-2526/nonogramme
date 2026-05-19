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
	return 0;
}
