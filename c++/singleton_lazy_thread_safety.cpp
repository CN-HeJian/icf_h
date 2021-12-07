#include <iostream>
#include <mutex>
#include <pthread.h>
using namespace std;


class SingleInstance{
public:
    static SingleInstance* GetInstance();
    static void deleteInstance();
    void print_addr();
private:
    SingleInstance();
    ~SingleInstance();

    SingleInstance(const SingleInstance &signal);
    const SingleInstance &operator = (const SingleInstance&signal);
private:
    static SingleInstance* m_SingleInstance;
    static std::mutex m_mutex;
};

SingleInstance * SingleInstance::m_SingleInstance = NULL;
std::mutex SingleInstance::m_mutex;

SingleInstance* SingleInstance::GetInstance(){
    if(m_SingleInstance==NULL){
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_SingleInstance==NULL){
            m_SingleInstance = new SingleInstance();
        }
    }
    return m_SingleInstance;
}

void SingleInstance::deleteInstance(){
    std::unique_lock<std::mutex> lock(m_mutex);
    if(m_SingleInstance){
        delete m_SingleInstance;
        m_SingleInstance = NULL;
    }
}

void SingleInstance::print_addr(){
    std::cout<<"obj addr is"<<this<<endl;
}

SingleInstance::SingleInstance(){
    std::cout<<"call instruction function"<<endl;
}

SingleInstance::~SingleInstance(){
    std::cout<<"call destruct function"<<endl;
}

void *PrintHello(void* thread_id){
    pthread_detach(pthread_self());

    int tid = *((int *)thread_id);
    SingleInstance::GetInstance()->print_addr();

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

    SingleInstance::deleteInstance();
    std::cout<<"main end"<<std::endl;

    return 0;
}
