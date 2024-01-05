#include<bits/stdc++.h>
using namespace std;

class solution {
   public:
      int f(int i, int j, string& s1, string& s2) {
        if()
        if(s1[i] == s2[i]) return (1+f(i-1,j-1,s1,s2));
        return (min(f(i-1,j,s1,s2),f(i,j-1,s1,s2)));
      }
      int shortCommonsub(string& s1, string& s2) {
        int l1 = s1.length(), l2 = s2.length();
        int a = f(l1-1,l2-1,s1,s2);
        return a;
      }
};

int main() {
   string s1 = "bleed";
   string s2 = "blue";
   solution obj
   int ans = obj.shortCommonsub(s1,s2);
   cout<<"Recurssive solution: "<<ans<<endl;
   return 0;
}