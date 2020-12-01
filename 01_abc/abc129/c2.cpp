#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

set<int> Ms;
int N;
ll res = 0;
const ll prime = pow(10,9)+7;
const int MAX_N = pow(10,5);

bool isFinish = true;
vector<int> Com(MAX_N);

void init(){
    rep(i,MAX_N) Com[i] = 0;
}

void upstairs(int x){
    if(Ms.count(x+1) == 1 && Ms.count(x+2) == 1){
        isFinish = false;
        return;
    }
    if(Com[x]){
        res += Com[x];
        return;
    }
    if(x == N){
        res++; res %= prime;
        return;
    }
    if(x+1 <= N && Ms.count(x+1) == 0){
        // res++; res %= prime;
        upstairs(x+1);
    }
    if(x+2 <= N && Ms.count(x+2) == 0){
        // res++; res %= prime;
        upstairs(x+2);
    }
    Com[x] = res;
    return;
}

int main()
{
    int M; cin >> N >> M;
    rep(i,M){
        int Mi; cin >> Mi;
        Ms.insert(Mi);
    }
    init();
    upstairs(0);
    if(isFinish) cout << res << endl;
    else cout << 0 << endl;
}