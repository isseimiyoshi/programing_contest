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

struct node{
  struct node *right;   // 右の子のポインタを持たせる
  struct node *left;    // 左の子のポインタを持たせる
  struct node *parent;  // 親のポインタを持たせる
  int key;              // キー
};
typedef struct node * Node;
// #define NIL NULL
const int NIL = -1;

Node root;

/*
Node treeMinimum(Node x){


}

Node treeMaximum(Node x){


}

Node treeSearch(Node u, int k){


}

Node treeSuccessor(Node x){


}

void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y



}
*/

void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;

  // z = malloc(sizeof(struct node));  // node構造体サイズのメモリ領域をとる
  z->key = k;   // ポインタ変数にアクセスする時はアロー演算子
  z->left = NIL;
  z->right = NIL;
  
  while(x != NIL){
      y = x;    // 最終的なzの親を決定する
      if(z->key < x->key) x = x->left;
      else x = x->right;
  }
  z->parent = y;
  if(y == NIL){
      root = z; // 親要素が空であれば、zが根となる
  }else{
      if(z->key < y->key){
          y->left = z;
      }else{
          y->right = z;
      }
  }
}

void inorder(Node u){
    if(u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}
void preorder(Node u){
    if(u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}


int main(){
  int n, i, x;
  // string com;
  // scanf("%d", &n);
  cin >> n;
  vector<pair<string, int> > com(n);
  rep(i, n){
    string command; int x;
    cin >> command >> x;
    com[i].first = command; com[i].second = x;
  }
  rep(i, n){
      if(com[i].first == "insert"){
          insert(com[i].second);
      }else if(com[i].first == "print"){
          inorder(root);
        printf("\n");
        preorder(root);
        printf("\n");
      }
  }
  /*
  for ( i = 0; i < n; i++ ){
    // scanf("%s", com);
    cin >> com;
    if ( com[0] == 'f' ){
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if ( t != NIL ) printf("yes\n");
      else printf("no\n");
    } else if ( com == "insert" ){
      //scanf("%d", &x);
      cin >> x;
      insert(x);
    } else if ( com == "print" ){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if ( com[0] == 'd' ){
      scanf("%d", &x);
      treeDelete(treeSearch(root, x));
    }
  }
  */

  return 0;
}