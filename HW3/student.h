#ifndef STUDENT_H
#define STUDENT_H

/** @brief Student creates a struct with a name and 2 numerial fields
    @param name *char name of student
    @param age - age of student int
    @param id - id of student int
typedef struct student* student;

no need to encapsulate this one???*/ 
 struct student{
    char *name;
    int age;
    int id;
}; //create a student type struct


void* student_clone(void* S1i);
void student_destroy(void* S1i);
void student_print(void* S1i);

#endif