#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

//A~Nをあらかじめ設定
char Data[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N'};
char stack[SIZE];
char charBuff;
int stackNum=0, dataNum=0;

//スタックの初期化
void setstack(){
    int i;
    for(i=0; i<SIZE; i++){
        stack[i]='0';
    }
}

int push(int pushNum){
    if(stackNum < SIZE){
        charBuff = Data[pushNum-1];
        stack[stackNum] = charBuff;
        stackNum++;
        dataNum++;
        return (1);
    }
    else{
        printf("Stack Over Flow");
        exit(1);
    }
}

int pop(int *popData){
    if(stackNum > 0){
        stackNum--;
        return (1);
    }
    else{
        printf("Stack Under Flow\n");
        exit(1);
    }
}

void stackPrint(){
    int i;
    printf("stack[ ");
    for(i=0; i<stackNum; i++)
        printf(" %c",stack[i]);
    printf("]\n");
}

int main(int argc, char *argv[]){
    int buffNum=1;
    setstack();
    for(;;){
        if(*argv[buffNum] != 'Q'){

            if(*argv[buffNum] == 'P'){
                push(buffNum);
            }
        
            if(*argv[buffNum] == 'O'){
                pop(&buffNum);
            }
        buffNum++;
        }

        else
            break;
    }

    stackPrint();
    return(0);
}