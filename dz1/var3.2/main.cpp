#include <iostream>

class CDeque {
public:
    void pushBack ( int elem );
    int popBack ();
    void pushFront ( int elem );
    int popFront ();
    bool isEmpty();
private:
    int n;

    struct CDequeNode {
        int Data;
        CDequeNode* Next;
        CDequeNode* Prev;
    };
    CDequeNode* head;
    CDequeNode* tail;
};

int main() {

    return 0;
}