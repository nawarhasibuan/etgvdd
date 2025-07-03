#include <iostream>
#include <string>

using namespace std;

struct A {
    string pattern;
    int idx_next_char;
    int max_length;
};
int string_cantik(string S);
void check_pattern(A &cantik, char c);
int main() {
    string S;
    cin >> S;
    cout << string_cantik(S) << endl;

    return 0;
}
int string_cantik(string S) {
    A cantiks[6] = {{"OSN", -1, 0}, {"ONS", -1, 0}, {"SON", -1, 0}, {"SNO", -1, 0}, {"NOS", -1, 0}, {"NSO", -1, 0}};

    for (size_t i = 0; i < S.length(); i++) {
        if (S[i] == 'O' || S[i] == 'S' || S[i] == 'N') {
            for (size_t j = 0; j < 6; j++) {
                check_pattern(cantiks[j], S[i]);
            }
        }
    }
    int max = 0;
    for (size_t i = 0; i < 6; i++) {
        max = (cantiks[i].max_length > max) ? cantiks[i].max_length : max;
    }
    return max < 3 ? -1 : max;
}
void check_pattern(A &cantik, char c) {
    if (cantik.idx_next_char == -1) {
        cantik.idx_next_char = (cantik.pattern.find(c) + 1) % 3;
        cantik.max_length++;
    } else if (cantik.pattern[cantik.idx_next_char] == c) {
        cantik.idx_next_char++;
        cantik.idx_next_char %= 3;
        cantik.max_length++;
    }
}
