#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;

int main() {
	List<int> a(5, 0);
	List<int> b(5, 0);

	cout << "enter first int list: ";
	cin >> a;

	cout << "enter second int list: ";
	cin >> b;

	cout << "\na: " << a;
	cout << "\nb: " << b;

	a[2] = 100;
	cout << "\na after a[2] = 100: " << a;

	List<int> c = a + b;
	cout << "\nc = a + b: " << c;

	List<int> d = a + 10;
	cout << "\nd = a + 10: " << d;

	Pair p(1, 1.5);

	List<Pair> x(3, p);
	List<Pair> y(3, p);

	cout << "\n\nenter first pair list:" << endl;
	cin >> x;

	cout << "enter second pair list:" << endl;
	cin >> y;

	cout << "\nx: " << x;
	cout << "\ny: " << y;

	List<Pair> z = x + y;
	cout << "\nz = x + y: " << z;

	List<Pair> q = x + p;
	cout << "\nq = x + p: " << q;

	cout << endl;

	return 0;
}