#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    char kelereng[N];
    int jumKel[26];
    for(int i=0; i<26; i++){
        jumKel[i] = 0;
    }
    for(int i=0; i<N; i++){
        cin >> kelereng[i];
        int idx = kelereng[i] - 'A';
        jumKel[idx]++;
    }
    int max1 = 0, max2 = 0, max3 = 0;
    int idx1, idx2, idx3;
    for(int i=0; i<26; i++){
        if(max1 < jumKel[i]){
            max1 = jumKel[i];
            idx1 = i;
        }
    }

    for(int i=0; i<26; i++){
        if((i != idx1) && (max2 < jumKel[i])){
            max2 = jumKel[i];
            idx2 = i;
        }
    }

    for(int i=0; i<26; i++){
        if((i != idx1) && (i != idx2) && (max3 < jumKel[i])){
            max3 = jumKel[i];
            idx3 = i;
        }
    }

    if(max3 == 0){
        cout << -1 << endl;
        return 0;
    }

    int total = max3 * 3;
    if(max1 > max3){
        total++;
    }
    if(max2 > max3){
        total++;
    }

    cout << total << endl;

}