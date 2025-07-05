#include <iostream>
#include <string>

using namespace std;

struct A {
    string pattern;
    int idx_search;
    int curr_length;
    char char_search() { return pattern[idx_search]; }
    void next_idx() { idx_search = (idx_search + 1 == 3) ? 0 : idx_search + 1; }
};
int string_cantik(string S);
int main() {
    string S;
    cin >> S;
    cout << string_cantik(S) << endl;

    return 0;
}
int string_cantik(string S) {
    const int number_permutation = 6;
    A cantiks[number_permutation] = {{"OSN", 0, 0}, {"ONS", 0, 0}, {"SON", 0, 0},
                                     {"SNO", 0, 0}, {"NOS", 0, 0}, {"NSO", 0, 0}};

    int max_length = 0;
    for (size_t i = 0; i < S.length(); i++) {
        for (size_t j = 0; j < number_permutation; j++) {
            A &cantik = cantiks[j];
            if (cantik.char_search() == S[i]) {
                cantik.curr_length++;
                cantik.next_idx();
                if (cantik.curr_length > max_length) {
                    max_length = cantik.curr_length;
                }
            }
        }
    }

    return max_length < 3 ? -1 : max_length;
}
