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
    int N; cin >> N;
    P coor[N];
    rep(i,N){
        cin >> coor[i].first >> coor[i].second;
    }
    vector<int> v; 
    rep(i,N) v.push_back(i);
    sort(v.begin(), v.end());
    vector<double> sumv;
    do{
        // 各順列についての処理を記述する
        double sum = 0;
        rep(i,N-1){
            double d = sqrt((coor[v[i]].first - coor[v[i+1]].first)*(coor[v[i]].first - coor[v[i+1]].first) + (coor[v[i]].second - coor[v[i+1]].second)*(coor[v[i]].second - coor[v[i+1]].second)); 
            sum += d;
        }
        sumv.push_back(sum);
    }while(next_permutation(v.begin(), v.end()));   // 全ての順列を列挙することができる
    double av = 0;
    for(double s: sumv){
        av += (s / sumv.size());
    }
    printf("%.7lf\n", av);

    return 0;
}