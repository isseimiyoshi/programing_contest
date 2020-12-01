#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int h, a; cin >> h >> a;
    if(h%a == 0){
        cout << h/a << endl;
    }else{
        cout << h/a+1 << endl;
    }
}