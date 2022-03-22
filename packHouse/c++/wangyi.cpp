#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int flag = 0;
vector<vector<int>> res;
unordered_set<int> set = {1,2,3};
bool helper(vector<vector<char>>& vec0,vector<vector<int>>&vec1,vector<vector<int>> res0)
{
    for (int i = 0; i<3; i++)
	{
		unordered_set<int> temp = set;
		for (int j = 0; j<3; j++)
		{
			if (temp.find(res0[i][j]) != temp.end())
				temp.erase(res0[i][j]);
			else
				return false;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		unordered_set<int> temp = set;
		for (int j = 0; j<3; j++)
		{
			if (temp.find(res0[j][i]) != temp.end())
				temp.erase(res0[j][i]);
			else
				return false;
		}
	}
	for (int i = 0; i<3; i++)
	{
		unordered_set<int> temp = set;
		for (int j = 0; j<3; j++)
		{
			if (temp.find( res0[ vec1[i][2 * j] ][ vec1[i][2 * j + 1]] )!= temp.end())
				temp.erase( res0[ vec1[i][2 * j]][ vec1[i][2 * j + 1]]);
			else
				return false;
		}
	}
    return true;
}
void dfs(vector<vector<char>>& vec0,vector<vector<int>>& vec1,int n,vector<vector<int>> res0)
{
    if(flag>=2)
        return ;
    if(n==9)
    {
        if(helper(vec0,vec1,res0))
        {
            flag++;
            if(flag==1)
                res = res0;
        }
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(vec0[n/3][n%3]!='*')
        {
            if(vec0[n/3][n%3]-'0'== i)
            {
                res0[n/3][n%3]=i;
                dfs(vec0,vec1,n+1,res0);
                break;
            }
            else
                continue;
        }
        res0[n/3][n%3]=i;
        dfs(vec0,vec1,n+1,res0);
    }
};
int main()
{
    // int n;
    // cin>>n;
    // vector<vector<vector<char>>> vec0(n,vector<vector<char>>(3,vector<char>(3)));
    // vector<vector<vector<int>>> vec1(n,vector<vector<int>>(3,vector<int>(6)));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         for(int k=0;k<3;k++)
    //             cin>>vec0[i][j][k];
    //     }
    //     for(int j=0;j<3;j++)
    //     {
    //         for(int k=0;k<6;k++)
    //             cin>>vec1[i][j][k];
    //     }
    // }

    int n = 4;
    vec0 = {{}};
    vec1 = {};

    vector<vector<int>> res0(3,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        dfs(vec0[i],vec1[i],0,res0);
        if(flag==0)
        {
            cout<<"NO"<<endl;
        }
        else if(flag==1)
        {
            cout<<"Unique"<<endl;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cout<<res[i][j];
                }
                cout<<endl;
            }
        }
        else
            cout<<"Multiple"<<endl;
        flag=0;
        res0.clear();
        res.clear();
    }
}
