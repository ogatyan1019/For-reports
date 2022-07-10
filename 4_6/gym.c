#include <stdio.h>

int main(void){
    typedef struct club{
        int   bangou;
        char  name[20];
        char  seibetu;
        int   nenrei;
        float shinchou;
        float taiju;
    } GYM;

    GYM fitness[]={ {1401,"Yamada", 'm', 40, 170.2, 67.9},
                    {1402,"Suzuki", 'f', 22, 152.4, 47.9},
                    {1403,"Nakano", 'f', 30, 160.5, 50.2},
                    {1404,"Morita", 'm', 52, 168.3, 72.4} };

    int num_H,num_W,i;
    float max_W=0, min_H=999,  ave_A=0, ave_W=0, ave_H=0;
    GYM *p;
    p = fitness;
    
    for(i=0; i<4; i++){
        ave_A=ave_A+(p->nenrei);
        ave_H=ave_H+(p->shinchou);
        ave_W=ave_W+(p->taiju);

        if(max_W<p->taiju){
            max_W=p->taiju;
            num_W=p->bangou;
        }

        if(min_H>p->shinchou){
            min_H=p->shinchou;
            num_H=p->bangou;
        }
        p++;
    }

    ave_A=ave_A/i;
    ave_H=ave_H/i;
    ave_W=ave_W/i;

    printf("平均年齢：%.1f\n",ave_A);
    printf("平均身長：%.1f\n",ave_H);
    printf("平均体重：%.1f\n",ave_W);
    printf("体重の最大値：%.1f  会員番号：%d\n",max_W,num_W);
    printf("身長の最小値：%.1f 会員番号：%d",min_H,num_H);

    return 0;
}