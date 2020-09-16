#include <iostream>
#include<bits/stdc++.h>
using namespace std;





int main(int argc, char** argv) {
		unordered_map<long long,long long> map;
	long long n;cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	long long sum=arr[0],gsum=sum;
	long long ct=0;
	
map[arr[0]]=1;
int i=0,j=1;
while(i<n-1 && j<n)
	{
		if(map.find(arr[j])==map.end())
		{
			sum+=arr[j];
			gsum=max(sum,gsum);
			map[arr[j++]]=1;
		}
		else
		{
				sum-=arr[i];
			map.erase(arr[i]);
			i++;
		
			
		}
	}
	cout<<gsum<<endl;
	
	return 0;
}
