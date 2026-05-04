#pragma once

class fraction {
    int first; // целая часть числа
    double second; // дробная часть числа

public:
    void Init(int f, double s); // Метод инициализации полей класса
    void Read(); // Метод ввода значений с клавиатуры
    void Show(); // Метод вывода значений на экран
    double multiply(int k); // Метод умножения числа на целое значение k
    double multiply(double k); // Метод умножения числа на вещественное значение k
};