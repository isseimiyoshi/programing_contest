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
＊substrは、端の処理が普通と違うので面倒＊

string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"
*/

int main()
{
    string s; cin >> s;
    int m; cin >> m;
    for(int i=0; i<m; i++){
        string command; cin >> command;
        if(command == "print"){
            int a, b;
            cin >> a >> b;
            if(a == 0){
                cout << s.substr(0,b+1) << endl;
            }else{
                cout << s.substr(a,b) << endl;
            }
        }else if(command == "reverse"){
            int a, b;
            cin >> a >> b;
            if(a == 0){
                string pick_s = s.substr(0, b+1);
                string b_s = s.substr(b+1);
                reverse(pick_s.begin(), pick_s.end());
                s = pick_s + b_s;
            }else{
                string pick_s = s.substr(a,b+1);
                string f_s = s.substr(0,a);
                string b_s = s.substr(b+1);
                reverse(pick_s.begin(), pick_s.end());
                s = f_s + pick_s + b_s;
            }
            // cout << s << endl;
        }else if(command == "replace"){
            int a, b;
            cin >> a >> b;
            string in_s; cin >> in_s;
            if(a == 0){
                s = in_s + s.substr(b+1);
            }else{
                s = s.substr(0,a) + in_s + s.substr(b+1);
            }
            // cout << s << endl;
        }
    }
}