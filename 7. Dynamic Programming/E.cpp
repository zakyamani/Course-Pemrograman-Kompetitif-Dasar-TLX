#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo(50, vector<int>(50, -1));

int dp(string str, int L, int R){
    if(L == R){
        return 1;
    }
    if(L > R){
        return 0;
    }
    if(memo[L][R] != -1){
        return memo[L][R];
    }

    if(str[L] == str[R]){
        memo[L][R] = dp(str, L+1, R-1) + 2;
    }else{
        memo[L][R] = max(dp(str, L+1, R), dp(str, L, R-1));
    }
    return memo[L][R];
}

void reset(){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            memo[i][j] = -1;
        }
    }
}


int main(){
    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        cout << dp(str, 0, str.size()-1) << endl;
        reset();
    }
}