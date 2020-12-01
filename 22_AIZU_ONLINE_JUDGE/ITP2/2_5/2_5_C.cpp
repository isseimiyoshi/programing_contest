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
    int n; cin >> n;
    vector<int> A;
    rep(i,n){
        int Ai; cin >> Ai;
        A.push_back(Ai);
    }
    auto B = A;
    sort(A.begin(), A.end());
    vector<int> ori_A;
    rep(i,n) ori_A.push_back(-1);

    bool is = false;
    bool is2 = false;
    do{
        if(A == B){
            if(ori_A[0] != -1){
                rep(i,n){
                    cout << ori_A[i];
                    if(i != n-1) cout << " ";
                }
                cout << endl;
            }
            rep(i,n){
                cout << A[i];
                if(i != n-1) cout << " ";
            }
            cout << endl;
            is = true;
        }
        ori_A = A;
        if(is2){
            rep(i,n){
                cout << A[i];
                if(i != n-1) cout << " ";
            }
            cout << endl;
            break;
        }
        if(is) is2 = true;
    }while(next_permutation(A.begin(), A.end()));
}