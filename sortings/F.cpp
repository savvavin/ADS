#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<ll> merge(vector<ll> a, vector<ll> b) {
    vector<ll> res;
    ll i = 0;
    ll j = 0;
    while (i < (ll) a.size() && j < (ll) b.size()) {
        if (a[i] <= b[j]) {
            res.push_back(a[i++]);
        } else {
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

vector<ll> merge_sort(vector<ll> a) {
    if (a.size() <= 1) {
        return a;
    }
    ll mid = a.size() / 2;
    vector<ll> left = vector<ll>(a.begin(), a.begin() + mid);
    vector<ll> right = vector<ll>(a.begin() + mid, a.end());
    return merge(merge_sort(left), merge_sort(right));
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
    auto res = merge_sort(a);
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}
