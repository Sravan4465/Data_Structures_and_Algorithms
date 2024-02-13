#include<bits/stdc++.h>
using namespace std;

class solution {
   public:
     int f(int i, int buy, vector<int>& v) {
        if(i==v.size()) return 0;
        int p1 = 0,p2 = 0;
        if(buy) {
            p1 = -v[i] + f(i+1,0,v);
            p2 = f(i+1,1,v);
        }
        else {
            p1 = v[i] + f(i+1,1,v);
            p2 = f(i+1,0,v);
        }
        return max(p1,p2);
     }
     int maxProfit(vector<int>& v) {
         int a = f(0,1,v);
         int n = v.size();
         vector<vector<int>> dp(n+1,vector<int>(2,0));
         dp[n][0] = 0;
         dp[n][1] = 0;
         for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                int p1 = 0, p2 = 0;
                if(j) {
            p1 = -v[i] + dp[i+1][0];
            p2 = dp[i+1][1];
        }
        else {
            p1 = v[i] + dp[i+1][1];
            p2 = dp[i+1][0];
        }
        dp[i][j] =  max(p1,p2);
         }
         }
         cout<<dp[0][1]<<endl;
         return a;
     }

};

int main() {
   vector<int> v = {7,1,5,3,6,4};
   solution obj;
   int ans = obj.maxProfit(v);
   cout<<"Recursive solution: "<<ans<<endl;
   return 0;
}