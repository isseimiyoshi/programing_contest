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

const int MOD = 1000000007;

int main()
{
    int N, K; cin >> N >> K;
    int A[N];
    rep(i,N) cin >> A[i];

    sort(A, A+N);

    // rep(i,N) cout << A[i] << endl;
    int mInd = 0;
    int Ind = N-1;

    // L1：選ぶ要素の個数が偶数のとき
    // 昨日考えたアルゴリズムでいける

    // L1：選ぶ要素の個数が奇数のとき
    // L2：選択肢要素がすべて奇数の場合
    // L2：選択肢要素がすべて奇数という条件に当てはまらない場合
    ll sum = 1;
    if(K % 2 == 0){
        int mInd_ch = -1;
        int Ind_ch = -1;
        rep(k,K){
            if(abs(A[mInd]) >= abs(A[Ind])){
                sum *= A[mInd];
                if(A[mInd] < 0 && A[mInd+1] >= 0 && mInd_ch < 0) mInd_ch = mInd;
                mInd++;
            }else{
                sum *= A[Ind];
                if(A[Ind] > 0 && A[Ind-1] <= 0 && Ind_ch < 0) Ind_ch = Ind;
                Ind--;
            }
            if(k == K-1){
                if(sum < 0){
                    if(A[Ind] >= 0){
                        sum /= A[mInd_ch];
                        sum *= Ind;
                    }else{
                        sum /= A[Ind_ch];
                        sum *= A[mInd];
                    }
                }
            }
            sum %= MOD;
        }
    }else{
        if(A[N-1] == 0) sum = 0;
        else if(A[N-1] < 0){
            rep(_,K){
                sum *= A[Ind];
                Ind--;
                sum %= MOD;
            }
        }else{
            int mInd_ch = -1;
            int Ind_ch = -1;
            rep(k,K){
                if(abs(A[mInd]) >= abs(A[Ind])){
                    sum *= A[mInd];
                    if(A[mInd] < 0 && A[mInd+1] >= 0 && mInd_ch < 0) mInd_ch = mInd;
                    mInd++;
                }else{
                    sum *= A[Ind];
                    if(A[Ind] > 0 && A[Ind-1] <= 0 && Ind_ch < 0) Ind_ch = Ind;
                    Ind--;
                }
                if(k == K-1){
                    if(sum < 0){
                        if(A[Ind] >= 0){
                            sum /= A[mInd_ch];
                            sum *= Ind;
                        }else{
                            sum /= A[Ind_ch];
                            sum *= A[mInd];
                        }
                    }
                }
                sum %= MOD;
            }
        }
    }
    if(sum < 0) cout << (MOD+sum) << endl;
    else cout << sum << endl;
}