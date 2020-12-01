#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int mod = 998244353;

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

int main()
{
    ll a, b, c, d; cin >> a >> b >> c >> d;
    mint dp[c+1][d+1];
    dp[a][b] = 1;

    // 初期値として、列のみ増やした場合と行のみ増やした場合を計算する
    for(int i=a+1; i<=c; i++) dp[i][b] = dp[i-1][b]*(mint)b;
    for(int i=b+1; i<=d; i++) dp[a][i] = dp[a][i-1]*(mint)a;

    /*
    重複組合せのように計算する。
    */
    for(int i=a+1; i<=c; i++){
        for(int j=b+1; j<=d; j++){
            dp[i][j] = dp[i-1][j]*(mint)j + dp[i][j-1]*(mint)i - dp[i-1][j-1]*(mint)(i-1)*(mint)(j-1);
        }
    }

    cout << dp[c][d].x << endl;
}