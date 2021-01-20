# log

## 1232 缀点成线

总结：使用直线的一般表现形式来判断，或者使用线性代数知识，向量的线性相关性，共线即相关，任一二维向量组成的行列式值为0,以任意一点作为起点,其他点与这个点连成向量，判断向量是否共线，即相关，如果有一个不为0，即不共线.

```C++
#define Epslion 1e-8
double value_1 = 3.3
double value_2 = 3.3
if(fabs(value_1-value_2)>Epslion) //not equal
```

```C++
int first_vector_x = coordinates[1][0]-start_x;
int first_vector_y = coordinates[1][1]-start_y;
for(int i = 2;i<coordinates.size();i++){
    int i_vector_x = coordinates[i][0] - start_x;
    int i_vector_y = coordinates[i][1] - start_y;
    if(i_vector_y*first_vector_x - i_vector_x*first_vector_y){
        return false;
    }
}
```

## 721 账户合并

### 并查集

第一步并查集初始化每个个体的根节点初始化为自己本身

```C++
int parent[n];
inline void init(int n){
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
}
```

第二步即是查询，一层一层访问父节点，直至根节点

```C++
int find(int x){
    if(parent[x]==x)
        return x;
    else
        return find(parent[x]);
}
```

第三步即是合并，提前将前者的父节点设置为后者即可,先简单的将前者的父节点设置为后者的根节点

```C++
int merge(int x,int y){
    parent(find(x)) = find(y);
}
```

### Vector插入Vector

在指定位置```loc```前插入区间```[start,end)```的所有元素

```C++
void insert(iterator loc,input_iterator start,input_iterator end)
```

例如：

```C++
vector<string> temp(1,account[k][0]);
temp.insert(temp.end(),v.begin(),v.end());
```

## 1584 连接所有点的最小费用

### 普里姆算法Prim

可以在加权连通图中搜索最小生成树，在现实中的应用在不同城市之间架设铁路，要求总的路径和最小，最终在连通图中选择的路线组成一棵树，因此得名，Prim算法的核心在于维护两个数组，一个是记录所有节点到已经访问过的节点的最小距离，一个记录节点是否访问

```C++
vector<int> min_cost(p_len,INT_MAX)         //初始化为INT_MAX
vector<bool> is_checked(p_len,false)        //全部初始化为未访问过
```

第一步，构建邻接矩阵

```C++
vector<vector<int>> dis(p_len,vector<int>(p_len,0));
for(int i=0;i<p_len;i++){
	for(int j=i+1;j<p_len;j++){
		int distance = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])；
		dis[i][j] = distance;
		dis[j][i] = distance;
	}
}
```

第二步，随机选择一个节点作为起点，并更新min_cost

```C++
int start_pos = 0;
min_cost[start_pos] = INT_MAX;       //将自身设置为最大值
is_checked[start_pos] = true;        //设置已经访问过
/*更新最小距离*/
for(int i=0;i<p_len;i++){            //n为节点数量
    if(i==start_pos)
        continue;
    min_cost[i] = dis[i][start_pos];
}
```

第三步，维护两个数组，找到另外n-1个最小距离

```C++
for(int i=1;i<p_len;i++){
    int min_dis = INT_MAX;
    int min_dis_id = -1;
    //寻找距离最近的距离以及点
    for(int j=0;j<p_len;j++){
        if(min_cost[j]<min_dis){
            min_dis = min_cost[j];
            min_dis_id = j;
        }
    }
    res +=min_dis;
    min_cost[min_dis_id] = INT_MAX;
    is_checked[min_dis_id] = true;
    //更新min_cost
    for(int i=0;i<p_len;i++){
    	if(is_checked[i]==false && min_cost[i]>dis[min_dis_id][i]){
			min_cost[i] = dis[min_dis_id][i];
        }   
    }
}
```



