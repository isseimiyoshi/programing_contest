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

const ll MOD = 998244353;

const int MAX = 1000100;
// const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    COMinit();
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll power(int m, int n){
    ll res = 1;
    if(n > 0){
        res = power(m, n/2);
        if(n % 2 == 0) res = (res * res) % MOD;
        else res = (((res*res)%MOD) * m) % MOD;
    }
    return res;
}

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int black = (C-A) + (D-B);
    int red1 = (C-A)*B;
    int red2 = (D-B)*A;
    int green = (C-A)*(D-B);
    printf("black:%d green:%d red1:%d red2:%d\n", black, green, red1, red2);
    ll sum = 0;
    rep(i,C-A+1){
        rep(j, D-B+1){
            int k = black-i-j;
            printf("i:%d j:%d k:%d\n", i, j, k);
            if(green<k) continue;
            else{
                ll green_sum, red1_sum, red2_sum;
                if(k == 0) green_sum = 1;
                else green_sum = COM(green, k);
                if(i == 0) red1_sum = 1;
                else red1_sum = COM(C-A, i)*power(B,i);
                if(j == 0) red2_sum = 1;
                else red2_sum = COM(D-B,j)*power(A,j);
                sum += (green_sum*red1_sum%MOD)*red2_sum%MOD;
                sum %= MOD;
                printf("%d %d %d\n", green_sum, red1_sum, red2_sum);
                printf("sum: %d\n", (green_sum*red1_sum%MOD)*red2_sum%MOD);
            }
        }
    }
    cout << sum << endl;
}