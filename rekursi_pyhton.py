class Node:
    """Kelas Node merepresentasikan 1 elemen dalam Stack."""
    def __init__(self, data):
        self.data = data      # menyimpan nilai
        self.next = None      # menunjuk ke node berikutnya (node di bawahnya)


class Stack:
    """Kelas Stack mengelola tumpukan node dengan operasi LIFO (Last In, First Out)."""
    def __init__(self):
        self.top = None       # pointer ke node paling atas

    def is_empty(self):
        """Cek apakah stack kosong."""
        return self.top is None

    def push(self, value):
        """Tambahkan elemen ke paling atas stack."""
        new_node = Node(value)
        new_node.next = self.top   # sambungkan ke node lama
        self.top = new_node        # perbarui top ke node baru
        print(f"{value} dimasukkan ke stack.")

    def pop(self):
        """Hapus elemen paling atas dari stack."""
        if self.is_empty():
            print("Stack kosong, tidak bisa pop!")
            return
        popped_value = self.top.data
        self.top = self.top.next   # pindahkan top ke node di bawahnya
        print(f"{popped_value} dihapus dari stack.")

    def peek(self):
        """Lihat elemen teratas tanpa menghapusnya."""
        if self.is_empty():
            print("Stack kosong!")
        else:
            print(f"Elemen teratas: {self.top.data}")

    def display(self):
        """Tampilkan semua elemen dari atas ke bawah."""
        if self.is_empty():
            print("Stack kosong!")
            return
        print("Isi stack:", end=" ")
        temp = self.top
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()
        
    def clear_recursive(self):
        """Menghapus seluruh isi stack menggunakan rekursi"""
        if self.is_empty():
            print("Stack sudah kosong.")
            return
        self.pop()
        self.clear_recursive()


# Program utama
if __name__ == "__main__":
    s = Stack()

    # Tambah data ke stack
    s.push(10)
    s.push(20)
    s.push(30)

    # Lihat isi dan elemen teratas
    s.display()
    s.peek()

    # Hapus elemen teratas
    s.pop()
    s.display()
    
    s.clear_recursive()
    
    s.display()
    s.push(10)
    s.push(20)
    s.push(30)
    s.display()