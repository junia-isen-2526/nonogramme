//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMME_SERVICE_VALID_H
#define NONOGRAMME_NONOGRAMME_SERVICE_VALID_H

#include "../entity/nonogram.h"
#include "stdlib.h"

unsigned char isNonogramBlackRowsEqualsBlackColumn(const Nonogram *nonogram);
unsigned char isNonogramEachConstraintsLessOrEqualsThanDimension(const Nonogram *nonogram);
unsigned char isNonogramAllConstraintsContainsOneZeroOrNone(const Nonogram *nonogram);

#endif //NONOGRAMME_NONOGRAMME_SERVICE_VALID_H
