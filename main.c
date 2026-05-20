#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"
#include "console/console.h"

int main(void) {
    Nonogram *nonogram = loadNonogramFromFile("../doc/jad.nono");

    displayNonogramWithConstraints(nonogram);

    deleteNonogram(nonogram);

    return 0;
}
