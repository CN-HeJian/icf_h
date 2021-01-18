# log

### 1232 缀点成线

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





