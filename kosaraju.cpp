#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 1000000

vector<unsigned int> e[N]; //edge list
vector<unsigned int> er[N];//reverse edge
vector<unsigned int> sccs; //size of sccs 
vector<unsigned int>order;
bool marked[N];
static int s = 0;

void dfs_front(unsigned int vertex){
marked[vertex]=true;

for(unsigned int i=0;i<er[vertex].size();i++)
  if(marked[er[vertex][i]] == false)
		dfs_front(er[vertex][i]);
		
order.push_back(vertex);
}	


unsigned int dfs_back(unsigned int vertex){
marked[vertex]=true;
s++;
for(unsigned int i=0;i<e[vertex].size();i++)
	if(marked[e[vertex][i]] == false)
		dfs_back(e[vertex][i]);

return s;
}	

bool myfunc(unsigned int a,unsigned b){return a>b;}

int main(){

#ifndef TEST
FILE* fp = fopen("SCC.txt","r");
unsigned int value = 875714;
#else
FILE* fp = fopen("temp.txt","r");
value = 9;
#endif
unsigned int x,y ,scc = 0;
while(!feof(fp)){
	fscanf(fp,"%u %u",&x,&y);
	e[x].push_back(y);
	er[y].push_back(x);

}

memset(marked,false,sizeof(marked));
for(unsigned int i =1;i<=value;i++)
	if(marked[i] == false)
		dfs_front(i);
cout<<"Front done"<<endl;

memset(marked,false,sizeof(marked));
for(long int i=order.size()-1;i>=0;i--){
	//cout<<order[i]<<endl;
	s = 0;//static variable
	if(marked[order[i]] == false)
		sccs.push_back(dfs_back(order[i]));
}
sort(sccs.begin(),sccs.end(),myfunc);
cout<<"Back done "<<sccs.size()<<endl;

unsigned int p = sccs.size();
p = min((unsigned int)5,p);
for(unsigned int i=0;i<p;i++)
		cout<<sccs[i]<<endl;
		
return 0;
}
