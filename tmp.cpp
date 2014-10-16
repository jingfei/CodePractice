#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int myints[8]={10,10,10,20,20,20,30,30};
	for(int i=0; i<8; i++) cout << myints[i] << ' ';
	cout << endl;
	int x;
	while(cin >> x){
		cout << "upper_bound: " << upper_bound(myints,myints+8,x)-myints << endl;
		cout << "lower_bound: " << lower_bound(myints,myints+8,x)-myints << endl;
	}
	return 0;
}
