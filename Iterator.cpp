#ifndef ITERATOR_H
#define ITERATOR_H

#include "HashEntry.cpp"

class Iterator {
public:
    // начать работу
    virtual void start() = 0;

    // проверка все ли проитерировано
    virtual bool hasNext() = 0;

    // получить очередной элемент
    virtual HashEntry *next() = 0;

    // вывести в поток
    friend std::ostream &operator<<(std::ostream &os, Iterator &element) {
        element.start();
        os << "Iterator";
        while (element.hasNext()) {
            os << ", " << *element.next();
        }
        return os;
    }};

#endif
