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

const int MAX_LINE = pow(4, 7);
int n;
vector<double> x(MAX_LINE), y(MAX_LINE);

void coho(double x1, double y1, double x2, double y2, int rp){
    // printf("%.5lf %.5lf\n", x1, y1);
    double s_x, u_x, t_x, s_y, u_y, t_y;
    if(rp < n){
        s_x = x1 + (x2 - x1) / 3; s_y = y1 + (y2 - y1) / 3;
        t_x = x1 + 2*(x2 - x1)/3; t_y = y1 + 2*(y2 - y1)/3;
        u_x = cos(M_PI/3.0)*(t_x-s_x)-sin(M_PI/3.0)*(t_y-s_y) + s_x;
        u_y = sin(M_PI/3.0)*(t_x-s_x)-sin(M_PI/3.0)*(t_y-s_y) + s_y;
        coho(s_x, s_y, u_x, u_y, rp+1);
        coho(u_x, u_y, t_x, t_y, rp+1);
    }
    if(rp == n){
        s_x = x1 + (x2 - x1) / 3; s_y = y1 + (y2 - y1) / 3;
        t_x = x1 + 2*(x2 - x1)/3; t_y = y1 + 2*(y2 - y1)/3;
        u_x = cos(M_PI/3.0)*(t_x-s_x)-sin(M_PI/3.0)*(t_y-s_y) + s_x;
        u_y = sin(M_PI/3.0)*(t_x-s_x)-sin(M_PI/3.0)*(t_y-s_y) + s_y;
        printf("%.5lf %.5lf\n", x1, y1);
        printf("%.5lf %.5lf\n", s_x, s_y);
        printf("%.5lf %.5lf\n", u_x, u_y);
        printf("%.5lf %.5lf\n", t_x, t_y);
        printf("%.5lf %.5lf\n", x2, y2);
    }
    // if(rp == 1) printf("%.5lf %.5lf\n", x2, y2);
}

int main()
{
    cin >> n;
    // vector<pair<int,int> > coor;
    coho(0.0, 0.0, 100.0, 0.0, 1);
}