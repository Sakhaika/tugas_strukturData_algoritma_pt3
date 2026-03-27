#include <iostream>
#include <string>
using namespace std;

int main() {
    string stringAsli;
    string stringDibalik;
    
    cout << "Masukkan string : ";
    getline(cin, stringAsli);
    
    // Menggunakan pointer untuk balik string
    char *ptr = (char*)stringAsli.c_str();  // Pointer ke string
    int length = stringAsli.length();
    
    // Balik dari belakang ke depan menggunakan pointer
    for (int i = length - 1; i >= 0; i--) {
        stringDibalik += *(ptr + i);  // Mengakses karakter menggunakan pointer
    }
    
    cout << "\n=============================" << endl;
    cout << "String yang di-input : " << stringAsli << endl;
    cout << "String yang dibalik  : " << stringDibalik << endl;
    cout << "=============================" << endl;
    
    return 0;
}
