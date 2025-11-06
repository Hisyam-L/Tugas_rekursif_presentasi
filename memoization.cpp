#include <iostream>
using namespace std;

int memo[100]; // tempat menyimpan hasil Fibonacci

int fib(int n) {
    if (memo[n] != -1) return memo[n]; // cek apakah sudah dihitung
    if (n <= 1) return memo[n] = n;    // simpan hasil basis rekursi
    return memo[n] = fib(n - 1) + fib(n - 2); // simpan hasil ke array
}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;

    for (int i = 0; i < 100; i++) {
        memo[i] = -1;
    }

    cout << "Hasil Fibonacci ke-" << n << " adalah: " << fib(n) << endl;
    return 0;
}