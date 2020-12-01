#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;

    int ng[n+1];
    rep(i,n+1) ng[i] = -1;
    rep(_,3){
        int ngi; cin >> ngi;
        ng[ngi] = 1;
        if(ngi == n){
            cout << "NO" << endl;
            return 0;
        }
    }
    ng[n] = 0;

    int cnt = 0;
    int pos = n;
    while(cnt<100){
        if(pos>=3 && ng[pos-3] != 1){
            ng[pos-3] = 0;
            pos -= 3;
        }else if(pos>+2 && ng[pos-2] != 1){
            ng[pos-2] = 0;
            pos -= 2;
        }else if(pos>=1 && ng[pos-1]!= 1){
            ng[pos-1] = 0;
            pos -= 1;
        }else{
            cout << "NO" << endl;
            return 0;
        }

        if(pos == 0) break;

        cnt++;
    }
    /*
    rep(i,n+1){
        printf("%d %d\n", i, ng[i]);
    }

    cout << cnt << endl;
    cout << pos << endl;
    */

    if(ng[0] == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

/*

300
57
121
244

*/