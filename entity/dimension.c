//
// Created by JAD on 19/05/2026.
//

#include "dimension-internal.h"

Dimension *createDimension(unsigned char width, unsigned char height) {
	Dimension *dimension = malloc(sizeof(Dimension));
	if (dimension == NULL) return NULL;
	dimension->width = width;
	dimension->height = height;
	return dimension;
}
void deleteDimension(Dimension *dimension) {
	if (dimension != NULL) {
		free(dimension);
	}
}
