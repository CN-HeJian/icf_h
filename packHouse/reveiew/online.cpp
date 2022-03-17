#include <bits/stdc++.h>

using namespace std;

bool toDouble(string str,double *result){
    bool res;

    int sig_num=0;
    bool postive = true;
    int dot=0;

    double temp_p = 0;
    double temp_b = 0;
    int count=0;

    double temp;
    
    for(int i=0;i<str.size();i++){
        if(str[i]=='+' && sig_num == 0){
            sig_num++;
            continue;
        }else if(str[i]=='+' && sig_num>0){
            return false;
        }

        if(str[i]=='-' && sig_num == 0){
            sig_num++;
            postive = false;
            continue;
        }else if(str[i]=='-' && sig_num>0){
            return false;
        }

        if(str[i]=='.'&&dot==0){
            dot++;
            continue;
        }else if(str[i]=='.' &&dot>0){
            return false;
        }

        if(str[i]<'0'|| str[i]>'9'){
            return false;
        }

        if(str[i]>='0'&& str[i]<='9' && dot==0){
            temp_p = temp_p*10+str[i]-'0';
        }

        if(str[i]>='0'&& str[i]<='9' && dot==1){
            count++;
            temp_b = temp_b*10+str[i]-'0';      
        }

    }

    //cout<<temp_p<<" "<<temp_b<<endl;

    //cout<<pow(10,count)<<endl;

    temp = temp_p + (double)temp_b/pow(10,count);

    temp  = postive==true?temp:(-temp);

    //cout<<temp<<endl;

    *result = temp;
    return true;
}


int main(){
    double res;
    bool ret = toDouble("-87s6x.534",&res);
    cout<<ret<<" "<<res<<endl;
}