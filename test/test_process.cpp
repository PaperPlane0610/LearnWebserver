#include<sys/types.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(){
    int num=10;
    pid_t pid;
    //创建新进程，以下代码共同执行
    // pid=fork();
    //创建5个子进程
    for(int i=0;i<5;++i){
        pid=fork();
        if(pid==0)break; //防止子进程继续创建子进程
    }
    //父子程序对于内存空间读时共享，写时拷贝 
    if(pid>0){
        while(1){
            printf("father process pid: %d\n",getpid());
            printf("num = %d\n",num);
            sleep(1);
        }
        
    }
    else if(pid==0){
        printf("child process pid: %d\n",getpid());
        printf("num = %d\n",num);
    }
    //孤儿进程：父进程比子进程先退出
    //僵尸进程：子进程退出了但是没被父进程回收

    //退出进程
    // _exit(getpid());    //Linux自带的函数，不刷新I/O缓冲区，因此printf的内容可能不显示
    // exit(getpid());   //c++封装的exit函数，退出前会刷新I/O缓冲区

    return 0;
}