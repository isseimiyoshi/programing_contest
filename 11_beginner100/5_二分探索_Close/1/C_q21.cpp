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

const ll MAX_H = 1100100100100100100;

vector<ll> H, S;
int N;

bool intime(ll X){
    vector<ll> limit;
    rep(i,N){
        if(X - H[i] < 0) return false;
        limit.push_back((X-H[i]) / S[i]);
    }
    sort(limit.begin(), limit.end());
    rep(i,limit.size()){
        if(limit[i] < i) return false;
    }
    return true;
}

ll binary_search(){
    ll left = 0, right = MAX_H;
    while(left < right){
        ll mid = (left + right) / 2;
        if(intime(mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main()
{
    cin >> N;
    rep(_,N){
        ll Hi, Si; cin >> Hi >> Si;
        H.push_back(Hi); S.push_back(Si);
    }
    ll minH = binary_search();
    cout << minH << endl;
}