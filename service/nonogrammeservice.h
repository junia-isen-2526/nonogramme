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

#endif //NONOGRAMME_NONOGRAMMESERVICE_H
