#include<iostream>
using namespace std;
int main()
{
int n;
 while(cin>>n)
 {
 int arr[100];
 for(int i=0;i<n;i++)
 {
 cin>>arr[i];
 }
 int m=arr[0];
 for(int i=1;i<n;i++)
 {
 if(arr[0]%arr[i]!=0)
{
 arr[0]+=m;
 i=0;
}
 }
 cout<<arr[0]<<endl;
 
 
 }
 return 0;
}

