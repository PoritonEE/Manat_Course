#include <stdio.h>
#include <stdlib.h>
#define MAX_ARRAY_SIZE 10000
void twoSum(int nums[], int nums_size, int target);
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
};
int main() {
 int target;
 int nums[MAX_ARRAY_SIZE] = {0};
 int array_size = 0;
 scanf("%d", &target);
 while (scanf("%d", &nums[array_size++]) == 1);
 array_size--;
 twoSum(nums, array_size, target);
 return (0);
}
void twoSum(int nums[], int numsSize, int target) {
 //creat a new array with the old indexes
 int* copy= (int*)malloc(numsSize*sizeof(int));
 for(int i=0; i<numsSize; i++){
    copy[i]=nums[i];
 }
 

//sort the copy
qsort(copy,numsSize,sizeof(int),cmpfunc);

 //find the two numbers 
 int arr_sol[2]= {0};
 int l_p=0;
 int r_p=numsSize-1;
 while(l_p!=r_p){

    if(copy[l_p]+copy[r_p]==target){
        arr_sol[0]=copy[l_p];
        arr_sol[1]=copy[r_p];
      break;
    }

    if(copy[l_p]+copy[r_p]>target){
        r_p--;
    }
    else{
        l_p++;
    }
 }

 //find the indexes
 int min=0; int max=0;int flag=1;
 for(int j=0;j<numsSize;j++){
    if(nums[j]==arr_sol[0]||nums[j]==arr_sol[1]){
        if(flag){
            min=j;
            flag=0;
        }
        else{
            max=j;
        }
    }
 }
 //free malloc
 free(copy);

 //print the solution
 printf("(%d, %d)", min,max);
 printf("\n");
}
