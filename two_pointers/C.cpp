#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        if(s.length()<t.length()){
            cout<<"NO\n";
        }else{
            ll i=s.size()-1;
            ll j=t.size()-1;
            while(i>=0 && j>=0){
                if(s[i]==t[j]){
                    --i;
                    --j;
                }else{
                    i-=2;
                }
            }
            if(j<0){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}
