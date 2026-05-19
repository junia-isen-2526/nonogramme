#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"

int main(void) {
    Nonogram *nonogram = loadNonogramFromFile("../doc/jad.nono");
    return 0;
}
