#pragma once
#include <map>
#include <iostream>
using namespace std;

template <class T>
class Container {
    map<int, T> data;

public:
    // создание и заполнение контейнера
    Container(int n) {
        for (int i = 0; i < n; i++) {
            T temp;
            cout << "Element " << i << ":\n";
            cin >> temp;
            data[i] = temp;
        }
    }

    // вывод контейнера
    void Print() {
        for (auto [key, val] : data)
            cout << key << ": " << val << endl;
    }

    // удаление элементов по диапазону ключей
    void RemoveRange(int k1, int k2) {
        for (int i = k1; i <= k2; i++)
            data.erase(i);
    }

    // добавление максимального элемента
    void AddMax() {
        if (data.empty()) return;

        auto max_it = data.begin();
        for (auto it = data.begin(); it != data.end(); ++it)
            if (it->second > max_it->second)
                max_it = it;

        int new_key = data.rbegin()->first + 1;
        data[new_key] = max_it->second;
    }

    // вычисление и добавление среднего значения
    void AddAverage() {
        if (data.empty()) return;

        T sum = data.begin()->second;
        auto it = data.begin();
        for (++it; it != data.end(); ++it)
            sum = sum + it->second;

        T avg = sum / (int)data.size();

        for (auto& [key, val] : data)
            val += avg;
    }
};