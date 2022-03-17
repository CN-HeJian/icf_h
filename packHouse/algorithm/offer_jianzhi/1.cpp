
bool quick(int y,int z,int x){
    //判断 y*z >= x
    int add = y;
    int res = 0;

    while(z){
        if(z&1){
            //add + res >=x 
            if(res<x-add){
                return false;
            }
            res += add;
        }
        if(z!=1){
            //add + add >=x
            if(add < x-add){
                return false;
            }
            add +=add;
        }
        z >>= 1;
    }
    return true;
}