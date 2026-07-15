#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main() {
    // input
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<ll> pref_b;
    pref_b.push_back(0);
    for (int i = 0; i < n; i++) {
        pref_b.push_back(pref_b[i] + b[i]);
    }

    // algoritma

    ll untung = 0;
    /**
     * keuntungan ke kiri saja
     */
    ll min_lokasi = x - k;
    ll idx_min_lok = lower_bound(a.begin(), a.end(), min_lokasi) - a.begin();
    ll idx_max_lok = upper_bound(a.begin(), a.end(), x) - a.begin();
    untung = max(untung, pref_b[idx_max_lok] - pref_b[idx_min_lok]);

    /**
     * keuntungan ke kanan saja
     */
    ll max_lokasi = x + k;
    idx_max_lok = upper_bound(a.begin(), a.end(), max_lokasi) - a.begin();
    idx_min_lok = lower_bound(a.begin(), a.end(), x) - a.begin();
    untung = max(untung, pref_b[idx_max_lok] - pref_b[idx_min_lok]);

    /**
     * keuntungan bolak balik
     * ke a[i] dahulu kemudian ke a[j] terjauh yang bisa dijangkau
     */
    ll idx_x = lower_bound(a.begin(), a.end(), x) - a.begin();
    for (ll i = 0; i < n; i++) {
        // bensin habis, a[i] tidak dapat dijangkau
        if ((k - abs(x - a[i])) <= 0) continue;
        ll j = 0;
        if (i < idx_x) { // i dikiri
            j = upper_bound(a.begin(), a.end(), k - x + 2 * a[i]) - a.begin() - 1;
            if (j > idx_x) // j harus dikanan
                untung = max(untung, pref_b[j + 1] - pref_b[i]);
        } else { // i di kanan
            j = lower_bound(a.begin(), a.end(), 2 * a[i] - x - k) - a.begin();
            if (j < idx_x) // j harus di kiri
                untung = max(untung, pref_b[i + 1] - pref_b[j]);
        }
    }

    // output
    cout << untung << endl;

    return 0;
}
