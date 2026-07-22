#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s1, s2;
vector<ll> m1;
vector<ll> m2;
vector<ll> posisi;
vector<ll> memo;
int main() {
    /**
     * 1. catat posisi ayam dan bebek dua terakhir dan semua posisi yang ada hewan
     * dibaris 1 dicatat pada index 1 sampai n, index 0 kandang ayam
     * dibaris 2 dicatat pada index n + 2 sampai 2*n + 1, index n + 1 kandang bebek
     * */

    cin >> n >> s1 >> s2;
    m1.assign(n, 0);
    m2.assign(n, 0);
    for (ll i = 0; i < n; i++) cin >> m1[i];
    for (ll i = 0; i < n; i++) cin >> m2[i];

    ll a1 = -1, a2 = -1, b1 = -1, b2 = -1;
    for (ll i = 0; i < n; i++) {
        if (s1[i] == 'A') {
            a1 = i;
            posisi.push_back(i + 1);
        }
        if (s1[i] == 'B') {
            b1 = i;
            posisi.push_back(i + 1);
        }
        if (s2[i] == 'A') {
            a2 = i;
            posisi.push_back(n + i + 2);
        }
        if (s2[i] == 'B') {
            b2 = i;
            posisi.push_back(n + i + 2);
        }
    }
    /**
     * tidak ada jawaban (return -1) jika:
     * - ada bebek lebih kiri daripada ayam di baris 1, b1 < a1
     * - ada ayam lebih kiri daripada bebek di baris 2, a2 < b2
     * - ada ayam di baris 2 dan ada bebek di baris 1
     */
    if ((a1 > b1 && b1 >= 0) || (a2 < b2 && a2 >= 0) || (a2 >= 0 && b1 >= 0)) {
        cout << -1 << endl;
        return 0;
    }
    /**
     * 2. tentukan kolom yang tidak terhubung ke kanan
     * jika yang paling belakang bebek, yang tidak terhubung di kolom terakhir ayam di baris 1
     * jika yang paling belakang ayam, yang tidak terhubung di kolom terakhir bebek di baris 2
     */

    ll col = -1;
    bool is_bebek = true;
    if (max(b1, b2) > max(a1, a2))
        col = a1;
    else {
        col = b2;
        is_bebek = false;
    }
    /**
     * 3. lakukan djikstra di memo dengan bobot di m1 dan m2
     * vertex(index) i terhubung dengan i + 1 dan n + i + 1
     * vertex(index) n + i + 1 terhubung dengan i dan n + i + 2
     * disimpan di vector memo -> djikstra baris i, j ada di memo[i*n + j]
     */
    memo.assign(2 * (n + 1), LLONG_MAX);
    memo[0] = 0;     // kandang ayam
    memo[n + 1] = 0; // kandang bebek
    for (ll i = 0; i < n; i++) {
        // update jarak  ke kanan di atas (baris 1), skip col jika is_bebek
        if (i != (col + 1) || !is_bebek) memo[i + 1] = memo[i] + m1[i];
        // update jarak ke kanan di bawah (baris 2), skip col jika !is_bebek
        if (i != (col + 1) || is_bebek) memo[n + i + 2] = memo[n + i + 1] + m2[i];
        // update atas - bawah
        if (i > col) {
            // update tetangga i dan n + i + 1. cek dari yang paling terkecil setelah diupdate i dan n + i + 1
            if (memo[i + 1] < memo[n + i + 2]) {
                memo[n + i + 2] = min(memo[n + i + 2], memo[i + 1] + m2[i]);
            } else if (memo[i + 1] > memo[n + i + 2]) {
                memo[i + 1] = min(memo[i + 1], memo[n + i + 2] + m1[i]);
            }
        }
    }
    // 4. hitung total kerisihan untuk semua ayam dan bebek
    ll kerisihan = 0;
    for (auto x : posisi) {
        kerisihan += memo[x];
    }
    cout << kerisihan << endl;
}
