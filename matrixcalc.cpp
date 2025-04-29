#include <bits/stdc++.h>
using namespace std;

const int mxn = 100;
int a[mxn][mxn];
int b[mxn][mxn];
int sum[mxn][mxn];

int main() {
    int r1, c1, r2, c2;
    cout << "Enter the size of row and column of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter the size of row and column of matrix B: ";
    cin >> r2 >> c2;

    if (r1 != r2 || c1 != c2) {
        cout << "Error: Matrices must have the same dimensions for addition." << endl;
        return 1;
    }

    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "A [" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "B [" << i << "][" << j << "] = ";
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            sum[i][j] = a[i][j] - b[i][j];
        }
    }
    cout << "Matrix A:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix B:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The summation of matrix A and B:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}






// ................... Matrix Multiplication...............// 
/*#include <bits/stdc++.h>
using namespace std;
const int mxn = 100;
int a[mxn][mxn];
int b[mxn][mxn];
int result[mxn][mxn];
int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and column for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and column for second matrix: ";
    cin >> r2 >> c2;

    // Ensure matrix multiplication condition
    if (c1 != r2) {
        cout << "Error! The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    // Taking input for the first matrix
    cout << "Enter the values of the first matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "A [" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Taking input for the second matrix
    cout << "Enter the values of the second matrix:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "B [" << i << "][" << j << "] = ";
            cin >> b[i][j];
        }
    }

    // Multiplying the matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Printing the first matrix
    cout << "Matrix A:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the second matrix
    cout << "Matrix B:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the result matrix
    cout << "Result Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}*/
