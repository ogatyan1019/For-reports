#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *sent;
    char *fname = "okeya.txt";
    FILE *fp;
    fp=fopen(fname,"r");
    if(fp==NULL){
        printf("File Open Error\n");
        exit(1);
    }

    fgets(sent,64,fp);
    printf("%s\n",sent);
    const char *p=sent;
    printf("aが何文字目か\n");
    while (p=strchr(p,'a')){
        printf("%d文字目",(int)(p-sent+1));
        printf(" ");
        p++;
    }
    
    fclose(fp);

    return 0;
}