#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo(1000, vector <int>(1000, -1));
int N;
vector <int> A;
vector <int> B;


int dp(int i, int j){
    if((i == 0) && (j == 0)){
        if(A[i] == B[i]){
            return 1;
        }else{
            return 0;
        }
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    if(A[i] == B[j]){
        if(i > 0){
            memo[i][j] = dp(i-1, j) + 1;
        }else{
            memo[i][j] = dp(i, j-1) + 1;
        }
    }else{
        if((i > 0) && (j > 0)){
            memo[i][j] = max(dp(i-1,j), dp(i,j-1));
        }else if(i > 0){
            memo[i][j] = dp(i-1, j);
        }else{
            memo[i][j] = dp(i, j-1);
        }
    }
    return memo[i][j];
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int temp; cin >> temp;
        A.push_back(temp);
    }
    for(int i=0; i<N; i++){
        int temp; cin >> temp;
        B.push_back(temp);
    }
    cout << dp(N-1, N-1);
    
}