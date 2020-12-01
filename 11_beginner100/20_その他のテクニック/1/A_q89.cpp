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
    int n; cin >> n;
    vector<int> D;
    int A[n];
    rep(i,n){
        cin >> A[i];
    }
    int len = 1;
    int ori_A = A[0];
    for(int i=1; i<n; i++){
        if(ori_A != A[i]){
            len++;
        }else{
            D.push_back(len);
            len = 1;
        }
        ori_A = A[i];
        if(i == n-1) D.push_back(len);
    }
    /*
    for(int d : D){
        cout << d << endl;
    }
    */
   int max_d = 0;
   int ds = D.size();
   if(ds == 1) cout << D[0] << endl;
   else if(ds == 2) cout << D[0] + D[1] << endl;
   else{
        for(int d = 0; d<ds-2; d++){
            int sum = D[d] + D[d+1] + D[d+2];
            if(max_d < sum) max_d = sum;
        }
        cout << max_d << endl;
   }
}