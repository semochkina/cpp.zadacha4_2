#ifndef LINKED_HASH_TABLE_H
#define LINKED_HASH_TABLE_H

#include "HashTable.cpp"

// Хеш-таблица, представленная в виде массива элементов (которые в свою очередь представляют список).
class LinkedHashTable : public HashTable {
private:
    // размер хеш таблицы
    static const int DIMENSION_SIZE = 11;
    // простая хеш-функция - остаток от деления на размер массива указателей
    int hash(int key) {
        return key % DIMENSION_SIZE;
    }

    HashEntry *search(int key, HashEntry *result) {
        while (result != nullptr && result->getKey() != key) {
            result = result->getNext();
        }
        return result;
    }

    bool delFromTable(int key) {
        int hashNumber = hash(key);
        HashEntry *result = table[hashNumber];
        if (result != nullptr) {
            if (result->getKey() == key) {
                table[hashNumber] = result->getNext();
                result->setNext(nullptr);
                delete result;
                return true;
            }
            while (true) {
                HashEntry *parent = result;
                result = result->getNext();
                if (result == nullptr)
                    break;
                if (result->getKey() == key) {
                    parent->setNext(result->getNext());
					result->setNext(nullptr);
                    delete result;
                    return true;
                }
            }

            HashEntry *entry2 = search(key, allEntry);

            entry2->setNext(nullptr);
            delete entry2;
        }
        return false;
    }

public:
    HashEntry *table[DIMENSION_SIZE];
    HashEntry *allEntry;
    HashEntry *allEntryLast;

    LinkedHashTable() {
        for (int i = 0; i < DIMENSION_SIZE; i++) {
            table[i] = nullptr;
        }
        allEntry = allEntryLast = nullptr;
    }

    ~LinkedHashTable() {
        clear();
    }

    // найти элемент
    HashEntry *find(int key) {
        return search(key, table[hash(key)]);
    }

    // добавить элемент в таблицу
    void push(int key, double value) {
        HashEntry *pEntry = find(key);
        if (pEntry == nullptr) {
            int hashNumber = hash(key);
            HashEntry *entry = new HashEntry(key, value);
            HashEntry *place = table[hashNumber];
            if (place == nullptr) {
                table[hashNumber] = entry;
            } else {
                while (place->getNext() != nullptr) {
                    place = place->getNext();
                }
                place->setNext(entry);
            }
            HashEntry *entry2 = new HashEntry(key, value);
            if (allEntry == nullptr) {
                allEntry = allEntryLast = entry2;
            } else {
                allEntryLast->setNext(entry2);
                allEntryLast = entry2;
            }
        } else {
            pEntry->setValue(value);
            search(key, allEntry)->setValue(value);
        }
    }

    // удалить элемент
    bool del(int key) {
        if (delFromTable(key)) {
            HashEntry *entry = search(key, allEntry);
            if (allEntry == allEntryLast) {
                // только один элемент
                allEntry = allEntryLast = nullptr;
            } else if (allEntry == entry) {
                // первый элемент
                allEntry = entry->getNext();
            } else {
                HashEntry *entry2 = allEntry;
                HashEntry *parent = allEntry;
                while (entry2 != nullptr) {
                    if (entry2->getKey() == key) {
                        parent->setNext(entry2->getNext());
                        if (entry2->getNext() == nullptr) {
                            allEntryLast = parent;
                        }
						break;
                    }
                    parent = entry2;
                    entry2 = entry2->getNext();
                }
            }
            entry->setNext(nullptr);
            delete entry;
        }
        return false;
    }

    // сделать таблицу пустой
    void clear() {
        for (int i = 0; i < DIMENSION_SIZE; i++) {
            delete table[i];
            table[i] = nullptr;
        }
        delete allEntry;
        allEntry = allEntryLast = nullptr;
    }

    // проверка таблицы на пустоту
    bool isEmpty() {        
        return allEntry == nullptr;
    }

    int dimensionSize() {
        return DIMENSION_SIZE;
    }
};

#endif
