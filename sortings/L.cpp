#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> c(26);

bool cmp(char &a, char &b) {
    return c[a - 'a'] < c[b - 'a'];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    for (ll i = 0; i < 26; ++i) {
        cin >> c[i];
    }
    vector<char> v(26);
    for (ll i = 0; i < 26; ++i) {
        v[i] = i + 'a';
    }
    vector<ll> cnt(26);
    for (ll i = 0; i < s.length(); ++i) {
        ++cnt[s[i] - 'a'];
    }
    deque<char> res;
    for (ll i = 0; i < 26; ++i) {
        while (cnt[i] > 2) {
            res.push_back(i + 'a');
            --cnt[i];
        }
        if (cnt[i] == 1) {
            res.push_back(i + 'a');
            --cnt[i];
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (ll i = 0; i < 26; ++i) {
        if (cnt[v[i] - 'a'] == 2) {
            res.push_front(v[i]);
            res.push_back(v[i]);
        }
    }
    for (auto x : res) {
        cout << x;
    }

    return 0;
}
