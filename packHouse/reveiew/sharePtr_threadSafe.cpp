#include <bits/stdc++.h>
using namespace std;


template <class T>
class SharePtr{
public:
    SharePtr(const T*r){
        m_source = r;
        m_count = new int(1);
        m_mutex = new mutex();
    }

    SharePtr(const SharePtr<T>& rhs){
        m_source = rhs->source;
        m_count = rhs->m_count;
        m_mutex = rhs->mutex;
        addRef();
    }

    int addRef(){
        unique_lock<mutex> lock(mutex);
        if(m_count){
            (*m_count)++;
        }else{
            return -1;
        }
        return *m_count;
    }

    SharePtr<T>& operator=(const SharePtr<T>& rhs){
        if(rhs.m_source != m_source){
            if(subRef()==0){
                delete m_count;
                delete m_source;
                delete m_mutex;
                m_count = nullptr;
                m_source = nullptr;
                m_mutex =nullptr;
            }
            m_source = rhs.m_source;
            m_count = rhs.count;
            m_mutex = rhs.mutex;
        }
        return *this;
    }

    int subRef(){
        unique_lock<mutex> lock(mutex);
        if(m_count){
            (*m_count)--;
        }else{
            return -1;
        }
        return *m_count;
    }

    ~SharePtr(){
        if(subRef()==0){
            delete m_count;
            delete m_source;
            delete m_mutex;
            m_count = nullptr;
            m_source = nullptr;
            m_mutex =nullptr;
        }
    }

private:
    int* m_count;
    T* m_source;
    mutex* m_mutex;
};
