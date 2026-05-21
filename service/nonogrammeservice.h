//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMMESERVICE_H
#define NONOGRAMME_NONOGRAMMESERVICE_H

#include "../entity/nonogram.h"
#include "stdlib.h"

unsigned char isNonogramBlackRowsEqualsBlackColumn(const Nonogram *nonogram);
unsigned char isNonogramEachConstraintsLessOrEqualsThanDimension(const Nonogram *nonogram);
unsigned char isNonogramAllConstraintsContainsOneZeroOrNone(const Nonogram *nonogram);

// Return 1 if true, else 0
unsigned char isNonogramRowCorrectlyFilled(const Nonogram *nonogram, unsigned char index);
unsigned char isNonogramColumnCorrectlyFilled(const Nonogram *nonogram, unsigned char index);

// Return 0 if all correctly filled, else index of incorrectly filled row
unsigned char isNonogramAllRowsCorrectlyFilled(const Nonogram *nonogram);
// Return 0 if all correctly filled, else index of incorrectly filled column
unsigned char isNonogramAllColumnsCorrectlyFilled(const Nonogram *nonogram);

// Return 0 if all correctly filled, else index of incorrectly filled row (positiv) or column (negativ)
char isNonogramCorrectlyFilled(const Nonogram *nonogram);

#endif //NONOGRAMME_NONOGRAMMESERVICE_H
