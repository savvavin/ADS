#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MAXN = 3e4;

ll cnt[MAXN];

vector<ll> count_sort(vector<ll> &a) {
    for (auto x : a) {
        x += 1e4;
        ++cnt[x];
    }
    vector<ll> res;
    for (ll i = 0; i <= 2e4; ++i) {
        while (cnt[i]--) {
            res.push_back(i - 1e4);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto res = count_sort(a);
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}
