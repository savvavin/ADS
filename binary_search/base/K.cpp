#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, a, b, w, h, l = 0, r, q, e;
    cin >> n >> a >> b >> w >> h;
    r = min(w, h);
    while (l + 1 < r){
        q = (l + r) / 2;
        e = max((w / (a + 2 * q)) * (h / (b + 2 * q)), (h / (a + 2 * q)) * (w / (b + 2 * q)));
        if (e >= n) l = q;
        else r = q;
    }
    cout << l;
    
    return 0;
}
