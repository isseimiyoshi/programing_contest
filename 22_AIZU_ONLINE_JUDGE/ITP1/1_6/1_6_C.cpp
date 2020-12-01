#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main()
{
    int bil[4][3][10];
    Fill(bil, 0);
    int n;
    cin >> n;
    int b, f, r, v;
    for(int i=0; i<n; i++){
        cin >> b >> f >> r >> v;
        bil[b-1][f-1][r-1] += v;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<10; k++){
                cout << " " << bil[i][j][k];
            }
            cout << endl;
        }
        if(i<3) cout << "####################" << endl;
    }
}