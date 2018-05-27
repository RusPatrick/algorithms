/*      push* и pop*.
        Формат входных данных.
        В первой строке количество команд n. n ≤ 1000000.
        Каждая команда задаётся как 2 целых числа: a b.
        a = 1 - push front
                a = 2 - pop front
                a = 3 - push back
                a = 4 - pop back
                Команды добавления элемента 1 и 3 заданы с неотрицательным параметром b.
        Для очереди используются команды 2 и 3. Для дека используются все четыре команды.
        Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.
        Формат выходных данных.
        Требуется напечатать YES - если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.
        Реализовать дек с динамическим зацикленным буфером.
 */
#include <iostream>
#include <deque>

class CDeque {
public:
    CDeque () : buffer ( nullptr ), size ( 0 ), capacity ( 0 ), head ( 0 ), tail ( 0 ) {}

    ~CDeque () {
        if ( buffer ) {
            delete[] buffer;
        }
    }

    void push_back ( int n ) {
        if ( capacity == 0 ) {
            create_deq();
        }

        if ( size == capacity ) {
            resize( capacity * mem_step );
        }

        if ( size != 0 ) {
            tail = ( tail + 1 ) % capacity;
        }
        buffer[tail] = n;
        size++;
    }

    void push_front( int n ) {
        if ( capacity == 0 ) {
            create_deq();
        }

        if ( size == capacity ) {
            resize ( capacity * mem_step );
        }

        if ( size != 0 ) {
            if ( head == 0 ) {
                head = capacity - 1;
            } else {
                head--;
            }
        }

        buffer[head] = n;
        size++;
    }

    int pop_back () {
        if ( size != 0 ) {
            int res = buffer[tail];
            size--;
            if ( size != 0 ) {
                if ( tail == 0 ) {
                    tail = capacity - 1;
                } else {
                    tail--;
                }
            }
            return res;
        }
        return -1;
    }

    int pop_front () {
        if ( size != 0 ) {
            int res = buffer[head];
            size--;
            if ( size != 0 ) {
                head = ( head + 1 ) % capacity;
            }
            return res;
        }
        return -1;
    }

    bool isEmpty () {
        if ( size == 0 )
            return true;
        return false;
    }

private:
    int *buffer;
    size_t size;
    size_t capacity;
    int head;
    int tail;

    static const size_t mem_step = 2;

    void create_deq () {
        capacity = mem_step;
        buffer = new int[capacity];
        head = capacity / 2;
        tail = head;
    }

    void resize ( const size_t new_size ) {
        if ( new_size > capacity ) {
            int *new_buf = new int[new_size];

            if ( head <= tail ) {
                std::copy ( buffer + head, buffer + tail + 1, new_buf + head );
            } else {
                std::copy ( buffer + head, buffer + capacity, new_buf + head + new_size - capacity );
                std::copy ( buffer, buffer + tail + 1, new_buf );
                head += new_size - capacity;
            }
            delete[] buffer;
            buffer = new_buf;
            capacity = new_size;
        }
    }
};



int main () {
    CDeque d;

    int num_cmd = 1;
    int cmd = 0;
    int value = 0;
    bool correct = true;

    std::cin >> num_cmd;

    for ( size_t i = 0; i < num_cmd; ++i ) {
        std::cin >> cmd >> value;

        switch ( cmd ) {
            case 1:
                d.push_front ( value );
                break;
            case 2:
                if ( value != d.pop_front() ) {
                    correct = false;
                }
                break;
            case 3:
                d.push_back ( value );
                break;
            case 4:
                if ( value != d.pop_back() ) {
                    correct = false;
                }
            default:
                break;
        }
    }

    if ( !correct ) {
        std::cout << "NO";
    }
    else {
        std::cout << "YES";
    }

    return 0;
}