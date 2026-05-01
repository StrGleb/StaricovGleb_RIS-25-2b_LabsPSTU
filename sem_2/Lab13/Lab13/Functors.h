#pragma once
#include "Pair.h"

// Предикат для удаления элементов с ключами в диапазоне [k1, k2]
struct InRange {
    int k1, k2;
    InRange(int a, int b) : k1(a), k2(b) {}
    bool operator()(const Pair& p) {
        return p.first >= k1 && p.first <= k2;
    }
};

// Функтор для алгоритма for_each (добавление среднего к каждому элементу)[cite: 2]
struct AddAvg {
    Pair avg;
    AddAvg(Pair p) : avg(p) {}
    void operator()(Pair& p) {
        p += avg;
    }
};

// Предикат для сортировки по убыванию[cite: 2]
struct GreaterThan {
    bool operator()(const Pair& p1, const Pair& p2) {
        return p1 > p2;
    }
};