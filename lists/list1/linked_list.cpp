#include <iostream>
#include <string>
#include "linked_list.hpp"
using namespace std;

node::node(int d) {
    datum = d;
    next = NULL;
}

linked_list::linked_list() {
    head = NULL;
}

void linked_list::add_to_front(int datum) {
    // make the new node
    node *new_node = new node(datum);

    // case: empty list
    if (head == NULL) {
        new_node->next = NULL;
        head = new_node;
    }
    
    // case: non-empty list
    else {
        new_node->next = head;
        head = new_node;
    }
}

string linked_list::to_str() {
    string s = "";
    
    // start at the beginning of the list
    node *tmp = head;

    // keep looping until we find the end of the list
    while (tmp != NULL) {
        s += to_string(tmp->datum) + ",";

        // move to the next node in the list
        tmp = tmp->next;
    }

    // remove the trailing comma if present
    if (s != "") {
        s.pop_back();
    }
    return s;
}

ostream& operator<<(ostream& out, linked_list& l) {
    out << l.to_str();
    return out;
}
