#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int r, c;
    cin >> r >> c;
    int x[r][c+1];
    vector<int> column_sum(c+1);
    for(int i=0; i<r; i++){
        int r_i_sum = 0;
        for(int j=0; j<c; j++){
            int c_j;
            cin >> c_j;
            x[i][j] = c_j;
            r_i_sum += c_j;
        }
        x[i][c] = r_i_sum;
    }
    fill(column_sum.begin(), column_sum.end(), 0);
    for(int i=0; i<r; i++){
        for(int j=0; j<c+1; j++){
            column_sum[j] += x[i][j];
            cout << x[i][j];
            if(j != c) cout << " ";
        }
        cout << endl;
    }
    for(int j=0; j<c+1; j++){
        cout << column_sum[j];
        if(j != c) cout << " ";
    }
    cout << endl;
}