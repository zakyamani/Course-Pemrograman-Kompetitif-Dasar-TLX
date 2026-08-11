#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <vector<ll>> memo(1001, vector<ll>(1001, -1));
const ll MOD = 1000000;

ll combin(ll n, ll k){
    if(memo[n][k] != -1){
        return memo[n][k];
    }
    if((n == k) || (k == 0)){
        memo[n][k] = 1;
    }else{
        memo[n][k] = (combin(n-1, k-1) + combin(n-1, k)) % MOD;
    }
    return memo[n][k];
}

int main(){
    ll N; cin >> N;
    ll total = 0;
    for(int i=0; i<=N; i+=3){
        total += combin(N - (i/3) * 2, i/3);
        total %= MOD;
    }
    cout << total;

}