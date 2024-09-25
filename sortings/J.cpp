#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), cmp);
    for (auto x : a) {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}
