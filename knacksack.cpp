#include<bits/stdc++.h>
using namespace std;

class solution {
   public:
   int knacksack(int w, vector<int>& val, vector<int>& wt, int s1, int s2,int id) {
    if(id == 0) {
        if(wt[0] <= w) return val[0];
        else return 0;
    }
    int not_take = knacksack(w,val,wt,s1,s2,id-1);
    int take = INT_MIN;
    if(wt[id] <= w) {
        take = val[id] + knacksack(w-wt[id], val, wt, s1,s2, id-1);
    }
    return max(take, not_take);

   }

};

int main() {

solution obj;

vector<int> wt = {6,1,5,3};
vector<int> val = {3,6,1,4};
int w = 10;
int s1 = wt.size(), s2 = val.size();
int ans = obj.knacksack(w,val,wt,s1,s2,s1-1);
cout<<ans<<endl;
return 0;
}