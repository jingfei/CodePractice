#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <char> c;

int main(){
	char a,tmp; bool ans=true;
	a=getchar(); 
	while(a!='\n'){
		c.push_back(a);
		a=getchar();
		int Size=c.size();
		while(c[Size-1]==a){
			c.erase(c.begin()+Size-1,c.end());
			a=getchar();
			Size=c.size();
		}
	}
	int Size=c.size();
	if(Size%2==1){ans=false;}
	else{
		for(int i=0; i<Size; i+=2)
			if(c[i]!=c[i+1]){ans=false; break;}
	}
	ans?printf("Yes\n"):printf("No\n");
	return 0;
}

