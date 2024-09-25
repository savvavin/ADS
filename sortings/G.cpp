#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> merge(vector<ll> a, vector<ll> b, ll &count) {
    vector<ll> res;
    ll i = 0;
    ll j = 0;
    while (i < (ll) a.size() && j < (ll) b.size()) {
        if (a[i] <= b[j]) {
            res.push_back(a[i++]);
        } else {
            count += a.size() - i;
            res.push_back(b[j++]);
        }
    }
    while (i < (ll) a.size()) {
        res.push_back(a[i++]);
    }
    while (j < (ll) b.size()) {
        res.push_back(b[j++]);
    }
    return res;
}

vector<ll> merge_sort(vector<ll> a, ll &count) {
    if (a.size() <= 1) {
        return a;
    }
    ll mid = a.size() / 2;
    vector<ll> left = vector<ll>(a.begin(), a.begin() + mid);
    vector<ll> right = vector<ll>(a.begin() + mid, a.end());
    return merge(merge_sort(left, count), merge_sort(right, count), count);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll count = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto res = merge_sort(a, count);
    cout << count;

    return 0;
}
