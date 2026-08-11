#include <bits/stdc++.h>

using namespace std;

vector<int> node(100001);
int N;




int findRepresentative(int x){
    if(node[x] == x){
        return x;
    }else{
        node[x] = findRepresentative(node[x]);
        return node[x];
    }
}

void join(int a, int b){
    int repA = findRepresentative(a);
    int repB = findRepresentative(b);
    node[repA] = repB;
}

void check(int a, int b){
    if(findRepresentative(a) == findRepresentative(b)){
        cout << "Y" << endl;
    }else{
        cout << "T" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Q;
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        node[i] = i;
    }
    while(Q--){
        int num,a,b;
        cin >> num >> a >> b;
        if(num == 1){
            join(a,b);
        }else{
            check(a,b);
        }
    }

}