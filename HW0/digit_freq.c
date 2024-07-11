// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
int main() {
    int his[SIZE] = {0} ;
    int place=0;
    while(1){
        //stdin
        char c= getchar();
        if(c == EOF){
            break;
        }
        //bulid the his
        if(c >= '0' && c<= '9'){
            place= c-'0';
            his[place]++;
        }

    }
    //stdout
    for(int i=0; i<10; i++){
        //11printf("%d",i);
        printf("%d%s", his[i], (i<9) ? " ":"");
    }
           
    return 0;
}
