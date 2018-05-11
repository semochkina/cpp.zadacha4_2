#ifndef FIRST_HASH_TABLE_H
#define FIRST_HASH_TABLE_H

#include "HashTable.cpp"

// Хеш-таблица, представленная в виде массива элементов (которые в свою очередь представляют список).
class FirstHashTable : public HashTable {
private:
    // простая хеш-функция - остаток от деления на размер массива указателей
    int hash(int key) {
        return key % DIMENSION_SIZE;
    }

public:
   
    FirstHashTable() {
        for (int i = 0; i < DIMENSION_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~FirstHashTable() {
        clear();
    }

    // найти элемент
    HashEntry *find(int key) {
        int hashNumber = hash(key);
        HashEntry *result = table[hashNumber];
        while (result != nullptr && result->getKey() != key) {
            result = result->getNext();
        }
        return result;
    }

    // добавить элемент в таблицу
    void push(int key, double value) {
        HashEntry *pEntry = find(key);
        if (pEntry == nullptr) {
            int hashNumber = hash(key);
            HashEntry *pers = new HashEntry(key, value);
            HashEntry *place = table[hashNumber];
            if (place == nullptr) {
                table[hashNumber] = pers;
            } else {
                while (place->getNext() != nullptr) {
                    place = place->getNext();
                }
                place->setNext(pers);
            }
        } else {
            pEntry->setValue(value);
        }
    }

    // удалить элемент
    bool del(int key) {
        int hashNumber = hash(key);
        HashEntry *result = table[hashNumber];
        if (result != nullptr) {
            if (result->getKey() == key) {
                table[hashNumber] = result->getNext();
               // result->setNext(nullptr);
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
					//result->setNext(nullptr);
                    delete result;
                    return true;
                }
            }
        }
        return false;
    }

    // сделать таблицу пустой
    void clear() {
        for (int i = 0; i < DIMENSION_SIZE; i++) {
            delete table[i];
            table[i] = nullptr;
        }
    }

    // проверка таблицы на пустоту
    bool isEmpty() {
        for (int i = 0; i < DIMENSION_SIZE; i++) {
            if (table[i] != nullptr)
                return false;
        }
        return true;
    }
};

#endif
