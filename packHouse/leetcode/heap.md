# 堆

##### 数组最小堆模板

```C++
arr //原数组
int n = arr.size();
vector<int> hh(n+1,0);//最小堆数组，开大一个的目的是下标从1开始
//循环赋值
for(int i=1;i<=n;i++){
    hh[i] = arr[i-1];
}
//生成最小堆
for(int i=n/2;i;--i){
    down(hh,i,n);//生成最小堆
}
```

```C++
//传入参数包括最小堆数组，当前需要排序的数字，所有排序的个数
void down(vector<int> &arr,int k,int n){
    int t = k;
    if(2*k<=n && arr[t] > arr[2*k]){
        t = 2*k;
    }
    if(2*k+1<=n && arr[t] > arr[2*k+1]){
        t = 2*k +1;
    }
    if(t != k){
        swap(arr[t],arr[k]); //交换
        down(arr,t,n);//继续找到合适的位置
    }
}
```

```C++
//获取堆顶元素并删除,进行k次
while(k--){
    res.push_back(hh[1]);
	hh[1] = hh[n];//置换到最后一个
	n--; //总的个数减去1
	down(hh,1,n);
}
```

