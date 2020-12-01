#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int mod = 1000000007;

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
    string s; cin >> s;
    int n = s.size();

    mint dp[n+1][4];
    rep(i,n+1) rep(j,4) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i,n){
        
        if(s[i] == 'A'){         // i番目の文字がAまたは?　かつ　その文字を採用する場合
            rep(j,4) dp[i+1][j] += dp[i][j];
            dp[i+1][1] += dp[i][0];
        }
        if(s[i] == 'B'){   // i番目の文字がBまたは?　かつ　その文字を採用する場合
            rep(j,4) dp[i+1][j] += dp[i][j];
            dp[i+1][2] += dp[i][1];
        }
        if(s[i] == 'C'){   // i番目の文字がCまたは?　かつ　その文字を採用する場合
            rep(j,4) dp[i+1][j] += dp[i][j];
            dp[i+1][3] += dp[i][2];
        }
        if(s[i] == '?'){
            dp[i+1][0] = dp[i][0];
            rep(j,3) dp[i+1][j+1] += (mint)3*dp[i][j+1];
            dp[i+1][1] += dp[i][0];
            dp[i+1][2] += dp[i][1];
            dp[i+1][3] += dp[i][2];
        }
    }

    cout << dp[n][3].x << endl;
}