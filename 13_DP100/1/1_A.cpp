#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

const int mod = 10000;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
struct mint {
  // 構造体の変数は public 変数であるためアクセス可能
  ll x; // typedef long long ll;

  // コンストラクタ
  mint(ll x=0):x((x%mod+mod)%mod){}

  // 単項演算子：符号やインクリメントなどを表すものなど
  // -（マイナス）演算子との区別は引数によって行う
  mint operator-() const { return mint(-x);}

  // 複合代入演算子のオーバーロード
  // *1 戻り値の型は必ず自分自身のクラスで参照を返す
  // *2 return文には「*this」を指定する
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }

  // 算術演算子のオーバーロード
  // 引数の型に & をつけることで参照を利用して受け取ることができる（コピーする必要がないため処理が高速化される）
  mint operator+(const mint a) const {  // メンバ変数の書き換えを防ぐために引数定義のあとに const をつけている
    mint res(*this);    // コピーコンストラクタ（コンパイラが自動で生成）
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
  // 素数の逆元計算にのみ有効
  mint inv() const { return pow(mod-2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

const int MAX = 1000100;
mint fac[MAX], finv[MAX], inv[MAX];
// 先にこれを行うことで O(1) で nCk を求められる
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i;
        finv[i] = finv[i-1]/i;
    }
}

mint COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * finv[k] * finv[n-k];
    // cout << COM(n,k).x << endl;
}

int main()
{
    int n, K; cin >> n >> K;

    int dist[n];
    rep(i,n) dist[i] = -1;

    rep(i,K){
        int ai, bi; cin >> ai >> bi;
        --ai; --bi;
        dist[ai] = bi;
    }

    mint dp[n][3][2];    // [何日目か][パスタの種類][連続で同じパスタが続いた日数]
    rep(i,n) rep(j,3) rep(k,2) dp[i][j][k] = 0;

    if(dist[0] >= 0){
        dp[0][dist[0]][0] = 1;
    }else{
        rep(j,3){
            dp[0][j][0] = 1;
        }
    }

    for(int i=1; i<n; i++){
        if(dist[i]>=0){
            rep(j,3){
                if(j == dist[i]){
                    dp[i][dist[i]][1] += dp[i-1][j][0];
                }else{
                    rep(k,2) dp[i][dist[i]][0] += dp[i-1][j][k];
                }
            }
        }else{
            rep(j,3){
                rep(k,3){
                    if(j == k){
                        dp[i][j][1] += dp[i-1][k][0];
                    }else{
                        rep(l,2){
                            dp[i][j][0] += dp[i-1][k][l];
                        }
                    }
                }
            }
        }
    }
    mint res(0);
    rep(j,3){
        rep(l,2){
            res += dp[n-1][j][l];
            // cout << dp[n-1][j][l].x << " ";
        }// cout << endl;
    }

    cout << res.x << endl;

}