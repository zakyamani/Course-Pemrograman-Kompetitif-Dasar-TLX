#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll B, K;
    cin >> B >> K;

    ll selisih = K - B;


    for(int i=60; i>=0; i--){
        ll pemberat = 1LL << i;
        if(selisih >= pemberat){
            selisih -= pemberat;
            cout << pemberat << endl;
        }
        if(selisih == 0){
            return 0;
        }
    }




}