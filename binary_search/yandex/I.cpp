#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using lll = __int128;
using ld = long double;

string to_string(__int128 a) {
    string s;
    bool bo = 0;
    if (a < 0) a *= -1, s.push_back('-'), bo = 1;
    do {
        s.push_back(a % 10 + '0');
        a /= 10;
    } while (a > 0);
    for (int i = 0; i < (s.size() - bo) / 2; i++)
        swap(s[i + bo], s[s.size() - i - 1]);
    return s;
}

ll a, k, b, m, x;

bool check(lll d) {
    lll trees = 0;
    trees += (a + b) * d;
    trees -= a * (d / k);
    trees -= b * (d / m);
    return trees >= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> k >> b >> m >> x;
    lll l = -1;
    lll r = 2e18;
    while (r - l > 1) {
        lll mid = (r - l) / 2 + l;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << to_string(r);

    return 0;
}
