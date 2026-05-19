//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_DIMENSION_INTERNAL_H
#define NONOGRAMME_DIMENSION_INTERNAL_H
#include "dimension.h"

Dimension *createDimension(unsigned char width, unsigned char height);
void deleteDimension(Dimension *dimension);

#endif //NONOGRAMME_DIMENSION_INTERNAL_H
