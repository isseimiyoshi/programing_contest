#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll,ll>;

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

const int MAX_A = 1000100;

int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    int res[MAX_A];
    rep(i,MAX_A) res[i] = 0;

    rep(j,n){
        int ori_n = a[j];
        for(int i=2; i*i<=a[j]; i++){
            ll cnt = 0;
            while(ori_n%i == 0){
                cnt++;
                ori_n /= i;
            }
            if(cnt>=1) ++res[i];
        }
        if(ori_n*ori_n > a[j]) res[ori_n]++;
    }
    /*
    rep(i,n) cout << a[i] << endl;
    cout << endl;
    */
    bool ispair = true;
    bool isset = false;
    bool isnot = true;

    rep(i,MAX_A){
        if(res[i] > 1) ispair = false;
    }

    int g = 0;
    rep(i,n) g = __gcd(g, a[i]);
    if(g == 1) isset = true;

    if(ispair) cout << "pairwise coprime" << endl;
    else if(isset) cout << "setwise coprime " << endl;
    else cout << "not coprime" << endl;

    /*
    bool isprime[MAX_A];
    rep(i,MAX_A) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(int i=2; i*i<MAX_A; i++){
        if(isprime[i]){
            int j = i + i;
            while(j<=MAX_A){
                isprime[j] = false;
                j += i;
            }
        }
    }
    vector<int> prime;
    rep(i,MAX_A){
        if(isprime[i]) prime.push_back(i);
    }
    int primes = prime.size();
    */
    

}