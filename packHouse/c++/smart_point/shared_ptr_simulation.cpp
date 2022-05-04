//
// Created by admin on 2022/4/28.
//

#ifndef LUOGU__SHAREPTR_H
#define LUOGU__SHAREPTR_H


template<typename T>
class shareptr{
public:
    //构造函数
    shareptr(T* _source==nullptr):source(_source){
        count = new int(0);
        if(source){
            (*count)++;
        }
    }

    //析构函数
    ~shareptr(){
        decRef();
    }

    //拷贝构造函数
    shareptr(const shareptr& rhs):{
        source = rhs.source;
        count = rhs.count;
        if(source)
            (*count)++;
    }

    //赋值构造函数
    sharedptr& operator=(const shareptr& rhs){
        if(rhs.source!=source) {
            //还需要删除一种！！！！！！！！！！！！！！！！！！
            decRef();

            count = rhs.count;
            source = rhs.source;

            //只有rhs.source != nullptr才能加1！！！！！！！！！！！！！！！！
            if(rhs.source){
                (*count)++;
            }

        }
        return *this;
    }

protect:
    void decRef(){
        //这儿需要提前判断！！！！！！！！！！！！！！！！！
        if(source ==nullptr){
            delete count;
            count = nullptr;
        }else{
            (*count)--;
            if((*count)<1){
                delete source;
                delete count;
                source = nullptr;
                count = nullptr;
            }
        }
    };

private:
    T* source;
    int* count;
};



#endif //LUOGU__SHAREPTR_H
