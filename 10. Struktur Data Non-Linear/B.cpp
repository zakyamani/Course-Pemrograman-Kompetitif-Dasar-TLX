#include <bits/stdc++.h>
#define ll long long

using namespace std;

priority_queue<ll> nilai;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll Q; cin >> Q;
    while(Q--){
        ll num; cin >> num;
        if(num == 1){
            ll x; cin >> x;
            nilai.push(x);
        }else if(num == 2){
            cout << nilai.top() << endl;
        }else{
            nilai.pop();
        }
    }
}