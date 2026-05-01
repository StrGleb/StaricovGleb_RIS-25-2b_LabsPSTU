#pragma once

class fraction {
    int first;
    double second;

public:
    void Init(int f, double s);
    void Read();
    void Show();
    double multiply(double k);
};