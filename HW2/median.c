#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HISTSIZE 101

/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/
//get the stdin and return the median number
int median(FILE *f);


/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main(int argc,char **argv){
int is_opened=0;
int check_for_error;
//task 1
FILE *f;
if (argc==1 || !strcmp("-", argv[1])){
f = stdin;
} else{
f= fopen(argv[1],"r");
is_opened=1;
}

if(!f){
fprintf(stderr, "File not found: \"%s\"\n",argv[1]);
return 1;
}

check_for_error=median(f);
if(is_opened){
	fclose(f);
}
return check_for_error;

}

int median(FILE *f){
  //task 2
    int input=0;
    int inputCount=0;
    int medianPlace=0;
    int hist[HISTSIZE]={0};
    int i=0;

    while (fscanf(f,"%d", &input) != EOF){
        if(input>100 || input<0){
          //task 4
            fprintf(stderr,"Error at line %d: grade %d invalid",
             inputCount, input);
            return  1;
        }
        inputCount++;
        hist[input]++;
   }

    medianPlace=(inputCount+1)/2;
    while(medianPlace>0){

        medianPlace=medianPlace-hist[i];
        if(medianPlace>0){
          i++;
        }

    }

    //task 3  
    printf("%d", i);
    return 0;
}
