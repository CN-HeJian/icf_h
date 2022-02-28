#include <iostream>

using namespace std;

class Singleton{
public:
    static Singleton* getInstance(){
        return m_instance;
    }

    static void deleteInstance(){
        if(m_instance){
        delete m_instance;
        m_instance = nullptr;
    }

private:
    Singleton(){}
    ~Singleton(){}

    Singleton(const Singleton& rhs);
    const  Singleton& operator=(const Singleton& rhs);

private:
    static Singleton* m_instance;
};


Singleton* Singleton::m_singleton = new Singleton();


Singleton::Singleton(){
    std::cout<<"instruction function"<<endl;
}

Singleton::~Singleton(){

}

Singleton* Singleton::getInstance(){
    return m_singleton;
}

void Singleton::deleteInstance(){
    if(m_singleton){
        delete m_singleton;
        m_singleton = nullptr;
    }
}

void Singleton::print_addr(){
    //std::cout<<"obj addr: "<<this<<endl;
}


void* myThread(void* arg){
    pthread_detach(pthread_self());  
    int tid = *((int*)arg);
    Singleton::getInstance()->print_addr();
    pthread_exit(0);
}

#define NUM_THREADS 200

int main(){
    pthread_t threads[NUM_THREADS] = {0};
    int index[NUM_THREADS] = {0};

    std::cout<<"main begin"<<std::endl;
    int ret = 0;
    int i=0;

    for(int i=0;i<NUM_THREADS;i++){
        ret = pthread_create(&threads[i],nullptr,myThread,(void*)&(index[i]));
        if(ret){
            std::cout<<"error create thread failed"<<endl;
        }
    }

    Singleton::deleteInstance();
    std::cout<<"end"<<endl;
    return 0;
}



