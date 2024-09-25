#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void merge(vector<ll> &a, ll l, ll mid, ll r) {
    ll n1 = mid - l + 1;
    ll n2 = r - mid;
    vector<ll> left(n1);
    vector<ll> right(n2);
    for (ll i = 0; i < n1; ++i) {
        left[i] = a[l + i];
    }
    for (ll i = 0; i < n2; ++i) {
        right[i] = a[mid + 1 + i];
    }
    ll i = 0;
    ll j = 0;
    ll k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            ++i;
        } else {
            a[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = left[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        a[k] = right[j];
        ++j;
        ++k;
    }
}

void merge_sort(vector<ll> &a, ll l, ll r) {
    if (l < r) {
        ll mid = (r - l) / 2 + l;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
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
    merge_sort(a, 0, n - 1);
    for (auto x : a) {
        cout << x << " ";
    }

    return 0;
}
