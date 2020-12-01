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
    vector<tuple<int, int, int>> ijk;
    vector<int> R, G, B;
    // j-i == k-jを満たす(i, j, k)の組み合わせを列挙する)O(N**2)
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            int k = 2*j-i;
            if(k>=N){
                continue;
            }
            else{
                if(i == j || j == k) continue;
                else ijk.push_back(make_tuple(i, j, k));
            }
        }
    }
    int R_count = 0, G_count = 0, B_count = 0;
    for(int i=0; i<N; i++){
        char Si = (char)S[i];
        if(Si == 'R'){
            R.push_back(i);
            R_count += 1;
        }
        else if(Si == 'B'){
            B.push_back(i);
            B_count += 1;
        }
        else{
            G.push_back(i);
            G_count += 1;
        }
    }
    ll ans = R_count*G_count*B_count;
    for(auto tup: ijk){
        int i, j, k;
        tie(i, j, k) = tup;
        set<char> x;
        x.insert(S[i]);
        x.insert(S[j]);
        x.insert(S[k]);
        if(x.size() == 3) ans--;
    }
    if(R_count*G_count*B_count == 0) cout << 0 << endl;
    else cout << ans << endl;
}