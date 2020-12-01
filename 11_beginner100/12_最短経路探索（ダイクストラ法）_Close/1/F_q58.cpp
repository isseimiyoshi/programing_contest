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

const int MAX_N = 100100;
const ll INF = pow(10,18);
const int WHITE = 0, GRAY = 1, BLACK = 2;

vector<int> to1[MAX_N]; // 危険な街をBFSで求めるための隣接リスト
ll dis1[MAX_N];
bool isDanger[MAX_N], isZonbi[MAX_N];

vector<pair<ll, ll>> to2[MAX_N];
ll dis2[MAX_N]; int color[MAX_N];



void init(){
    rep(i,MAX_N){
        dis1[i] = INF;
        dis2[i] = INF;
        isDanger[i] = false;
        isZonbi[i] = false;
        color[i] = WHITE;
    }
}

void bfs(int s){
    queue<int> q;
    q.push(s);
    dis1[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: to1[u]){
            if(dis1[v] == INF){
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
        }
    }
}

void dijkstra(int s){
    dis2[s] = 0;
    priority_queue<pair<ll, ll>> pq;
    pq.push(make_pair((-1)*dis2[s], s));
    while(!pq.empty()){
        pair<ll, ll> p_u = pq.top(); pq.pop();
        ll u = p_u.second; ll uh = (-1)*p_u.first;
        color[u] = BLACK;
        if(dis2[u] < uh) continue;
        for(auto p_v: to2[u]){
            ll v = p_v.first; ll vh = p_v.second;
            if(dis2[v] > dis2[u] + vh && color[v] != BLACK){
                dis2[v] = dis2[u] + vh;
                color[v] = GRAY;
                pq.push(make_pair((-1)*dis2[v], v));
            }
        }
    }
}

int main()
{
    int N, M, K, S; cin >> N >> M >> K >> S;
    int P, Q; cin >> P >> Q;
    int C[K];
    rep(i,K) cin >> C[i], C[i]--;
    int A[M], B[M];
    rep(i,M){
        int Ai, Bi; cin >> Ai >> Bi; --Ai; --Bi;
        to1[Ai].push_back(Bi);
        to1[Bi].push_back(Ai);
        A[i] = Ai; B[i] = Bi;
    }
    // 危険な街を求める
    init();
    // 仮想の町Nを仮定し、これはゾンビに支配されている町すべてとつながっているものとする
    // このように仮想の町を設定することにより一回のBFSで危険な街をすべて把握することができる
    rep(i,K) to1[N].push_back(C[i]);
    bfs(N);
    rep(i,N) if(dis1[i] <= S+1) isDanger[i] = true;
    rep(i,K) isZonbi[C[i]] = true;
    rep(i,M){
        if(isZonbi[B[i]]) to2[A[i]].push_back(make_pair(B[i], INF));
        else if(isDanger[B[i]]) to2[A[i]].push_back(make_pair(B[i], Q));
        else to2[A[i]].push_back(make_pair(B[i], P));

        if(isZonbi[A[i]]) to2[B[i]].push_back(make_pair(A[i], INF));
        else if(isDanger[A[i]]) to2[B[i]].push_back(make_pair(A[i], Q));
        else to2[B[i]].push_back(make_pair(A[i], P));
    }
    dijkstra(0);
    cout << (dis2[N-1]-P) << endl;

    // rep(i,N) cout << dis1[i] << endl;

}