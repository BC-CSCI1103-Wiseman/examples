using namespace std;

class fixed_array {
private:
    int *data;
    int capacity;
    int current_size;

public:
    fixed_array(int size);
    ~fixed_array();

    int size();
    int cap();

    int& at(int index);
    int& operator[](int index);
    void add(int value);
};

ostream& operator<<(ostream& out, fixed_array& a);

