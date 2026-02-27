#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,X;
    cin>>N>>X;

    int A;
    int selisih_min = 999999;
    int ans;
    for(int i=0; i<N; i++){
        cin>>A;
        int selisih = abs(A - X);
        if(selisih < selisih_min){
            selisih_min = selisih;
            ans = A;
        }else if(selisih == selisih_min){
            if(A < ans){
                ans = A;
            }
        }
    }
    cout<<ans;



}