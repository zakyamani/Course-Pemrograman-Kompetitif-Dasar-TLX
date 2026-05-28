#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N;
    cin >> N;
    ll A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    ll K;
    cin >> K;
    ll jumlahKoin[K+1];
    jumlahKoin[0] = 0;
    ll min;
    for(int i=1; i<=K; i++){
        min = 50001;
        for(int j=0; j<N; j++){
            if((i >= A[j]) && (jumlahKoin[i - A[j]] + 1 < min) && (jumlahKoin[i - A[j]] != -1)){
                min = jumlahKoin[i - A[j]] + 1;
            }
        }
        if(min == 50001){
            jumlahKoin[i] = -1;
        }else{
            jumlahKoin[i] = min;
        }

    }
    cout << jumlahKoin[K];
}
