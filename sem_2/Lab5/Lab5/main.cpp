#include "object.h"
#include "person.h"
#include "employee.h"
#include "vector.h"

#include <iostream>
using namespace std;

int main() {
    Vector v(5);

    Person a;
    cin >> a;
    cout << endl;

    Employee b;
    cin >> b;

    Object* p = &a;
    v.Add(p);

    p = &b;
    v.Add(p);

    cout << v;

    cout << "\nSalary with bonus: " << b.getFullSalary(20) << endl;

    return 0;
}