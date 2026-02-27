#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll N; cin >> N;
    ll A[N+1];


    for(ll i=1; i<=N; i++){
        cin >> A[i];
    }

    ll Q; cin >> Q;

    for(ll i=1; i<=Q; i++){
        ll x,y;
        cin >> x >> y;

        ll batas_kiri = 0;
        ll batas_kanan = 0;

        ll kiri = 1;
        ll kanan = N;
        ll tengah = (kiri + kanan)/2;

        while((kiri <= kanan) && (batas_kiri == 0)){


            if(x < A[tengah]){
                if((x > A[tengah - 1]) && (tengah > 1)){
                    batas_kiri = tengah;
                    break;
                }
                if(tengah == 1){
                    batas_kiri = tengah;
                    break;
                }
                kanan = tengah - 1;
            }else if(x > A[tengah]){
                if((x < A[tengah + 1]) && (tengah < N)){
                    batas_kiri = tengah;
                    break;
                }
                if(tengah == N){
                    batas_kiri = tengah;
                    break;
                }

                kiri = tengah + 1;
            }else{
                batas_kiri = tengah;
            }
            tengah = (kiri + kanan)/2;
            //cout << tengah << endl;
        }

        if(batas_kiri == 0){
            batas_kiri = tengah;
        }

        while((A[batas_kiri] <= x) && (batas_kiri <= N)){
            batas_kiri++;
        }

        kiri = 1;
        kanan = N;
        tengah = (kiri + kanan)/2;

        while((kiri <= kanan) && (batas_kanan == 0)){
            if(y < A[tengah]){
                if((y > A[tengah - 1]) && (tengah > 1)){
                    batas_kanan = tengah;
                    break;
                }
                if(tengah == 1){
                    batas_kanan = tengah;
                }
                kanan = tengah - 1;
            }else if(y > A[tengah]){
                if((y < A[tengah + 1]) && (tengah < N)){
                    batas_kanan = tengah;
                    break;
                }
                if(tengah == N){
                    batas_kanan = tengah;
                }
                kiri = tengah + 1;
            }else{
                batas_kanan = tengah;
            }
            tengah = (kiri + kanan)/2;
        }

        if(batas_kanan == 0){
            batas_kanan = tengah;
        }

        while((A[batas_kanan] > y) && (batas_kanan > 0)){
            batas_kanan--;
        }
        while((A[batas_kanan] == A[batas_kanan + 1]) && (batas_kanan < N)){
            batas_kanan++;
        }


        //cout << batas_kiri << " " << batas_kanan << endl;
        cout << batas_kanan - batas_kiri + 1 << endl;






    }






}
