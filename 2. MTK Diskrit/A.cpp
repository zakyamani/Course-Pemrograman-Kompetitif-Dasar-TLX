#include <iostream>

using namespace std;

int main(){
    int n; 
    cin>>n;
    for(int i =0; i<n; i++){
        int k;
        cin>>k;
        int counter =0;
        bool prima = true;
        for(int i =1; i<=k;i++){
            if(k%i == 0){
                prima =false;
                counter++;
            }
            if(counter >4){
                break;
            }
        }
        if(counter <=4){
            cout<<"YA"<<endl;
        }else{
            cout<<"BUKAN"<<endl;
        }
    }
}