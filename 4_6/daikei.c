#include <stdio.h>

int main(void){
    typedef struct daikei{
        int kahen;
        int jouhen;
        int takasa;
    } daikei;
    
    int da_V,db_V,dc_V;

    daikei da,db,dc;
    printf("台形Aの値入力\n");
    printf("下辺->"); scanf("%d",&da.kahen);
    printf("上辺->"); scanf("%d",&da.jouhen);
    printf("高さ->"); scanf("%d",&da.takasa);
    printf("\n");

    printf("台形Bの値入力\n");
    printf("下辺->"); scanf("%d",&db.kahen);
    printf("上辺->"); scanf("%d",&db.jouhen);
    printf("高さ->"); scanf("%d",&db.takasa);
    printf("\n");

    da_V =(da.jouhen+da.kahen)*da.takasa/2;
    db_V =(db.jouhen+db.kahen)*db.takasa/2;

    printf("台形Aの面積：%d  台形Bの面積：%d\n",da_V,db_V);

    dc.jouhen=da.jouhen+db.jouhen;
    dc.kahen=da.kahen+db.kahen;
    dc.takasa=da.takasa+db.takasa;
    printf("台形Cの上辺：%d 下辺：%d 高さ%d\n",dc.jouhen, dc.kahen, dc.takasa);
    dc_V =(dc.jouhen+dc.kahen)*dc.takasa/2;

    printf("台形Cの面積：%d",dc_V);

    return 0;
    }