#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> select_sort(vector<ll> &a) {
    for (ll i = 0; i < (ll) a.size() - 1; ++i) {
        for (ll j = i + 1; j < (ll) a.size(); ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    return a;
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
    auto res = select_sort(a);
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}
