#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll CNT1[80];
ll CNT2[80];

bool is_eq() {
    bool flg = true;
    for (int i = 0; i < 80; ++i) {
        if (CNT1[i] != CNT2[i]) {
            flg = false;
            break;
        }
    }
    return flg;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    for (auto c : s1) {
        ++CNT1[c-'0'];
    }
    for (auto c : s2) {
        ++CNT2[c - '0'];
    }
    if (is_eq()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
