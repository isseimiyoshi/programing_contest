#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    string s; cin >> s;
    int n = s.size();
    if(s[n-1] == 's'){
        cout << s << "es" << endl;
        return 0;
    }else{
        cout << s << "s" << endl;
    }
}