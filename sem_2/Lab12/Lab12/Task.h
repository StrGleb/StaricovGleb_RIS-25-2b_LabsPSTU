#pragma once
#include <set>
#include <map>
#include "Pair.h"

using namespace std;

// ===== ЗАДАЧА 1 =====
// контейнер set<double>
typedef set<double> TSet;

// создание контейнера
TSet make_set(int n);

// вывод контейнера
void print_set(const TSet& s);

// обработка контейнера
void modify_set(TSet& s, double a, double b);


// ===== ЗАДАЧА 2 =====
// контейнер map<int, Pair>
typedef map<int, Pair> TMap;

// создание контейнера
TMap make_map(int n);

// вывод контейнера
void print_map(const TMap& m);

// обработка контейнера
void process_map(TMap& m, int k1, int k2);