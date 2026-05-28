#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, K;
    cin >> N >> K;
    ll W[K], H[K];
    for(int i=0; i<K; i++){
        cin >> W[i] >> H[i];
    }

    bool statusBatu[N+1][K];
    ll totHarga[N+1];
    totHarga[0] = 0;

    for(int i=0; i<=N; i++){
        for(int j=0; j<K; j++){
            statusBatu[i][j] = false;
        }
    }

    for(int i=1; i<=N; i++){
        ll tempHarga = totHarga[i-1];
        ll tempBerat = i;
        ll idxBerat = -1;
        ll idxBatu = -1;
        for(int j=i-1; j>=0; j--){
            for(int k=K-1; k>=0; k--){
                if((statusBatu[j][k] == false) && (tempBerat >= j + W[k]) && (tempHarga < totHarga[j] + H[k])){
                    tempHarga = totHarga[j] + H[k];
                    tempBerat = j + W[k];
                    idxBerat = j;
                    idxBatu = k;
                }
            }
        }
        if(idxBatu == -1){
            totHarga[i] = tempHarga;
            for(int j=0; j<K; j++){
                if(statusBatu[i-1][j]){
                    statusBatu[i][j] = true;
                }
            }
        }else{
            totHarga[i] = tempHarga;
            for(int j=0; j<K; j++){
                if(statusBatu[idxBerat][j]){
                    statusBatu[i][j] = true;
                }
                if(j == idxBatu){
                    statusBatu[i][j] = true;
                }
            }
        }
    }

    for(int i=0; i<K; i++){
        if(statusBatu[N][i]){
            cout << i+1 << endl;
        }
    }


}