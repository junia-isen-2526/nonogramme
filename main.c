#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"
#include "console/console.h"
#include "service/nonogrammeservice.h"

int main(void) {
	Nonogram *nonogram = loadNonogramFromFile("../doc/jad.nono");

	displayNonogramWithConstraints(nonogram);
	displayNonogram(nonogram);

	printf("%d\n", isNonogramBlackRowsEqualsBlackColumn(nonogram));

	printf("%d\n", isNonogramEachConstraintsLessOrEqualsThanDimension(nonogram));

	printf("%d\n", isNonogramAllConstraintsContainsOneZeroOrNone(nonogram));

	deleteNonogram(nonogram);

	// system("pause");

	return 0;
}
