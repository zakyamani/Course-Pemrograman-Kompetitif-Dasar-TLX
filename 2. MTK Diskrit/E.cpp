#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MOD = 1000000007;


int main(){
    ll N, A ,B;
    cin >> N >> A >> B;

    ll combin[N+1][N+1];
    for(ll i=0; i<=N; i++){
        combin[i][0] = 1;
    }
    for(ll i=0; i<=N; i++){
        combin[i][i] = 1;
    }
    for(ll i=2; i<=N; i++){
        for(ll j=1; j<i; j++){
            combin[i][j] = ((combin[i-1][j] % MOD) + (combin[i-1][j-1] % MOD)) % MOD;
        }
    }
    ll total = 0;
    for(ll i=A; i<=B; i++){
        total = (total + combin[N][i]) % MOD;
    }

    cout << total;


}