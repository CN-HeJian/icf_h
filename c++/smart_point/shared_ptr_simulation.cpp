// Copyright 2021 icf
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



template<class T>
class SharedPointer
{
public:
    //默认构造函数，内部指针，未指向任何资源，引用计数为0,因为它未与任何资源绑定
    SharedPointer() :m_refCount(nullptr), m_pointer(nullptr){}
    
    //构造函数，初始化时，指向一个已经分配好的资源
    SharedPointer(T* adoptTarget) :m_refCount(nullptr), m_pointer(adoptTarget)
    {
        addReference();
    }
    
    //构造函数，使用其它对象创建新对象
    SharedPointer(const SharedPointer<T>& copy)
        :m_refCount(copy.m_refCount), m_pointer(copy.m_pointer)
    {
        addReference();
    }
    
    //析构函数，引用计数递减，当为0时，释放资源
    virtual ~SharedPointer()
    {
        removeReference();
    }
    
    //赋值操作
    //当左值被赋值时，表明它不再指向所指的资源，故引用计数减一
    //之后，它指向了新的资源，所以对应这个资源的引用计数加一
    SharedPointer<T>& operator=(const SharedPointer<T>& that)
    {
        if (this != &that)
        {
            removeReference();
            this->m_pointer = that.m_pointer;
            this->m_refCount = that.m_refCount;
            addReference();
        }
        return *this;
    }
    
    //判断是否指向同一个资源
    bool operator==(const SharedPointer<T>& other)
    {
        return m_pointer == other.m_pointer;
    }
    bool operator!=(const SharedPointer<T>& other)
    {
        return !operator==(other);
    }
    
    //指针解引用
    T& operator*() const
    {
        return *m_pointer;
    }
    //调用所知对象的公共成员
    T* operator->() const
    {
        return m_pointer;
    }
    
    //获取引用计数个数
    int GetReferenceCount() const
    {
        if (m_refCount)
        {
            return *m_refCount;
        } 
        else
        {
            return -1;
        }
    }
    
protected:
    //当为nullpter时，创建引用计数资源，并初始化为1
    //否则，引用计数加1。
    void addReference()
    {
        if (m_refCount)
        {
            (*m_refCount)++;
        }
        else
        {
            m_refCount = new int(0);
            *m_refCount = 1;
        }
    }
    
    //引用计数减一，当变为0时，释放所有资源
    void removeReference()
    {
        if (m_refCount)
        {
            (*m_refCount)--;
            if (*m_refCount == 0)
            {
                delete m_refCount;
                delete m_pointer;
                m_refCount = 0;
                m_pointer = 0;
            }
        }
    }
    
private:
    int * m_refCount;
    T   * m_pointer;
};

#include <iostream>
#include <memory>
#include <string>
#include <vector>


using namespace std;
class MyClass
{
public:
    ~MyClass()
    {
        cout << "释放MyClass(" << _id << ")\n";
    }
    
    MyClass(int i) :_id(i)
    {
        
    }
    
    void Print() const
    {
        cout << "MyClass(" << _id << ")" << endl;
    }
private:
    int _id;
};

int main()
{
    {
        MyClass* px = new MyClass(1);
        
        SharedPointer<MyClass> ap(px);
        SharedPointer<MyClass> bp = ap;
        SharedPointer<MyClass> cp;
        
        cout << "ap的引用计数(2): "
             << ap.GetReferenceCount() << endl;
        
        cout << "将ap赋值给cp\n";
        cp = ap;
        
        cout << "ap的引用计数(3): "
             << ap.GetReferenceCount() << endl;
        
        
        MyClass* qx = new MyClass(5);
        SharedPointer<MyClass> dp(qx);
        ap = dp;
        
        cout << "ap的引用计数(2): "
             << ap.GetReferenceCount() << endl;
        
        cout << "dp的引用计数(2): "
             << dp.GetReferenceCount() << endl;
        
        //"像指针一样使用智能指针"
        dp->Print();
        (*cp).Print();
    }
    
    cin.get();
}