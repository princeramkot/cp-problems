	#include <iostream>
	#include<bits/stdc++.h>
	
	#include <algorithm>
	#define lli long long int
	#define li long int
	#define ld long double
	#define ll long long 
	using namespace std;

void reverse(vector<int>& ns){
	int l=0,r=ns.size()-1;
	while(l<r)
	{
		swap(ns[l],ns[r]);
		l++;
		r--;
		
	}
}
	
long getMaxArea(long long arr[], int n){
	
	   stack<int> s;
	   stack<int>s2;
 vector<int>ps;
 vector<int>ns;

 for(int i=0;i<n;i++)
 {
     
     if(s.empty())
     {
         s.push(i);
         ps.push_back(-1);
     }
     
     else if(arr[s.top()]>=arr[i])
     {
         while(s.size()!=0 && arr[s.top()]>=arr[i])
         {
             s.pop();
         }
         
         if(s.empty())
         {
         s.push(i);
         ps.push_back(-1);
         }
         else
         { 
         	ps.push_back(s.top());
             s.push(i);
         }
     }
     else
     {		 ps.push_back(s.top());
     	 	s.push(i);
        
	 }
 }
 
 
 
 
 
 for(int i=n-1;i>=0;i--)
 {
 	if(s2.empty())
 	{
 		s2.push(i);
 	ns.push_back(n);
	 }
	 
	 else if(arr[s2.top()]>=arr[i])
	 {
	 	while(s2.size()!=0 && arr[s2.top()]>=arr[i])
	 	s2.pop();
	 	
	 	if(s2.empty())
	 	{
	 	ns.push_back(n)	;
		 s2.push(i);
	 	
	 	}
	 	else
	 	{	ns.push_back(s2.top());
	 		s2.push(i);
	 		
		 }
	 	
	 	
	 }
	 else
	 {
	 	ns.push_back(s2.top());
	 	s2.push(i);
	 }
 }
 
 reverse(ns);
 
 long long curr=0;
 long long res=-1;
 for(int i=0;i<n;i++)
 {
 	curr=arr[i];
 	curr+=(i-ps[i]-1)*arr[i];
 	curr+=(ns[i]-i-1)*arr[i];
 
 	res=max(res,curr);
 
 	
 }
 return res;
	

	
	
}



   
	int main()
	{
	
 long long arr[]={6,2,5,4,5,1,6};
 
 
 cout<<getMaxArea(arr,7);

	return 0;
	
	}
