#include<iostream>
using namespace std;

struct mahasiswa {
    string nama;
    long long nim;
    string prodi;
    int semester;
    int tahun_masuk;
    int nilaiAkhir, nilaiTugas, nilaiKuis, nilaiMid, nilaiUas;
};

void perulanganMahasiswa(int jumlahMahasiswa){
    mahasiswa mhs;
    for(int i = 0; i < jumlahMahasiswa; i++){
        cout << "Masukkan Nama Mahasiswa: "; getline(cin, mhs.nama);
        cout << "Masukkan NIM Mahasiswa: "; cin >> mhs.nim;
        cout << "Masukkan Prodi Mahasiswa: "; getline(cin >> ws, mhs.prodi);
        cout << "Masukkan Semester Mahasiswa: "; cin >> mhs.semester;
        cout << "Masukkan Tahun Masuk Mahasiswa: "; cin >> mhs.tahun_masuk;
        cout << "Masukkan Nilai Tugas Mahasiswa: "; cin >> mhs.nilaiTugas;
        cout << "Masukkan Nilai Kuis Mahasiswa: "; cin >> mhs.nilaiKuis;
        cout << "Masukkan Nilai Mid Mahasiswa: "; cin >> mhs.nilaiMid;
        cout << "Masukkan Nilai UAS Mahasiswa: "; cin >> mhs.nilaiUas;
    }
}

// prosedur untuk input data mahasiswa
void inputMahasiswa(mahasiswa &mhs){
    cout << "\nMasukkan Nama Mahasiswa: "; getline(cin, mhs.nama);
    cout << "Masukkan NIM Mahasiswa: "; cin >> mhs.nim;
    cout << "Masukkan Prodi Mahasiswa: "; getline(cin >> ws, mhs.prodi);
    cout << "Masukkan Semester Mahasiswa: "; cin >> mhs.semester;
    cout << "Masukkan Tahun Masuk Mahasiswa: "; cin >> mhs.tahun_masuk;
    cout << "Masukkan Nilai Tugas Mahasiswa: "; cin >> mhs.nilaiTugas;
    cout << "Masukkan Nilai Kuis Mahasiswa: "; cin >> mhs.nilaiKuis;
    cout << "Masukkan Nilai Mid Mahasiswa: "; cin >> mhs.nilaiMid;
    cout << "Masukkan Nilai UAS Mahasiswa: "; cin >> mhs.nilaiUas;
}

// prosedur untuk output data mahasiswa
void outputMahasiswa(mahasiswa &mhs){
    cout << "\nNama Mahasiswa: " << mhs.nama << endl;
    cout << "NIM Mahasiswa: " << mhs.nim << endl;
    cout << "Prodi Mahasiswa: " << mhs.prodi << endl;
    cout << "Semester Mahasiswa: " << mhs.semester << endl;
    cout << "Tahun Masuk Mahasiswa: " << mhs.tahun_masuk << endl;
    cout << "Nilai Tugas Mahasiswa: " << mhs.nilaiTugas << endl;
    cout << "Nilai Kuis Mahasiswa: " << mhs.nilaiKuis << endl;
    cout << "Nilai Mid Mahasiswa: " << mhs.nilaiMid << endl;
    cout << "Nilai UAS Mahasiswa: " << mhs.nilaiUas << endl;
}

// function utuk menghitung nilai akhir mahasiswa
int hitungNilaiAkhir(mahasiswa &mhs){
    mhs.nilaiAkhir = (mhs.nilaiTugas * 0.3) + (mhs.nilaiKuis * 0.1) + (mhs.nilaiMid * 0.3) + (mhs.nilaiUas * 0.3);
    return mhs.nilaiAkhir;
}

// Menentukan nilai mutu berdasarkan nilai akhir mahasiswa
void mutuNilai(int nilaiAkhir){
    if(nilaiAkhir > 85){
        cout << "Mutu Nilai: A" << endl;
    } else if(nilaiAkhir > 70){
        cout << "Mutu Nilai: B" << endl;
    } else if(nilaiAkhir > 55){
        cout << "Mutu Nilai: C" << endl;
    } else if(nilaiAkhir > 40){
        cout << "Mutu Nilai: D" << endl;
    } else {
        cout << "Mutu Nilai: E" << endl;
    }
}

void menuPilihanSearching(mahasiswa &mhs){
    int pilihan;
    cout << "1. Cari Berdasarkan NIM" << endl;
    cout << "2. Cari Berdasarkan Nama" << endl;
    cout << "3. Cari Berdasarkan Prodi" << endl;
    cout << "4. Cari Berdasarkan Semester" << endl;
    cout << "5. Cari Berdasarkan Tahun Masuk" << endl;
    cout << "Masukkan Pilihan: "; cin >> pilihan;

    switch(pilihan){
        case 1: {
            long long nimCari;
            cout << "Masukkan NIM yang ingin dicari: "; cin >> nimCari;
            if(mhs.nim == nimCari){
                outputMahasiswa(mhs);
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        }
        case 2: {
            string namaCari;
            cout << "Masukkan Nama yang ingin dicari: "; getline(cin >> ws, namaCari);
            if(mhs.nama == namaCari){
                outputMahasiswa(mhs);
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        }
        case 3: {
            string prodiCari;
            cout << "Masukkan Prodi yang ingin dicari: "; getline(cin >> ws, prodiCari);
            if(mhs.prodi == prodiCari){
                outputMahasiswa(mhs);
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        }
        case 4: {
            int semesterCari;
            cout << "Masukkan Semester yang ingin dicari: "; cin >> semesterCari;
            if(mhs.semester == semesterCari){
                outputMahasiswa(mhs);
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        }
        case 5: {
            int tahunMasukCari;
            cout << "Masukkan Tahun Masuk yang ingin dicari: "; cin >> tahunMasukCari;
            if(mhs.tahun_masuk == tahunMasukCari){
                outputMahasiswa(mhs);
            } else {
                cout << "Data tidak ditemukan." << endl;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
    }
}

// code utama program dijalankan
int main(){
    mahasiswa mhs;
    int jumlahMahasiswa;

    cout << "Selamat Datang di Program Menghitung Nilai Akhir Mahasiswa" << endl;
    cout << "Berapa Mahasiswa yang ingin diinput? "; cin >> jumlahMahasiswa;
    perulanganMahasiswa(jumlahMahasiswa);

    // memanggil prosedur input data mahasiswa
    inputMahasiswa(mhs);
    cout << "========================" << endl;
    // memanggil prosedur output data mahasiswa
    outputMahasiswa(mhs);
    cout << "========================" << endl;
    // memanggil function untuk menghitung nilai akhir mahasiswa
    hitungNilaiAkhir(mhs);
    cout << "Nilai Akhir Mahasiswa: " << mhs.nilaiAkhir << endl;
    // memanggil prosedur untuk menentukan mutu nilai mahasiswa
    mutuNilai(mhs.nilaiAkhir);

    cout << "\n===== menu pilihan =====" << endl;
    menuPilihanSearching(mhs);
    return 0;
}