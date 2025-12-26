#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;

// หาค่ากำลังสองของ 2 ที่ >= n
int nextPowerOfTwo(int n) {
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

// matrix r x c = 0
Matrix makeMatrix(int r, int c) {
    return Matrix(r, vector<ll>(c, 0));
}

// + mat n x n
Matrix addSquare(const Matrix &A, const Matrix &B) {
    int n = (int)A.size();
    Matrix C = makeMatrix(n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// - mat n x n
Matrix subSquare(const Matrix &A, const Matrix &B) {
    int n = (int)A.size();
    Matrix C = makeMatrix(n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen n x n (n เป็น 2^k)
Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = (int)A.size();
    Matrix C = makeMatrix(n, n);

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;

    Matrix A11 = makeMatrix(k, k), A12 = makeMatrix(k, k);
    Matrix A21 = makeMatrix(k, k), A22 = makeMatrix(k, k);
    Matrix B11 = makeMatrix(k, k), B12 = makeMatrix(k, k);
    Matrix B21 = makeMatrix(k, k), B22 = makeMatrix(k, k);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    Matrix M1 = strassen(addSquare(A11, A22), addSquare(B11, B22));
    Matrix M2 = strassen(addSquare(A21, A22), B11);
    Matrix M3 = strassen(A11, subSquare(B12, B22));
    Matrix M4 = strassen(A22, subSquare(B21, B11));
    Matrix M5 = strassen(addSquare(A11, A12), B22);
    Matrix M6 = strassen(subSquare(A21, A11), addSquare(B11, B12));
    Matrix M7 = strassen(subSquare(A12, A22), addSquare(B21, B22));

    Matrix C11 = addSquare(subSquare(addSquare(M1, M4), M5), M7);
    Matrix C12 = addSquare(M3, M5);
    Matrix C21 = addSquare(M2, M4);
    Matrix C22 = addSquare(subSquare(addSquare(M1, M3), M2), M6);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j]       = C11[i][j];
            C[i][j + k]   = C12[i][j];
            C[i + k][j]   = C21[i][j];
            C[i + k][j+k] = C22[i][j];
        }
    }

    return C;
}

// wrapper: รับเมทริกซ์ W (a x b), X (c x d) แล้วคูณด้วย Strassen (padding)
Matrix multiplyStrassenRect(const Matrix &W, const Matrix &X) {
    int a = (int)W.size();
    int b = (int)W[0].size();
    int c = (int)X.size();
    int d = (int)X[0].size();

    // สมมติว่า b == c แล้ว (เช็คใน main)
    int n = nextPowerOfTwo(a);
    if (n < b) n = nextPowerOfTwo(b);
    if (n < d) n = nextPowerOfTwo(d);

    Matrix A_pad = makeMatrix(n, n);
    Matrix B_pad = makeMatrix(n, n);

    // W -> A_pad
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            A_pad[i][j] = W[i][j];

    // X -> B_pad
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            B_pad[i][j] = X[i][j];

    Matrix C_pad = strassen(A_pad, B_pad);

    // ตัดเหลือ a x d
    Matrix C = makeMatrix(a, d);
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < d; ++j)
            C[i][j] = C_pad[i][j];

    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    if (!(cin >> a >> b >> c >> d)) return 0;

    if (b != c) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    Matrix W = makeMatrix(a, b);
    Matrix X = makeMatrix(c, d);

    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            cin >> W[i][j];

    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            cin >> X[i][j];

    Matrix Y = multiplyStrassenRect(W, X);  // a x d size

    // คัดกรองผู้ป่วย: col 1 คน (= d คน)
    for (int col = 0; col < d; ++col) {
        ll sum = 0;
        for (int row = 0; row < a; ++row)
            sum += Y[row][col];

        double avg = (double)sum / (double)a;
        double yi = avg;

        if (yi > 0.0)
            cout << "y[" << col << "] is positive\n";
        else
            cout << "y[" << col << "] is negative\n";
    }

    return 0;
}
