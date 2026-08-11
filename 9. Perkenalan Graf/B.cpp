#include <bits/stdc++.h>
#define kalcer ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int C, R;
char mp[500][500];
bool visited[500][500];
int areaOfK = 0, areaOfB = 0;
int area = 0;
bool sewilayah;

void count(int column, int row){
    visited[row][column] = true;
    if(mp[row][column] == '#') return;
    if((column + 1 < C) && (!visited[row][column + 1])){
        if(mp[row][column + 1] == '.'){
            area++;
            count(column+1, row);
        }else if(mp[row][column + 1] != '#'){
            count(column+1, row);
            sewilayah = true;
            return;
        }else{
            visited[row][column+1] = true;
        }
    }
    if((row + 1 < R) && (!visited[row + 1][column])){
        if(mp[row + 1][column] == '.'){
            area++;
            count(column, row + 1);
        }else if(mp[row + 1][column] != '#'){
            count(column, row + 1);
            sewilayah = true;
            return;
        }else{
            visited[row+1][column] = true;
        }
    }
    if((row - 1 >= 0) && (!visited[row - 1][column])){
        if(mp[row - 1][column] == '.'){
            area++;
            count(column, row - 1);
        }else if(mp[row - 1][column] != '#'){
            count(column, row - 1);
            sewilayah = true;
            return;
        }else{
            visited[row-1][column] = true;
        }
    }
    if((column - 1 >= 0) && (!visited[row][column - 1])){
        if(mp[row][column - 1] == '.'){
            area++;
            count(column-1, row);
        }else if(mp[row][column - 1] != '#'){
            count(column-1, row);
            sewilayah = true;
            return;
        }else{
            visited[row][column-1] = true;
        }
    }
    
    
    return;
}



int main(){
    
    cin >> C >> R;
    int CofB, CofK, RofB, RofK;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'B'){
                RofB = i;
                CofB = j;
            }
            if(mp[i][j] == 'K'){
                RofK = i;
                CofK = j;
            }
        }
    }
    
    count(CofK, RofK);
    areaOfK = area;
    if(!sewilayah){
        area = 0;
        count(CofB, RofB);
        areaOfB = area;
        if(areaOfB > areaOfK){
            cout << "B " << areaOfB - areaOfK << endl;
        }else if(areaOfK > areaOfB){
            cout << "K " << areaOfK - areaOfB << endl;
        }else{
            cout << "SERI" << endl; 
        }
    }else{
        cout << "SERI" << endl;
    }

    
    
}