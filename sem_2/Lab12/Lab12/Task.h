#pragma once
#include <set>
#include <map>
#include "Pair.h"

// Задача 1: set <double>
typedef std::set<double> TSet;
TSet make_set(int n);
void print_set(const TSet& s);
void modify_set(TSet& s, double min_v, double max_v);

// Задача 2: map <int, Pair>
typedef std::map<int, Pair> TMap;
TMap make_map(int n);
void print_map(const TMap& m);
void process_map(TMap& m, int k1, int k2); // внешний символ