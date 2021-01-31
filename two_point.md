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

## 26 删除排序数组中的重复项

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		int i=0;
		int res =0;
		while(i<nums.size()){
			while(i+1<nums.size() && nums[i] == nums[i+1] ){
                i++; //i指向的是改变数字的前一个，也就是相同数字的最后一个
            }
            nums[res] =  nums[i];
            i++;
            res++;
		}
        if(i == nums.size()-1){
            nums[res] = nums[i];
        	i++;
        }
        return res;
    }
};
```

## 76 最小覆盖子串

## 155 最小栈

## 84 柱状图中的最大矩形

单调栈模版，找到一侧比当前数最大或者最小的最接近的值

```C++
n = nums.size();
vector<int> left(n,0);
stack<int> min_stk;
min_stk.push(-1); //如果是左侧
min_stk.push(n);  //如果是右侧
for(int i=0;i<n;++i){
    while(min_stk.top()==-1 && nums[min_stk.top()]>= nums[i])
        min_stk.pop();
    left[i] = min_stk.top();
    min_stk.push(i);  //存储的编号
}
```

## 42 接雨水

```C++

```



## 239 滑动窗口最大值

```C++

```

## 860 柠檬水找零

优先使用10元的钱，获得一个局部最优解，此题只要注意一下，找钱的同时自己的钱也增加了，需要记得级数,写题过程中犯了判断数值相等用=号的错误

```C++
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_count=0;
        int ten_count=0;
        for(auto c:bills){
            if(c == 5){
                five_count++;
            }else if( c == 10){ 
                ten_count ++;
                if(five_count > 0)
                    five_count--;
                else
                    return false;
            }else if( c == 20){
                int temp =15;
                if(ten_count>0){
                    ten_count--;
                    temp-=10;
                }
                while(temp>0){
                    if(five_count>0){
                        five_count--;
                        temp-=5;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```

## 392 判断子序列

emm,此题有一个隐含条件，String最后一位是空

```C++
class Solution {
public:
    int point = 0 ;
    bool isSubsequence(string s, string t) {
		for(int i=0;i<s.size();++i){
            char c = s[i];
            while(point<t.size() && t[point]!=c ){
                point++;
            }
            if(t[point]!=c)   //判断是否找到，还是到最后一位
                return false;
            point++; //找到的字符已经被使用，需要跳过
        }
        return true;
    }
};
```

## 