#include<iostream>
#include<cstring>
#include<set>
using namespace std;

typedef set<char> cset;
typedef set<char>::iterator csetItr;
void removeDublicate(char*p,int len){
int ll=-1;
int i=0;
cset myset;
csetItr itr;
for(i=0;i<len;i++)
{
  cout<<i<<endl;
	char ch=p[i];
	if((itr=myset.find(ch)) == myset.end()) //means not yet found.
	{
		myset.insert(ch);
		  if(ll==-1){
            continue;
		  }
          else if(ll!=i)
          {
			  p[++ll]=ch;
			  p[i]='\0';
			  cout<<"#setting ll="<< ll<<"char="<<ch<<endl;
		  }
	}
	else{ //dublicate character
	    if(ll==-1)
	    ll=i-1;
	    
	    p[i]='\0';
	    cout<<"setting ll="<<ll<<"p[i]="<<i<<p[i]<<endl;
	}
}
}
int main(){
char  array[]="madam I am adam yogendra";
removeDublicate(array,strlen(array));
cout<<array<<endl;
return 0;

}
