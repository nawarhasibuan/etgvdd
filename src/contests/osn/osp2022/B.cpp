#include <algorithm>
#include <iostream>
#include <vector>

#define p(i) kandang[i].first
#define c(i) kandang[i].second

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    // input
    int k, n;
    cin >> k;
    // kandang.first = kapasaitas kandang
    // kandang.second = biaya per kg berat kandang
    vector<pair<int, int>> kandang(k);
    for (int i = 0; i < k; ++i) {
        cin >> kandang[i].first;
    }
    for (int i = 0; i < k; ++i) {
        cin >> kandang[i].second;
    }
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // algoritma
    // 1. sorting turun bebek berdasarkan berat
    sort(b.begin(), b.end(), [](int a, int b) { return a > b; });

    // 2. sorting kandang berdasarkan biaya per kg berat kandang
    sort(kandang.begin(), kandang.end(), cmp);

    // 3. greedy
    //    - untuk bebek paling berat, cari kandang yang paling murah
    int i = 0, j = 0;
    long long biaya = 0;
    while (i < b.size() && j < kandang.size()) {
        if (kandang[j].first > 0) {
            // bebek i bisa masuk kandang j
            // 4. biaya = berat bebek * biaya
            biaya += b[i] * kandang[j].second;
            // 5. kurangi kapasitas kandang
            kandang[j].first--;
            // pindah ke bebek selanjutnya
            i++;
        } else {
            // bebek i tidak bisa masuk kandang j, pindah ke kandang selanjutnya
            j++;
        }
    }
    // output

    cout << biaya << endl;

    return 0;
}
