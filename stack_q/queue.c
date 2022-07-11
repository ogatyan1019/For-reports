#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//A~Nをあらかじめ設定
char Data[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N'};
char queue[SIZE];
char charBuff;
int queueNum=0, dataNum=0;

//キューの初期化
void setQueue(){
    int i;
    for(i=0; i<SIZE; i++){
        queue[i]='0';
    }
}


void queuePrint(){
    int i;
    printf("queue[ ");
    for(i=0; i<queueNum; i++)
        printf(" %c",queue[i]);
    printf("]\n");
}

int main(int argc, char *argv[]){
    int buffNum=1;
    setQueue();
    for(;;){
        if(*argv[buffNum] != 'Q'){

            if(*argv[buffNum] == 'E'){
                enqueue(buffNum);
            }
        
            if(*argv[buffNum] == 'D'){
                dequeue(&buffNum);
            }
        buffNum++;
        }

        else
            break;
    }

    queuePrint();
    return(0);
}