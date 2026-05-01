#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main() {
    try {
        List a(2); 
        a[0] = 10;
        a[1] = 20;
        cout << "List A: " << a;

        cout << "Adding 5 to start..." << endl;
        a = a + 5; 
        cout << "List A after addition: " << a;

        cout << "Trying to access wrong index (5)..." << endl;
        cout << a[5] << endl; 
    }
    catch (error e) {
        cout << "CAUGHT EXCEPTION: ";
        e.what();
    }
    
    return 0;
}