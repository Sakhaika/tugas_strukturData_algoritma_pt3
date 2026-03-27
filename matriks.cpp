#include <iostream>
using namespace std;

int main() {
    int A[3][4]={1, 3, 2, 4, 5, 7, 6, 8, 9,11, 12 };
    int B[3][3]={{1, 2}, {3, 4, 5} ,{ 7 }};
    cout << "Matriks A: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matriks B: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}