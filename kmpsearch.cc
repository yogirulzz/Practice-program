//KMP search
// http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


void preprocessing(char *s,int *kt)
{
  int i;
	kt[0]=0;
	int preLen=0;
	for(i=1;s[i]!=0;i++)
	{
		preLen=kt[i-1];
		if(s[preLen]==s[i])
		{
			kt[i]=++preLen;
		}
		else
		{
			kt[i]=preLen=0;
		}
		
	}
	for(i=0;i<strlen(s);i++)
	cout<<kt[i]<<endl;
}


int nativeWay(char *s,int n ,char* ptn)
{
	int count=0;
	int i=0,j=0;
    for(i=0;s[i]!=0 && strlen(s)-i>=strlen(ptn) ;i++)
    {
    	for(j=0;j<strlen(ptn)&& ptn[j]==s[i+j];j++);
    	if(ptn[j]==0)
    	count ++;
	
	}
	
	return count;
    
}

int KMPSearch(char *s,char * ptn)
{
	if((!s || !ptn))
	return 0;
	 if((!s || !ptn))
	return 0;
	int  sLen=strlen(s);
	int pLen=strlen(ptn);
	int *lps=(int *) malloc(sizeof(int)*pLen);
	
	
	int count=0;
	int j=0;
	int i=0;
	preprocessing(ptn,lps);
	for(i=0;i<sLen;)
	{
		if(s[i]==ptn[j])
		{
			cout<<s[i]<<endl;
			i++;
			j++;
		
		}
		else if(ptn[j]==0){
		j=0;
		count++;
	    }
		else
		{
			if(j!=0)
			j=lps[j-1];
			else
			{
		     j=0;	 
			 i++;
	    	}
		}
	}
	
	free(lps);
	return count;
}

int main()
{

cout<<"result="<<KMPSearch("AABAACAADAABAAABAA","AABA")<<endl;
	return 0;
	
}
