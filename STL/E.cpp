#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct Pr {
    ll num;
    ll state;
};

struct Less {
    bool operator()(Pr *left, Pr *right) const {
        return left->num < right->num;
    }
};

struct Greater {
    bool operator()(Pr *left, Pr *right) const {
        return left->num > right->num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, p;
    cin >> n >> m >> p;
    ll res = 0;
    vector<Pr> a;
    a.reserve(n);
    vector<vector<Pr *>> in(p + 1);
    vector<vector<Pr *>> out(p + 1);
    for (ll i = 0; i < n; ++i) {
        ll ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        if (ai - bi > 0) {
            a.push_back({ai - bi, 0});
            in[ci].push_back(&a.back());
            out[di].push_back(&a.back());
        }
        res += bi * (di - ci);
    }
    ll sum = 0;
    ll cnt = 0;
    priority_queue<Pr *, vector<Pr *>, Less> stand;
    priority_queue<Pr *, vector<Pr *>, Greater> sit;
    for (ll ost = 1; ost <= p; ++ost) {
        for (auto x : out[ost]) {
            if (x->state == 1) {
                x->state = 0;
                sum -= x->num;
                --cnt;
            } else {
                x->state = 0;
            }
        }
        for (auto x : in[ost]) {
            stand.push(x);
            x->state = 2;
        }
        while (!stand.empty() && cnt < m) {
            auto x = stand.top();
            stand.pop();
            if (x->state != 0) {
                x->state = 1;
                sit.push(x);
                ++cnt;
                sum += x->num;
            }
        }
        while (!sit.empty() && !stand.empty() && sit.top()->num < stand.top()->num) {
            if (sit.top()->state == 0) {
                sit.pop();
                continue;
            }
            if (stand.top()->state == 0) {
                stand.pop();
                continue;
            }
            auto x1 = sit.top();
            sit.pop();
            auto x2 = stand.top();
            stand.pop();
            sum -= x1->num;
            sum += x2->num;
            sit.push(x2);
            stand.push(x1);
            x2->state = 1;
            x1->state = 2;
        }
        res += sum;
    }
    cout << res;

    return 0;
}
