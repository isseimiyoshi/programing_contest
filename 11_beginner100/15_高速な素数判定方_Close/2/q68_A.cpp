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
    int ori_n = n;
    vector<P> res;
    for(int i=2; i*i<=ori_n; i++){
        ll cnt = 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        res.push_back(make_pair(i,cnt));
    }
    if(n*n > ori_n) res.push_back(make_pair(n,1));
    
    printf("%d:", ori_n);
    for(P re: res){
        rep(i,re.second){
            printf(" %d", re.first);
        }
    }
    cout << endl;
}