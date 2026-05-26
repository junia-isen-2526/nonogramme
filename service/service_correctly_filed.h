//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_NONOGRAMME_SERVICE_CORRECTLY_FILLED_H
#define NONOGRAMME_NONOGRAMME_SERVICE_CORRECTLY_FILLED_H

#include "../entity/nonogram.h"
#include "stdlib.h"

unsigned char isNonogramAllRowsCorrectlyFilled(const Nonogram *nonogram);
unsigned char isNonogramAllColumnsCorrectlyFilled(const Nonogram *nonogram);
unsigned char isNonogramRowCorrectlyFilled(const Nonogram *nonogram, unsigned char index);
unsigned char isNonogramColumnCorrectlyFilled(const Nonogram *nonogram, unsigned char index);
char isNonogramCorrectlyFilled(const Nonogram *nonogram);

#endif //NONOGRAMME_NONOGRAMME_SERVICE_CORRECTLY_FILLED_H
