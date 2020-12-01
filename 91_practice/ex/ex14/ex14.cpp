#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int minN = min(min(A, B), C);
  int maxN = max(max(A, B), C);
  cout << maxN - minN << endl;
}
