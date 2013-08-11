#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;
#define N 210
#define min(x,y) (x)<(y)?(x):(y)
#define INF 10000000

struct node{
int v1,v2;long long int weight;
node(int x,int y,long long int z) : v1(x),v2(y),weight(z)
{
};

};
int cost[N],exp[N][N];
bool visited[N];

/* Copied from C++ reference*/
class mycomparison
{
  bool reverse;
public:
  
  bool operator() (const node &lhs, const node &rhs) const
  {
    return (lhs.weight>rhs.weight);
  }
};

void init(){
for(int i=0;i<N;i++) cost[i]=INF;
for(int i=0;i<N;i++) for(int j=0;j<N;j++) exp[i][j]=-1;
for(int i=0;i<N;i++) visited[i]=false;
}

int main(){
int x,y,wt;
long long int w;
init();

FILE* fp = fopen("dijkstraData_parsed.txt","r"); // parsed file 
if(fp == NULL)
  return 0;
while(!feof(fp)){
	fscanf(fp,"%d %d %d",&x,&y,&wt);
	exp[y][x] = exp[x][y] = wt;

}
//Djikstra
priority_queue< node, std::vector<node>, mycomparison > distance;
node temp(1,1,0);
distance.push(temp);
while(!distance.empty()){
	temp = distance.top();
	distance.pop();
	w = temp.weight;
	//Calculate min of costs
	cost[temp.v2] = min(cost[temp.v2],w);
	
	//See if this guy is visited else go to all his friends and  calc path and push them
	if(visited[temp.v2] == true) //Avoid loops
		continue;
	for(int i=0;i<N;i++)
		if(exp[temp.v2][i]!=-1){
			w = temp.weight+exp[temp.v2][i];
			node t(temp.v1,i,w);
			distance.push(t);
		}
	visited[temp.v2] = true;
}

/* result*/
int result[]={7,37,59,82,99,115,133,165,188,197};
y = 0;
for(int i=0;i<sizeof(result)/sizeof(int);i++,cout<<y<<",")
	y = (cost[result[i]] == INF) ? 1000000 :cost[result[i]];

fclose(fp);
return 0;
}
