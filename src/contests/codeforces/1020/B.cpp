#include <bits/stdc++.h>

using namespace std;

int solve(int start, vector<int> &p);

int main() {
    // input
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        p[i] = s - 1; // convert zero base
    }

    for (int i = 0; i < n; i++) {
        cout << solve(i, p) << ' ';
    }

    return 0;
}

int solve(int start, vector<int> &p) {
    // lakukan dfs, dari start.
    vector<bool> visited(p.size(), false);
    int siswa = start;

    while (!visited[siswa]) {  // berhenti jika ditemukan siswa yang dikunjungi kedua kali
        visited[siswa] = true; // tandai sudah dikunjungi
        siswa = p[siswa];      // siswa berikutnya akan dikunjungi
    }

    // return siswa tersebut. convert to one base
    return siswa + 1;
}
