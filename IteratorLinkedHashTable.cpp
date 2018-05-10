#include "Iterator.cpp"
#include "LinkedHashTable.cpp"

// итератор для HashTable
class IteratorLinkedHashTable : public Iterator {
private:
    LinkedHashTable *hashTable;
    HashEntry *currHashEntry;

public:
    IteratorLinkedHashTable(LinkedHashTable *hashTable) : hashTable(hashTable) {
        start();
    }

    void start() {
        currHashEntry = hashTable->allEntry;
    }

    HashEntry *next() {
        HashEntry *result = currHashEntry;
        currHashEntry = currHashEntry == nullptr ? nullptr : currHashEntry->getNext();
        return result;
    }

    bool hasNext() {
        return currHashEntry != nullptr;
    }
};
