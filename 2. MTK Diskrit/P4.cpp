#include <bits/stdc++.h>
#define ll long long


using namespace std;

ll pangkat(ll x, ll y){
    if(y == 0){
        return 1;
    }else{
        return x * pangkat(x,y-1);
    }
}

ll pangkat_max(ll x, ll y){
    ll blyat = 0;
    while(x >= pangkat(y,blyat)){
        blyat++;
    }
    blyat--;
    return blyat;
}

int main(){
    ll num;
    ll base;

    cin >> num;
    cin >> base;

    ll num_sementara = num;

    ll new_num = 0;
    for(ll j=pangkat_max(num,base); j>=0; j--){
        ll angka = 0;
        if(num_sementara >= pangkat(base,j)){
            angka = floor(num_sementara/(pangkat(base,j)));
            new_num += angka * pangkat(10,j);
            num_sementara -= angka * pangkat(base,j);
        }
    }

    cout << new_num<< endl;
}
