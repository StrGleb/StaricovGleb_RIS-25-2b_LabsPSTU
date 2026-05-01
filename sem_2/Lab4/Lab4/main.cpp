#include "Person.h"
#include "Employee.h"
#include <iostream>

using namespace std;

void f1(Person& p) {
    p.setName("Ivan");
    cout << p;
}

Person f2() {
    Employee e("Petr", 25, "manager", 50000);
    return e;
}

int main() {
    Person a;
    Person b("Alex", 20);

    cin >> a;
    cout << a;

    cout << b;

    a = b;
    cout << a << endl;

    Employee c;
    cin >> c;
    cout << c;

    cout << "\nSalary with bonus: " << c.getFullSalary(20) << endl;

    f1(c);

    a = f2();
    cout << a;

    return 0;
}