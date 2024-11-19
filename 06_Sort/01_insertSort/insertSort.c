#include "insertSort.h"

// 芯的扑克牌的不断和前面元素进行判断，满足条件进行交换 [0 1...9, 10)
void insertSortV1(SortTable *table) {
	for (int i = 1; i < table->length; ++i) {
		Element e = table->data[i];
		int j;
		for (j = i; j > 0 && e.key < table->data[j - 1].key; --j) {
			// swapElement(&table->data[j], &table->data[j - 1]);
			table->data[j] = table->data[j - 1];
		}
		table->data[j] = e;
	}
}

void shellSort(SortTable *table) {
	// 按gap进行分组
	for (int gap = table->length / 2; gap > 0; gap /= 2) {
		// 每组都参加插入排序
		for (int i = gap; i < table->length; ++i) {
			Element temp = table->data[i];
			int j;
			for (j = i; j >= gap && table->data[j - gap].key > temp.key; j-=gap) {
				swapElement(&table->data[j], &table->data[j - gap]);
			}
			table->data[j] = temp;
		}
	}
}
