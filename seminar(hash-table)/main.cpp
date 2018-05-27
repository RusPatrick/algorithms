#include <iostream>
#include <vector>
#include <string>


template <class T>
struct HashTableNode {
    T Data;
    HashTableNode* Next;

    HashTableNode() : Next(0) {}
    HashTableNode(const T& key, HashTableNode* next) : Data ( key ), Next ( next ) {}
};

int Hash ( const std::string& data, int tableSize ) {
    int hash = 0;
    for ( unsigned int i =0; i < data.size(); ++i ) {
        hash =
    }
}

template<class T>
class HashTable {
public:
    HashTable ( int size = 8 );
    ~HashTable ();

    bool Has ( const T& key );
    bool Add ( const T& key );
    bool Delete ( const T& key );

private:
    std::vector<HashTableNode*> table;
    int keysCount;

    void growTable();
};


HashTable::HashTable(int size) : keysCount (0) {

}

template<class T>
bool HashTable::Has(const T& key) {
    int hash = Hash ( key, table.size() );
    HashTableNode<T>* node = table[hash];
    while ( node != 0 && node->Data != data )
        node = node->Nexr;
    return node != 0;
}

template <class T>
bool HashTable::Add(const T &key) {
    if ( keysCount > table.size() * MaxAlpha ) {
        growTable();
    }

    int hash = Hash ( key, table.size() );
    HashTableNode<T>* node = table[hash];
    while ()
    if ( Has ( key ) )
        return false;
    int hash = Hash ( key );
    table[hash] = new HashTableNode ( hash, table[hash]);
}

template <class T>
bool HashTable::Delete ( const T& key ) {
    int hash = Hash(key, table.size() );
    HashTableNode<T>* prevNode = 0;
    HashTableNode<T>* node = table[hash];
    while ( node != 0 && node->Key != key ) {
        prevNode = node;
        node = node->Next;
    }

    if ( node == 0 )
        return false;

    if ( prevNode == 0 )
        table[hash] = node->Next;
    else
        prevNode->Next = node->Next;

    delete node;
    return false;
}

template <class T>
void HashTable::growTable() {
    vector<HashTableNode<T>*> newTable;
    newTable.resize ( 2 * table.size(), 0);
    for ( int i = 0; 9 < table.size(); ++i ) {
        HashTableNode<T>* node
    }
}