#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    ll a[n][m], b[m][l], c[n][l];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a_ij;
            cin >> a_ij;
            a[i][j] = a_ij;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<l; j++){
            int b_ij;
            cin >> b_ij;
            b[i][j] = b_ij;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            c[i][j] = 0;
            for(int k=0; k<m; k++) c[i][j] += a[i][k]*b[k][j];
            cout << c[i][j];
            if(j != l-1) cout << " ";
        }
        cout << endl;
    }
}