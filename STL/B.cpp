#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ll x = 0;
        for (ll j = 0; j < 2000; ++j) {
            x += max(1000 - ai - j, 1LL);
            a.push_back({x, i});
        }
    }
    sort(a.begin(), a.end());
    ll t = 0;
    ll ind = 0;
    for (auto x : a) {
        if (abs(ind - x.second) > x.first - t) {
            cout << x.first;
            return 0;
        }
        t = x.first;
        ind = x.second;
    }

    return 0;
}
