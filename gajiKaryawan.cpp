#include<iostream>
#include<iomanip>
using namespace std;

// deklarasi struct karyawan
struct karyawan {
    string nama;
    int jamKerjaPerMinggu;
};

// fungsi untuk mencetak garis tabel
void cetakGaris(){
    cout << "+" << setfill('-') << setw(5) << "+"
         << setw(25) << "+"
         << setw(20) << "+"
         << setw(25) << "+" << setfill(' ') << endl;
}

// fungsi untuk mencetak header tabel
void cetakHeader(){
    cetakGaris();
    cout << "| " << left << setw(3)  << "No"
         << " | " << setw(22) << "Nama Karyawan"
         << " | " << setw(17) << "Jam Kerja/Minggu"
         << " | " << setw(22) << "Gaji Total Per Minggu"
         << " |" << endl;
    cetakGaris();
}

// fungsi untuk mencetak satu baris data karyawan dalam tabel
void cetakBaris(int no, string nama, int jam){
    string gaji = "Rp " + to_string(gajiTotal(jam));
    cout << "| " << left << setw(3)  << no
         << " | " << setw(22) << nama
         << " | " << setw(17) << jam
         << " | " << setw(22) << gaji
         << " |" << endl;
}

// fungsi untuk menghitung gaji total berdasarkan jam kerja per minggu
int gajiTotal(int jamKerjaPerMinggu){
    if(jamKerjaPerMinggu <= 40){
        return jamKerjaPerMinggu * 6000;
    } else {
        int gajiLembur = (jamKerjaPerMinggu - 40) * 18000;
        return (40 * 6000) + gajiLembur;
    }
}

// fungsi untuk input data karyawan
void perulanganKaryawan(karyawan employee[], int jumlahKaryawan){
    cin.ignore();
    for(int i = 0; i < jumlahKaryawan; i++){
        cout << "\n=== Input Data Karyawan ke-" << i+1 << " ===" << endl;
        cout << "Masukkan Nama Karyawan: ";
        getline(cin, employee[i].nama);

        cout << "Masukkan Jam Kerja Per Minggu: ";
        while(!(cin >> employee[i].jamKerjaPerMinggu)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Harap masukkan angka." << endl;
            cout << "Masukkan Jam Kerja Per Minggu: ";
        }
        cin.ignore();
    }
}

// fungsi untuk output semua karyawan dalam tabel
void outputTabelKaryawan(karyawan employee[], int jumlahKaryawan){
    cout << "\n========== DATA SEMUA KARYAWAN ==========" << endl;
    cetakHeader();
    for(int i = 0; i < jumlahKaryawan; i++){
        cetakBaris(i+1, employee[i].nama, employee[i].jamKerjaPerMinggu);
    }
    cetakGaris();
}

// fungsi untuk mencari karyawan berdasarkan nama
void cariByNama(karyawan employee[], int jumlahKaryawan){
    string keyword;
    cout << "\nMasukkan Nama yang dicari: ";
    getline(cin, keyword);

    bool ditemukan = false;
    cout << "\n========== HASIL PENCARIAN ==========" << endl;
    cetakHeader();
    for(int i = 0; i < jumlahKaryawan; i++){
        if(employee[i].nama == keyword){
            cetakBaris(i+1, employee[i].nama, employee[i].jamKerjaPerMinggu);
            ditemukan = true;
        }
    }
    if(!ditemukan){
        cetakGaris();
        cout << "Karyawan dengan nama \"" << keyword << "\" tidak ditemukan." << endl;
    } else {
        cetakGaris();
    }
}

// fungsi untuk mencari karyawan berdasarkan jam kerja per minggu
void cariByJamKerja(karyawan employee[], int jumlahKaryawan){
    int jam;
    cout << "\nMasukkan Jam Kerja Per Minggu yang dicari: ";
    while(!(cin >> jam)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        cout << "Masukkan Jam Kerja Per Minggu yang dicari: ";
    }

    bool ditemukan = false;
    cout << "\n========== HASIL PENCARIAN ==========" << endl;
    cetakHeader();
    for(int i = 0; i < jumlahKaryawan; i++){
        if(employee[i].jamKerjaPerMinggu == jam){
            cetakBaris(i+1, employee[i].nama, employee[i].jamKerjaPerMinggu);
            ditemukan = true;
        }
    }
    if(!ditemukan){
        cetakGaris();
        cout << "Karyawan dengan jam kerja " << jam << " tidak ditemukan." << endl;
    } else {
        cetakGaris();
    }
}

// fungsi untuk menampilkan menu pencarian
void tampilkanMenu(karyawan employee[], int jumlahKaryawan){
    int pilihan;
    do {
        cout << "\n========== MENU PENCARIAN ==========" << endl;
        cout << "1. Cari Karyawan Berdasarkan Nama" << endl;
        cout << "2. Cari Karyawan Berdasarkan Jam Kerja Per Minggu" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Menu (1-3): ";
        while(!(cin >> pilihan)){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Harap masukkan angka." << endl;
            cout << "Pilih Menu (1-3): ";
        }

        switch(pilihan){
            case 1:
                cin.ignore();
                cariByNama(employee, jumlahKaryawan);
                break;
            case 2:
                cariByJamKerja(employee, jumlahKaryawan);
                break;
            case 3:
                cout << "\nProgram selesai. Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan pilih angka 1-3." << endl;
        }
    } while(pilihan != 3);
}

// code utama yang dijalankan program
int main(){
    int jumlahKaryawan;
    cout << "Masukkan Jumlah Karyawan: ";
    while(!(cin >> jumlahKaryawan)){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harap masukkan angka." << endl;
        cout << "Masukkan Jumlah Karyawan: ";
    }

    karyawan employee[jumlahKaryawan];
    // memanggil fungsi untuk input data karyawan
    perulanganKaryawan(employee, jumlahKaryawan);
    // memanggil fungsi untuk output semua karyawan dalam tabel
    outputTabelKaryawan(employee, jumlahKaryawan);
    // memanggil fungsi untuk menu pilihan pencarian
    tampilkanMenu(employee, jumlahKaryawan);

    return 0;
}