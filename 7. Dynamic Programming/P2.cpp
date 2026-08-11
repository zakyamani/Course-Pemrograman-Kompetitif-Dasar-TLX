#include <bits/stdc++.h>

using namespace std;

vector <int> H(1000);
vector <int> K(1000);
vector <int> D(1000);
vector <vector<int>> memo(1000, vector<int>(10001, -1));

int dp(int i, int duit){
    if(i == -1){
        return 0;
    }
    if(duit <= 0){
        return 0;
    }
    if(memo[i][duit] != -1){
        return memo[i][duit];
    }
    if(duit < H[i]){
        memo[i][duit] = dp(i-1, duit);
    }else{
        if(D[i] == 1){
            memo[i][duit] = max(dp(i-1, duit), dp(i-1, duit-H[i]) + K[i]);
        }else{
            memo[i][duit] = max(dp(i-1, duit), dp(i, duit-H[i]) + K[i]);
        }
    }
    return memo[i][duit];
}

int main(){
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) cin >> H[i] >> K[i] >> D[i];
    cout << dp(N-1, M);
}