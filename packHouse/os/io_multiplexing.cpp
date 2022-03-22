// 使用最小生成树思想 
// 1. 将所有边排序，按称重从小到大
// 2. 每次选择一条边，假如边会使树成环则丢弃
// 3. 所有点都存在树中时，即可停止添加
// 4. 选择这些边中称重最小的即为答案 

#include<bits/stdc++.h>

using namespace std;

int f[1010];

struct position
{
	int x;
	int y;
	int v;
};

bool cmp(position p1, position p2)
{
	return p1.v > p2.v;
}

int find(int root)
{
	int node = root;
	while(root != f[root])
	{
		root = f[root];
	}
	
	
	while(node != root)
	{
		int t = f[node];
		f[node] = root;
		node = t;
	}
	
	return root;
}

int main()
{
	int n, m;
	cin>>n>>m;
	
	for(int i = 1; i <= n; i++)
	{
		f[i] = i;	
	}
	
	int minn = 1e8;
	int a[n + 1][n + 1] = {0};
	bool b[n + 1] = {false};
	position positions[m]; 
	int sum = 0;
	
	for(int i = 0; i < m; i++)
	{
		int x, y, v;
		cin>>positions[i].x>>positions[i].y>>positions[i].v;
	}
	
	sort(positions, positions + m, cmp);
	
	for(int i = 0; i < m; i++)
	{
		int x = positions[i].x;
		int y = positions[i].y;
		
		int fx = find(x);
		int fy = find(y);
		if(fx != fy)
		{
			minn = min(minn, positions[i].v);
			
			f[fx] = fy;
			
			if(!b[x])
			{
				b[x] = true;
				sum++;
			}
			
			if(!b[y])
			{
				b[y] = true;
				sum++;
			}
		}
		
		if(sum >= n)
		{
			break;
		} 
	}
	
	cout<<minn;
}