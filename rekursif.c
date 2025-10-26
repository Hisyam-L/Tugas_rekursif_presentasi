#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char nama[100];
    char penyakit[100];
    struct Node *next;
};

struct Node *depanantrian, *belakangantrian, *bantu, *depanriwayat, *belakangriwayat;

void buatlist() {
    depanantrian = NULL;
    belakangantrian = NULL;
    depanriwayat = NULL;
    belakangriwayat = NULL;
}

int kosong() {
    return depanantrian == NULL;
}

void tambahpasien(char namabaru[]) {
    struct Node *nodebaru = (struct Node*) malloc(sizeof(struct Node));
    strcpy(nodebaru->nama, namabaru);
    strcpy(nodebaru->penyakit, "");
    nodebaru->next = NULL;

    if (kosong()) {
        depanantrian = nodebaru;
        belakangantrian = nodebaru;
    } else {
        belakangantrian->next = nodebaru;
        belakangantrian = nodebaru;
    }
    printf("Data Antrian Pasien Berhasil Ditambah!\n");
}

void cetakpasien1(struct Node* node, int i) {
    if (node == NULL) {
        return;
    }
    printf("%-3d| %-30s |\n", i, node->nama);
    cetakpasien1(node->next, i + 1);
}

void cetakpasien2(struct Node* node, int i) {
    if (node == NULL) {
        return;
    }
    cetakpasien2(node->next, i + 1);
    printf("%-3d| %-30s |\n", i, node->nama);
}

void layanipasien() {
    char penyakit[100];
    if (depanantrian == NULL) {
        printf("Data Antrian Pasien Kosong!\n");
        return;
    }

    bantu = depanantrian;
    depanantrian = depanantrian->next;
    bantu->next = NULL;

    printf("=== Panggil dan Layani Pasien ===\n");
    printf("Melayani Pasien atas nama %s\n", bantu->nama);
    printf("Masukkan Penyakit Pasien : ");
    getchar();
    fgets(penyakit, sizeof(penyakit), stdin);
    penyakit[strcspn(penyakit, "\n")] = 0;
    strcpy(bantu->penyakit, penyakit);

    if (depanriwayat == NULL) {
        depanriwayat = bantu;
        belakangriwayat = bantu;
    } else {
        bantu->next = depanriwayat;
        depanriwayat = bantu;
    }

    printf("Pasien dengan nama %s telah disimpan di riwayat pasien\n", bantu->nama);
}

void cetakriwayat() {
    bantu = depanriwayat;
    int i = 1;
    if (depanriwayat == NULL) {
        printf("Data Riwayat Pasien Kosong!\n");
        return;
    }
    printf("=== Tampilkan Data Riwayat Pasien ===\n");
    while (bantu != NULL) {
        printf("%-3d| %-20s | %s\n", i++, bantu->nama, bantu->penyakit);
        bantu = bantu->next;
    }
}

void rekursifhapusantrian(struct Node* node) {
    if (node == NULL) return;
    rekursifhapusantrian(node->next);
    free(node);
}

void kosongkanantrian() {
    if (depanantrian == NULL) {
        printf("Data Antrian Pasien Kosong!\n");
        return;
    }
    rekursifhapusantrian(depanantrian);
    depanantrian = NULL;
    belakangantrian = NULL;
    printf("Semua Antrian sudah Dihapus!!!\n");
}

void rekursifhapusriwayat(struct Node* node) {
    if (node == NULL) return;
    rekursifhapusriwayat(node->next);
    free(node);
}

void kosongkanriwayat() {
    if (depanriwayat == NULL) {
        printf("Data Riwayat Pasien Kosong!\n");
        return;
    }
    rekursifhapusriwayat(depanriwayat);
    depanriwayat = NULL;
    belakangriwayat = NULL;
    printf("Semua Riwayat sudah Dihapus!!!\n");
}

char tanyaKembali() {
    char jawab;
    do {
        printf("Apakah anda ingin kembali ke menu (y/n) : ");
        scanf(" %c", &jawab);
        if (jawab != 'y' && jawab != 'Y' && jawab != 'n' && jawab != 'N') {
            printf("Input tidak valid! Masukkan hanya (y/n)!\n");
        }
    } while (jawab != 'y' && jawab != 'Y' && jawab != 'n' && jawab != 'N');
    return jawab;
}

int main() {
    char nama[100];
    int pilihan;
    char kembali;
    buatlist();

    do {
        system("cls");
        printf("\n=== Program Manajemen Pasien ===\n");
        printf("1. Tambah Data Antrian Pasien\n");
        printf("2. Panggil dan Layani Pasien\n");
        printf("3. Tampilkan Data Antrian Pasien\n");
        printf("4. Tampilkan Data Antrian Pasien Terbalik\n");
        printf("5. Tampilkan Data Riwayat Pasien\n");
        printf("6. Kosongkan Data Antrian Pasien\n");
        printf("7. Kosongkan Data Riwayat Pasien\n");
        printf("8. Keluar\n");
        printf("Pilih menu: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                do {
                    system("cls");
                    getchar();
                    printf("=== Tambah Data Antrian Pasien ===\n");
                    printf("Masukkan Nama Pasien : ");
                    fgets(nama, sizeof(nama), stdin);
                    nama[strcspn(nama, "\n")] = 0;
                    tambahpasien(nama);
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 2:
                do {
                    system("cls");
                    layanipasien();
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 3:
                do {
                    system("cls");
                    if (depanantrian == NULL) {
                        printf("Data Antrian Pasien Kosong!\n");
                    } else {
                        printf("=== Tampilkan Data Antrian Pasien ===\n");
                        cetakpasien1(depanantrian, 1);
                    }
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 4:
                do {
                    system("cls");
                    if (depanantrian == NULL) {
                        printf("Data Antrian Pasien Kosong!\n");
                    } else {
                        printf("=== Tampilkan Data Antrian Pasien Terbalik ===\n");
                        cetakpasien2(depanantrian, 1);
                    }
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 5:
                do {
                    system("cls");
                    cetakriwayat();
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 6:
                do {
                    system("cls");
                    kosongkanantrian();
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 7:
                do {
                    system("cls");
                    kosongkanriwayat();
                    kembali = tanyaKembali();
                } while (kembali != 'y' && kembali != 'Y');
                break;
            case 8:
                system("cls");
                kosongkanantrian();
                kosongkanriwayat();
                printf("Terima Kasih\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 8);

    return 0;
}
