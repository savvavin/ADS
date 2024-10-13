#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

ll n, m;
vector<ll> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> questions(m);
    for (ll i = 0; i < m; ++i) {
        cin >> questions[i];
    }
    set<ll> st;
    map<ll, ll> m1;
    map<ll, ll> m2;
    for (ll i = 0; i < m; ++i) {
        st.insert(questions[i]);
    }
    for (auto h : a) {
        ++m1[h];
    }
    map<ll, ll> res;
    for (ll i = 0; i < n; ++i) {
        ++m2[a[i]];
        if (st.find(a[i]) != st.end()) {
            ll fp = m2[a[i]] * ((n - i - 1) - (m1[a[i]] - m2[a[i]]));
            res[a[i]] = max(res[a[i]], fp);
        }
    }
    for (ll i = 0; i < m; ++i) {
        cout << res[questions[i]] << " ";
    }

    return 0;
}
