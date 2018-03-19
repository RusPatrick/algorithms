#include <iostream>

bool checkSame( const int *A, int a, int curnum ) {
    for ( int i = 0; i < curnum ; ++i ) {
        if ( a == A[i] ) {
            return true;
        }
    }
    return false;
}

bool checkIncrease ( const int *A, int a, int curnum ) {
    for ( int i = 0; i < curnum; ++i ) {
        if (a < A[i]) {
            return true;
        }
    }
    return false;
}

void inpArray ( int *A, int n ) {
    for ( int i = 0; i < n; ++i ) {
        std::cin >> A[i];
        int j = 0;
        if ( checkSame( A, A[i], i) )
            i--;
        if ( checkIncrease( A, A[i], i ) )
            i--;
    }
}

void checkArrays ( const int *A, const int n, const int *B, const int m ) {
    int curval = 0;
    for ( int i = 0; i < m; ++i ) {
        int j = curval;
        while ( B[i] != A[j] && j < n) {
            j++;
        }
        if ( B[i] == A[j] ) {
            std::cout << B[i] << ' ';
            curval = j;
        }
    }
}

int main () {
    int n = 0;
    int m = 0;

    do {
        std::cin >> n >> m;
        if ( n < m ) {
            std::cout << "repeat\n";
        }
    } while ( n < m );

    int *A = new int[n];
    inpArray ( A, n );


    int *B = new int [m];
    inpArray ( B, m );

    checkArrays ( A, n, B, m);


    free(A);
    free(B);
    return 0;
}