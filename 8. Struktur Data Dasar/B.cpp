#include <bits/stdc++.h>

using namespace std;

int main(){
    int Q; cin >> Q;
    queue <int> num;
    queue <int> frek;
    int total = 0;

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
            cout << num.front() << endl;
            while(Y > 0){
                if(Y >= frek.front()){
                    Y -= frek.front();
                    frek.pop();
                    num.pop();
                }else{
                    frek.front() -= Y;
                    Y = 0;
                }
            }
        }else{
            stack <int> numTerm;
            stack <int> frekTerm;
            while(num.size()){
                numTerm.push(num.front());
                frekTerm.push(frek.front());
                num.pop();
                frek.pop();
            }
            while(numTerm.size()){
                num.push(numTerm.top());
                frek.push(frekTerm.top());
                numTerm.pop();
                frekTerm.pop();
            }
        }
    }
}