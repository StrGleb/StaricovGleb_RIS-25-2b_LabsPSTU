#pragma once

// Абстрактный базовый класс Object
class Object {
public:
	Object() {}              // конструктор
	virtual ~Object() {}    // виртуальный деструктор (важен для полиморфизма)
	virtual void Show() = 0; // чисто виртуальная функция (делает класс абстрактным)
};