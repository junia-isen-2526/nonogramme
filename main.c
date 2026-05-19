#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"

int main(void) {
    Nonogram *nonogram = loadNonogramFromFile("../doc/jad.nono");

    for (unsigned char row = 0; row < nonogramGetHeight(nonogram); row++) {
        for (unsigned char column = 0; column < nonogramGetWidth(nonogram); column++) {
            Pixel pixel = nonogramGetXY(nonogram, column, row);
            printf("%c ", pixel == BLACK ? '#' : ' ');
        }
        printf("\n");
    }
    return 0;
}
