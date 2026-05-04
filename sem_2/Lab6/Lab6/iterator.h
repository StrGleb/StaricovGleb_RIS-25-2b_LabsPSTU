#pragma once

class Iterator {
private:
    int* elem; // указатель на текущий элемент

public:
    Iterator() { elem = 0; } // конструктор
    Iterator(const Iterator& it) { elem = it.elem; } // конструктор копирования

    bool operator==(const Iterator& it) const { return elem == it.elem; } // проверка равенства
    bool operator!=(const Iterator& it) const { return elem != it.elem; } // проверка неравенства

    void operator++() { ++elem; } // переход к следующему элементу
    Iterator operator++(int) { Iterator tmp = *this; ++elem; return tmp; } // постфиксный инкремент

    void operator--() { --elem; } // переход к предыдущему элементу

    int& operator*() { return *elem; } // доступ к текущему элементу

    friend class List; // доступ класса List к закрытым данным
};