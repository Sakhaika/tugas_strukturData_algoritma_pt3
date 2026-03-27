#include <iostream>
using namespace std;

int main() {
    int bilangan[10];
    int terbesar, terkecil;
    double rata_rata = 0;
    int *ptr = bilangan;  // Pointer ke array
    
    // Input 10 bilangan integer dari keyboard menggunakan pointer
    cout << "Masukkan 10 bilangan integer:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Bilangan ke-" << (i + 1) << " : ";
        cin >> *(ptr + i);  // Mengakses array menggunakan pointer
    }
    
    // Inisialisasi nilai terbesar dan terkecil
    terbesar = *ptr;
    terkecil = *ptr;
    
    // Cari bilangan terbesar, terkecil, dan hitung rata-rata menggunakan pointer
    int jumlah = 0;
    for (int i = 0; i < 10; i++) {
        int *current = ptr + i;  // Pointer ke elemen saat ini
        
        // Cari terbesar
        if (*current > terbesar) {
            terbesar = *current;
        }
        
        // Cari terkecil
        if (*current < terkecil) {
            terkecil = *current;
        }
        
        // Akumulasi untuk rata-rata
        jumlah += *current;
    }
    
    // Hitung rata-rata
    rata_rata = (double)jumlah / 10;
    
    // Tampilkan array yang diinputkan menggunakan pointer
    cout << "\n========== HASIL ==========" << endl;
    cout << "Array yang diinputkan: ";
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i);
        if (i < 9) cout << ", ";
    }
    cout << endl;
    
    // Tampilkan hasil
    cout << "Bilangan Terbesar    : " << terbesar << endl;
    cout << "Bilangan Terkecil    : " << terkecil << endl;
    cout << "Nilai Rata-rata      : " << rata_rata << endl;
    cout << "===========================" << endl;
    
    return 0;
}