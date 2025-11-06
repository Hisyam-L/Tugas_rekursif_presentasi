
def Node(data):
    """Membuat node baru"""
    return {"data": data, "next": None}

def push(top):
    """Menambahkan data ke dalam stack"""
    data = input("Masukkan data yang akan ditambahkan: ")
    new_node = Node(data)
    new_node["next"] = top
    print(f"Data '{data}' berhasil ditambahkan ke stack.")
    return new_node


def pop(top):
    """Menghapus data teratas dari stack"""
    
    if top is None:
        print("Stack kosong, tidak bisa menghapus data.")
        return None
    print(f"Data '{top['data']}' dihapus dari stack.")
    return top["next"]


def print_stack(node):
    """Menampilkan isi stack secara rekursif"""
    if node is None:
        return
    print(node["data"])
    print_stack(node["next"])


def tampilkan_stack(top):
    """Fungsi wrapper untuk print_stack agar ada pesan pembuka"""
    if top is None:
        print("Stack kosong.")
    else:
        print("Isi stack (dari atas ke bawah):")
        print_stack(top)



def main():
    top = None

    while True:
        print("\n=== MENU STACK REKURSIF ===")
        print("1. Push data")
        print("2. Pop data")
        print("3. Tampilkan stack")
        print("4. Keluar")

        pilihan = input("Pilih menu [1-4]: ")

        if pilihan == "1":
            top = push(top)
        elif pilihan == "2":
            top = pop(top)
        elif pilihan == "3":
            tampilkan_stack(top)
        elif pilihan == "4":
            print("Program selesai.")
            break
        else:
            print("Pilihan tidak valid!")


if __name__ == "__main__":
    main()
