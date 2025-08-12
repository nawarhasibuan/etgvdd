#include <iostream>
#include <string>
#include <vector>

using namespace std;
void solution();
int score(vector<int> &bob_alice) {
    int sum = 0;
    int n = bob_alice.size();
    for (int i = 0; i < n; i++) {
        sum += bob_alice[i] * (n - i);
    }
    return sum;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solution();
    }

    return 0;
}

void solution() { // input
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> bob_alice;
    // algoritma
    for (int i = n - 1; i > 0 && score(bob_alice) < k; i--) {
        if (s[i] == '1') {
            bob_alice.push_back(1);
        } else {
            // hitung nol berurutan
            // hitung 1 berurutan berikutnya
            // selisihnya pushback ke bob_alice
            int count_zeros = 0; // nol di tengah
            for (int j = i; j >= 0 && s[j] == '0'; j--) {
                i--;
                count_zeros++;
            }
            int count_ones = 0;
            for (int j = i; j >= 0 && s[j] == '1' && count_zeros - count_ones > 1; j--) {
                i--;
                count_ones++;
            }
            bob_alice.push_back(count_zeros - count_ones);
        }
    }

    // output
    if (score(bob_alice) < k) {
        cout << -1 << endl;
    } else {
        cout << "selisih ikan per kelompok: ";
        for (int i = 0; i < bob_alice.size(); i++) {
            cout << bob_alice[i] << " ";
        }
        cout << endl;
        int mod = 1e9 + 7; // 7*10^9
        mod = min(n, k);

        cout << "k:" << k << "; skor: " << score(bob_alice) << endl;
    }
}

int solve(int x, const vector<int> &koin) {
    vector<int> solusi(x + 1, 1e9);
    solusi[0] = 0; // tidak perlu koin untuk 0
    for (int i = 0; i < x; i++) {
        for (size_t j = 0; j < koin.size(); i++) {
            if (x >= koin[j]) {
                solusi[i] = min(solusi[i], 1 + solusi[i - koin[j]]);
            }
        }
    }
    return solusi[x];
}
/*
{
    {1, 2, 5, 10, 20, 50, 100, 200}; // pecahan koin
    pecahan koin tersedia = {1, 7, 23} akan menukarkan jumlah uang = 20 + 23 = 43;
greedy:
    23 + 7 * 2 + 1 * 6 = 9

        jumlah_koin minimal;
    7 * 6 + 1 = 7
}

43 = 23 + 20;
43 = 43

    p(0) = 0;
p(x) = tak hingga;
jika koin tersedia > x p(koin[i]) = 1;

p(4) = min(p(3) + 1; p(4)) = p(3) + 1;
= 2

    p(8) = min(p(7) + 1; p(1) + 1) = p(7) + 1;

p(7) = min(p(6) + 1; p(0) + 1) = p(0) + 1;

p(x) = minimum banyak koin yang digunakan untuk menukar x

    jika koin[i] dipakai pertama;
sisa akan ditukar x - koin[i];

p(x) = min(p(x - koin[i]) + 1, p(x) tanpa koin[i])
*/
