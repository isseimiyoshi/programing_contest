#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while(true){
        string s;
        cin >> s;
        if(s == "0") break;
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            int s_i = s[i] - '0';
            sum += s_i;
        }
        cout << sum << endl;
    }

    /*
    while(true){
        ll x;
        cin >> x;
        if(x == 0) break;
        ll sum = 0;
        while(true){
            ll x_1 = x % 10;
            if(x_1 == 0 && x == 0) break;
            else sum += x_1;
            x /= 10;
        }
        cout << sum << endl;
    }
    */
}