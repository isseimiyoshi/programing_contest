#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

int pow(int x, int n){
    if(n == 0) return 1;
    ll res = pow(x*x, n/2);
    if(n%2 == 1){
        res *= x;
    }
    return x;
}

int main()
{
    int n; cin >> n;
    int nketa = (int)log10(n)+1;
    int nf = n / pow(10,nketa-1);
    int ne = n % 10;

    int ans = 0;

    for(int i=1; i<=n; i++){

        int iketa = (int)log10(i)+1;
        int ir = i / pow(10,iketa-1);
        int ie = i % 10;

        if(ie == 0) continue;

        while(iketa<=nketa){
            if(iketa == 1){
                ans++;
                iketa++;
            }else{
                if(ie*pow(10,iketa-1)+ir > n) break;

                if(ir == ne && ie == nf){
                    int ori_n = n;
                    ori_n -= nf * pow(10,nketa-1);
                    ori_n /= 10;
                    ans += ori_n;
                    break;
                }else{
                    ans += pow(10,iketa-2);
                }
                iketa++;
            }
        }
    }

    cout << ans << endl;
}