#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

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
    int h, w; cin >> h >> w;
    int n = h*w;

    mint k2[n+1];
    k2[0] = 1;
    for(int i=1; i<=n; i++){
        k2[i] = k2[i-1]*2;
    }

    int a[h][w]; int Bn = 0; int Wn = 0;
    rep(i,h) rep(j,w){
        char moji; cin >> moji;
        if(moji == '#'){
            a[i][j] = 1;
            Bn += 1;
        }else{
            a[i][j] = 0;
            Wn += 1;
        }
    }

    int right[h][w], left[h][w], up[h][w], down[h][w];
    rep(i,h){
        rep(j,w){
            if(a[i][j] == 0){
                if(j == 0){
                    right[i][j] = 1;
                    continue;
                }else{
                    right[i][j] = right[i][j-1]+1;
                }
            }else{
                right[i][j] = 0;
            }
        }
    }
    rep(i,h){
        for(int j=w-1; j>=0; j--){
            if(right[i][j] == 0) left[i][j] = 0;
            else{
                if(j != w-1 && right[i][j+1] != 0) left[i][j] = left[i][j+1];
                else left[i][j] = right[i][j];
            }
        }
    }

    rep(j,w){
        rep(i,h){
            if(a[i][j] == 0){
                if(i == 0){down[i][j] = 1; continue;}
                else{ down[i][j] = down[i-1][j]+1;}
            }else{ down[i][j] = 0;}
        }
    }    
    rep(j,w){
        for(int i=h-1; i>=0; i--){
            if(down[i][j] == 0) up[i][j] = 0;
            else{
                if(i != h-1 && up[i+1][j] != 0) up[i][j] = up[i+1][j];
                else up[i][j] = down[i][j];
            }
        }
    }

    mint ans = 0;

    rep(i,h){
        rep(j,w){
            if(a[i][j] == 1) continue;

            ans += k2[Wn] - k2[Wn-(left[i][j]+up[i][j]-1)];
        }
    }

    cout << ans.x << endl;
    /*
    rep(i,h){
        rep(j,w) cout << left[i][j] << " ";
        cout << endl;
    }

    rep(i,h){
        rep(j,w) cout << up[i][j] << " ";
        cout << endl;
    }
    */
}