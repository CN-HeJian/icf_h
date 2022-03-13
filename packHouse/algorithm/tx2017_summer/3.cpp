#include <bits/stdc++.h>

using namespace std;

int main(){
   int n;
   while(cin>>n){
       vector<int> res;
       while(n--){
           int temp;
           cin>>temp;
           res.push_back(temp);
       }

        int n = res.size();

        sort(res.begin(),res.end());

        int diff;
        int min_Diff = INT_MAX;//用来记录diff值的
        bool flag = false;
        int minCnt = 1;

        int i=0;
        for(i=0;i<n-1;i++){
            int d = res[i+1]-res[i];
            if(d == 0){
                minCnt = 0;
                flag = true;
                break;
            }
            if(d<min_Diff){
                min_Diff = d;
                minCnt=1;
            }else if(d == min_Diff){
                minCnt++;   
            }
        }

        if(minCnt==0 && flag==true){
            while(i<n-1){
                int cur = i,cnt =1;
                while(cur<n-1){
                    if(res[cur]==res[cur+1]){
                        cnt++;
                        cur++;
                    }else{
                        break;
                    }
                }    
                minCnt +=(cnt*(cnt-1)/2);
                i = cur+1;
            }
        }

        int maxcnt=1;
          //计算最大  
        int l = 1, r = 1;  
        for(int i = 0; i < n - 1; ++i) {  
            if(res[i] == res[i+1]) ++l;  
            else break;  
        }  
        for(int i = n - 1; i > 0; --i) {  
            if(res[i] == res[i-1]) ++r;  
            else break;  
        }  
        maxcnt = l * r;  
        cout<<minCnt<<" "<<maxcnt<<endl;  


   } 
}