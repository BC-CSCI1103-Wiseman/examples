#include <iostream>
#include <stdexcept>
#include "fixed_array.hpp"
using namespace std;

int main() {
    fixed_array a(4);
    cout << "array: " << a << endl;
    a.add(7);
    a.add(-2);
    cout << "array: " << a << endl;

    try {
        cout << a[2] << endl;
    } catch (out_of_range& e) {
        cout << e.what() << endl;
    }

    a[1] = 4;
    cout << "array: " << a << endl;
    return 0;
}

