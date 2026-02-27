#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin>>N;
    string data[N];
    for(int i=0; i<N; i++){
        cin>>data[i];
    }

    for(int i=N-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(data[j].size() > data[j+1].size()){
                swap(data[j],data[j+1]);
            }else if(data[j].size() == data[j+1].size()){
                for(int k=0; k < data[j].size(); k++){
                    if(data[j][k] > data[j+1][k]){
                        swap(data[j],data[j+1]);
                        break;
                    }else if(data[j][k] < data[j+1][k]){
                        break;
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        cout<<data[i]<<endl;
    }




}