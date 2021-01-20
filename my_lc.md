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
void merge(int x,int y){
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

### 定义并查集数据结构

```c++
class Djset{
public:
    Djset(int n){
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] =i;
        }
    }
    int find(int x){
        if(x==parent[x])
            return parent[x];
        else
            return find(parent[x]);
    }
    void merge(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);
        parent[parent_x] = parent_y;
    }
private:  
    vector<int> parent;
};
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

### lambada表达式

capture list是一个lambada所在函数中定义的局部变量的列表(通常为空)；

lambada表达式必须使用尾置返回来指定返回类型

```C+
[capture list](parameter list)->return type {function body}
```

本题目中不用邻接矩阵来存储距离，使用lambada表达式子来计算距离

```C++
auto dis = [&](int i,int j)->int{
    return abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
}
```

使用lambada表达式对对象按照成员成员的名字进行排序,例如定义了一个学生类，包含了学生姓名、各科的成绩，本题定义了一个边的结构体,存入了多条边，依据边的长度对edges进行排序

```C++
struct Edge{
    int len；
    int x;
    int y;
    Edge(int len,int x,int y):len(len),x(x),y(y){
    }
}
```

存入多条边对其进行排序,依据边的长度进行排序

```C++
vector<Edge> edges;
sort(edges.begin(),edges.end(),[](Edge a,Edge b)->bool{return a.len<b.len;});
```

###  ```Kruskal```算法

此算法以边为基础，对边进行排序，并查集也就分为两类，一类为已经添加的节点，这些节点并查集中有共同的root，另一类还未添加到已经存在的集合中,因此需要定义并查集数据结构，并查集数据结构参考721，使用自定义数据结构以及lambada表达式可以简化代码

第一步，定义并查集数据结构，注意完整的并查集数据结构初始化时需要重新resize记录节点的根节点的数组

```c++
class DjSet{
public:
    DjSet(int n){
        for(int i=0;i<n;i++){
            parent.resize(n,0);
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return parent[x];
        }
        return find(parent[x]);
    }
    bool merge(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y)
            return true;
        else{
            parent[parent_x] = parent_y;
            return false;
        }
     }
private:
    vector<int> parent;
};
```

 第二步，定义存储边的数据结构,如果是定义为class类型，需要将构造函数定义为public函数，因此这种一般定义为```struct```类型

```C++
class Edge{
public:
    Edge(int x,int y,int len):x(x),y(y),len(len){ 
    }
    int x;
    int y;
    int len;
};
```

第三步，计算所有的边的长度，任一节点之间的距离，并依据距离长短来进行排序，使用并查集辅助判断节点是否添加进去，如果属于同一结集合，即两个节点之间已经连接在一起，当添加的边数为节点数减1时，最小生成树构建完毕。

```C++
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0;
        int p_size = points.size();
        vector<Edge> edges;
        auto dis = [&](int x,int y)->int{
          	return abs(points[x][0]-points[y][0])+abs(points[y][1]-points[x][1]);  
        };
        for(int i=0;i<p_size;i++){
            for(int j = i+1;j<p_size;j++){
                edges.emplace_back(Edge(i,j,dis(i,j)));
            }
        }
        sort(edges.begin(),edges.end(),[](Edge a,Edge b)->bool{return a.len<b.len;});
        DjSet dj(p_size);
        int num = 0;
        for(auto &[x,y,len]:edges){
            if(dj.merge(x,y) == false){
                num++;
                res += len;
                if(num == p_size-1){
                    break;
                }
            }
        }
        return res;  
    }
};
```



​                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         

