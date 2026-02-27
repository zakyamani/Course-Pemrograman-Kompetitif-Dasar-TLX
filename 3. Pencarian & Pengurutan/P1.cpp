#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N, K;
    cin >> N >> K;

    ll A[N+1];
    ll total_sementara = 0;
    for(ll i=1; i<=N; i++){
        cin >> A[i];
        total_sementara += A[i];
        A[i] = total_sementara;
    }
    

    for(ll i = 1; i<=K; i++){
        ll B; cin >> B;
        if(B < A[1]){
            cout << 0 << endl;
            continue;
        }

        ll kiri = 1;
        ll kanan = N;
        ll tengah = (kiri + kanan)/2;

        while(kiri < kanan){
            if(B < A[tengah]){
                kanan = tengah - 1;
            }else if (B > A[tengah]){
                kiri = tengah + 1;
            }else{
                break;
            }
            tengah = (kiri + kanan)/2;
        }

        if(B < A[tengah]){
            tengah--;
        }

        cout << tengah << endl;


    }


}