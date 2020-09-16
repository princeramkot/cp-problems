#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int constructstree(long long arr[],int l,int r,int *st,int pos)
{
	if(l==r)
	{
		st[pos]=arr[l];
		return arr[l];
	}
	
	int mid=(l+r)/2;
	
	st[pos]=constructstree(arr,l,mid,st,2*pos+1)+
	constructstree(arr,mid+1,r,st,2*pos+2);
	
	return st[pos];

}

int getsum(int *st,int ss,int se,int qs,int qe,int si )
{
	if(ss>= qs && se<=qe)
	return st[si];
	
if(ss>qe || se<qs)
return 0;
	
int mid=(ss+se)/2;

return getsum(st,ss,mid,qs,qe,2*si+1)+
		getsum(st,mid+1,se,qs,qe,2*si+2);


}

// i is the the index where value needs to be changed
void update(int *st,int ss,int se,int i,long long diff,int si)
{
	if(ss>i || se<i)
	return ;
	
	st[si]=st[si]+diff;
	
		if(se!=ss)
	{
		int mid=ss+(se-ss)/2;
		update(st,ss,mid,i,diff,2*si+1);
		update(st,mid+1,se,i,diff,2*si+2);
	}
}


void updatehelper(long long arr[],int *st,int n,int i,long long new_val)
{
	if(i<0 || i>n-1)
	return;
	
	long long diff=new_val-arr[i];
	arr[i]=new_val;
	
	update(st,0,n-1,i,diff,0);
	

	
	
}


void print_seg(int *st,int n,int index)
{
cout<<endl;
for(int i=0;i<n;i++)
cout<<st[i]<<" ";
	
}

int main(int argc, char** argv) {

long long n;cin>>n;
long long arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];


int x=(int)(ceil(log2(n)));

int max_size=2*(int)pow(2,x)-1;

int *st=new int[max_size];

constructstree(arr,0,n-1,st,0);


//print_seg(st,max_size,0);


long long q;cin>>q;
while(q--)
{	cout<<"enter range "<<endl;
	int l,r;cin>>l>>r;
	cout<<getsum(st,0,n-1,l,r,0)<<endl;
	
	cout<<"want to update press 1 else press any other button "<<endl;
	int i,new_val, choise;cin>>choise;
	if(choise==1)
	{
	cout<<"enter index and value u want to update"<<endl;
	 cin>>i>>new_val;
	
	updatehelper(arr,st,n,i,new_val);
	
	//i would be index for new value;
}
	
}


	
	return 0;
}
