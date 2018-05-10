#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "HashEntry.cpp"

// Хеш-таблица
class HashTable {
public:
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
};

#endif
