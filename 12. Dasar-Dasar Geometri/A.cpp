#include <bits/stdc++.h>

using namespace std;

int main(){
    double x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double PQ = sqrt((y2-y1) * (y2-y1) + (x2-x1)*(x2-x1));
    if((PQ > r1 + r2) || ((PQ + r1 < r2) && (PQ < r2)) || ((PQ + r2 < r1) && (PQ < r1))){
        cout << "tidak bersentuhan" << endl;
    }else{
        cout << "bersentuhan" << endl;
    }
}