#include "IteratorFirstHashTable.cpp"
#include "IteratorLinkedHashTable.cpp"

/**
 https://ruhighload.com/%d0%a7%d1%82%d0%be+%d1%82%d0%b0%d0%ba%d0%be%d0%b5+%d1%85%d0%b5%d1%88-%d1%82%d0%b0%d0%b1%d0%bb%d0%b8%d1%86%d1%8b+%d0%b8+%d0%ba%d0%b0%d0%ba+%d0%be%d0%bd%d0%b8+%d1%80%d0%b0%d0%b1%d0%be%d1%82%d0%b0%d1%8e%d1%82

 Хеш-таблица, реализация методом цепочек (открытым хешированием)
*/

void start(HashTable *newTable, Iterator *iterator) {
    newTable->push(2, 2.2);
    newTable->push(4, 4.4);
	newTable->push(3, 3.3);
    newTable->push(1, 1.1);
	newTable->push(12, 12.12);
	newTable->push(13, 44);

    newTable->del(4);

    HashEntry *search = newTable->find(3);
    if (search) {
        std::cout << "search - " << search->getValue() << std::endl;
    }

    std::cout << *newTable << std::endl;
	std::cout << *iterator << std::endl;

    std::cout << "isEmpty() - " << newTable->isEmpty() << std::endl;
    std::cout << "clear()" << std::endl;
    newTable->clear();
    std::cout << "isEmpty() - " << newTable->isEmpty() << std::endl;

    std::cout << "---------------------\n";
}

int main() {
    FirstHashTable firstHashTable;
    IteratorFirstHashTable iteratorFirstHashTable(&firstHashTable);
    start(&firstHashTable, &iteratorFirstHashTable);

    LinkedHashTable linkedHashTable;
    IteratorLinkedHashTable iteratorLinkedHashTable(&linkedHashTable);
    start(&linkedHashTable, &iteratorLinkedHashTable);

    std::cin.get();
    return 0;
}
