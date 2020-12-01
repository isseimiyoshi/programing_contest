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

const double theta90 = 90*M_PI/180;
const double theta90m = 90*M_PI/180*(-1);

int n;
vector<pair<double, double> > A;

vector<pair<double, double> > calc(pair<double,double> p1, pair<double, double> p2){
    pair<double, double> q1, q2, q3, q4;
    q1.first = cos(theta90)*p2.first - sin(theta90)*p2.second + p1.first;
    q1.second = sin(theta90)*p2.first + cos(theta90)*p2.second + p1.second;
    q2.first = cos(theta90)*p1.first - sin(theta90)*p1.second + p2.first;
    q2.second = sin(theta90)*p1.first + cos(theta90)*p1.second + p2.second;
    vector<pair<double, double> > Q;
    Q.push_back(q1); Q.push_back(q2);
    q3.first = cos(theta90m)*p2.first - sin(theta90m)*p2.second + p1.first;
    q3.second = sin(theta90m)*p2.first + cos(theta90m)*p2.second + p1.second;
    q4.first = cos(theta90m)*p1.first - sin(theta90m)*p1.second + p2.first;
    q4.second = sin(theta90m)*p1.first + cos(theta90m)*p1.second + p2.second;
    Q.push_back(q3); Q.push_back(q4);
    return Q;
}

int binary_tree(int left, int right, pair<double,double> q){
    while(left < right){
        int mid = (left + right) / 2;
        if(q.first == A[mid].first){
            if(q.second == A[mid].second){
                return mid;
            }else if(q.second > A[mid].second) left = mid;
            else right = mid;
        }
        else if(q.first > A[mid].first) left = mid;
        else right = mid;
    }
    return 0;
}

bool search(int j, pair<double, double> q1, pair<double, double> q2){
    if(binary_tree(j,n, q1) && binary_tree(j,n,q2)) return true;
    else return false;
}


int main()
{
    cin >> n;
    rep(i,n){
        double x, y; cin >> x >> y;
        A.push_back(make_pair(x, y));
    }
    sort(A.begin(), A.end());
    double max = 0;
    rep(i,A.size()){
        for(int j=i+1; j<A.size(); j++){
            vector<pair<double, double> > Q(4);
            Q =  calc(A[i], A[j]);
            if(search(j, Q[0], Q[1])){
                double S = pow((A[i].first - A[j].first),2) + pow((A[i].second - A[j].second), 2);
                if(max < S) max = S;
            }
            if(search(j, Q[2], Q[3])){
                double S = pow((A[i].first - A[j].first),2) + pow((A[i].second - A[j].second), 2);
                if(max < S) max = S;
            }
        }
    }
    cout << max << endl;
}