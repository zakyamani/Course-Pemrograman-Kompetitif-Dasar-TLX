#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N; cin >> N;
    ll counter = 0;
    ll div = 5;
    while(N >= div){
        counter += (N/div);
        div *= 5;
    }
    cout << counter << endl;
}