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
    int n, k; cin >> n >> k;
    int p[n];
    rep(i,n) cin >> p[i];

    int sumpi[1005];
    rep(i,1005){
        if(i == 0){
            sumpi[i] = i;
            continue;
        }
        sumpi[i] = i + sumpi[i-1];
    }

    double prov[n];
    rep(i,n){
        prov[i] = (double)sumpi[p[i]] / (double)p[i];
    }
    rep(i,n){
        if(i == 0) continue;
        prov[i] = prov[i] + prov[i-1];
    }
    
    double ans = -1;
    rep(i,n-k+1){
        if(i == 0){
            ans = max(ans, prov[k-1]);
        }else{
            ans = max(ans, prov[i+k-1]-prov[i-1]);
        }
    }
    /*
    rep(i,n) cout << prov[i] << " ";
    cout << endl;
    */

    printf("%f\n",ans);
    return 0;
}