#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin>>N;
    int num[N];
    for(int i=0; i<N; i++){
        cin>>num[i];
    }



    int counter = 0;

    for(int i=N-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(num[j] > num[j+1]){
                swap(num[j],num[j+1]);
                counter++;
            }
        }
    }

    cout<<counter;



}