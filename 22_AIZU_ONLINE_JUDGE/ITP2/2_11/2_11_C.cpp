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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

ll kaizyo(int n){
    if(n == 1) return 1;
    return n*kaizyo(n-1);
}

ll combi(int n, int k){
    return kaizyo(n)/kaizyo(k);
}

int main()
{
    int n; cin >> n;
    int k; cin >> k;
    queue<int> Q;
    rep(i,k){
        int ki; cin >> ki;
        Q.push(ki);
    }
    vector<ll> res;
    // lはキューからとる要素の個数
    for(int l=1; l<=k; l++){
        // キューから要素を取り出す回数
        ll m = combi(k ,l);
        rep(i,m){
            bitset<28> A(0);
            rep(j,l){
                int b = Q.front(); Q.pop();
                A.set(b); Q.push(b);
            }
            res.push_back(A.to_ullong());
        }
    }
    sort(res.begin(), res.end());
    printf("0:\n");
    for(ll re: res){
        if(pow(2,n) > re){
            bitset<28> R(re);
            printf("%ld:", re);
            rep(i, 28){
                if(R.test(i)) printf(" %d", i);
            }
            cout << endl;
        }
    }
}