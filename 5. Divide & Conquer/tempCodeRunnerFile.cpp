#include <iostream>
#include <cmath>

using namespace std;



int main(){
    int N,M;
    cin>>N>>M;
    int S[N];

    for(int i=0; i<N; i++){
        cin>>S[i];
    }

    int ways=0;
    int x=0;
    int total;

    while(total<=M){
        total=0;
        for(int i=0; i<N; i++){
            total+=floor(x/S[i]);
        }
        if(total<M){
            continue;
        }else if(total==M){
            ways++;
        }
        

    }
    cout<<ways;

}