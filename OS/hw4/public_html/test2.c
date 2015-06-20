#include <stdio.h>
#include <string.h>

int hit[1000000]={0};  //remember to initialize
void bubble(char *list, int n, int dir); /* bubble sort, able to select sort direction*/

int toInt(char *Num, int Len){
	int i, tmp=0;
	for(i=0; i<Len; ++i)
		tmp=tmp*10 + (Num[i]-'0');
	return tmp;
}

int FindBC(char *A, char *B, char *C, int Len){
	/*copy string A to others*/
	strcpy(B,A);
	strcpy(C,A);
	/*do bubble sort*/
	bubble(B,Len,0);
	bubble(C,Len,1);
	/*change to int*/
	int iB=toInt(B,Len);
	int iC=toInt(C,Len);
	return iB-iC;
}

/* return the len of char */
int toChar(int Num, char *A){
	/* find the length of A */
	int tmpN=Num, Len=0;
	while(tmpN){tmpN/=10; ++Len;}
	/* change to A */
	int i;
	for(i=Len-1; i>=0; --i){
		A[i]= (Num%10) + '0';
		Num/=10;
	}

	return Len;
}

int main(){
	char A[100], B[100], C[100];
	scanf("%s",A);
	int Len=strlen(A);
	int ans=1;
	int minus=FindBC(A,B,C,Len);
	while(!hit[minus]){
		hit[minus]=1;  //set to true
		Len = toChar(minus,A);
		minus=FindBC(A,B,C,Len);
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}

/* bubble sort, able to select sort direction*/
void bubble(char *list, int n, int dir){
	/*if dir==1 sort, else sort in contrary*/
	int i,j,temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++){
			if(dir && list[j]>list[j+1])
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
			else if(!dir && list[j]<list[j+1])
			{
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
}

