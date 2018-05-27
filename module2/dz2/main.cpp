#include <iostream>
#include <stack>

template <typename T>
struct CNode {
    CNode ( T k );

    CNode* left;
    CNode* right;
    T data;
};

template <typename T>
CNode<T>::CNode ( T k ) {
    data = k;
    left = nullptr;
    right = nullptr;
}


template <class T>
class CBinaryTree {
public:
    CBinaryTree ( T key ) { root = new CNode<T>( key ); }
    ~CBinaryTree ();

    void Add ( T value );
    void traversal( void (*func)( CNode<T>* n) );
private:
    CNode<T>* root;
    void inOrder ( void (*func)( CNode<T>* node ) );
    static void deleteNode ( CNode<T>* node );
};

template <typename T>
CBinaryTree<T>::~CBinaryTree () {
    inOrder ( deleteNode );
}

template <typename T>
void CBinaryTree<T>::Add ( T value ) {
    CNode<T>* newNode = new CNode<T>(value);

    CNode<T>* current = root;

    while ( true ) {
        if ( current->data <= newNode->data ) {
            if ( current->right == NULL ) {
                current->right = newNode;
                return;
            } else {
                current = current->right;
            }
        } else {
            if ( current->left == NULL ) {
                current->left = newNode;
                return;
            } else {
                current = current->left;
            }
        }
    }
}



template <typename T>
void CBinaryTree<T>::deleteNode(CNode<T> *node) {
    delete node;
}

template <typename T>
void CBinaryTree<T>::inOrder ( void (*func)( CNode<T> *node ) ) {
    std::stack<CNode<T>*> s;
    CNode<T> *curr = root;
    while ( !s.empty() || curr != nullptr ) {
        if ( curr != nullptr ) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.top();
            s.pop();
            func(curr);
            curr = curr->right;
        }
    }
}

template <typename T>
void CBinaryTree<T>::traversal( void ( *func )(CNode<T>* n)) {
    inOrder(func);
}

int main () {
    int n;
    std::cin >> n;

    int data;
    std::cin >> data;

    CBinaryTree<int>* tree = new CBinaryTree<int>(data);

    for ( int i = 0; i < n - 1; i++ ) {
        std::cin >> data;

        tree->Add(data);
    }

    tree->traversal( [](CNode<int>* node) { std::cout << node->data << " "; } );

    delete tree;

    return 0;
}


