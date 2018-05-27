#include <iostream>

template <typename DataType, typename KeyType = DataType>
class AVL{
public:
    AVL();
    ~AVL();

    void insert(KeyType key, DataType data);
    bool remove(KeyType key);
    void clear();

    DataType* find(KeyType key);
    void print() const;
    DataType kStat(int k) const;

    void insert(DataType key);

private:
    struct Node{
        Node(KeyType key, DataType data, Node * father);

        void fix();

        int bfactor() const;

        KeyType key;

        int height;
        int leftSize;
        int rightSize;

        DataType data;

        Node* father;
        Node* left;
        Node* right;
    };

    void clearRec(Node * node);
    void balance(Node * node);
    void rotateRight(Node * node);
    void rotateLeft(Node * node);
    void deleteNode(Node * & node);
    void printRec(Node * node, int depth) const;

    Node * root_;
};

template <typename DataType, typename KeyType>
AVL<DataType, KeyType>::AVL():
        root_(nullptr)
{}

template <typename DataType, typename KeyType>
AVL<DataType, KeyType>::~AVL(){
    clear();
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::insert(KeyType key, DataType data){
    Node * node = root_;
    Node * nodeFather = nullptr;

    while(node != nullptr){
        nodeFather = node;
        node = (node->key > key)?(node->left):(node->right);
    }

    Node * tmp = new Node(key, data, nodeFather);
    if(nodeFather == nullptr)
        root_ = tmp;
    else if(nodeFather->key > key)
        nodeFather->left = tmp;
    else
        nodeFather->right = tmp;

    node = nodeFather;
    while(node != nullptr){
        balance(node);
        node = node->father;
    }
    balance(root_);
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::clear(){
    clearRec(root_);
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::print() const{
    printRec(root_, 0);
}

template <typename DataType, typename KeyType>
bool AVL<DataType, KeyType>::remove(KeyType key){
    Node * node = root_;
    Node * nodeFather = nullptr;

    while(node->key != key && node != nullptr){
        nodeFather = node;
        node = (key < node->key)?(node->left):(node->right);
    }

    if(node == nullptr)
        return false;

    if(nodeFather == nullptr)
        deleteNode(root_);
    else if(key < nodeFather->key)
        deleteNode(nodeFather->left);
    else
        deleteNode(nodeFather->right);

    node = nodeFather;
    while(node != nullptr){
        balance(node);
        node = node->father;
    }
    balance(root_);
    return true;
}

template <typename DataType, typename KeyType>
DataType AVL<DataType, KeyType>::kStat(int k) const{
    Node * node = root_;
    while(k != node->leftSize){
        if(node->leftSize < k){
            k -= node->leftSize + 1;
            node = node->right;
        }
        else
            node = node->left;
    }
    return node->data;
}

template <typename DataType, typename KeyType>
DataType * AVL<DataType, KeyType>::find(KeyType key){
    Node * node = root_;
    while (node != nullptr && node->key != key)
        node = (key < node->key)?(node->left):(node->right);
    if(node == nullptr)
        return NULL;
    return &(node->data);
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::insert(DataType key){
    insert(key, key);
}



template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::clearRec(Node * node){
    if(node == nullptr)
        return;
    clearRec(node->left);
    clearRec(node->right);
    delete node;
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::printRec(Node * node, int depth) const{
    if(node == nullptr)
        return;
    printRec(node->right, depth + 1);
    for(int i = 0; i < depth*3; i++)
        std::cout << ' ';
    std::cout << node->data << "  F: " << node->father << "  T: " << node
         <<"  L: " << node->leftSize << "  R: "
         << node->rightSize << "  H: " << node->height << "\n";
    printRec(node->left, depth + 1);
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::balance(Node * node){
    if(node == nullptr)
        return;
    node->fix();
    if(node->bfactor() == 2){
        if(node->right->bfactor() == -1)
            rotateRight(node->right);
        rotateLeft(node);
    }
    else if(node->bfactor() == -2){
        if(node->left->bfactor() == 1)
            rotateLeft(node->left);
        rotateRight(node);
    }
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::rotateRight(Node * node){
    Node * C = node->left->right;
    Node * a = node;
    Node * b = node->left;

    b->father = a->father;
    if(b->father == nullptr)
        root_ = b;
    else if(b->father->left == a)
        b->father->left = b;
    else
        b->father->right = b;

    a->father = b;
    b->right = a;

    if(C != nullptr){
        C->father = a;
        a->left = C;
    }
    else
        a->left = nullptr;

    a->fix();
    b->fix();
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::rotateLeft(Node * node){
    Node * C = node->right->left;
    Node * b = node;
    Node * a = node->right;

    a->father = b->father;
    if(a->father == nullptr)
        root_ = a;
    else if(a->father->left == b)
        a->father->left = a;
    else
        a->father->right = a;

    b->father = a;
    a->left = b;

    if(C != nullptr){
        C->father = b;
        b->right = C;
    }
    else
        b->right = nullptr;

    b->fix();
    a->fix();
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::deleteNode(Node * & node){
    Node * nodeFather = node->father;
    Node * left = node->left;
    Node * right = node->right;
    delete node;

    if(left == nullptr){
        node = right;
        if(right != nullptr) right->father = nodeFather;
    }
    else if(right == nullptr){
        node = left;
        left->father = nodeFather;
    }
    else{
        Node * minNode = right;
        while (minNode->left != nullptr)
            minNode = minNode->left;

        if(right == minNode){
            node = minNode;
            node->father = nodeFather;
            node->left = left;
            left->father = node;
            balance(node);
        }
        else{
            node = minNode;
            node->father->left = node->right;
            if(node->right != nullptr)
                node->right->father = node->father;

            minNode = node->father;
            node->father = nodeFather;
            node->left = left;
            left->father = node;
            node->right = right;
            right->father = node;

            while(minNode != nodeFather){
                balance(minNode);
                minNode = minNode->father;
            }
        }
    }
}


template <typename DataType, typename KeyType>
AVL<DataType, KeyType>::Node::Node(KeyType key, DataType data, Node * father):
        key(key),
        data(data),
        father(father),
        left(nullptr),
        right(nullptr),
        height(1),
        rightSize(0),
        leftSize(0)
{}

template <typename DataType, typename KeyType>
int AVL<DataType, KeyType>::Node::bfactor() const{
    return ((right == nullptr)?(0):(right->height)) -
           ((left == nullptr)?(0):(left->height));
}

template <typename DataType, typename KeyType>
void AVL<DataType, KeyType>::Node::fix(){
    int hl = (left == nullptr)?(0):(left->height);
    int hr = (right == nullptr)?(0):(right->height);
    height = ((hl > hr)?(hl):(hr)) + 1;
    leftSize = (left == nullptr)?(0):(left->leftSize + left->rightSize + 1);
    rightSize = (right == nullptr)?(0):(right->leftSize + right->rightSize + 1);
}

int main(){
    AVL <int> avl;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int x, k;
        std::cin >> x >> k;
        if(x < 0)
            avl.remove(-x);
        else
            avl.insert(x);
        std::cout << avl.kStat(k) << ' ';
    }
}
