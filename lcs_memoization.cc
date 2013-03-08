###Longest common subsequesing using DP(memoization)
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int lcs(char *s,char*y,int l,int m)
{
        int result[l+1][m+1];
        if((l==-1)||(m==-1)){
               return 0;
        }

        for(int i=0;i<=l;i++)
        {int j;
                for(j=0;j<=m;j++)
                {
                        if((i==0)||(j==0))
                                result[i][j]=0;
                        else if(s[i-1]==y[j-1]){
                                result[i][j]=result[i-1][j-1]+1;
                        }
                        else
                            result[i][j]= max(result[i-1][j],result[i][j-1]);
                }
        }
        return result[l][m];
}

int main()
{

        string s ="yogendra";
        string y ="yogfhjra";
        cout<<lcs(const_cast<char*>(s.c_str()),const_cast<char*>(y.c_str()),s.length(),y.length())<<endl;
        return 0;
}
