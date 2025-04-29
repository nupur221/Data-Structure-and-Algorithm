
//***********  Index Search   ***************//

#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
     int n;   cin>>n;
     vector<int> v(n);
     for(int i = 0; i<n ; i++) cin>>v[i];
     int target;   cin>>target;
     int l = 0, r = v.size()-1;
     bool done = false; 
     while(l <= r){
          int mid = (l+r)/2;

          if(v[mid] == target){
               cout<< mid<<endl;
               done = true;
               break;
          }
          if(v[mid] < target){
               l = mid+1;
               //cout << "Element Found : " << (l = mid+1) << " th index" << endl;
          }
          else{
               r = mid - 1;
              // cout << "Element Found : " << (r = mid - 1) << " th index" << endl;
          } 
     }
     if(!done) cout << -1 << endl;

}


// practice problem : leetcode --> 704.Binary search

/*
Note 1 : Binary search always followed by sorted array.
Note 2 : In this code I found the Index of target element 
*/