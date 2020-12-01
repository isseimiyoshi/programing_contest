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

bool binarySearch(int arr[], int dim, int key){
    int left = 0, right = dim;
    while(left < right){
        int mid = (left + right) / 2;
        if(arr[mid] == key){
            return true;
        }else if(key < arr[mid]){
            right = mid;
        }else if(key > arr[mid]){
            left = mid + 1;
        }
    }
    return false;
}

int main()
{
    int An; cin >> An;
    int A[An];
    for(int i=0; i<An; i++){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    int Bn; cin >> Bn;
    int B[Bn];
    int count = 0;
    for(int i=0; i<Bn; i++){
        int Bi; cin >> Bi;
        if(binarySearch(A, An, Bi)) count += 1;
    }
    cout << count << endl;
}