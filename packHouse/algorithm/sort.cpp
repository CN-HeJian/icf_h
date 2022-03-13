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

#include <iostream>
#include <vector>
using namespace std;


//bubble、insert
//merge、quick、topologic
//heap、bucket


//稳定排序：相等的两个数，排序之后相对位置不会替换

 
//冒泡排序 O(n^2) 稳定
//核心思想：每一轮都在寻找的范围内找到最大的数
// void bubble(vector<int>&array){
//     int cycle = array.size();
//     bool flag = true;
//     for(int i=0;i<cycle-1&&flag;i++){
//         flag =false;
//         for(int j=0;j<cycle-1-i;j++){
//             if(array[j]>array[j+1]){
//                 //int temp = array[j];
//                 array[j] = array[j]^array[j+1];
//                 array[j+1] = array[j]^array[j+1];
//                 array[j] = array[j]^array[j+1];
//                 flag = true;
//             }
//         }
//     }
// }

void sort(vector<int>& array){
    int n= array.size();
    bool flag = true;
    for(int i=0;i<n-1&&flag;i++){
        flag = false;
        for(int j=0;j<n-1-i;j++){
            if(array[j]>array[j+1]){
                swap(array[j],array[j+1]);
                flag = true;
            }
        }
    }
}


//插入排序 O(n^2) 稳定
//核心思想：默认左边是有序的，插入新值到有序的序列中
void insert(vector<int>&array){
    int cycle = array.size();
    for(int i=1;i<cycle;i++){
        //i 表示未排序的
        //i 之前的是已经排序过的
        int temp = array[i];
        int j;
        for(j = i-1; j>=0; j--){
            if(array[j]>temp){
                array[j+1] = array[j];
            }else{
                break;
            }
        }
        array[j+1] = temp;
    }
}

//归并排序 nlog(n) 每一层归并都是O(n),一共有log(n)层
//难点：将两个有序数组合二为一，需要一个辅助数组
vector<int> f_array;
void merge(vector<int>& array,int l,int r){
    if(l>=r){
        return ;
    }
    int mid = (l+r) >>1;
    merge(array,l,mid);
    merge(array,mid+1,r);

    //int k=0;
    //int i = l,j=mid+1;

    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(array[i]<=array[j]){
            f_array[k] = array[i];
            i++;
            k++;
        }else{
            f_array[k] = array[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        f_array[k++] = array[i++];
    }
    while(j<=r){
        f_array[k++] = array[j++];
    }
    //最后一段忘记过,还有右边界应该是r,而不是r-1，即要加上等于号
    for(int i=l,j=0;i<=r&&j<k;i++,j++){
        array[i] = f_array[j];
    }

}


struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val),next(nullptr){}
};


ListNode* reverse(ListNode* head){
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* temp = head->next;
        head->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

ListNode* rec(ListNode* head){
    if(head ==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* p = rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;//注意这儿返回的是p!!!
}



void quickSort(vector<int> &array,int l,int r){
    if(l>=r){
        return ;
    }
    int x = array[l];

    int i = l-1,j=r+1;

    while(i<j){
        do{
            i++;
        }while(array[i]<x);

        do{
            j--;
        }while(array[j]>x);

        if(i<j){
            swap(array[i],array[j]);
        }
    }

    quickSort(array,l,j);
    quickSort(array,j+1,r);

}


int main(){


    ListNode* head = new ListNode(0);
     ListNode* node1 = new ListNode(1);
      ListNode* node2 = new ListNode(2);
       ListNode* node3 = new ListNode(3);
        ListNode* node4 = new ListNode(4);
         ListNode* node5 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // ListNode *p = reverse(head);
    
    // while(p){
    //     cout<<p->val<<" "<<endl;
    //     p = p->next;
    // }
    // cout<<endl;

    ListNode* r =rec(head);
    while(r){
        cout<<r->val<<" ";
        r = r->next;
    }







    vector<int> array={88,588,46,67,52,29,7,777,87,6574,546,27687,47,7358,676,8564,859337,989,2,5,7834};
    
    sort(array);
    
    //insert(array);

    //f_array.resize(array.size(),0);
    //merge(array,0,array.size()-1);
    //f_array.resize(array.size(),0);

    //quickSort(array,0,array.size()-1);

    cout<<"b"<<endl;
    for(auto c:array){
        cout<<c<<"  ";
    }
    cout<<endl;
}