#include<bits/stdc++.h>
using namespace std;

// bool func(long i, long s1, long s2, long n) {
//   if(s1 == s2) return 1;
//   if(i > n) return 0;
//   bool t1 = func(i + 1,s1 + i,s2 - i, n);
//   bool t2 = func(i + 1, s1, s2, n);
//   return t1||t2;
// }

int main() {
  long n;
  cin>>n;
  vector<long> v;
  for(int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  long sum = (n+1)*(n);
  if(sum % 4 != 0) {
    cout<<"NO"<<endl;
    return 0;
  }
  else {
    cout<<"YES"<<endl;
    if(n % 2 == 0) {
      long num = n / 2;
      long s = 0, e = n-1;
      long i = 0;
      cout<<num<<endl;
      while(i < num) {
        cout<<v[s]<<" "<<v[e]<<" ";
        s++,e--;
        i+=2;
      }
      i = 0;
      cout<<endl;
      cout<<num<<endl;
      while(i < num) {
        cout<<v[s]<<" "<<v[e]<<" ";
        s++,e--;
        i+=2;
      }
    }
    else {
      int num = n / 2;
      int s = 0, e = n-1;
      int i = 1;
      cout<<num<<endl;
      while(i < num) {
        cout<<v[s]<<" "<<v[e]<<" ";
        s++,e--;
        i+=2;
      }
      cout<<v[e]<<endl;
      e--;
      cout<<n - num<<endl;
      while(s < e) {
           cout<<v[s]<<" "<<v[e]<<" ";
        s++,e--;
      }
    }
  }
return 0;
}