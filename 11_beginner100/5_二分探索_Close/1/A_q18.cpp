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

vector<int> S;
int n;

bool binary_search(int key){
    int left = 0, right = n;
    while(left < right){
        int mid = (left + right) / 2;
        if(S[mid] == key) return true;
        else if(S[mid] < key) left = mid+1;
        else right = mid;
    }
    return false;
}

int main()
{
    cin >> n;
    rep(i,n){
        int Si; cin >> Si;
        S.push_back(Si);
    }
    int q; cin >> q;
    vector<int> T(q);
    rep(i,q) cin >> T[i];
    sort(S.begin(), S.end());
    int sum = 0;
    rep(i,q){
        if(binary_search(T[i])) sum++;
        else continue;
    }
    cout << sum << endl;
}