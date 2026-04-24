#include <iostream>
#include <clocale>
#include <string>
using namespace std;

void poisk(const string& str, const string& key) {
	int length_str = str.length();
	int length_key = key.length();

	for (int i = 0; i <= length_str - length_key; i++) {
		bool flag = true;
		for (int j = 0; j < length_key; j++) {
			if (str[i + j] != key[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Подстрока найдена. Индекс первого символа: " << i;
			return;
		}
	}
	cout << "Подстрока не найдена.";
}

int main() {
	setlocale(LC_ALL, "ru");

	string str, key;
	cout << "Введите строку: ";
	getline(cin, str);

	cout << "Введите ключ: ";
	getline(cin, key);

	poisk(str, key);
}