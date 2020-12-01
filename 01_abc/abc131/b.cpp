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

const int INF = 10000000;

int main()
{
    int N; int L; cin >> N >> L;
    vector<int> Apple(N);
    int sum = 0; int min_i; int min_n = INF;
    rep(i,N){
        Apple[i] = L + i;
        sum += L+i;
        if(min_n > abs(L+i)){
            min_i = i;
            min_n = abs(L+i);
        }
    }
    int sum2 = 0;
    rep(i,N){
        if(min_i != i){
            sum2 += Apple[i];
        }
    }
    cout << sum2 << endl;
}