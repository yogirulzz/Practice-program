/*
link:-    http://www.careercup.com/question?id=17124662
You have two sorted list A and B. 


A = [1, 3, 4, 6,8,10, 17, 34] 
B = [2, 8, 17, 33, 44, 66, 89, 100, 123] 

Write a program to print those numbers which are 
1) in A and not in B 
2) in B and not in A 

Eg: After print: 1 , 3 , 4 , 6 , 10, 33, 34, 44,, 66, 89, 100, 123 


*/
#include<iostream>
#include<vector>

using namespace std;

void printArray(int *a, int *b, int _a,int _b )
{

int i=0,j=0;
vector<int> onlyA;
vector<int> onlyB;

vector<int>::iterator it;
   
	 for(;i<_a && j<_b;)
	 {
	 	if(a[i]==b[j])
	 	{
	 	 i++;
		 j++;
	    }
	    else
	    if(a[i]<b[j])
	    {
	    	if(a[i]!=a[i-1])
	       onlyA.push_back(a[i]);
	       i++;
	    }
	    else if(a[i]>b[j])
	    {
	    	if(b[j]!=b[j-1])
	       onlyB.push_back(b[j]);
	       j++;
	    }

	 }
	    while(i<_a)
	    {
	    	onlyA.push_back(a[i++]);
	    }
	   
	    while(j<_b)
	    {
	    	onlyB.push_back(b[j++]);
	    }
	    cout<<"Present in  a only"<<endl;
	    for(it=onlyA.begin();it!=onlyA.end();++it)
	    cout<<*it<<endl;
	    
	    
	    cout<<"Present in  b only"<<endl;
	    for(it=onlyB.begin();it!=onlyB.end();++it)
	    cout<<*it<<endl;
	 
}

int main()
{
	int a[]={1,2, 3, 4, 6,8,10, 17, 34} ;
	int b[]={2,2,2,2, 8, 17, 33, 44, 66, 89, 100, 123};
	printArray(a,b,sizeof(a)/sizeof(a[0]),sizeof(b)/sizeof(b[0]));
	return 0;
}
