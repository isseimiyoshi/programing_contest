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

vector<pair<int, int> > A;
int n;

bool search(pair<int, int> q, int left, int right){
    while(left < right){
        int mid = (left + right) / 2;
        if(A[mid] == q) return true;
        else if(A[mid] < q) left = mid+1;
        else right = mid;
    }
    return false;
}

int main()
{
    cin >> n;
    rep(_,n){
        int xi, yi; cin >> xi >> yi;
        A.push_back(make_pair(xi, yi));
    }
    sort(A.begin(), A.end());   // x座標を基準にして昇順でソートする
    int max_squ = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            pair<int, int> p1 = A[i], p2 = A[j];
            pair<int, int> q1, q2;
            // 選択した２点を結んだ辺を使用して正方形をなす点を計算して求める
            q1.first = p1.first - (p2.second - p1.second);
            q1.second = p1.second + (p2.first - p1.first);
            q2.first = p2.first - (p2.second - p1.second);
            q2.second = p2.second + (p2.first - p1.first);
            // printf("p1(%d, %d), p2(%d, %d), q1(%d, %d), q2(%d, %d)\n", p1.first, p1.second, p2.first, p2.second, q1.first, q1.second, q2.first, q2.second);
            if(search(q1, 0, n) && search(q2, 0, n)){
                int squ = (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
                // printf("squ: %d\n", squ);
                if(max_squ < squ) max_squ = squ;
            }
        }
    }
    cout << max_squ << endl;
}