#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//get the stdin and return the histogram
int build_his(FILE *f,int bin);

#define HISTSIZE 10
#define HUNDRED 100
/*=========================================================================
  Constants and definitions:
==========================================================================*/

/* put your #defines and typedefs here*/



/*-------------------------------------------------------------------------
  The main program. (describe what your program does here)
 -------------------------------------------------------------------------*/
int main(int argc,char **argv)
{
//task 1
FILE *f=NULL;
int bin = HISTSIZE;
int check_for_error;
int is_opened=0;

if (!strcmp("-", argv[1]) || argc<2){
        f = stdin;
}else{
for(int i=1; i<argc;++i){    
    if(!strcmp(argv[i], "-nbins") && i<=argc){
        i++;
		bin= atoi(argv[i]);
    }else{
		
        f= fopen(argv[i],"r");
		is_opened=1;
    }
}
}
//task 2



if(!f){
fprintf(stderr, "File not found: \"%s\"\n",argv[1]);
return 1;
}
check_for_error=build_his(f,bin);
if(is_opened){
fclose(f);
}
  return check_for_error;
}

int build_his(FILE *f,int bin){

    int input=0;
    int inputCount=0;
    int* hist= (int*)malloc(bin*sizeof(int)); //can also use calloc
    if(hist== NULL) {
      printf("Memory not allocated.\n");
      return 1;
    }
    //intial histogram to 0
    for (int i = 0; i < bin; i++) {
            hist[i] = 0;
        }

    while (fscanf(f,"%d", &input) != EOF){
      if(input>HUNDRED || input<0){
        fprintf(stderr,"Error at line %d: grade %d invalid",
                inputCount, input);
            return  1;
        }
        inputCount++;
        if(input/(HUNDRED/bin)>=bin){
          hist[bin-1]++;
        }
        else{
          hist[input/(HUNDRED/bin)]++;
        }

        }
    //task 4
    int jump=HUNDRED/bin ;int current=0;
    for(int i=0; i<bin-1;i++){
      printf("%d-%d\t",current, current+jump-1);
      printf("%d\n", hist[i]);
      current=current +jump;
    }
    printf("%d-%d\t",current, 100);
    printf("%d\n", hist[bin-1]);
  free(hist);
  return 0;
}


