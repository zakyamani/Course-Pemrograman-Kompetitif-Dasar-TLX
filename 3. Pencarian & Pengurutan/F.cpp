#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N; cin >> N;
    ll A[N];
    ll total_sementara = 0;
    for(ll i=0; i<N; i++){
        cin >> A[i];
        total_sementara += A[i];
        A[i] = total_sementara;
    }
    
    ll Q; cin >> Q;

    for(ll i=0; i<Q; i++){
        ll x;
        cin >> x;

        ll kiri = 0;
        ll kanan = N-1;
        ll tengah = (kanan+kiri)/2;

        while(kiri < kanan){

            if((x > A[tengah]) && (x < A[tengah + 1])){
                tengah++;
                break;
            }else if((x < A[tengah]) && (x > A[tengah - 1])){
                break;
            }
            
            if(x < A[tengah]){
                kanan = tengah - 1;
            }else if(x > A[tengah]){
                kiri = tengah + 1;
            }else{
                kanan = tengah;
                kiri = tengah;
            }
            tengah = (kanan+kiri)/2;
        }

        cout << tengah+1 << endl;


    }






}
