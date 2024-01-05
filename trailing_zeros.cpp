#include<bits/stdc++.h>
using namespace std;

void func(vector<string>& l1, long long n) {
    if(n == 1) return;
    vector<string> l2 = l1;
    reverse(l2.begin(),l2.end());
    for(int i = 0; i < l1.size(); i++) {
        l1[i] = "0" + l1[i];
        l2[i] = "1" + l2[i];
    }
    l1.insert( l1.end(), l2.begin(), l2.end() );
    return func(l1,n-1);
}

int main() {
vector<string> l1 = {"0", "1"};
long long n;
cin>>n;
func(l1, n);
for(int i = 0; i < l1.size(); i++) {
    cout<<l1[i]<<endl;
}

return 0;
}