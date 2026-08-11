#include <bits/stdc++.h>

using namespace std;

int main(){
    int Q; cin >> Q;
    queue <int> arr;
    while(Q--){
        string q; cin >> q;
        if(q == "add"){
            int X, Y; cin >> X >> Y;
            while(Y--) arr.push(X);
            cout << arr.size() << endl;
        }else if(q == "del"){
            int Y; cin >> Y;
            cout << arr.front() << endl;
            while(Y--) arr.pop();
        }else{
            arr.swap(arr);
        }
    }
}