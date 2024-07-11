#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//get the stdin and return the mean number
int mean(FILE *f);

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

check_for_error=mean(f);
if(is_opened){
	fclose(f);
}
return check_for_error;
}


int mean(FILE *f){
    
    int inputCount=0;
    double total=0;
    int input=0;
    double mean=0;
   
     // receive input

        while (fscanf(f,"%d", &input) != EOF){

        if(input>100 || input<0){
         fprintf(stderr,
         "Error at line %d: grade %d invalid",
          inputCount, input);
         return  1;
        }
            inputCount++;
            total= total+input;
        }     
        mean=(double)(total*100/inputCount)/100;
        printf("%.2f", mean);
        return 0;
    }
  

