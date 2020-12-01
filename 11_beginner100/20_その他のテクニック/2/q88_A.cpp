#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/


int main()
{
    int n; cin >> n;
    vector<P> go;
    rep(i,n){
        int ci; cin >> ci;
        if(i == 0){
            go.push_back(make_pair(ci, 1));
            continue;
        }

        int gosize = go.size();
        if((i+1) % 2 == 1){
            if(go[gosize-1].first == ci) go[gosize-1].second = go[gosize-1].second + 1;
            else go.push_back(make_pair(ci,1));
        }else{
            int ori_c = go[gosize-1].first;
            int ori_n = go[gosize-1].second;
            if(ori_c == ci) go[gosize-1].second = go[gosize-1].second + 1;
            else{
                go.pop_back();
                ori_n += 1;
                int gosize2;
                bool iszero = false;
                while(true){
                    gosize2 = go.size();
                    if(gosize2 == 0){
                        go.push_back(make_pair(ci, ori_n));
                        iszero = true;
                        break;
                    }
                    if(go[gosize2-1].first != ci){
                        ori_n += go[gosize2-1].second;
                        go.pop_back();
                    }else{
                        break;
                    }
                }
                if(!iszero) go[gosize2-1].second = go[gosize2-1].second + ori_n;
            }
        }
        /*
        for(P g: go){
            printf("%d times: %d %d\n", i+1, g.first, g.second);
        }
        */
    }
    ll ans = 0;
    for(P g: go){
        if(g.first == 0) ans += g.second;
    }
    cout << ans << endl;
}