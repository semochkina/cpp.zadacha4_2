#ifndef HASH_ENTRY_H
#define HASH_ENTRY_H

#include <iostream>

// односвязный список с соответствующей информацией (ключ + значение)
class HashEntry {
private:
    // при одинаковом значении хэш функции указывает на следующий элемент в односвязном списоке
    HashEntry *next;
    int key;
    double value;
public:
    HashEntry(int key, double value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    ~HashEntry() {
//        std::cout << "Delete " << this->value << std::endl;
        if (this->next != nullptr) delete this->next;
    }

    int getKey() {
        return key;
    }

    double getValue() {
        return value;
    }

    void setValue(double value) {
        this->value = value;
    }

    HashEntry *getNext() {
        return next;
    }

    void setNext(HashEntry *next) {
        this->next = next;
    }

    friend std::ostream &operator<<(std::ostream &os, HashEntry &element) {
        os << "{" << element.key << ", " << element.value << "}";
        return os;
    }

};
#endif