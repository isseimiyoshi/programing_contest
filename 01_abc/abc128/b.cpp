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
    vector<tuple<string, int, int> > T;
    int N; cin >> N;
    rep(i,N){
        string Si; int Pi;
        cin >> Si >> Pi;
        T.push_back(make_tuple(Si, Pi, i+1));
    }
    sort(T.begin(), T.end());
    vector<tuple<int, string, int> > Tpart;
    string ori_S = "";
    rep(i,T.size()-1){
        string s; int v, n;
        tie(s,v,n) = T[i];
        if(i == 0){
            ori_S = s;
            Tpart.push_back(make_tuple(v, s, n));
        }else{
            if(ori_S == s){
                Tpart.push_back(make_tuple(v, s, n));
            }else{
                sort(Tpart.begin(), Tpart.end(), greater<tuple<int, string , int>>());
                rep(j,Tpart.size()-1){
                    string ps; int pv, pn;
                    tie(pv, ps, pn) = Tpart[j];
                    cout << pn << endl;
                }
                Tpart.clear();
                ori_S = s;
                Tpart.push_back(make_tuple(v, s, n));
            }
        }
        if(i == T.size()-1){
            sort(Tpart.begin(), Tpart.end(), greater<tuple<int, string, int>>());
            rep(j,Tpart.size()-1){
                string ps; int pv, pn;
                tie(pv, ps, pn) = Tpart[j];
                cout << pn << endl;
            }
        }
    }
}