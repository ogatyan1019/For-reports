#include<stdio.h>
#include<stdlib.h>
int main(void){
    int i,h,j;
    FILE *fp;
    puts("段数を入れてください");
    printf("段数->"); scanf("%d",&h); printf("\n");

    fp=fopen("pylamid.txt", "w");
    if(fp==NULL){
        printf("File open error!\n");
        exit(1);
    }

    for(i=1; i<=h; i++){
        for(j=1; j<=i-1; j++){
            putchar(' ');
            fputc(' ',fp);
        }
        for(j=1; j<=2*h-(2*i-1); j++){
            printf("%d",i%10);
            fprintf(fp,"%d",i);
        } 
        printf("\n");
        fputc('\n',fp);
    }
    fclose(fp);
    return 0;
}