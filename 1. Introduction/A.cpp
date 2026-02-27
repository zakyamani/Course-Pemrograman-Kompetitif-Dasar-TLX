#include <bits/stdc++.h>

using namespace std;

int main(){
    int M,N;
    cin>>M>>N;
    
    int mat1[M+1][N+1];
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            cin>>mat1[i][j];
        }
    }
    
    int mat2[N+1][M+1];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            mat2[i][j] = mat1[M+1-j][i];
    }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout<<mat2[i][j]<<" ";
    }
    cout<<endl;
    }
    
}