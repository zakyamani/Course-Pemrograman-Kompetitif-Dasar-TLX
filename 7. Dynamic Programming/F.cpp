#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
vector<ll> memo(51, -1);

ll dp(int N){
    if(N == 0){
        return 1;
    }
    if(N % 2 == 1){
        return 0;
    }
    if(memo[N] != -1){
        return memo[N];
    }
    memo[N] = 0;
    for(int i=1; i<N; i++){
        memo[N] += (dp(i-1) * dp(N-i-1));
    }
    return memo[N];
}

int main(){
    cin >> N;
    cout << dp(N);
}