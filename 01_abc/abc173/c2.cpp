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

int H, W, K;

int count(vector<vector<int> > M, int h1, int h2, int w1, int w2){
    for(int i=h1; i<=h2; i++){
        rep(j,W) M[i][j] = 2;
    }
    for(int j=w1; j<=w2; j++){
        rep(i,H) M[i][j] = 2;
    }
    int cnt = 0;
    rep(i,H){
        rep(j,W){
            if(M[i][j] == 1) cnt++;
        }
    }
    return cnt;
}

int count2(vector<vector<int> > M, int h1, int h2){
    for(int i=h1; i<=h2; i++){
        rep(j,W) M[i][j] = 2;
    }
    int cnt = 0;
    rep(i,H){
        rep(j,W){
            if(M[i][j] == 1) cnt++;
        }
    }
    return cnt;
}

int count3(vector<vector<int> > M, int w1, int w2){
    for(int i=w1; i<=w2; i++){
        rep(j,H) M[j][i] = 2;
    }
    int cnt = 0;
    rep(i,H){
        rep(j,W){
            if(M[i][j] == 1) cnt++;
        }
    }
    return cnt;
}


int main()
{
    cin >> H >> W >> K;
    vector<vector<int>> M(H, vector<int>(W));
    int sum = 0;
    rep(i,H){
        rep(j,W){
            char m; cin >> m;
            if(m == '.') M[i][j] = 0;
            else M[i][j] = 1;
            if(M[i][j] == 1) sum++;
        }
    }
    int cnt = 0;
    rep(h1, H){
        for(int h2 = h1; h2<H; h2++){
            rep(w1, W){
                for(int w2=w1; w2<W; w2++){
                    if(K == count(M, h1, h2, w1, w2)) cnt++;
                }
            }
        }
    }
    rep(h1, H){
        for(int h2=h1; h2<H; h2++){
            if(K == count2(M, h1, h2)) cnt++;
        }
    }
    rep(w1, W){
        for(int w2=w1; w2<W; w2++){
            if(K == count3(M, w1, w2)) cnt++;
        }
    }
    if(sum == K) cnt++;
    cout << cnt << endl;
}