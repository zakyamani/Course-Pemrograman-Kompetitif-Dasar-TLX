#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD =  1000000;

int main(){
    ll A, B;
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

    ll pangkatA[30];
    pangkatA[0] = A;
    ll pangkat2[30];
    pangkat2[0] = 1;
    for(int i=1; i<30; i++){
       pangkatA[i] = pangkatA[i-1] * pangkatA[i-1];
       pangkatA[i] %= MOD;
       pangkat2[i] = pangkat2[i-1] * 2;
    }
    ll result = 1;
    for(int i=29; i>=0; i--){
        if(B >= pangkat2[i]){
            B -= pangkat2[i];
            result *= pangkatA[i];
            result %= MOD;
        }
        if(B <= 0){
            break;
        }
    }
    if(sixDigit){
        if(result < 100000){
            cout <<"0";
        }
        if(result < 10000){
            cout <<"0";
        }
        if(result < 1000){
            cout <<"0";
        }
        if(result < 100){
            cout <<"0";
        }
        if(result < 10){
            cout <<"0";
        }
    }
    cout << result;
}