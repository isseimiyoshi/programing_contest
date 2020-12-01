#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    char S; cin >> S;
    string t; cin >> t;
    int tn = t.size();
    if(S == 'Y'){
        rep(i,tn){
            if(t[i] == 'a') cout << 'A';
            else if(t[i] == 'b') cout << 'B';
            else cout << 'C';
        }
        cout << endl;
    }else{
        cout << t << endl;
    }
}