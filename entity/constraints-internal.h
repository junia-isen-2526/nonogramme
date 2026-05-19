//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_CONSTRAINTS_INTERNAL_H
#define NONOGRAMME_CONSTRAINTS_INTERNAL_H

#include "constraints.h"

Constraints *createConstraints();
void deleteConstraints(Constraints *constraints);
void ConstraintsAddConstraints(Constraints *contraints, unsigned char adjacentBlack);
unsigned char constraintsGetSize(Constraints *constraints);
unsigned char *constraintsToArray(Constraints *constraints);

#endif //NONOGRAMME_CONSTRAINTS_INTERNAL_H
