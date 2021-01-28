## 167 两数之和

双指针算法，对撞指针的核心思想就是解的方向一定是沿着同一个方向，充分利用题干来降低算法时间复杂度,以167题目为例

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
		int n = numbers.size();
        for(int i=0,j = n-1;i<n;i++){
            while(j>i && numbers[j]+numbers[i]>=target){
                if(numbers[i]+numbers[j] == target)
                    return {i+1,j+1};
                j--;
            }
        }
        return {-1,-1};
    }
};
```

## 88 合并有序数组

刚开始从前开始,遇到需要后移数组的问题,往后移位碰到比较大的问题,因此可以从后面进行移位

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m-1,j =n-1,k=m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while(j>=0){
            nums1[k--] = nums2[j--];
        }
    }
};
```

