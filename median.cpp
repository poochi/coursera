#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include<stdio.h>
#include<set>

using namespace std;

/*Heap wasnt implemented it was used : Cheating again!*/	
int main(){


int c = 0;
set<int > myset;
set< int >::iterator it,jt;
  
FILE* fp = fopen("Median.txt","r");
long long int sum = 0;

while(!feof(fp)){
	int t;
	if(feof(fp))
		break;
	fscanf(fp,"%d",&t);
	myset.insert(t);
	it = myset.begin();
	advance(it,(((myset.size()+1)>>1)-1));
	sum+=(*it);
	c++;
	cout<<c<<" "<<myset.size()<<endl;
}
cout<<c<<endl;
cout<<myset.size()<<endl;
cout<<sum<<endl;
fclose(fp);
return 0;
}
