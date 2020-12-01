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

int main()
{
    int n, m; cin >> n >> m;
    vector<int> p(n+1);
    p[0] = 0;
    rep(i,n) cin >> p[i+1];

    sort(p.begin(), p.end());

    vector<int> sum;
    vector<int> sum2;

    rep(i,n+1){
        rep(j,n+1){
            sum.push_back(p[i]+p[j]);
            sum2.push_back(p[i]+p[j]);
        }
    }

    sort(sum.begin(), sum.end());
    sort(sum2.begin(), sum2.end());

    // cout << sum[sum.size()-1] << endl;

    int ans = -1;
    rep(i,sum.size()){
        if(sum[i] > m) break;

        auto itr = upper_bound(sum2.begin(), sum2.end(), (m-sum[i]));

        --itr;

        int ad = *itr;

        int res = sum[i] + ad;

        ans = max(res, ans);
    }

    cout << ans << endl;
}