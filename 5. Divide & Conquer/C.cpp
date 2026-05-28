#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    string hasil;

    cout << "?" << endl;
    cout << "1 2 3 4" << endl;
    cout << "5 6 7 8" << endl;

    cin >> hasil;

    if(hasil == "KIRI"){
        cout << "?" << endl;
        cout << "1 2" << endl;
        cout << "3 4" << endl;

        cin >> hasil;
        
        if(hasil == "KIRI"){
            cout << "?" << endl;
            cout << "1" << endl;
            cout << "2" << endl;

            cin >> hasil;

            if(hasil == "KIRI"){
                cout << "! 1" << endl;
            }else if(hasil == "KANAN"){
                cout << "! 2" << endl;
            }
            
        }else if(hasil == "KANAN"){
            cout << "?" << endl;
            cout << "3" << endl;
            cout << "4" << endl;

            cin >> hasil;

            if(hasil == "KIRI"){
                cout << "! 3" << endl;
            }else if(hasil == "KANAN"){
                cout << "! 4" << endl;
            }
        }
    }else if(hasil == "KANAN"){
        cout << "?" << endl;
        cout << "5 6" << endl;
        cout << "7 8" << endl;

        cin >> hasil;
        
        if(hasil == "KIRI"){
            cout << "?" << endl;
            cout << "5" << endl;
            cout << "6" << endl;

            cin >> hasil;
            
            if(hasil == "KIRI"){
                cout << "! 5" << endl;
            }else if(hasil == "KANAN"){
                cout << "! 6" << endl;
            }
            
        }else if(hasil == "KANAN"){
            cout << "?" << endl;
            cout << "7" << endl;
            cout << "8" << endl;

            cin >> hasil;

            if(hasil == "KIRI"){
                cout << "! 7" << endl;
            }else if(hasil == "KANAN"){
                cout << "! 8" << endl;
            }
        }
    }
}