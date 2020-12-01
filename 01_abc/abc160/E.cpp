#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
*/

int main()
{
    int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    priority_queue<ll> p, q, r, all;
    // ll p[A], q[B], r[C];
    rep(i, A){
        ll Ai; cin >> Ai;
        p.push(Ai);
    }
    rep(i, B){
        ll Bi; cin >> Bi;
        q.push(Bi);
    }
    rep(i, C){
        ll Ci; cin >> Ci;
        r.push(Ci);
    }
    rep(i, X){
        all.push(p.top());
        p.pop();
    }
    rep(i, Y){
        all.push(q.top());
        q.pop();
    }
    rep(i, C){
        all.push(r.top());
        r.pop();
    }
    ll sum = 0;
    rep(i, X+Y){
        sum += all.top();
        all.pop();
    }
    /*
    while(X>0){
        if(p.empty()){
            sum += r.top(); r.pop();
        }else if(r.empty()){
            sum += p.top(); p.pop();
        }else if(p.empty() && r.empty()){
            break;
        }else{
            if(p.top() >= r.top()){
                sum += p.top(); p.pop();
            }else{
                sum += r.top(); r.pop();
            }
        }
        X--;
    }
    while(Y>0){
        if(q.empty()){
            sum += r.top(); q.pop();
        }else if(r.empty()){
            sum += q.top(); q.pop();
        }else if(q.empty() && r.empty()){
            break;
        }else{
            if(q.top() >= r.top()){
                sum += q.top(); q.pop();
            }else{
                sum += r.top(); r.pop();
            }
        }
        Y--;
    }
    */
    cout << sum << endl;
}