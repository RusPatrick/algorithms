#include <iostream>


void first_indexes (size_t n, int *A, size_t &a, int *B, size_t &b, int maxA, int maxB ) {
    for ( size_t i = 0; i < n; ++ i ) {
        for ( size_t j = i; j < n; ++j ) {
            if ( A[i] + B[j] == maxA + maxB ) {
                a = i;
                b = j;
                return;
            }
        }
    }
}

int main() {

    int n = 0;
    std::cin >> n;

    int maxA = 0;
    size_t num_maxA = 0;
    int maxB = 0;


    int *A = new int[n];
    for ( size_t i = 0; i < n; ++i ) {
        std::cin >> A[i];
        if ( i == 0 )
            maxA = A[i];
        if ( A[i] > maxA ) {
            maxA = A[i];
            num_maxA = i;
        }
    }


    int *B = new int[n];
    for ( size_t i = 0; i < n; ++i ) {
        std::cin >> B[i];
        if ( i >= num_maxA) {
            if ( i == num_maxA )
                maxB = B[i];
            if ( B[i] > maxB )
                maxB = B[i];
        }
    }

    size_t iA = 0;
    size_t jB = 0;

    first_indexes(n, A, iA, B, jB, maxA, maxB);
    std::cout << iA << ' ' << jB;

    free(A);
    free(B);
    return 0;
}