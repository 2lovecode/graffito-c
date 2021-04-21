#include <iostream>

using namespace std;

class Box {
    public:
        int x;
        void print();
};

void Box::print() {
    cout << "good Box" << endl;
}

int main() {
    Box b1;

    b1.x = 10;
    b1.print();

    return 0;
}