#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1000000;

ll pangkat(ll A, ll B){
    if(B == 1){
        return A % MOD;
    }else if(B == 2){
        return ((A%MOD) * (A% MOD)) % MOD;
    }

    if(B % 2 == 0){
        return (pangkat(pangkat(A,2) % MOD, B/2)) % MOD;
    }else{
        return (pangkat(A % MOD, B-1) * A) % MOD;
    }
}

int main(){
    ll A,B;
    cin >> A >> B;
    bool sixDigit = false;
    ll temp = 1;
    if(A != 1){
        for(ll i=0; i<B; i++){
            temp *= A;
            if(temp >= 1000000){
                sixDigit = true;
                break;
            }
        }
    }
    A %= MOD;
    ll hasil = pangkat(A,B) % MOD;
    if(sixDigit){
        if(hasil < 100000){
            cout <<"0";
        }
        if(hasil < 10000){
            cout <<"0";
        }
        if(hasil < 1000){
            cout <<"0";
        }
        if(hasil < 100){
            cout <<"0";
        }
        if(hasil < 10){
            cout <<"0";
        }
    }
    cout << hasil;

}