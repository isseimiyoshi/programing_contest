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

void maxHeapify(vector<int> &A, int i, int H){
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left < H && A[i] < A[left]) largest = left;
    if(right < H && A[largest] < A[right]) largest = right;

    if(largest != i){
        swap(A[i], A[largest]);
        maxHeapify(A, largest, H);
    }
}

void buildMaxHeap(vector<int> &A, int H){
    for(int i = (H-1)/2; i>=0; i--){
        maxHeapify(A, i, H);
    }
}

int main()
{
    vector<int> A;    
    while(true){
        string c; cin >> c;
        if(c == "end"){
            break;
        }else if(c == "insert"){
            int x; cin >> x;
            A.push_back(x);
        }else if(c == "extract"){
            buildMaxHeap(A, A.size());
            cout << A[0] << endl;
            swap(A[0], A[A.size()-1]);
            A.pop_back();
        }else{
            continue;
        }
    }
}