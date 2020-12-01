#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m], b[m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a_ij;
            cin >> a_ij;
            a[i][j] = a_ij;
        }
    }
    for(int j=0; j<m; j++){
        int b_j;
        cin >> b_j;
        b[j] = b_j;
    }
    // int c[n];
    vector<int> c(n);
    fill(c.begin(), c.end(), 0);
    for(int i=0; i<n; i++){
        int c_i = 0;
        for(int j=0; j<m; j++){
            c_i += a[i][j]*b[j];
        }
        c[i] = c_i;
    }
    for(int i=0; i<n; i++) cout << c[i] << endl;
}