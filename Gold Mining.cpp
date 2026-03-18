#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, L1, L2, result = 0;
  cin >> n >> L1 >> L2;
  vector<int> a(n + 1), f(n + 1);
  deque<int> dq;

  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = 1; i <= n; ++i){
    if(i <= L1) f[i] = a[i];
    else{
       int high = i - L1;
       while(!dq.empty() && f[dq.back()] <= f[high]){
          dq.pop_back();
       }
       dq.push_back(high);
       while(!dq.empty() && dq.front() < i - L2){
         dq.pop_front();
       }
       f[i] = f[dq.front()] + a[i];
       result = max(result, f[i]);
    }
  }
  cout << result;
}
