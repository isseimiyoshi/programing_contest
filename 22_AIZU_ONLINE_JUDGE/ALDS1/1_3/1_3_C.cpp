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

void insert(int x, vector<int> &lis){
    int lis_size = lis.size();
    int ori_lis;
    for(int i=0; i<=lis_size; i++){
        if(i == 0) ori_lis = x;
        else ori_lis = lis[i-1];
        if(i == lis_size) lis.push_back(ori_lis);
        else lis[i] = ori_lis;
    }
}

void 

int main()
{
    int n; cin >> n;
    vector<int> lis;
    for(int i=0; i<n; i++){
        string command; int num;
        cin >> command >> num;

    }
}