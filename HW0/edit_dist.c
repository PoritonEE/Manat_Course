#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100

//this function returns the lulu number or something - LOL
int edit_dist(char word1[], char word2[]);
//return min value
int MinV(int a,int b, int c);


int main() {
	char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
	
	fgets(word1, MAX_WORD_LEN, stdin);
	word1[strlen(word1) - 1] = '\0';
	fgets(word2, MAX_WORD_LEN, stdin);
	word2[strlen(word2) - 1] = '\0';

	printf("%d\n", edit_dist(word1, word2));
    
	return (0);
}

int MinV(int a,int b, int c){
    int ans=0;
    ans= (a<b) ? a : b ;
    ans= (c<ans) ? c : ans;
    return ans;
}



 
int edit_dist(char strA[], char strB[]) {

//getting the length for the building of the matrix
int lengthA= strlen(strA);// rows
int lengthB= strlen(strB);//columns

//checking input
if(lengthA==0 ||lengthB==0){
    if(lengthA>=lengthB){
        return lengthA;
    } else{
        return lengthB;
    }
}

//utilities
int ans=0;
int appear_r=0;
int appear_0=0;//helps with detecting the first time of the same
             //letter to apear

//initial matrix

 // Allocate memory for an array of pointers
    int **disMatrix = (int **)malloc(lengthA * sizeof(int *));
    if (disMatrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
// Allocate memory for each row
    for (int i = 0; i < lengthA; i++) {
        disMatrix[i] = (int *)malloc(lengthB * sizeof(int));
        if (disMatrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }
  //set values in the array to zero
    for (int i = 0; i < lengthA; i++) {
        for (int j = 0; j < lengthB; j++) {
            disMatrix[i][j] = 0;
        }
    }


//fill the first cell, top left corner
if(strA[0]==strB[0]){
	disMatrix[0][0]=0;
    appear_0=1;
} else{
    disMatrix[0][0]=1;
}	
//fill the first line 

 for(int i=1; i<lengthB; i++){
    disMatrix[0][i]=disMatrix[0][i-1];
    if(strA[0]!=strB[i] || appear_r || appear_0){
        disMatrix[0][i]++;        
    } else{
        appear_r=1;
    }	
		
}
//reset to appeariance 
appear_r=0;
// fill the first column

 for(int i=1; i<lengthA; i++){
    disMatrix[i][0]=disMatrix[i-1][0];
	if(strA[i]!=strB[0] ||appear_r ||appear_0){
		disMatrix[i][0]++;        
    } else {
         appear_r=1;       		
    }
}

// fill the rest of the table according to the previous cells

for(int i=1; i<lengthA; i++){
	for(int j=1; j<lengthB; j++){
        
	disMatrix[i][j]= MinV(disMatrix[i-1][j],//top
                         disMatrix[i][j-1],//left
                         disMatrix[i-1][j-1]);//corner
		
		if(strA[i]!=strB[j]){
			disMatrix[i][j]++;
		}
	}		
}

ans=disMatrix[lengthA-1][lengthB-1];

//free them all
for (int i = 0; i < lengthA; i++) {
        free(disMatrix[i]);
    }
free(disMatrix);

//returning the last cell in the left bottom corner
return ans;
}

