//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_CONSTRAINTS_INTERNAL_H
#define NONOGRAMME_CONSTRAINTS_INTERNAL_H

#include "constraints.h"
#include "stdlib.h"

ConstraintCell *createConstraintCell(Constraint constraint);
void deleteConstraintCell(ConstraintCell *constraintCell);

Constraints *createConstraints();
void deleteConstraints(Constraints *constraints);
void ConstraintsAddConstraints(Constraints *contraints, Constraint constraint);
unsigned char constraintsGetSize(const Constraints *constraints);
unsigned char *constraintsToArray(const Constraints *constraints);

#endif //NONOGRAMME_CONSTRAINTS_INTERNAL_H
