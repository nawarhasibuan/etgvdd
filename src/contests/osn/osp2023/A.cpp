#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    // input
    ll n, m;
    cin >> n >> m;
    vector<int> a(n);
    ll sum_a = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum_a += a[i];
    }
    /**
     * key: beratnya
     * value: banyaknya
     * (3, 5): kentang dengan berat 3 ada sebanyak 5 di b
     */
    map<ll, ll, greater<ll>> b;
    ll sum_b = 0;
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b[x] += 1;
        sum_b += x;
    }
    /**
     * sum_a jumlah berat kentang di truk a
     * sum_b jumlah berat kentang di truk b
     * n banyak kentang di truk a
     * m banyak kentang di b
     */
    ll berat_pindah = 0;
    auto it = b.begin();
    // algoritma
    while (sum_a * m <= sum_b * n && it != b.end()) {
        // pindahkan paling depan di b ke a
        ll pindah = (*it).first * (*it).second;
        berat_pindah += pindah;
        sum_a += pindah;
        sum_b -= pindah;
        n += (*it).second;
        m -= (*it).second;

        it++; // next iteration
    }
    /**
     * kondisi saat ini:
     * sum_a*m > sum_b * n
     * rata-rata di a > rata-rata di b
     * */
    // output
    if (it == b.end()) // truk b kosong
        cout << -1 << endl;
    else
        cout << berat_pindah << endl;

    return 0;
}
