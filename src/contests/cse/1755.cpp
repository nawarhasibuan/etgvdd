#include <bits/stdc++.h>

using namespace std;

void solve();

int main() {
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

void solve() {
    string s;
    cin >> s;
    vector<int> huruf(26, 0);
    // hitung jumlah huruf
    for (int i = 0; i < s.size(); i++) {
        huruf[s[i] - 'A']++;
    }
    // index huruf yang ganjil
    int odd_idx = -1;
    for (int i = 0; i < 26; i++) {
        if (huruf[i] % 2) {
            if (odd_idx != -1) {
                // banyak ganjil lebih dari 1
                cout << "NO SOLUTION" << endl;
                return;
            }
            odd_idx = i;
        }
    }
    // huruf ganjil taro di tengah
    if (odd_idx != -1) {
        s[s.size() / 2] = 'A' + odd_idx;
        huruf[odd_idx]--;
    }
    // index di s yang akan diisi
    int idx_s = 0;
    for (int i = 0; i < 26; i++) {
        // huruf ke - i diisi di s, sampai hurufnya habis
        // langsung isi di kiri dan kanan
        for (int j = huruf[i]; j > 0; j -= 2) {
            s[idx_s] = 'A' + i;
            s[s.size() - 1 - idx_s] = 'A' + i;
            idx_s++;
        }
    }
    cout << s << endl;
}
