#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int N; string S;
    cin >> N >> S;
    set<int> r,g,b;
    for(int i=0; i<N; i++){
        if(S[i] == 'R') r.insert(i);
        else if(S[i] == 'G') g.insert(i);
        else b.insert(i);
    }
    ll ans = r.size()*g.size()*b.size();
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            ll k = 2*j-i;
            if(k>N) break;
            set<char> x;
            x.insert(S[i-1]);
            x.insert(S[j-1]);
            x.insert(S[k-1]);
            if(x.size() == 3) ans--;
        }
    }
    cout << ans << endl;
}