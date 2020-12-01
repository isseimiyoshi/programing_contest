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

const int MAX_N = 15;
const ll INF = 1000100100100100100;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    ll ans = INF;

    rep(i,(1<<n)){
        bitset<MAX_N> b(i);

        ll cost = 0;
        if(b.count() == k){
            if(!b.test(0)) continue;

            int ori_a = a[0];

            for(int j=1; j<n; j++){
                if(b.test(j)){
                    if(a[j] > ori_a){
                        ori_a = a[j];
                    }else{
                        cost += ori_a - a[j] + 1;
                        ori_a = ori_a + 1;
                    }
                }else{
                    if(ori_a < a[j]){
                        ori_a = a[j];
                    }
                }
            }
        }else{
            cost = INF;
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;
}