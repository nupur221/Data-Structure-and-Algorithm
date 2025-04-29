#include<bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define checkmate           return 0
#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl
#define vmax               *max_element(v.begin(),v.end())
#define vmin               *min_element(v.begin(),v.end())
#define fast()              ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl                '\n'
const int N = (int) 1e6+5;
using namespace std;

void merge(vector<int>& v , int low , int mid, int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> temp1(n1), temp2(n2);
    for (int i = 0; i < n1; i++)
        temp1[i] = v[low + i];
    for (int i = 0; i < n2; i++)
        temp2[i] = v[mid + 1 + i];
    int i = 0; 
    int j = 0; 
    int k = low; 
    while (i < n1 && j < n2) {
        if (temp1[i] <= temp2[j]) {
            v[k] = temp1[i];
            i++;
        } else {
            v[k] = temp2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = temp1[i];
        i++;
        k++;
    }
    while (j < n2) {
        v[k] = temp2[j];
        j++;
        k++;
    }
}
void mergesort(vector<int>& v , int low , int high){
     if (low < high) {
        int mid = low + (high - low) / 2;
        mergesort(v, low , mid);
        mergesort(v, mid+1 , high);

        merge(v, low, mid, high);
     }
}
int main(){
    //fast();
    int n; 
    cout << "Enter the number of elements: ";
    cin>>n;

    vector<int>v(n);
    cout << "Enter the elements: ";
    for(int i = 0; i<n ; i++) cin>>v[i];
    
    mergesort(v, 0, n-1);

    cout<<"Sorted Array is :";
    for(int i = 0; i<n ; i++) cout<<v[i]<<" ";
    cout<<endl;
   
   checkmate;
}

