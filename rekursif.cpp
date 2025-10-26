#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
    string nama;
    string penyakit;
    Node *next;

    Node( string namabaru)
    {
        nama = namabaru;
    }
};

Node *depanantrian, *belakangantrian, *bantu, *depanriwayat, *belakangriwayat;

void buatlist()
{
    depanantrian = NULL;
    belakangantrian = NULL;
    depanriwayat = NULL;
    belakangriwayat = NULL;
}

bool antriankosong()
{
    return depanantrian == NULL;
}

bool riwayatkosong()
{
    return depanriwayat == NULL;
}

void tambahpasien(string namabaru){
    Node *nodebaru = new Node(namabaru);
    nodebaru->penyakit = "";
    nodebaru->next = NULL;

    if (antriankosong())
    {
        depanantrian = nodebaru;
        belakangantrian = nodebaru;
        cout << "Data Antrian Pasien Berhasil Ditambah!" << endl;
    }else{
        belakangantrian->next = nodebaru;
        belakangantrian = nodebaru;
        nodebaru->next = NULL;
        cout << "Data Antrian Pasien Berhasil Ditambah!" << endl;
    }
}

void cetakpasien1(Node* node, int i = 1){
    if(node == nullptr){
        return;
    }
    cout << left << setw(3) << i << "| " << setw(30) << node->nama << " | " << endl;
    cetakpasien1(node->next, i+1);
}

void cetakpasien2(Node* node, int i = 1){
    if(node == nullptr){
        return;
    }
    cetakpasien2(node->next, i+1);
    cout << left << setw(3) << i << "| " << setw(30) << node->nama << " | " << endl;
}

void layanipasien(){
    string penyakit;
    if(antriankosong()){
        cout << "Data Antrian Pasien Kosong!" << endl;
        return;
    }

    bantu = depanantrian;
    depanantrian = depanantrian->next;
    bantu->next = NULL;

    cout << "=== Panggil dan Layani Pasien ===\n";
    cout << "Melayani Pasien atas nama " << bantu->nama << endl;
    cout << "Masukkan Penyakit Pasien : " ;
    cin.ignore();
    getline(cin, penyakit);
    bantu->penyakit = penyakit;

    if (riwayatkosong()){
        depanriwayat = bantu;
        belakangriwayat = bantu;
    }else{
        bantu->next = depanriwayat;
        depanriwayat = bantu;
    }

    cout << "Pasien Dengan nama " << depanriwayat->nama << " Telah disimpan di riwayat pasien" << endl;
}

void cetakriwayat(){
    bantu = depanriwayat;
    int i = 1;
    if(riwayatkosong()){
        cout << "Data Riwayat Pasien Kosong!" << endl;
        return;
    }
    cout << "=== Tampilkan Data Riwayat Pasien ===\n";
    while (bantu != NULL)
    {
        cout << left << setw(3) << i++ << "| " << setw(20) << bantu->nama << " | " << bantu->penyakit << endl;
        bantu = bantu->next;
    }
}

void rekursifhapusantrian(Node* node){
    if(node == nullptr){
        return;
    }
    rekursifhapusantrian(node->next);
    delete node;
}

void kosongkanantrian(){
    if(antriankosong()){
        cout << "Data Antrian Pasien Kosong!" << endl;
        return;
    }
    rekursifhapusantrian(depanantrian);
    depanantrian = nullptr;
    belakangantrian = nullptr;
    cout << "Semua Antrian sudah Dihapus!!!" << endl;
}

void rekursifhapusriwayat(Node* node){
    if(node == nullptr){
        return;
    }
    rekursifhapusriwayat(node->next);
    delete node;

}

void kosongkanriwayat(){
    if(riwayatkosong()){
        cout << "Data Riwayat Pasien Kosong!" << endl;
        return;
    }
    rekursifhapusriwayat(depanriwayat);
    depanriwayat = nullptr;
    belakangriwayat = nullptr;
    cout << "Semua Riwayat sudah Dihapus!!!" << endl;
}

char tanyaKembali() {
    char jawab;
    do {
        cout << "Apakah anda ingin kembali ke menu (y/n) : ";
        cin >> jawab;
        if (jawab != 'y' && jawab != 'Y' && jawab != 'n' && jawab != 'N') {
            cout << "Input tidak valid! Masukkan hanya (y/n)!" << endl;
        }
    } while (jawab != 'y' && jawab != 'Y' && jawab != 'n' && jawab != 'N');
    return jawab;
}

int main()
{
    string nama;
    int pilihan;
    char kembali;
    buatlist();

    do
    {
        system("cls");
        cout << "\n=== Program Manajemen Pasien ===\n";
        cout << "1. Tambah Data Antrian Pasien\n";
        cout << "2. Panggil dan Layani Pasien\n";
        cout << "3. Tampilkan Data Antrian Pasien\n";
        cout << "4. Tampilkan Data Antrian Pasien Terbalik\n"; 
        cout << "5. Tampilkan Data Riwayat Pasien\n";
        cout << "6. Kosongkan Data Antrian Pasien\n";
        cout << "7. Kosongkan Data Riwayat Pasien\n";
        cout << "8. Keluar\n";
        cout << "Pilih menu: ";
        while (!(cin >> pilihan)) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Input tidak valid!" << endl;
            cout << "Masukkan angka untuk Menu : ";
        }
        switch (pilihan)
        {
        case 1:
            do
            {
                system("cls");
                cin.ignore();
                cout << "=== Tambah Data Antrian Pasien ===\n";
                cout << "Masukkan Nama Pasien : ";
                getline(cin, nama);
                tambahpasien(nama);
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 2:
            do
            {
                system("cls");
                layanipasien();
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 3:
            do
            {
                system("cls");
                if(antriankosong()){
                    cout << "Data Antrian Pasien Kosong!" << endl;

                }else{
                    cout << "=== Tampilkan Data Antrian Pasien ===\n";
                    cetakpasien1(depanantrian);
                }
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 4:
            do
            {
                system("cls");
                if(antriankosong()){
                    cout << "Data Antrian Pasien Kosong!" << endl;

                }else{
                    cout << "=== Tampilkan Data Antrian Pasien Terbalik===\n";
                    cetakpasien2(depanantrian);
                }
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 5:
            do
            {
                system("cls");
                cetakriwayat();
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 6:
            do
            {
                system("cls");
                kosongkanantrian();
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 7:
            do
            {
                system("cls");
                kosongkanriwayat();
                kembali = tanyaKembali();
            } while (kembali != 'y' && kembali != 'Y');
            break;
        case 8:
            system("cls");
            kosongkanantrian();
            kosongkanriwayat();
            cout << "Terima Kasih" << endl;
            break;
        default:
            break;
        }
    } while (pilihan != 8);
}