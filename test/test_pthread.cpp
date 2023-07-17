#include<pthread.h>
#include<iostream>

//回调函数
void* callback(void* arg){
    printf("child thread: %d\n",*(int*)arg);
    return nullptr;
}

int main(){
    pthread_t tid;
    int num=10;
    //创建线程
    int ret=pthread_create(&tid,nullptr,callback,(void*)&num);
    //退出主线程，不会影响其他线程
    pthread_exit(nullptr);
    return 0;
}
