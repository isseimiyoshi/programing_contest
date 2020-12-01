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

bool isPrime(int n){
    for(int i=2; i*i<=n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int Q; cin >> Q;
    // 最初に10^5までの素数を列挙した配列を作成する
    vector<int> prime_v;
    prime_v.push_back(2);   // 2は素数なので、vectorに値を入れる
    for(int i=3; i<=100000; i+=2){
        if(isPrime(i)) prime_v.push_back(i);
    }
    sort(prime_v.begin(), prime_v.end());
    // 2017に似た数字のみを配列として新しく作る
    vector<int> similar_v;
    for(int p: prime_v){
        int m = (p+1)/2;
        if(*lower_bound(prime_v.begin(), prime_v.end(), m) == m){
            similar_v.push_back(p);
        }
    }
    sort(similar_v.begin(), similar_v.end());
    rep(_,Q){
        int l, r; cin >> l >> r;
        auto itr_l = lower_bound(similar_v.begin(), similar_v.end(), l);
        auto itr_r = lower_bound(similar_v.begin(), similar_v.end(), r);
        if(*itr_l == *itr_r){
            if(*itr_l>l && *itr_r>r) cout << 0 << endl;
            else if(*itr_r == r) cout << 1 << endl;
        }
        else{
            cout << distance(itr_l, itr_r) << endl;
        }
    }
}