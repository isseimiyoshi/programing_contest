#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;

    map<P,int> m;

    for(int i=1; i<=n; i++){
        int iketa = (int)log10(i)+1;
        int ir = i / pow(10,iketa-1);
        int ie = i % 10;

        m[make_pair(ir,ie)]++;
    }
    int ans = 0;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            ans += m[make_pair(i,j)]*m[make_pair(j,i)];
        }
    }
    cout << ans << endl;
}