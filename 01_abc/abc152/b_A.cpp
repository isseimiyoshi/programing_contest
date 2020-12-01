#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    
    int a,b; cin >> a >> b;
    if(a>b) swap(a,b);
    rep(i,b){
        cout << a;
    }cout << endl;
}