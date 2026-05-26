#include <stdio.h>
#include "entity/nonogram.h"
#include "repository/nonogramfile.h"
#include "console/console.h"
#include "service/service_correctly_filed.h"
#include "service/service_nonogram_solve.h"
#include "service/service_nonogram_valid.h"

int main(void) {
	Nonogram *nonogram = loadNonogramFromFile("../doc/damier.nono");

	displayNonogramWithConstraints(nonogram);
	// displayNonogram(nonogram);

	printf("%d\n", isNonogramBlackRowsEqualsBlackColumn(nonogram));

	printf("%d\n", isNonogramEachConstraintsLessOrEqualsThanDimension(nonogram));

	printf("%d\n", isNonogramAllConstraintsContainsOneZeroOrNone(nonogram));

	printf("%d\n", isNonogramRowCorrectlyFilled(nonogram, 10));
	printf("%d\n", isNonogramAllRowsCorrectlyFilled(nonogram));

	printf("%d\n", isNonogramCorrectlyFilled(nonogram));

	nonogramSolve(nonogram);

	saveNonogramToFile("../doc/damier-solved.nono", nonogram);
	Nonogram *nonogramSolved = loadNonogramFromFile("../doc/damier-solved.nono");
	displayNonogramWithConstraints(nonogramSolved);

	deleteNonogram(nonogram);
	deleteNonogram(nonogramSolved);

	// system("pause");

	return 0;
}
