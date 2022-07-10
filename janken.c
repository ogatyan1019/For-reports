# include<stdio.h>
# include<time.h>

typedef enum janken{Gu=0, choki=2, Pa=5} JPON ;

//乱数生成（1～6）
int saikoro(void){
    int sai;
    srand((unsigned)time(NULL));
    sai =rand()%6+1;
    return (sai);
}

int sysjan(int sai){
    int pon;
    switch (sai)
    {
        //sai=1or2
        case 1: pon=0; break;
        case 2: pon=0; break;

        //sai=3or4
        case 3: pon=2; break;
        case 4: pon=2; break;

        //sai=5or6
        case 5: pon=5; break;
        case 6: pon=5; break;
    }

    return ((JPON)pon);
}

int watshinoken (JPON(ken)){
    switch (ken)
    {
        case 0:{
            printf("私はグーを出しました\n");
            break;
        }
        
        case 2:{
            printf("私はチョキを出しました\n");
            break;
        }

        case 5:{
            printf("私はパーを出しました\n");
            break;
        }
    }
}

int anatnoken (JPON(ken)){
    switch (ken)
    {
        case 0:{
            printf("あなたはグーを出しました\n");
            break;
        }
        
        case 2:{
            printf("あなたはチョキを出しました\n");
            break;
        }

        case 5:{
            printf("あなたはパーを出しました\n");
            break;
        }
    }
}

int shoubu (JPON(kenin), JPON(konout)){
    int shoubukekka;
    switch(kenin){
        //playerがグーの時
        case 0:{
            if(konout==0) shoubukekka=0;
            else if(konout==2) shoubukekka=1;
            else shoubukekka=-1;
            break;
        }

        //playerがチョキの時
        case 2:{
            if(konout==2) shoubukekka=0;
            else if(konout==5) shoubukekka=1;
            else shoubukekka=-1;
            break;
        }

        //playerがパーの時
        case 5:{
            if(konout==5) shoubukekka=0;
            else if(konout==0) shoubukekka=1;
            else shoubukekka=-1;
            break;
        }
        break;
    }

    return (shoubukekka);
}

int kekka(shoubukekka){
    if(shoubukekka==-1) printf("あなたの負けです\n");
    else if(shoubukekka==1) printf("あなたの勝ちです\n");
    else if(shoubukekka==0) printf("あいこです\n");
    else printf("error");    
}

int main(void){
    JPON choken;
    JPON sysken;
    int ken_buf, sai, shoubukekka;
    int win, lose, drow;
    int ContinueFlag;
    int hist[3]={0, 0, 0}; //すべてプレイヤー目線, 順に[勝, 敗, 引き分け]
    for(;;){
        do{
            printf("\nじゃんけんをしましょう\n");
            printf("グーは０,チョキは２,パーは5を入力してください\n");
            printf("じゃんけんぽん！はいどうぞ：\a");
            scanf("%d", &ken_buf);
            choken=(JPON)ken_buf;
            if((choken!=Gu)&&(choken!=choki)&&(choken!=Pa))
            printf("\n@@@@正しく入れてください@@@@\n");
        }while(!(choken==Gu || choken==choki || choken==Pa));
    
        sai=saikoro();
        sysken=sysjan(sai);

        shoubukekka=shoubu(choken, sysken);

        switch (shoubukekka)
        {
        case 1: hist[0]=hist[0]+1;
                 break;
        case -1: hist[1]=hist[1]+1;
                 break;
        case 0: hist[2]=hist[2]+1;
                 break;
        default:
            break;
        }

        printf("\a");
        anatnoken(choken);
        watshinoken(sysken);
        kekka(shoubukekka);

        printf("あなたは%d勝,%d敗,%d分けです\n",hist[0], hist[1], hist[2]);
        printf("続ける場合は１を入力し、やめる場合はそれ以外の値を入力してください\n");
        scanf("%d", &ContinueFlag);

        if(ContinueFlag!=1)
            break;
    }
        printf("\n終わります。　お疲れさまでした。\n\n");
    
    return (0);
}