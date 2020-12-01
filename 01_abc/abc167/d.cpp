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
    ll N, K; cin >> N >> K;
    vector<ll> A(N); //vector<ll> cnt(N); // 循環回数を数えるためのベクトル
    rep(i,N){
        cin >> A[i]; A[i]--;    // 0オリジンのためにデクリメント
        //cnt[i] = 0;
    }
    int next = 0; //cnt[0]++;
    ll cnt1 = 0, cnt2 = 0;
    ll start;

    set<int> S;
    S.insert(next);
    rep(_,N){
        next = A[next];
        if(S.count(next)){
            start = next;
            break;
        }else{
            S.insert(next);
        }
        // cout << i << endl;
    }
    //cout << start << endl;
    ll count = 0; next = 0;
    rep(_,N){
        if(next == start){
            cnt1 = count;
            break;
        }
        next = A[next];
        count++;
    }
    //cout << cnt1 << endl;
    count = 0; next = start;
    rep(_,N){
        next = A[next];
        count++;
        if(next == start){
            cnt2 = count;
            break;
        }
    }
    //cout << cnt2 << endl;
    /*
    while(true){
        cnt[next]++;
        next = A[next];
        count++;
        // cout << next << endl;
        rep(i,N){
            // cout << cnt[i] << " ";
            if(cnt[i] == 2 && cnt1 == 0){
                cnt1 = count;
                start = i;
            }
            if(cnt[i] == 3){
                cnt2 = count;
                isRoop = true;
                break;
            }
        }
        // cout << endl;
        if(isRoop) break;
    }
    */

    // 循環回数の決定
    ll roop = cnt2 - cnt1;
    // 循環する番号に行くまでのループ回数を決定する
    ll cnt0; next = 0; count = 0;
    rep(i,N){
        if(next == start){
            cnt0 = count;
        }else{
            count++;
            next = A[next];
        }
    }
    // cout << cnt0 << endl;
    // cout << roop << endl;
    // 情報が揃ったので仕上げ
    if(K < cnt0){
        next = 0;
        rep(_,K){
            next = A[next];
        }
        next++;
        cout << next << endl;
    }
    else{
        K = K - cnt0;
        K = K % roop;
        next = start;
        rep(_,K){
            next = A[next];
        }
        next++;
        cout << next << endl;
    }
}