#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

int main()
{
    int n,q; cin >> n >> q;
    vector<int> V[n];
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int t, x; cin >> t >> x;
            V[t].push_back(x);
        }else if(query == 1){
            int t; cin >> t;
            /*
            rep(j,V[t].size()-1){
                cout << V[t][j];
                if(j != V[t].size()-1) cout << " ";
            }
            */
            for(int j=0; j<V[t].size()-1; j++){
                cout << j << endl;
            }
            // cout << V[t].size() << endl;
            cout << endl;
        }else{
            int t, s; cin >> s >> t;
            rep(k,V[s].size()-1) V[t].push_back(V[s][k]);
            V[s].clear();
        }
    }
}