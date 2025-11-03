def Node(nama, penyakit=""):return{"nama": nama, "penyakit": penyakit,"next":None 
}

depanAntrian = None
belakangAntrian = None
depanRiwayat = None
belakangRiwayat = None
bantu = None

def buatList():
    global depanAntrian, belakangAntrian, depanRiwayat, belakangRiwayat
    depanAntrian = belakangRiwayat = belakangAntrian = depanRiwayat = None

def cekAntrian():
    return depanAntrian is None

def cekRiwayat():
    return depanRiwayat is None

def tambahPasien():
    global depanAntrian, belakangAntrian
    print("Tambah pasien")
    nama = input("Masukan nama pasien : ")
    newNode = Node(nama)
    if cekAntrian():
        depanAntrian = belakangAntrian = newNode
    else :
        belakangAntrian["next"] = newNode
        belakangAntrian = newNode
        newNode["next"] = None
    print("Data pasien berhasil ditambah!!!!")
    
def layaniPasien():
    global depanAntrian, belakangAntrian, bantu, depanRiwayat, belakangRiwayat
    print("Fungsi layani pasien")    
    if cekAntrian():
        print("Data antrian masih kosong")
        return
    bantu = depanAntrian
    depanAntrian = depanAntrian["next"]
    bantu["next"] = None
    print(f"Sedang melayani pasien dengan nama {bantu['nama']}")
    penyakit = input("Input nama penyakit : ")
    bantu["penyakit"] = penyakit
    if cekRiwayat():
        depanRiwayat = belakangRiwayat = bantu
    else :
        bantu["next"] = depanRiwayat
        depanRiwayat = bantu
    print(f"Pasien dengan nama {depanRiwayat['nama']} telah disimpan di riwayat")

def rekursifHapusAntrian(Node):
    if Node is None:
        print("Antrian masih kosong cik") 
        return
    rekursifHapusAntrian(Node["next"])
    Node.clear()

def kosongkanAntrian(Node):
    global depanAntrian, belakangAntrian
    if cekAntrian():
        print("Antrian masih kosong cik")
        return
    rekursifHapusAntrian(Node)
    depanAntrian = None
    belakangAntrian = None
    print("Antrian sudah bersih cik hore")

def rekursifHapusRiwayat(Node):
    if Node is None:
        print("Antrian masih kosong cik") 
        return
    rekursifHapusRiwayat(Node["next"])
    Node.clear()

def kosongkanRiwayat(Node):
    if cekRiwayat():
        print("Riwayat masih kosong cik")
        return
    rekursifHapusRiwayat(Node)
    global depanRiwayat, belakangRiwayat
    depanRiwayat = None
    belakangRiwayat = None
    print("Riwayat sudah bersih cik hore")
    
def cetakRiwayat(current, i = 1):
    if current is None:
        print("Riwayat sudah kosong")
        return
    print(f"{i:<3}| {current['nama']:<20}| {current['penyakit']}")
    cetakRiwayat(current["next"],i+1)
    
def tanyaKembali():
    while True:
        jawab = input("Apakah anda ingin kembali ke menu (y/n): ").lower()
        if jawab in ('y','n'):
            return jawab
        print("Input tidak valid! Masukkan hanya (y/n)!")

def cetakPasienUrut(node, i=1):
    if node is None:
        return
    print(f"{i:<3}| {node['nama']:<30}|")
    cetakPasienUrut(node["next"], i+1)

def cetakPasienTerbalik(node, i=1):
    if node is None:
        return
    cetakPasienTerbalik(node["next"], i+1)
    print(f"{i:<3}| {node['nama']:<30}|")

def cetakriwayat():
    current = depanRiwayat
    i = 1
    while current:
        print(f"{i:<3}| {current['nama']:<20}| {current['penyakit']}")
        current = current["next"]
        i += 1

def main():
    buatList()
    while True:
        print("\n=== Program Manajemen Pasien ===")
        print("1. Tambah Data Antrian Pasien")
        print("2. Panggil dan Layani Pasien")
        print("3. Tampilkan Data Antrian Pasien (Urut)")
        print("4. Tampilkan Data Antrian Pasien (Terbalik)")
        print("5. Tampilkan Data Riwayat Pasien")
        print("6. Kosongkan Antrian Pasien")
        print("7. Kosongkan Riwayat Pasien")
        print("8. Keluar")
        
        try:
            pilihan = int(input("Pilih menu: "))
        except ValueError:
            print("Input tidak valid!")
            continue

        if pilihan == 1:
            while True:
                tambahPasien()
                if tanyaKembali() == 'y':
                    break
        elif pilihan == 2:
            while True:
                layaniPasien()
                if tanyaKembali() == 'y':
                    break
        elif pilihan == 3:
            if cekAntrian():
                print("Data Antrian Pasien Kosong!")
            else:
                print("=== Data Antrian Pasien (Urut) ===")
                cetakPasienUrut(depanAntrian)
        elif pilihan == 4:
            if cekAntrian():
                print("Data Antrian Pasien Kosong!")
            else:
                print("=== Data Antrian Pasien (Terbalik) ===")
                cetakPasienTerbalik(depanAntrian)
        elif pilihan == 5:
            if cekRiwayat():
                print("Riwayat Pasien Kosong!")
            else:
                print("=== Data Riwayat Pasien ===")
                cetakriwayat()
        elif pilihan == 6:
            if not cekAntrian():
                kosongkanAntrian(depanAntrian)
        elif pilihan == 7:
            if not cekRiwayat():
                kosongkanRiwayat(depanRiwayat)
        elif pilihan == 8:
            print("Terima kasih! Program selesai.")
            break
        else:
            print("Pilihan menu tidak valid!")

if __name__ == "__main__":
    main()