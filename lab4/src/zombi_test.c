#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    printf("hello, world\n");
    pid_t child;
    
    if(fork()>0){
        printf("chiled Z1 start \n");
        sleep(5);
        printf("chiled Z1 end \n");
        return 0;
    }
    else{
        printf("Start! zooooombi \n");
        if(fork()>0){
            printf("chiled ps1 start \n");
           execl("ps", " ");
           return 0;
        }
        sleep(1);
        printf("Start! zooooombi s1 \n");
        if(fork()>0){
            execl("ps", " ");
            return 0;
        }
        sleep(5);
        printf("Start! zooooombi s5 \n");
        if(fork()>0){
            execl("ps", " ");
            return 0;
        }
        sleep(10);
        if(fork()>0){
            printf("chiled Z2 start \n");
            sleep(5);
            printf("chiled Z2 end \n");
            return 0;
        }
        printf("End! zooooombi \n");
    }
    return 0;
    
}