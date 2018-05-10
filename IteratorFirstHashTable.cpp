#include "Iterator.cpp"
#include "FirstHashTable.cpp"

// итератор для HashTable
class IteratorFirstHashTable : public Iterator {
private:
    FirstHashTable *hashTable;
    // текущий элемент
    int currHashNumber;
    HashEntry *currHashEntry;

public:
    IteratorFirstHashTable(FirstHashTable *hashTable) : hashTable(hashTable) {
        start();
    }

    void start() {
        currHashNumber = -1;
    }

    HashEntry *next() {
        return currHashEntry;
    }

    bool hasNext() {
        if (currHashNumber < hashTable->dimensionSize()) {
            if (currHashNumber == -1) {
                // первый элемент
                currHashNumber = 0;
            } else {
                // не первый элемент и пока не все перебрали
                currHashEntry = currHashEntry->getNext();
                if (currHashEntry != nullptr) {
                    // в этом списке еще остались элементы
                    return true;
                }
                currHashNumber++;
            }
            while (currHashNumber < hashTable->dimensionSize()) {
                currHashEntry = hashTable->table[currHashNumber];
                if (currHashEntry != nullptr) {
                    return true;
                }
                currHashNumber++;
            }
        }
        return false;
    }
};
