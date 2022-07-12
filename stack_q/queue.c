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

int enqueue(int enqNum){
    if(queueNum >= SIZE){
        printf("Queue Over Flow\n");
        exit(1);
    }
    
    else{
        if(queueNum>=1){
            for(int i=queueNum-1; i>=0; i--){
                charBuff = queue[i];
                queue[i+1] = charBuff;
            }
        }
        charBuff = Data[dataNum];
        queue[0] = charBuff;
        dataNum++;
        queueNum++;
    }
}

int dequeue(int *deqNum){
    if(queueNum!=0)
        queueNum--;
    
    else{
        printf("Queue Under Flow");
        exit(1);
    }
}


void queuePrint(){
    int i;
    printf("queue[");
    for(i=0; i<queueNum; i++)
        printf("%c ",queue[i]);
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