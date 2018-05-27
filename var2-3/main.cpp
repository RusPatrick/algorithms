#include <iostream>
#include <cassert>

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
    int left = 0;
    int right;

    for (int i = 0; i < m; ++i) {
        right = n - 1;
        while ( right - left > 0) {
            if ( B[i] > A[ ( right + left ) / 2] ) {
                left = ( right + left ) / 2 + 1;
            } else {
                right = ( right + left ) / 2;
            }
        }

        if (A[right] == B[i])
            std::cout << B[i] << ' ';
    }
}

int main () {
    int n = 0;
    int m = 0;


    std::cin >> n >> m;
    assert( n > m );
    

    int *A = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }
    //inpArray ( A, n );


    int *B = new int [m];
    for (int i = 0; i < m; ++i) {
        std::cin >> B[i];
    }
    //inpArray ( B, m );

    checkArrays ( A, n, B, m);


    free(A);
    free(B);
    return 0;
}
