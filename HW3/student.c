#include "common.h"
#include "student.h"
#include <string.h>

/*
typedef struct {
    char *name;
    int age;
    int id;
} student; //create a student type struct 
*/
void* student_clone(void* S1i){
    //allocating memory for the clone
    struct student *S1=(struct student*)S1i;
    struct student *S2=(struct student*)malloc(sizeof(struct student));
    if(!S2){
        return NULL;
    } 

    char *name_2=(char *)malloc(strlen(S1->name)*sizeof(char));
    S2->name=name_2;
    //copying 
    strcpy(S2->name,S1->name);
    S2->id=S1->id;
    S2->age=S1->age;
    
    return (void*)S2;
}

void student_destroy(void* S1i){
    struct student* S1=(struct student*) S1i;
    free(S1->name);
    free(S1);
    
}

void student_print(void* S1i){
    if( S1i==NULL){
        return;
    }
    struct student* S1=(struct student*) S1i;
    printf("student name: ");
    printf("%s", S1->name);
    printf(", age: %d, id: %d.\n", S1->age,S1->id);
}
