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

const int INF = 1000100100;

int main()
{
    int N, Q; cin >> N >> Q;
    int belong[N];                      // 各幼児が所属する幼稚園の番号
    int rate[N];                        // 各幼児のレート
    vector<int> park_infant[200000];    // 幼稚園にどの幼児がいるのか
    int min_per_park[200000];
    rep(i,200000) min_per_park[i] = 0;
    int fair = INF;
    rep(i,N){
        int Ai, Bi; cin >> Ai >> Bi; --Bi;
        belong[i] = Bi;
        rate[i] = Ai;
        park_infant[Bi].push_back(i);
        if(min_per_park[belong[i]] < rate[i]){
            min_per_park[belong[i]] = rate[i];
            if(fair < min_per_park[belong[i]]) fair = min_per_park[belong[i]];
        }
    }
    rep(_,Q){
        int Ci, Di; cin >> Ci >> Di; --Ci, --Di;
        remove(park_infant[belong[Ci]].begin(), park_infant[belong[Ci]].end(), Ci);
        int be_bel_inf = belong[Ci];
        min_per_park[be_bel_inf] = 0;
        for(int infant: park_infant[be_bel_inf]){
            if(min_per_park[be_bel_inf] < rate[infant]) min_per_park[be_bel_inf] = rate[infant];
        }
        if(fair > min_per_park[be_bel_inf]) fair = min_per_park[be_bel_inf];
        
        park_infant[Di].push_back(Ci);
        if(min_per_park[Di] < rate[Ci]){
            min_per_park[Di] = rate[Ci];  
            if(fair > min_per_park[Di]) fair = min_per_park[Di];
        }
        
        cout << fair << endl;
    }
}