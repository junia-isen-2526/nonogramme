//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMMEFILE_H
#define NONOGRAMME_NONOGRAMMEFILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../entity/nonogram.h"

Nonogram *loadNonogramFromFile(const char *filename);

int saveNonogramToFile(const char *filename, Nonogram *nonogram);

#endif //NONOGRAMME_NONOGRAMMEFILE_H
