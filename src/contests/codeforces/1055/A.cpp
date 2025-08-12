#include <iostream>
#include <vector>

using namespace std;

int main() {
    // input
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // algoritma
    if (!a[0]) { // if(a[0] == 0) {
        cout << "no" << endl;
        return 0;
    }
    if (a[0] && a[s - 1]) { // if(a[0] == 1 && b[s - 1] == 1) {
        // case stasiun di line 1. stasiun 1 dan stasiun s buka
        cout << "yes" << endl;
        return 0;
    }
    if (a[0] && b[s - 1]) { // if(a[0] == 1) {
        // case stasiun 1 buka ke line 1, stasiun s buka di line 2, cari apakah ada stasiun > s yang buka di kedua line
        for (int i = s; i < n; i++) {
            if (a[i] == 1 && b[i] == 1) {
                cout << "yes" << endl;
                return 0;
            }
        }
        cout << "no" << endl; // jika tidak ada stasiun yang buka di kedua line setelah s, output "no"
    }
    cout << "no" << endl; // jika tidak ada stasiun yang buka di kedua line setelah s, output "no"
    // output

    return 0;
}
