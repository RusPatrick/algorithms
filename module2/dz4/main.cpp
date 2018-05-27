#include <iostream>
#include <stack>
#include <cstdint>


struct CNode {
    int Key;
    int Height;
    int Weight;
    CNode* Left;
    CNode* Right;

    CNode (int key);
};

CNode::CNode ( int key ) : Key(key), Height(1), Weight(1), Left(nullptr), Right(nullptr) {}

int Height ( CNode *node ) {
    return ( node == nullptr ) ? 0 : node->Height;
}

int Weight ( CNode* node ) {
    return ( node == nullptr ) ? 0 : node->Weight;
}

void FixWeight ( CNode *node ) {
    int WL = Weight ( node->Left );
    int WR = Weight ( node->Right );
    node->Weight = WR + WL + 1;
}

int BalanceFactor ( CNode *node ) {
    return Height ( node->Right ) - Height ( node->Left );
}

void FixHeight ( CNode *node ) {
    int HL = Height ( node->Left );
    int HR = Height ( node->Right );

    node->Height = ( HL > HR ) ? HL + 1 : HR + 1;
}

CNode* RotateRight ( CNode *p ) {
    CNode *new_node = p->Left;

    p->Left = new_node->Right;
    new_node->Right = p;

    FixHeight (p);
    FixWeight (p);
    FixHeight (new_node);
    FixWeight (new_node);
    return new_node;
}

CNode* RotateLeft ( CNode *p ) {
    CNode *new_node = p->Right;

    p->Right = new_node->Left;
    new_node->Left = p;

    FixHeight (p);
    FixWeight (p);
    FixHeight (new_node);
    FixWeight (new_node);
    return new_node;
}

CNode* Balance ( CNode *p ) {
    FixHeight (p);
    FixWeight (p);
    if ( BalanceFactor (p) < -1 ) {
        if ( BalanceFactor ( p->Left ) > 0) {
            p->Left = RotateLeft ( p->Left );
        }
        return RotateRight (p);
    } else if ( BalanceFactor (p) > 1) {
        if ( BalanceFactor ( p->Right ) < 0) {
            p->Right = RotateRight ( p->Right );
        }
        return RotateLeft (p);
    }

    return p;
}

CNode* Insert ( CNode *p, int key ) {
    if ( p == NULL ) {
        return new CNode (key);
    }

    if ( key < p->Key ) {
        p->Left = Insert ( p->Left, key );
    } else {
        p->Right = Insert ( p->Right, key );
    }

    return Balance (p);
}

CNode* Remove ( CNode *p, int key ) {
    if ( p == nullptr )
        return nullptr;
    if ( key == p->Key ) {
        if ( p->Right == nullptr ) {
            CNode* buf = p->Left;
            delete p;
            return buf;
        }
        CNode* min = p->Right;
        std::stack<CNode*> NodesForRebalans;
        while ( min->Left != nullptr ) {
            NodesForRebalans.push (min);
            min = min->Left;
        }
        p->Key = min->Key;
        if ( NodesForRebalans.empty () ) {
            delete min;
            p->Right = nullptr;
            return Balance (p);
        }
        CNode* buf = NodesForRebalans.top ();
        NodesForRebalans.pop ();
        buf->Left = min->Right;
        delete min;
        while ( !NodesForRebalans.empty () ) {
            Balance (buf);
            buf = NodesForRebalans.top ();
            NodesForRebalans.pop ();
        }
    }
    if ( key < p->Key ) {
        p->Left = Remove ( p->Left, key );
    } else {
        p->Right = Remove ( p->Right, key );
    }

    return Balance (p);
}

void Delete ( CNode *node ) {
    if (!node) return;

    Delete ( node->Left );
    Delete ( node->Right );

    delete node;
}

int kStat ( CNode *node, int position ) {
    int leftWeight= 0;
    int rightWeight = 0;
    if ( node->Left != 0 )
        leftWeight = node->Left->Weight;
    if ( node->Right != 0 )
        rightWeight = node->Right->Weight;
    if ( position + 1 == node->Weight - rightWeight )
        return node->Key;
    else if ( node->Left != 0 && node->Left->Weight > position ) {
        return kStat ( node->Left, position );
    }
    else if ( node->Right != 0 ) {
        return kStat ( node->Right, position - leftWeight - 1 );
    }
    else
        return 0;
}

int main () {
    CNode* root = 0;
    int n = 0;
    std::cin >> n;
    for ( int i = 0; i < n; ++i ) {
        int value = 0;
        int position = 0;
        std::cin >> value;
        std::cin >> position;
        if ( value >= 0 ) {
            root = Insert ( root, value );
        } else {
            root = Remove ( root, -value );
        }
        std::cout << kStat ( root, position ) << " ";
    }

    Delete (root);

    return 0;
}
