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

const int INF = 1000100100;

int main()
{
    int n, k; cin >> n >> k;
    int p[n], c[n];

    ll csum = 0;
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> c[i];
    // rep(i,n) csum += c[i];
    rep(i,n) --p[i];

    ll ans = -INF;

    rep(i,n){
        // まずはループするまでの回数とコストの合計値を求める
        int iti = i;
        int ori_iti = i;
        ll csum = 0;
        ll cnt = 0;
        rep(_,n){
            csum += c[p[iti]];
            iti = p[iti]; 
            cnt++;
            if(iti == ori_iti) break;
        }  

        if(csum <= 0){
            ll sum = 0;
            iti = i;
            rep(_,n){
                sum += c[p[iti]];
                iti = p[iti];

                ans = max(sum, ans);
            }
        }else{
            ll sum = 0;
            sum += (k / cnt)*csum;
            sum -= csum;
            ans = max(sum, ans);

            ll roop = k % cnt;
            iti = ori_iti;

            rep(_,cnt){
                sum += c[p[iti]];
                iti = p[iti];

                ans = max(sum, ans);
            }

            rep(_,roop){
                sum += c[p[iti]];
                iti = p[iti];

                ans = max(sum, ans);
            }
        }
    }

    /*
    rep(i,n){   // このループは、初期位置の決め方
        if(csum > 0){
            ll sum = 0;
            sum += (k / n)*csum;
            ans = max(sum, ans);

            ll roop = k % n;
            int iti = i;

            rep(_,roop){
                sum += c[p[iti]];
                iti = p[iti];

                ans = max(sum, ans);
            }

            ans = max(sum, ans);

        }else{
            
        }
        
    }
    */


    cout << ans << endl;

}