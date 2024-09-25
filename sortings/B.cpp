#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> insert_sort(vector<ll> &a) {
    for (ll x = 1; x < (ll) a.size(); ++x) {
        ll i = x;
        while (i > 0 && a[i] < a[i - 1]) {
            swap(a[i], a[i - 1]);
            --i;
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
    auto res = insert_sort(a);
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}
