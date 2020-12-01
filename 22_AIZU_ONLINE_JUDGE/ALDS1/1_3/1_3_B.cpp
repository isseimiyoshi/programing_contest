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
    int n, q;
    cin >> n >> q;
    queue<pair<string, int> > robin;
    for(int i=0; i<n; i++){
        string name; int time;
        cin >> name >> time;
        robin.push(make_pair(name, time));
    }
    int sum_time = 0;
    while(!robin.empty()){
        pair<string, int> process = robin.front();
        if(process.second > q){
            process.second -= q;
            sum_time += q;
            robin.pop();
            robin.push(process);
        }else{
            sum_time += process.second;
            robin.pop();
            cout << process.first << " " << sum_time << endl;
        }
    }
}