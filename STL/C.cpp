#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

map<ll, set<ll>> sets;
map<ll, set<ll>> nums;

void add(ll e, ll s) {
    sets[s].insert(e);
    nums[e].insert(s);
}

void del(ll e, ll s) {
    sets[s].erase(e);
    nums[e].erase(s);
}

void clear(ll s) {
    for (auto x : sets[s]) {
        nums[x].erase(s);
    }
    sets[s].clear();
}

void listset(ll s) {
    if (sets[s].empty()) {
        cout << "-1";
    } else {
        for (auto x : sets[s]) {
            cout << x << " ";
        }
    }
    cout << "\n";
}

void listsetof(ll e) {
    if (nums[e].empty()) {
        cout << "-1";
    } else {
        for (auto x : nums[e]) {
            cout << x << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < k; ++i) {
        string t;
        cin >> t;
        ll e, s;
        if (t == "ADD") {
            cin >> e >> s;
            add(e, s);
        } else if (t == "DELETE") {
            cin >> e >> s;
            del(e, s);
        } else if (t == "CLEAR") {
            cin >> s;
            clear(s);
        } else if (t == "LISTSET") {
            cin >> s;
            listset(s);
        } else {
            cin >> e;
            listsetof(e);
        }
    }

    return 0;
}
