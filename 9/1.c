#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char **argv) {
    FILE *f;
    char *p,s[100];
    int n,*fpos=0,position=0,realPosition=0;

    if(argc>1)
    {
        f=fopen(argv[1],"r");
        while(fgets(s,100,f)) {
            fpos=(int*) realloc (fpos,(position+1)*sizeof(int));
            fpos[position++]=realPosition;
            realPosition=ftell (f);
        }

        n=argc>2? atoi(argv[2]) : 5;

        if(n>position) { 
            n=position;
        }

        fseek(f,fpos[position-n],SEEK_SET);
        while(fgets(s,100,f)) {
            if(p=strchr(s,'\n')) {
                *p=0;
            }
            printf("%s\n",s);
        }

        fclose(f);

        if(fpos){
            free(fpos);
        }
    }
    return 0;
}