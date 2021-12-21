//内部静态变量的懒汉单例(C++11线程安全)
#include <iostream>
using namespace std;

class Singleton{
public:
    static Singleton& getInstance();
    void print_addr();
private:
    Singleton();
    ~Singleton();

    Singleton(const Singleton&signal);
    const Singleton &operator=(const Singleton &singnal);
};

Singleton& Singleton::getInstance(){
    static Singleton s;
    return s;
}

void Singleton::print_addr()
{
    std::cout << "我的实例内存地址是:" << this << std::endl;
}

Singleton::Singleton()
{
    std::cout << "构造函数" << std::endl;
}

Singleton::~Singleton()
{
    std::cout << "析构函数" << std::endl;
}

void *PrintHello(void* thread_id){
    pthread_detach(pthread_self());

    int tid = *((int *)thread_id);
    Singleton::getInstance().print_addr();

    pthread_exit(NULL);
}

#define NUM_THREADS 200

int main(){
    pthread_t threads[NUM_THREADS] = {0};
    int indexes[NUM_THREADS] = {0};

    std::cout<<"main begin"<<std::endl;
    int ret = 0;
    int i=0;

    for(i=0;i<NUM_THREADS;i++){
        ret = pthread_create(&threads[i],nullptr,PrintHello,(void*)&(indexes[i]));
        if(ret){
            std::cout<<"error create thread failed"<<endl;
            exit(-1);
        }
    }

    //Singleton::deleteInstance();
    std::cout<<"main end"<<std::endl;

    return 0;
}

