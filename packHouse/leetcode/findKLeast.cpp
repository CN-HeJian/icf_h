// Copyright 2022 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find(const vector<int> &nums1,const vector<int>&nums2,int k){
        
        int m = nums1.size();
        int n = nums2.size(); 

        int index1 =0,index2 =0;

        while(true){
            if(index1 == m){
                return nums2[index2+k-1];
            }
            if(index2 == n){
                return nums1[index1+k-1];
            }
            if(k==1){
                return min(nums1[index1],nums2[index2]);
            }

            int newIndex1 = min(index1+k/2-1,m-1);
            int newIndex2 = min(index2+k/2-1,n-1);

            int temp1 = nums1[newIndex1];
            int temp2 = nums2[newIndex2];

            if(temp1 <= temp2 ){
                k -= newIndex1-index1+1;
                index1 = newIndex1+1;
            }else{
                k -= newIndex2-index2+1;
                index2 = newIndex2+1;
            }
        }

    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        //奇数
        if(n%2==1){
            return find(nums1,nums2,n/2+1);
        }
        //偶数
        else{
            return (find(nums1,nums2,n/2)+find(nums1,nums2,n/2+1))/2.0;
        }
    }
};