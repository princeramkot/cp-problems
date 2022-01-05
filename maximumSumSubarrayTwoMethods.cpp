#include <iostream>
#include<bits/stdc++.h>

using namespace std;


    int maxSubArrayKadaneAlgo(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        int msum=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<nums[i])
                sum=nums[i];
            msum=max(sum,msum);
           
        }
        return msum;
        
    }
    
    long long int maxSubArrayDivideAndConc(long long int nums[],int i,int j){
    	
    	if(i==j)
    	return nums[j];
    
    	int mid=(i+j)/2;
    	long long sum=0;
    	long long int leftMaxSum=INT_MIN;
    	for(int p=mid;p>=i;p--){
    		sum+=nums[p];
    		leftMaxSum=max(leftMaxSum,sum);
		}
    
    	
    	long long int rightMaxSum=INT_MIN;
    	sum=0;
    	for(int p=mid+1;p<=j;p++){
    			sum+=nums[p];
    			rightMaxSum=max(rightMaxSum,sum);
		}
    
    	long long int maxLeftRight= max(maxSubArrayDivideAndConc(nums,mid+1,j),
		maxSubArrayDivideAndConc(nums,i,mid));
		
		return max(maxLeftRight, leftMaxSum+rightMaxSum);
    	
	}
    
int main() {
	long long int arr[5];
	arr[0]=-10;
	arr[1]=-4;
	arr[2]=-36;
	arr[3]=-5;
	arr[4]=-3;
		
	cout<<maxSubArrayDivideAndConc(arr,0,4);
	return 0;
}
