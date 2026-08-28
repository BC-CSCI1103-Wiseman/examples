using namespace std;

class node {
private:
    int datum;
    node *next;

    node(int d);

    // this allows the linked_list class to access
    // everything in the node class directly
    friend class linked_list;
};

class linked_list {
private:
    node *head;

public:
    linked_list();
    void add_to_front(int datum);
    string to_str();
};

ostream& operator<<(ostream& out, linked_list& l);
