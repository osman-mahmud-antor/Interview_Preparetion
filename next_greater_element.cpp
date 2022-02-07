// Simple C++ program to print
// next greater elements in a array
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int next,i,j;
    for(i=0;i<n;++i){
        next=-1;
        for(j=i+1;j<n;++j){
            if(arr[i]<arr[j]){
                next=arr[j];
                break;
            }
        }
        cout<<arr[i]<<"-->"<<next<<endl;
    }
    return 0;
}
//Time Complexity: O(n^2)
