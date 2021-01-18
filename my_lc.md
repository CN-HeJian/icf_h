# log

### 1232 缀点成线

总结：使用直线的一般表现形式来判断，或者使用线性代数知识，向量的线性相关性，共线即相关，任一二维向量组成的行列式值为0.

```class Solution {
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int start_x = coordinates[0][0];
        int start_y = coordinates[0][1];
        int first_vector_x = coordinates[1][0]-start_x;
        int first_vector_y = coordinates[1][1]-start_y;
        for(int i = 2;i<coordinates.size();i++){
            int i_vector_x = coordinates[i][0] - start_x;
            int i_vector_y = coordinates[i][1] - start_y;
            if(i_vector_y*first_vector_x - i_vector_x*first_vector_y){
                return false;
            }
        }
        return true;
    }
};
```





