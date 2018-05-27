#include <iostream>
#include <string>

using namespace std;

const int INIT_BUFFER_SIZE = 8;
const int GORNER = 127;


class HashTable {
public:
    HashTable();

    HashTable(int init_buff_size);

    ~HashTable();

    HashTable(const HashTable &other) = delete;

    HashTable(const HashTable &&other) = delete;

    HashTable &operator=(const HashTable &other) = delete;

    HashTable &operator=(HashTable &&other) = delete;


    bool Add(const string value);

    bool Has(const string value);

    bool Del(const string value);

private:
    string *buffer;
    bool *deleted_cells;

    int buffer_size;
    int size;

    int hash(const string value, int size);

    bool is_completed(int buffer_size, int size);

    void resize();
};

HashTable::HashTable() {
    buffer = new string[INIT_BUFFER_SIZE];
    deleted_cells = new bool[INIT_BUFFER_SIZE];
    for (int i = 0; i < INIT_BUFFER_SIZE; ++i) {
        buffer[i] = "";
        deleted_cells[i] = false;
    }
    buffer_size = INIT_BUFFER_SIZE;
    size = 0;
}

HashTable::HashTable(int init_buff_size) {
    buffer = new string[init_buff_size];
    deleted_cells = new bool[init_buff_size];
    for (int i = 0; i < init_buff_size; ++i) {
        buffer[i] = "";
        deleted_cells[i] = false;
    }
    buffer_size = init_buff_size;
    size = 0;
}

HashTable::~HashTable() {
    delete[] buffer;
    delete[] deleted_cells;
}

int HashTable::hash(const string value, int buffer_size) {
    int hash = 0;
    for (int i = 0; i < value.length(); i++) {
        hash = (hash * GORNER + value[i]) % buffer_size;
    }
    return hash;
}

bool HashTable::is_completed(int buffer_size, int size) {
    if (4 * size >= 3 * buffer_size)
        return true;
    return false;
}

bool HashTable::Add(const string value) {
    if (Has(value))
        return false;
    if (is_completed(buffer_size, size))
        resize();

    size++;

    int key = hash(value, buffer_size);

    int i = 1;
    while (1) {
        if (buffer[key] == "") {
            buffer[key] = value;
            deleted_cells[key] = false;
            return true;;
        }
        key = (key + i * i) % buffer_size;
        i++;
    }
}

bool HashTable::Has(const string value) {
    int key = hash(value, buffer_size);

    int i = 0;
    while (1) {
        if (buffer[key] == value)
            return true;
        if (buffer[key] == "" && deleted_cells[key] == false)
            return false;
        if (i == buffer_size)
            return false;
        key = (key + i * i) % buffer_size;
        i++;
    }
}

bool HashTable::Del(const string value) {
    if (!Has(value))
        return false;

    size--;

    int key = hash(value, buffer_size);

    int i = 0;
    while (1) {
        if (buffer[key] == value) {
            buffer[key] = "";
            deleted_cells[key] = true;
            return true;
        }
        key = (key + i * i) % buffer_size;
        i++;
    }
}

void HashTable::resize() {
    int new_buffer_size = buffer_size * 2;
    HashTable new_hash_table(new_buffer_size);

    for (int i = 0; i < buffer_size; ++i) {
        new_hash_table.Add(buffer[i]);
    }

    buffer = new string[new_buffer_size];
    deleted_cells = new bool[new_buffer_size];
    for (int i = 0; i < new_buffer_size; ++i) {
        buffer[i] = "";
        deleted_cells[i] = false;
    }

    for (int i = 0; i < new_buffer_size; ++i) {
        buffer[i] = new_hash_table.buffer[i];
        deleted_cells[i] = new_hash_table.deleted_cells[i];
    }
    buffer_size = new_buffer_size;
    size = new_hash_table.size;
}

int main() {
    char command;
    string value;

    HashTable hash_table;

    while (cin >> command >> value) {

        if (command == '+')
            if (hash_table.Add(value))
                cout << "OK" << endl;
            else
                cout << "FAIL" << endl;

        if (command == '-')
            if (hash_table.Del(value))
                cout << "OK" << endl;
            else
                cout << "FAIL" << endl;

        if (command == '?')
            if (hash_table.Has(value))
                cout << "OK" << endl;
            else
                cout << "FAIL" << endl;
    }

    return 0;
}