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
    ll N; cin >> N;
    vector<pair<ll, int>> fs;   // ある値の素因数分解を行うときは、vectorの中にpairというデータ型を定義して、それぞれの底およびべき指数を格納する
    for(ll i=2; i*i<=N; i++){   // 1は素数ではないので、素因数分解を行うときは2からループを始める
        int x = 0;
        while(N%i==0){
            ++x;
            N /= i;
        }
        fs.push_back(make_pair(i,x));
    }
    // 素因数分解をするためのループ回数を少なくするために、エラトステネスのふるいを用いているが、
    // もし素因数分解ができなかった場合を含めるために、最後に素因数分解できたか判定して
    // できていない場合は素因数分解の結果を格納する配列に追加する
    if(N != 1) fs.push_back(make_pair(N, 1));


    int ans = 0;
    for(auto f: fs){
        int x = f.second;
        int b = 1;
        while(x >= b){
            x -= b;
            ++b;
            ++ans;
        }
    }
    cout << ans << endl;
}