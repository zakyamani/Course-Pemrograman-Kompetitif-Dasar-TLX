#include <bits/stdc++.h>

using namespace std;

int main(){
    int Q; cin >> Q;
    int total = 0;
    stack <int> num;
    stack <int> frek;
    while(Q--){
        string q; cin >> q;
        if(q == "add"){
            int X, Y; cin >> X >> Y;
            num.push(X);
            frek.push(Y);
            total += Y;
            cout << total << endl;
        }else if(q == "del"){
            int Y; cin >> Y;
            total -= Y;
            cout << num.top() << endl;
            while(Y > 0){
                if(Y >= frek.top()){
                    Y -= frek.top();
                    frek.pop();
                    num.pop();
                }else{
                    frek.top() -= Y;
                    Y = 0;
                }
            }
        }else if(q == "adx"){
            int D; cin >> D;
            int size = num.size();
            int numTerm[size];
            for(int i=0; i<size; i++){
                numTerm[i] = num.top() + D;
                num.pop();
            }
            for(int i=size-1; i>=0; i--){
                num.push(numTerm[i]);
            }
        }else{
            int D; cin >> D;
            int size = num.size();
            int numTerm[size];
            for(int i=0; i<size; i++){
                numTerm[i] = num.top() - D;
                num.pop();
            }
            for(int i=size-1; i>=0; i--){
                num.push(numTerm[i]);
            }
        }
    }
}