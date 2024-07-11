#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//get the stdin and return the min number
int min_f(FILE *f);

int main(int argc,char **argv){
   //task 1
FILE *f;
int is_opened=0;
int check_for_error;
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

check_for_error=min_f(f);
if(is_opened){
	fclose(f);
}
return check_for_error;
}
  



int min_f(FILE *f){
     
    int min=100;
    int inputCount=1;
    int input=0;

    

        while (fscanf(f,"%d", &input) != EOF){

            if(input>100 || input<0){
            fprintf(stderr,"Error at line %d: grade %d invalid", inputCount, input);
            return  1;
            }

            inputCount++;

            if(input<min){
                min=input;
            }
        }



        printf("%d", min);
        return 0;
}
