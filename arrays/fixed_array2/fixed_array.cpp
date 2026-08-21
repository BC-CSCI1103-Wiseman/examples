#include <iostream>
#include <stdexcept>
#include "fixed_array.hpp"
using namespace std;

fixed_array::fixed_array(int size) {
    if (size <= 0) {
        throw invalid_argument("size must be at least 1");
    }

    capacity = size;
    data = new int[capacity];
    current_size = 0;
}

fixed_array::~fixed_array() {
    delete[] data;
}

int fixed_array::size() {
    return current_size;
}

int fixed_array::cap() {
    return capacity;
}

int& fixed_array::at(int index) {
    if (index < 0 or index >= current_size) {
        throw out_of_range("invalid index");
    }
    return data[index];
}

int& fixed_array::operator[](int index) {
    return at(index);
}

int fixed_array::find(int value) {
    for (int i = 0; i < current_size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

void fixed_array::insert(int index, int value) {
    if (current_size == capacity) {
        throw out_of_range("array is full");
    }

    for (int i = current_size-1; i >= index; i--) {
        data[i+1] = data[i];
    }

    data[index] = value;
    current_size++;
}

void fixed_array::append(int value) {
    insert(current_size, value);
}

void fixed_array::remove_index(int index) {
    if (index >= current_size) {
        throw out_of_range("invalid index");
    }

    for (int i = index; i < current_size-1; i++) {
        data[i] = data[i+1];
    }

    current_size--;
}

bool fixed_array::remove_value(int value) {
   int index = find(value);
   if (index == -1) {
       return false;
   }

   remove_index(index);
   return true;
}

ostream& operator<<(ostream& out, fixed_array& a) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ",";
        }
    }
    return out;
}

