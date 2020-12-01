#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int a_i[n];
    for(int i=0; i<n; i++) cin >> a_i[i];
    for(int i=n-1; i>=0; i--){
        cout << a_i[i];
        if(i != 0) cout << " ";
    }
    cout << endl;
}