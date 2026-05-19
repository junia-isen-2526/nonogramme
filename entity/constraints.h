//
// Created by JAD on 19/05/2026.
//

#ifndef NONOGRAMME_CONSTRAINTS_H
#define NONOGRAMME_CONSTRAINTS_H
#include "constraint.h"

typedef struct ConstraintCell {
	Constraint constraint;
	struct ConstraintCell *next;
} ConstraintCell;

typedef struct Constraints {
	ConstraintCell *head;
} Constraints;

#endif //NONOGRAMME_CONSTRAINTS_H
