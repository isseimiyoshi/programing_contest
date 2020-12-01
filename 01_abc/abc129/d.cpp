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

int main()
{
    int H, W; cin >> H >> W;
    vector<bool> mass;
    rep(i, H*W){
        char m; cin >> m;
        if(m=='#') mass.push_back(false);
        if(m=='.') mass.push_back(true);
    }
    vector<int> hor(H*W);
    vector<int> ver(H*W);
    rep(i,H){
        vector<int> wallj;
        rep(j,W){
            if(mass[i*H+j] == false) wallj.push_back(j);
        }
        rep(wj, wallj.size()-2){
            for(int k=0; k<wallj[0]; k++){
                if(k == wallj[0]) hor[i*H+k] = 0;
                hor[i*H+k] = wallj[0]-1;
            }
            for(int k=wallj[wj]; k<wallj[wj+1]; k++){
                if(k == wallj[wj] || k == wallj[wj+1]){
                    hor[i*H+k] = 0;
                }else{
                    hor[i*H+k] = wallj[wj+1]-wallj[wj]-1;
                }
            }
        }
    }
    rep(i,W){
        vector<int> Hj;
        rep(j,H){
            if(mass[j*H+i] == false) Hj.push_back(j);
        }
        rep(hj, Hj.size()-2){
            for(int k=0; k<Hj[0]; k++){
                if(k == Hj[0]) ver[k*H+i] = 0;
                ver[k*H+i] = Hj[0]-1;
            }
            for(int k=Hj[hj]; k<Hj[hj+1]; k++){
                if(k == Hj[hj] || k == Hj[hj+1]){
                    ver[k*H+i] = 0;
                }else{
                    ver[k*H+i] = Hj[hj+1]-Hj[hj]-1;
                }
            }
        }
    }
    vector<int> res(H*W);
    rep(i,H*W){
        res[i] = hor[i]+ver[i];
    }
    int max_n = 0;
    for(int re: res){
        if(max_n < re) max_n = re;
    }
    cout << max_n-1 << endl;
}