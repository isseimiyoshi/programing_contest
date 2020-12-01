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
    int N, K; cin >> N >> K;
    vector<tuple<int, int, int> > T;
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(i == 1 && j == N) T.push_back(make_tuple(1, i, j));
            else T.push_back(make_tuple(j-i, i, j));
        }
    }
    sort(T.begin(), T.end());
    bool isOK = true;
    int rn = 0;
    for(int i = T.size()-1; i>=0; i--){
        if(rn == K) break;
        int a, b, c;
        tie(a, b, c) = T[i];
        if(a == 1){
            isOK = false;
            break;
        }else{
            T.pop_back();
        }
        rn++;
        // printf("%d %d %d\n", a, b, c);
    }
    if(isOK){
        cout << T.size() << endl;
        rep(i,T.size()){
            int a, b, c;
            tie(a, b, c) = T[i];
            printf("%d %d\n", b, c);
        }
    }else{
        cout << -1 << endl;
    }
}