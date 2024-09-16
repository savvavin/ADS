#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll can_L(string& s, ll L){
    ll cur=0;
    ll k=0;
    while(cur<s.length()) {
        while (s[cur] == '0') {
            ++cur;
        }
        if(cur>=s.length() || L==0){
            return k;
        }
        ++k;
        cur+=L;
    }
    return k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll l=0;
        ll r=s.length();
        while(r-l>1){
            ll mid=(r-l)/2+l;
            if(can_L(s, mid)<=k){
                r=mid;
            }else{
                l=mid;
            }
        }
        cout<<r<<"\n";
    }

    return 0;
}
