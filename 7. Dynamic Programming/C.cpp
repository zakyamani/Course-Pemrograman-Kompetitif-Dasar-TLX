#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector <vector <ll>> memo(100, vector <ll>(100, -1));
vector <vector <ll>> ways(100, vector <ll>(100, -1));
vector <ll> cara(100,0);
ll N;
vector <ll> A;
ll MOD = 26101991;

ll solve1(ll i, ll j){
    if(i == j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    ll min = -1;
    for(int k=i; k<j; k++){
        ll temp = solve1(i,k) + solve1(k+1, j) + A[i] * A[k+1] * A[j+1];
        if((min == -1) || (min > temp)){
            min = temp;
        }
    }
    memo[i][j] = min;
    return min;
}

ll solve2(ll i, ll j){
    if(i == j){
        return 1;
    }

    if(ways[i][j] != -1){
        return ways[i][j];
    }

    ll min = 1e+18;
    for(int k=i; k<j; k++){
        ll temp = solve1(i,k) + solve1(k+1, j) + A[i] * A[k+1] * A[j+1];
        if(min > temp){
            min = temp;
            ways[i][j] = ((solve2(i,k) % MOD) * (solve2(k+1, j) % MOD)) % MOD;
        }else if(min == temp){
            ways[i][j] += (((solve2(i,k) % MOD) * (solve2(k+1, j) % MOD)) % MOD);
        }
    }
    ways[i][j] %= MOD;
    return ways[i][j];
}

ll solve3(ll N){
    if(N == 1){
        return 1;
    }

    if(cara[N] != 0){
        return cara[N] % MOD;
    }

    for(int i=1; i<N; i++){
        cara[N] += (((solve3(i) % MOD) * (solve3(N-i) % MOD)) % MOD);
    }
    cara[N] %= MOD;
    return cara[N];
}

int main(){
    cin >> N;
    for(int i=0; i<=N; i++){
        ll temp; cin >> temp;
        A.push_back(temp);
    }
    int Q; cin >> Q;
    if(Q == 1){
        cout << solve1(0,N-1);
    }else if(Q == 2){
        cout << solve2(0,N-1);
    }else{
        cout << solve3(N);
    }
}