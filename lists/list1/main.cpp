#include <iostream>
#include "linked_list.hpp"
using namespace std;

int main() {
    linked_list list;
    list.add_to_front(1);
    cout << list << endl;

    list.add_to_front(2);
    list.add_to_front(3);
    cout << list << endl;
    return 0;
}
