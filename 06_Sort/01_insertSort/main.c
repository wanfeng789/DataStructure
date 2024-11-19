#include "insertSort.h"

int main() {
	int n = 50000;
	SortTable *table1 = generateRandomArray(n, 0, n);
	SortTable *table2 = generateLinearArray(n, 5);
	SortTable *table3 = copySortTable(table1);

	testSort("random insertSort: ", insertSortV1, table1);
	testSort("linear insertSort: ", insertSortV1, table2);
	testSort("shell insertSort: ", shellSort, table3);

	releaseSortTable(table1);
	releaseSortTable(table2);
	releaseSortTable(table3);
	return 0;
}
