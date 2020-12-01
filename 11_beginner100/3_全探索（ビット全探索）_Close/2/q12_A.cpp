#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

const int MAX_N = 12;

int main()
{
    int n, m; cin >> n >> m;
    vector<P> r;
    rep(i,m){
        int x, y; cin >> x >> y; --x; --y;
        r.push_back(make_pair(x, y));
    }
    sort(r.begin(), r.end());

    int ans = -1;
    rep(i,(1<<n)){
        bitset<MAX_N> b(i);

        bool isok = true;
        int cnt = 0;
        rep(j,n){
            if(b.test(j)){
                rep(k,n){
                    if(j == k || !b.test(k)) continue;
                    else{
                        if((lower_bound(r.begin(), r.end(), make_pair(j,k)) != upper_bound(r.begin(), r.end(), make_pair(j,k))) || (lower_bound(r.begin(), r.end(), make_pair(k,j)) != upper_bound(r.begin(), r.end(), make_pair(k,j)))){
                            continue;
                        }else{
                            isok = false;
                            break;
                        }
                    }
                }
                if(isok) cnt++;
                else{
                    cnt = -1;
                    break;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}