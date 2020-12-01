#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int pow(int x, int n){
    if(n == 0) return 1;
    ll res = pow(x*x, n/2);
    if(n%2 == 1){
        res *= x;
    }
    return x;
}

int f(int x, int n){
    int res = 0;

    int nketa = (int)log10(n)+1;
    int xketa = (int)log10(x)+1;

    int xf = x / pow(10,xketa-1);
    int xe = x % 10;
    if(xe == 0) return 0;

    int nf = n / pow(10,nketa-1);
    int ne = n % 10;
    /*
    printf("x:%d n:%d\n", x, n);
    printf("xf:%d xe:%d\n", xf, xe);
    printf("nf:%d ne:%d\n", nf, ne);
    */
    int betw = 0;
    while(true){
        if(betw+1 > nketa) break;

        if(betw == 0){
            if(xf == xe) res++;
            betw++;
        }else if(betw == 1){
            if(10*xe+xf > n) break;
            else{
                res++;
                betw++; 
            }
        }else if(betw+1 == nketa){
            if(xe > nf) break;
            else if(xe == nf && xf>ne) break;
            else if(xe == nf && xf == ne){
                n -= nf * pow(10,nketa-1);
                n /= 10;
                res += n;
                break;
            }else{
                res += pow(10,betw-1);
                break;
            }
        }else{
            res += pow(10,betw-1);
            betw++;
        }
    }
    cout << res << endl << endl;
    return res;
}

int main()
{
    int n; cin >> n;

    int ans = 0;
    for(int i=1; i<=n; i++){
        ans += f(i,n);
    }
    cout << ans << endl;
    return 0;
    
}