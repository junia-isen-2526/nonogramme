//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMMEFILE_H
#define NONOGRAMME_NONOGRAMMEFILE_H

#include <stdlib.h>
#include <stdio.h>
#include "../entity/nonogram.h"

Nonogram *loadNonogramFromFile(const char *filename) {
	if (filename == NULL) return NULL;
	FILE *file = fopen(filename, "r");
	if (file == NULL) return NULL;
	Nonogram *nonogram = NULL;
	char buffer[256];
	if (fgets(buffer, sizeof(buffer), file) != NULL) {
		int rows, cols;
		if (strtol(buffer, NULL, 10) > 0 && strtol(buffer, NULL, 10) > 0) {
			nonogram = createNonogram(rows, cols);
		}
	}
}

int saveNonogramToFile(const char *filename, Nonogram *nonogram);

#endif //NONOGRAMME_NONOGRAMMEFILE_H
