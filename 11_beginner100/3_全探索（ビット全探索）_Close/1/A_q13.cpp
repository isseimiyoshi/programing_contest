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

const int MAX_R = 10;

int main()
{
    int R, C; cin >> R >> C;
    int A[R][C];
    rep(i,R){
        rep(j,C){
            cin >> A[i][j];
        }
    }
    // R行をひっくり返すパターンを列挙する
    int max_sum = 0;
    for(int tmp=0; tmp<(1<<R); tmp++){
        bitset<MAX_R> B(tmp);
        rep(i,R){
            if(B.test(i)){
                rep(j,C){
                    // i行目のせんべいを裏返す
                    if(A[i][j] == 1) A[i][j] = 0;
                    else A[i][j] = 1;
                }
            }
        }
        int sum = 0;
        rep(j,C){
            int count0 = 0;
            int count1 = 0;
            rep(i,R){
                if(A[i][j] == 0) count0++;
                else count1++;
            }
            if(count0 < count1){
                rep(i,R){
                    if(A[i][j] == 0) A[i][j] = 1;
                    else{
                        A[i][j] = 0;
                        sum++;
                    }
                }
            }else{
                rep(i,R){
                    if(A[i][j] == 0) sum++;
                }
            }
        }
        if(max_sum < sum) max_sum = sum;
    }
    cout << max_sum << endl;
}