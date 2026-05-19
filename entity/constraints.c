//
// Created by JAD on 19/05/2026.
//

#include "constraints-internal.h"

ConstraintCell *createConstraintCell(const Constraint constraint) {
	ConstraintCell *constraintCell = malloc(sizeof(ConstraintCell));
	if (constraintCell == NULL) return NULL;
	constraintCell->constraint = constraint;
	constraintCell->next = NULL;
	return constraintCell;
}

void deleteConstraintCell(ConstraintCell *constraintCell) {
	if (constraintCell != NULL) free(constraintCell);
}

Constraints *createConstraints() {
	Constraints *constraints = malloc(sizeof(Constraints));
	if (constraints == NULL) return NULL;
	constraints->head = NULL;
	return constraints;
}

void deleteConstraints(Constraints *constraints) {
	if (constraints != NULL) {
		ConstraintCell *current = constraints->head;
		while (current != NULL) {
			ConstraintCell *next = current->next;
			deleteConstraintCell(current);
			current = next;
		}
		free(constraints);
	}
}

void ConstraintsRecursiveAddConstraints(ConstraintCell *head, Constraint constraint) {
	if (head->next == NULL) {
		head->next = createConstraintCell(constraint);
	} else {
		ConstraintsRecursiveAddConstraints(head->next, constraint);
	}
}

void ConstraintsAddConstraints(Constraints *contraints, const Constraint constraint) {
	if (contraints != NULL) {
		if (contraints->head == NULL) {
			contraints->head = createConstraintCell(constraint);
		} else {
			ConstraintsRecursiveAddConstraints(contraints->head, constraint);
		}
	}
}

unsigned char constraintsGetSize(const Constraints *constraints) {
	if (constraints != NULL) {
		unsigned char size = 0;
		const ConstraintCell *current = constraints->head;
		while (current != NULL) {
			size++;
			current = current->next;
		}
		return size;
	}
	return 0;
}

unsigned char *constraintsToArray(const Constraints *constraints) {
	if (constraints != NULL) {
		const unsigned char size = constraintsGetSize(constraints);
		unsigned char *array = malloc(sizeof(unsigned char) * size);
		if (array != NULL) {
			unsigned char index = 0;
			const ConstraintCell *current = constraints->head;
			while (current != NULL) {
				array[index] = current->constraint;
				index++;
				current = current->next;
			}
			return array;
		}
	}
	return NULL;
}
