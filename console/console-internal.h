//
// Created by JAD on 18/05/2026.
//

#ifndef NONOGRAMME_CONSOLE_INTERNAL_H
#define NONOGRAMME_CONSOLE_INTERNAL_H

#include "console.h"
#include <stdlib.h>

#define CHARACTER_BLACK 219
#define CHARACTER_WHITE ' '

void displayError(const char *message);
unsigned char getMaxConstraintsRowFromNonogram(const Nonogram *nonogram, unsigned char height);
unsigned char getMaxConstraintsColumnFromNonogram(const Nonogram *nonogram, unsigned char width);

#endif //NONOGRAMME_CONSOLE_INTERNAL_H
