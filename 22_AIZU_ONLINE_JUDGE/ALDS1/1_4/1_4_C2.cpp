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

bool find(vector<string> dict, string s){
    sort(dict.begin(), dict.end());
    int left = 0; int right = dict.size();
    // 二分探索木
    while(left < right){
        int mid = (left + right) / 2;
        if(dict[mid] == s){
            return true;
        }else if(dict[mid] > s){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n; cin >> n;
    vector<string> dict;
    for(int i=0; i<n; i++){
        string command, s;
        cin >> command >> s;
        if(command == "insert"){
            dict.push_back(s);
        }else if(command == "find"){
            if(find(dict, s)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}