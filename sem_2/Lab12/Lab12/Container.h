#pragma once
#include <map>
#include <iostream>

template <class T>
class Container {
    std::map<int, T> data;
public:
    Container(int n) {
        for (int i = 0; i < n; i++) {
            T temp;
            std::cout << "  Element " << i << ":" << std::endl;
            std::cin >> temp;
            data[i] = temp;
        }
    }

    void Print() {
        for (auto const& [key, val] : data) std::cout << key << " : " << val << "\n";
    }

    void RemoveRange(int k1, int k2) {
        for (int i = k1; i <= k2; i++) data.erase(i);
    }

    void AddMax() {
        if (data.empty()) return;
        auto max_it = data.begin();
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it->second > max_it->second) max_it = it;
        }
        int next_key = data.rbegin()->first + 1;
        data[next_key] = max_it->second;
    }

    void AddAverage() {
        if (data.empty()) return;
        T sum = data.begin()->second;
        auto it = data.begin();
        for (++it; it != data.end(); ++it) sum = sum + it->second;
        T avg = sum / (int)data.size();
        for (auto& [key, val] : data) val += avg;
    }
};