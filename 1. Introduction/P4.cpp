#include <bits/stdc++.h>
#define ll long long


using namespace std;

int main(){
    string str;
    cin >> str;

    ll sisi = ceil(sqrt(str.size()));

    char str_tambahan[sisi * sisi - str.size()];
    if(str.size() < (sisi * sisi)){
        
        for(ll i=0; i < sisi * sisi - str.size(); i++){
            str_tambahan[i] = '.';
        }
    }
    string str_baru = str + str_tambahan;
    
    for(ll i=0; i<sisi; i++){
        if(i % 2 == 0){
            for(ll j = sisi * i; j < sisi * (i+1); j++){
                cout<<str_baru[j];
            }
        }else{
            for(ll j = sisi * (i+1) - 1; j >= sisi * i; j--){
                cout<<str_baru[j];
            }
        }
        cout<<endl;
    }

}