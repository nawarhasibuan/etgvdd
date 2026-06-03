/**
 * Diberikan sebuah string, tugasmu adalah mengatur ulang huruf-hurufnya sehingga menjadi palindrom
(yaitu, dibaca sama dari depan maupun belakang). Masukan Satu baris masukan berisi sebuah string
dengan panjang n n yang terdiri dari karakter A–Z.

Keluaran
Cetak sebuah palindrom yang terdiri dari karakter-karakter string asli. Kamu boleh mencetak solusi
apa saja yang valid. Jika tidak ada solusi, cetak "NO SOLUTION".
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> cntr(26, 0);
    for (char c : s) {
        cntr[c - 'A']++;
    }
    // cek apakah valid jadi palindrom

    int i = 0;
    int odd_idx = -1;
    while (i < 26) {
        if (cntr[i] % 2 == 0) {
            if (odd_idx >= 0) {
                cout << "NO SOLUTION";
                return 0;
            }
            odd_idx = i;
        }
        i++;
    }
    // bentuk string palindrom
    if (odd_idx >= 0) {
        s[odd_idx] = odd_idx + 'A';
    }
    int i = 0;
    for (int j = 0; j < cntr.size(); j++) {
        for (int k = 0; k < cntr[j] / 2; k++) {
            s[i] = 'A' + j;
            s[s.length() - i] = 'A' + j;
            i++;
        }
    }
    cout << s << endl;

    return 0;
}