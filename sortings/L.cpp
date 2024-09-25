#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> w(26);

bool cmp(char &c1, char &c2) {
    if (w[c1 - 'a'] == w[c2 - 'a']) {
        return c2 > c1;
    }
    return w[c1 - 'a'] > w[c2 - 'a'];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (ll i = 0; i < 26; ++i) {
        cin >> w[i];
    }
    sort(s.begin(), s.end(), cmp);
    string t, res;
    for (ll i = 0; i < s.length() - 1; ++i) {
        if (s[i] == s[i + 1] && (t.empty() || (!t.empty() && t[t.length() - 1] != s[i]))) {
            t.push_back(s[i]);
            ++i;
        } else {
            res.push_back(s[i]);
        }
    }
    if (s.length() > res.length() + 2 * t.length()) {
        res.push_back(s[s.length() - 1]);
    }
    cout << t << res;
    for (ll i = t.length() - 1; i >= 0; --i) {
        cout << t[i];
    }

    return 0;
}
