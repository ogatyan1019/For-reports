#include <stdio.h>
#include <time.h>

typedef enum janken{Rock=0, Scissors=1, Paper=2} Hand;

int Dice(void){
    int Dice;
    srand((unsigned)time(NULL));
    Dice =rand()%3;
    return (Dice);
}
int PrintComHands(Hand(Com)){
    switch (Com)
    {
        case 0:{ 
            printf("Comはグーを出しました\n");
            break;
        }
        case 1: {
            printf("Comはチョキを出しました\n");
            break;
        }
        case 2: {
            printf("Comはパーを出しました\n");
            break;
        }
        default:
            break;
    }
}

int PrintPlayerHands(Hand(Player)){
    switch (Player)
    {
        case 0:{ 
            printf("Playerはグーを出しました\n");
            break;
        }
        case 1: {
            printf("Playerはチョキを出しました\n");
            break;
        }
        case 2: {
            printf("Playerはパーを出しました\n");
            break;
        }
        default:
            break;
    }
}


int main(void){
	Hand Player;
	Hand Com;
    int PlayerIn, Judge, ContinueFlag;
    int Hist[3]={0,0,0}; //0：引き分け, 1：勝, 2：負け

    for(;;){
        do{
            printf("\nじゃんけんをしましょう\n");
            printf("グーは0,チョキは1,パーは2を入力してください\n");
            printf("じゃんけんぽん！はいどうぞ：\a");
            scanf("%d", &PlayerIn);
			Player = PlayerIn;
            if((Player!=Rock)&&(Player!=Scissors)&&(Player!=Paper))
            printf("\n@@@@正しく入れてください@@@@\n");
        }while(!(Player==Rock || Player==Scissors || Player==Paper));

        Com = Dice();
        Judge=(Com - Player +3)%3;
        PrintComHands(Com);
        PrintPlayerHands(Player);
        switch (Judge)
        {
        case 0: printf("引き分けです\n");
            break;
        case 1: printf("Playerの勝ちです\n");
            break;
        case 2: printf("Comの勝利です\n");
            break;
        default:
            break;
        }

        Hist[Judge]++;
        printf("---Playerの戦績・・・%d勝%d敗%d分---\n", Hist[1], Hist[2], Hist[0]);
        printf("続けますか？続ける場合は1を、やめる場合はそれ以外の数字を入力してください\n");
        scanf("%d",&ContinueFlag);

        if(ContinueFlag!=1)
            break;    
    }
    printf("お疲れさまでした。\n\n");
    
    return 0;
}