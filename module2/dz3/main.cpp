#include <iostream>
#include <queue>

template <typename T>
struct CNode {
    CNode ( T data );
    CNode ( T x, int y );

    int priority;
    T data;
    CNode* left;
    CNode* right;
};

template <typename T>
CNode<T>::CNode ( T data ) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template <typename T>
CNode<T>::CNode ( T x, int y ) {
    data = x;
    priority = y;
    left = nullptr;
    right = nullptr;
}

template <typename T>
class CDecTree {
public:
    CDecTree ( CNode<T>* node ) { root = node; }
    ~CDecTree ();

    void Add ( CNode<T>* newNode );
    CNode<T>* getRoot () { return root; }
private:
    CNode<T>* root;

    void Split ( CNode<T>* currNode, T key, CNode<T>*& left, CNode<T>*& right );
    CNode<T>* Merge ( CNode<T>* left, CNode<T>* right );
};

template <typename T>
CDecTree<T>::~CDecTree () {
    std::queue<CNode<T>*> q;
    q.push (root);

    while ( !q.empty() ) {
        CNode<T>* node = q.front ();
        q.pop ();

        if ( node->right != nullptr )
            q.push ( node->right );

        if ( node->left != nullptr )
            q.push ( node->left );

        delete node;
    }
}

template <typename T>
void CDecTree<T>::Add ( CNode<T>* newNode ) {
    CNode<T>* node = newNode;
    CNode<T>* sLeft = nullptr;
    CNode<T>* sRight = nullptr;
    Split ( root, node->data, sLeft, sRight );
    root = Merge ( Merge ( sLeft, node ), sRight );
}

template <typename T>
void CDecTree<T>::Split ( CNode<T>* currNode, T key, CNode<T>*& left, CNode<T>*& right ) {
    if ( currNode == nullptr ) {
        left = nullptr;
        right = nullptr;
    } else if ( key >= currNode->data ) {
        Split ( currNode->right, key, currNode->right, right );
        left = currNode;
    } else {
        Split ( currNode->left, key, left, currNode->left );
        right = currNode;
    }
}

template <typename T>
CNode<T>* CDecTree<T>::Merge ( CNode<T>* left, CNode<T>* right ) {
    if ( left == nullptr || right == nullptr ) {
        return left == nullptr ? right : left;
    } else if ( left->priority > right->priority ) {
        left->right = Merge ( left->right, right );
        return left;
    } else {
        right->left = Merge ( left, right->left );
        return right;
    }
}

template <typename T>
struct CNodeBin {
    CNodeBin ( T data );

    T data;
    CNodeBin* left;
    CNodeBin* right;
};

template <typename T>
CNodeBin<T>::CNodeBin ( T data ) {
    this->data = data;
    left = nullptr;
    right = nullptr;
}

template <typename T>
class CBinaryTree {
public:
    CBinaryTree ( CNodeBin<T>* r ) { root = r; }
    ~CBinaryTree ();

    void Add ( CNodeBin<T>* newNode );
private:
    CNodeBin<T>* root;
};

template <typename T>
CBinaryTree<T>::~CBinaryTree () {
    std::queue<CNodeBin<T>*> q;
    q.push (root);
    while ( !q.empty () ) {
        CNodeBin<T>* node = q.front ();
        q.pop ();

        if ( node->right != nullptr )
            q.push ( node->right );

        if ( node->left != nullptr )
            q.push ( node->left );

        delete node;
    }
}

template <typename T>
void CBinaryTree<T>::Add ( CNodeBin<T>* newNode ) {
    CNodeBin<T>* current = root;

    while ( true ) {
        if ( current->data <= newNode->data ) {
            if ( current->right == nullptr ) {
                current->right = newNode;
                return;
            } else {
                current = current->right;
            }
        } else {
            if ( current->left == nullptr ) {
                current->left = newNode;
                return;
            } else {
                current = current->left;
            }
        }
    }
}

template <typename T>
int depth ( CNode<T>* node )
{
    if ( node == nullptr )
        return 0;

    int left, right;

    if ( node->left != nullptr )
        left = depth ( node->left );
    else
        left = 0;

    if ( node->right != nullptr )
        right = depth ( node->right );
    else
        right = 0;

    int max = left > right ? left : right;

    return max + 1;
}

template <typename T>
int depth ( CNodeBin<T>* node )
{
    if ( node == nullptr )
        return 0;

    int left, right;

    if ( node->left != nullptr )
        left = depth ( node->left );
    else
        left = 0;

    if ( node->right != nullptr )
        right = depth ( node->right );
    else
        right = 0;

    int max = left > right ? left : right;

    return max + 1;
}

int main () {
    int n;
    std::cin >> n;

    int key;
    std::cin >> key;

    int priority;
    std::cin >> priority;

    CNode<int> *decRoot = new CNode<int>(key, priority);
    CNodeBin<int> *binRoot = new CNodeBin<int>(key);

    CDecTree<int> *treap = new CDecTree<int>(decRoot);
    CBinaryTree<int> *binTree = new CBinaryTree<int>(binRoot);

    for (int i = 0; i < n - 1; ++i) {
        std::cin >> key;
        std::cin >> priority;

        CNode<int> *new_decNode = new CNode<int>(key, priority);
        CNodeBin<int> *new_binNode = new CNodeBin<int>(key);

        treap->Add(new_decNode);
        binTree->Add(new_binNode);
    }


    int dBinT = depth(binRoot);
    int dDecT = depth(treap->getRoot());
    std::cout << dBinT - dDecT;

    delete binTree;
    delete treap;

    return 0;
}