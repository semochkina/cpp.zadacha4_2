#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "HashEntry.cpp"

// Хеш-таблица
class HashTable {
public:

	// размер хеш таблицы
	static const int DIMENSION_SIZE = 11;
	HashEntry *table[DIMENSION_SIZE];

	// добавить элемент в таблицу
	virtual void push(int key, double value) = 0;

	// найти элемент
	virtual HashEntry *find(int key) = 0;

	// удалить элемент
	virtual bool del(int key) = 0;

	// сделать таблицу пустой
	virtual void clear() = 0;

	// проверка таблицы на пустату
	virtual bool isEmpty() = 0;

	// количество ячеек у хеш-таблицы
	int dimensionSize() {
		return DIMENSION_SIZE;
	}

	// вывести в поток
	friend std::ostream &operator<<(std::ostream &os, HashTable &element) {
		for (int i = 0; i < DIMENSION_SIZE; i++) {
			os << "Row " << i;
			HashEntry *pEntry = element.table[i];
			while (pEntry != nullptr) {
				os << (pEntry == element.table[i] ? ": " : ", ") << *pEntry;
				pEntry = pEntry->getNext();
			}
			os << "\n";
		}
		return os;
	}

};

#endif
