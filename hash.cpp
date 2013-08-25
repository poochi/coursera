#include<iostream>
#include <set>
#include<stdio.h>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;
/*This is not using hash (to make sure it runs within 1-2 s )., Uses sets instead , makes use of the fact that the input are integers */
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define N 300000

int main(){
	set<long long int> myset,res;  
	set<long long int>::iterator it,jt,st,et;
	ifstream fp;
	ofstream fout;
	fp.open("hash.txt");
	//fout.open("test.txt");
	long long int t=0;
	int a[N];
while(!fp.eof()){
	long long int t;
	fp>>t;
	myset.insert(t);
}
	unsigned int c = 0;
	for(it = myset.begin();it!=myset.end();it++){
	long long int maxi = (10000-(*it));
	long long int mini= (-10000-(*it));
	st = myset.lower_bound(mini-1);
	et = myset.lower_bound(maxi+1);

	/*utmost 10000*/
	for(jt = st;jt!=et;jt++){
	long long int v = (*it)+(*jt);
		if(v>=-10000 && v<=10000)
			a[v+10000] = 1;
	c++;
}

}
	unsigned int cnt = 0;
	for(int i=-10000;i<=10000;i++)
		cnt+=(a[i+10000]);
	cout<<cnt<<endl;
	cout<<c<<endl;



	fp.close();	


return 0;
}