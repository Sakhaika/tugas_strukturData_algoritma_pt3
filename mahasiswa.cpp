#include<iostream>
#include<iomanip>
using namespace std;
// Sakha Ibadil Kirom - 2507411064

// deklarasi struct mahasiswa
struct mahasiswa {
    string nama;
    long long nim;
    string prodi;
    int semester;
    int tahun_masuk;
    int nilaiAkhir, nilaiTugas, nilaiKuis, nilaiMid, nilaiUas;
};

// fungsi untuk input data mahasiswa
void perulanganMahasiswa(mahasiswa mhs[], int jumlahMahasiswa){
    for(int i = 0; i < jumlahMahasiswa; i++){
        cout << "\n=== Input Data Mahasiswa ke-" << i+1 << " ===" << endl;
        cin.ignore();
        cout << "Masukkan Nama Mahasiswa: "; getline(cin, mhs[i].nama);
        cout << "Masukkan NIM Mahasiswa: "; cin >> mhs[i].nim;
        cout << "Masukkan Prodi Mahasiswa: "; getline(cin >> ws, mhs[i].prodi);
        cout << "Masukkan Semester Mahasiswa: "; cin >> mhs[i].semester;
        cout << "Masukkan Tahun Masuk Mahasiswa: "; cin >> mhs[i].tahun_masuk;
        cout << "Masukkan Nilai Tugas Mahasiswa: "; cin >> mhs[i].nilaiTugas;
        cout << "Masukkan Nilai Kuis Mahasiswa: "; cin >> mhs[i].nilaiKuis;
        cout << "Masukkan Nilai Mid Mahasiswa: "; cin >> mhs[i].nilaiMid;
        cout << "Masukkan Nilai UAS Mahasiswa: "; cin >> mhs[i].nilaiUas;
        mhs[i].nilaiAkhir = (mhs[i].nilaiTugas * 0.3) + (mhs[i].nilaiKuis * 0.1) + (mhs[i].nilaiMid * 0.3) + (mhs[i].nilaiUas * 0.3);
    }
}

// fungsi untuk menentukan mutu nilai berdasarkan nilai akhir
string getMutuNilai(int nilaiAkhir){
    if(nilaiAkhir > 85)     return "A";
    else if(nilaiAkhir > 70) return "B";
    else if(nilaiAkhir > 55) return "C";
    else if(nilaiAkhir > 40) return "D";
    else                     return "E";
}

// print garis tabel
void printGaris(){
    cout << "+" << string(5,'-') << "+" << string(20,'-') << "+" << string(13,'-') << "+" << string(20,'-') 
         << "+" << string(10,'-') << "+" << string(13,'-') << "+" << string(8,'-') << "+" << string(8,'-') 
         << "+" << string(8,'-') << "+" << string(8,'-') << "+" << string(13,'-') << "+" << string(7,'-') << "+" << endl;
}

// membuat header tabel
void printHeader(){
    printGaris();
    cout << "|" << left << setw(5)  << "No"
         << "|" << left << setw(20) << "Nama"
         << "|" << left << setw(13) << "NIM"
         << "|" << left << setw(20) << "Prodi"
         << "|" << left << setw(10) << "Semester"
         << "|" << left << setw(13) << "Tahun Masuk"
         << "|" << left << setw(8)  << "Tugas"
         << "|" << left << setw(8)  << "Kuis"
         << "|" << left << setw(8)  << "Mid"
         << "|" << left << setw(8)  << "UAS"
         << "|" << left << setw(13) << "Nilai Akhir"
         << "|" << left << setw(7)  << "Mutu"
         << "|" << endl;
    printGaris();
}

// print satu baris data mahasiswa
void printBaris(mahasiswa &mhs, int no){
    cout << "|" << left << setw(5)  << no
         << "|" << left << setw(20) << mhs.nama
         << "|" << left << setw(13) << mhs.nim
         << "|" << left << setw(20) << mhs.prodi
         << "|" << left << setw(10) << mhs.semester
         << "|" << left << setw(13) << mhs.tahun_masuk
         << "|" << left << setw(8)  << mhs.nilaiTugas
         << "|" << left << setw(8)  << mhs.nilaiKuis
         << "|" << left << setw(8)  << mhs.nilaiMid
         << "|" << left << setw(8)  << mhs.nilaiUas
         << "|" << left << setw(13) << mhs.nilaiAkhir
         << "|" << left << setw(7)  << getMutuNilai(mhs.nilaiAkhir)
         << "|" << endl;
    printGaris();
}

// output semua mahasiswa dalam tabel
void outputTabelMahasiswa(mahasiswa mhs[], int jumlah){
    printHeader();
    for(int i = 0; i < jumlah; i++){
        printBaris(mhs[i], i+1);
    }
}

// output satu mahasiswa dalam tabel (untuk hasil searching)
void outputMahasiswa(mahasiswa &mhs){
    printHeader();
    printBaris(mhs, 1);
}

// menu pilihan searching
void menuPilihanSearching(mahasiswa mhs[], int jumlah){
    int pilihan;
    
    do {
        cout << "\n===== Menu Pencarian =====" << endl;
        cout << "1. Cari Berdasarkan NIM" << endl;
        cout << "2. Cari Berdasarkan Nama" << endl;
        cout << "3. Cari Berdasarkan Prodi" << endl;
        cout << "4. Cari Berdasarkan Semester" << endl;
        cout << "5. Cari Berdasarkan Tahun Masuk" << endl;
        cout << "6. Cari Berdasarkan Mutu Nilai" << endl;
        cout << "7. Keluar" << endl;
        cout << "Masukkan Pilihan: "; cin >> pilihan;

        bool found = false;
        
        mahasiswa hasil[jumlah];
        int jumlahHasil = 0;

        switch(pilihan){
            case 1: {
                long long nimCari;
                cout << "Masukkan NIM yang ingin dicari: "; cin >> nimCari;
                for(int i = 0; i < jumlah; i++){
                    if(mhs[i].nim == nimCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 2: {
                string namaCari;
                cout << "Masukkan Nama yang ingin dicari: "; getline(cin >> ws, namaCari);
                for(int i = 0; i < jumlah; i++){
                    if(mhs[i].nama == namaCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 3: {
                string prodiCari;
                cout << "Masukkan Prodi yang ingin dicari: "; getline(cin >> ws, prodiCari);
                for(int i = 0; i < jumlah; i++){
                    if(mhs[i].prodi == prodiCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 4: {
                int semesterCari;
                cout << "Masukkan Semester yang ingin dicari: "; cin >> semesterCari;
                for(int i = 0; i < jumlah; i++){
                    if(mhs[i].semester == semesterCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 5: {
                int tahunMasukCari;
                cout << "Masukkan Tahun Masuk yang ingin dicari: "; cin >> tahunMasukCari;
                for(int i = 0; i < jumlah; i++){
                    if(mhs[i].tahun_masuk == tahunMasukCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 6: {
                string mutuCari;
                cout << "Masukkan Mutu Nilai yang ingin dicari (A/B/C/D/E): "; cin >> mutuCari;
                for(int j = 0; j < mutuCari.length(); j++) mutuCari[j] = toupper(mutuCari[j]);
                for(int i = 0; i < jumlah; i++){
                    if(getMutuNilai(mhs[i].nilaiAkhir) == mutuCari){ hasil[jumlahHasil++] = mhs[i]; found = true; }
                }
                break;
            }
            case 7:
                cout << "Terima kasih, program selesai!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        // tampilkan hasil searching dalam tabel
        if(pilihan != 7){
            if(found){
                cout << "\n=== Hasil Pencarian ===" << endl;
                printHeader();
                for(int i = 0; i < jumlahHasil; i++){
                    printBaris(hasil[i], i+1);
                }
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
        }

    } while(pilihan != 7);
}

// code utama yang dijalankan program
int main(){
    int jumlahMahasiswa;

    cout << "Selamat Datang di Program Sakha Menghitung Nilai Akhir Mahasiswa" << endl;
    cout << "Berapa Mahasiswa yang ingin diinput: "; cin >> jumlahMahasiswa;

    mahasiswa mhs[jumlahMahasiswa];

    // memanggil fungsi untuk input data mahasiswa
    perulanganMahasiswa(mhs, jumlahMahasiswa);

    cout << "\n========== DATA SEMUA MAHASISWA ==========" << endl;
    // memanggil fungsi untuk output semua mahasiswa dalam tabel
    outputTabelMahasiswa(mhs, jumlahMahasiswa);

    // memanggil fungsi untuk menu pilihan searching
    menuPilihanSearching(mhs, jumlahMahasiswa);

    return 0;
}