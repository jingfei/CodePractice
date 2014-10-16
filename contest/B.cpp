#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c[100000],tmp[100000];
int tmp_n;
bool Jud;
void Div(){
	tmp_n=0;
	for(int i=0 ; i<strlen(c); i++){
		int Num=c[i]-'0';
		int ans=Num/2;
		if(!(i==0 && ans==0))
			tmp[tmp_n++]=(char)(ans+'0');
		if(i+1!=strlen(c)) c[i+1]+=((Num%2)*10);
	}
	if(tmp_n==0){tmp[tmp_n++]='0'; Jud=false;}
	tmp[tmp_n++]='\0';
	strcpy(c,tmp);
}

long long int modular(long long int A,long long int n){

    long long int result=1;

    while(Jud){
		int x=strlen(c);
        if((c[x-1]-'0')%2==1){

            result=(result*A)%n;

        }

        Div();
//		printf("%s\n",c);

        A=(A*A)%n;

    }

    return result;

}



int main(){
	long long int a,b;
	int Case;
	while(scanf("%d",&Case)!=EOF && Case!=0){
		while(Case--){
			Jud=true;
			scanf("%lld%lld",&a,&b);
			getchar();
			scanf("%s",c);
			getchar();
//			printf("%lld %lld %s\n",a,b,c);
    		printf("%lld\n", modular(a,b));
		}
	}
    return 0;
}
