#include <iostream>
#include "Vector.h"  // вариант 1 (int)
#include "List.h"    // вариант 2 (error)
#include "Error.h"

using namespace std;

/*
    Демонстрация двух способов обработки исключений:

    Вариант 1:
    исключения передаются через тип int

    Вариант 2:
    используется пользовательский класс error
*/

int main() {

    // ===== ВАРИАНТ 1 =====
    try {
        cout << "=== Variant 1 (Vector) ===\n";

        int n;
        cout << "Enter size of vector: ";
        cin >> n;

        Vector v(n);

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cout << "v[" << i << "] = ";
            cin >> v[i];
        }

        int i;
        cout << "Enter index: ";
        cin >> i;

        cout << "Element: " << v[i] << endl;
    }
    catch (int e) {
        cout << "EXCEPTION CODE: " << e << endl;
    }

    cout << "\n----------------------\n";

    // ===== ВАРИАНТ 2 =====
    try {
        cout << "=== Variant 2 (List) ===\n";

        int n;
        cout << "Enter size of list: ";
        cin >> n;

        List a(n);

        cout << "Enter elements:\n";
        for (int i = 0; i < a(); i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }

        int x;
        cout << "Enter element to add: ";
        cin >> x;

        List b = a + x;

        cout << "New list: " << b;

        int i;
        cout << "Enter index: ";
        cin >> i;

        cout << "Element: " << b[i] << endl;
    }
    catch (error e) {
        cout << "Error: ";
        e.what();
    }

    return 0;
}
/*
    ПРИМЕРЫ ДЛЯ ВЫЗОВА ОШИБОК (ВАРИАНТ 1, int):

    КОДЫ ОШИБОК:
    1 — size > MAX_SIZE
    2 — index < 0
    3 — index >= size
    4 — overflow (a + b)
    5 — overflow (a + int)
    6 — empty vector

    -------------------------------------

    1) Ошибка 1 (превышен размер)
       Ввод:
       Enter size: 100

    2) Ошибка 2 (индекс < 0)
       Ввод:
       1 2 3
       Index: -1

    3) Ошибка 3 (индекс >= size)
       Ввод:
       1 2 3
       Index: 10

    4) Ошибка 4 (переполнение при a + b)
       Ввод:
       (20 элементов для a)
       (20 элементов для b)

    5) Ошибка 5 (переполнение при a + int)
       Ввод:
       (30 элементов)
       Добавить элемент

    6) Ошибка 6 (удаление из пустого)
       Ввод:
       size: 1
       5
       (--a несколько раз)


    ПРИМЕРЫ ДЛЯ ВЫЗОВА ОШИБОК (ВАРИАНТ 2):

    1) size > MAX_SIZE
       Ввод:
       Enter size: 50

    2) index < 0
       Ввод:
       Enter size: 3
       1 2 3
       Enter element: 5
       Index: -1

    3) index > size
       Ввод:
       Enter size: 3
       1 2 3
       Enter element: 5
       Index: 10

    4) overflow (добавление элемента)
       Ввод:
       Enter size: 20
       (ввести 20 чисел)
       Enter element: 5

    5) empty list
       Ввод:
       Enter size: 1
       5
       Enter element: 2
       Index: 0
       (далее выполняется --a несколько раз)
*/