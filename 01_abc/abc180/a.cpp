#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int n, a, b; cin >> n >> a >> b;
    int res = 0;
    res += n;
    if(res<a) res = 0;
    else res = res -a;
    res += b;
    cout << res << endl;
}