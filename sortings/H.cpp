#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll randd(ll l, ll r) {
    return (ll) (rand() % (r - l + 1) + l);
}

ll divide(vector<ll> &a, ll l, ll r) {
    ll p = randd(l, r);
    p = a[p];
    ll l_i = l;
    ll r_i = r;
    while (l_i <= r_i) {
        while (a[l_i] < p) {
            ++l_i;
        }
        while (a[r_i] > p) {
            --r_i;
        }
        if (l_i <= r_i) {
            swap(a[l_i], a[r_i]);
            ++l_i;
            --r_i;
        }
    }
    return l_i;
}

void quick_sort(vector<ll> &a, ll l, ll r) {
    if (l < r) {
        ll p = divide(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    for (auto x : a) {
        cout << x << " ";
    }

    return 0;
}
