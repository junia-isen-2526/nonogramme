#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"
#include "console/console.h"

int main(void) {
    Nonogram *nonogram = loadNonogramFromFile("../doc/9.nono");

    displayNonogramWithConstraints(nonogram);
    displayNonogram(nonogram);

    deleteNonogram(nonogram);

    // system("pause");

    return 0;
}
