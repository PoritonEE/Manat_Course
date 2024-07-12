#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grades.h"
#include "linked-list.h"

enum {Success=0 , FAIL};

typedef struct course{
    char* name;
    int grade;
}Course;

typedef struct student{
    int ID;
    char* name;
    struct list* courses;

}Students;

struct grades{
    struct list* studnet_list;    
};

//---------courses------------

int clone_courses(void *element, void **output){
    //cast the given element and creat a new course 
    Course *input_element=(Course *)element;  
    Course *new_course=(Course *)malloc(sizeof(Course));
        if(!new_course){
            return FAIL;
        }
    char *p_name=(char *)malloc(strlen(input_element->name)*sizeof(char));
    if(!p_name){
        return FAIL;
    }
    //copying
    new_course->name=p_name;
    strcpy(new_course->name,input_element->name);
    new_course->grade = input_element->grade;

    *output=new_course;
    return Success;
}
void destroy_courses(void *element){
    Course *course=(Course *)element;
    free(course->name);
    free(course);
}

//---------studnets------------
int clone_student(void *element, void **output){
    //cast the given element and creat a new student
    Students *input_element=(Students *)element;
    Students *new_student=(Students *)malloc(sizeof(Students));
        if(!new_student){
            return FAIL;
        }
    char *p_name=(char *)malloc(strlen(input_element->name)*sizeof(char));
    if(!p_name){
        return FAIL;
    }
    //copying
    new_student->name=p_name;
    strcpy(new_student->name,input_element->name);
    new_student->ID=input_element->ID;

    //making a list of courses
    new_student->courses= list_init(&clone_courses,&destroy_courses);
    if(!new_student->courses){
        return FAIL;
    }
    //output the new student
    *output=new_student; 
    return Success;    
}
void destroy_student(void *element){
   Students *studnet=(Students *)element; 
   list_destroy(studnet->courses);
   free(studnet->name);
   free(studnet);
}

/**
 * @brief Creates a new list of grades
 * @returns A pointer to the list, or NULL on error
 * @note for using the list ADT we need to give elem_clone and elem_destroy.
 * so we will provide:
 *      clone courses, destroy courses
 *      clone studnets, destroy studnets 
 * when the clone studnets will pass the pointer to clone and destroy courses
 */
struct grades* grades_init(){
    
    struct grades *init_grades= (struct grades*)malloc(sizeof(struct grades));
    if(!init_grades){
        return NULL;
    }

    init_grades->studnet_list= list_init(&clone_student,
                                        &destroy_student);
    if(!init_grades->studnet_list){
        return NULL;
    }    
   
    return init_grades;
}

void grades_destroy(struct grades *grades){
    if(grades==NULL){
        return;
    }
    list_destroy(grades->studnet_list);
    free(grades);
}

int grades_add_student(struct grades *grades, const char *name, int id){
    if(grades ==NULL){
        return FAIL;
    }
    int status;
    Students *student;
    student->name=name;
    student->ID=id;
    status=list_push_back(grades->studnet_list, student);
    if(status!=Success){
        return FAIL;    
    } else{
        return Success;
    }
}