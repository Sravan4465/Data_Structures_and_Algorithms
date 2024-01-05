#include<bits/stdc++.h> 
using namespace std;

int main() {
     vector <int> v = {12,4,55,67,2,3,34};
     int key;
     for(int i=1;i<v.size();i++) {
        int k = v[i];
        int j = i-1;
        while(j>=0 && v[j]>k) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
     }
     for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
     }
     cout<<endl;
     return 0;
}