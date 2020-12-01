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

const int LIM = 10000001;

int main()
{
    int N; cin >> N;
    int D_n[LIM];
    rep(i,LIM) D_n[i] = 0;
    D_n[0] = 0;
    D_n[1] = 1;
    for(int i=2; i<LIM; i++){
        int ori_i = i;
        vector<pair<ll, ll> > res;
        ll yakusu_n = 0;
        for(int j=2; j*j<=i; j++){
            if(i % j != 0) continue;
            ll ex = 0;
            while(i % j == 0){
                ++ex;
                i /= j;
                if(D_n[i]){
                    yakusu_n += D_n[i];
                    i /= i;
                }
            }
        }
        ll yakusu_n2 = 1;
        for(pair<ll,ll> re: res){
            yakusu_n2 *= (re.second+1);
        }
        yakusu_n += yakusu_n2;
        D_n[ori_i] = yakusu_n;
    }   
}