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
    struct list* student_list;    
};

//deaclerations

int add_grade(struct student* student,  int grade,const char* name);
/**
 * @brief helps printing student
 * @param student - will print the given object
 * @return 0 on success
 */
int student_print(struct student* student);

//---------courses------------

int clone_courses(void *element, void **output){
    //cast the given element and creat a new course 
    Course *input_element=(Course *)element;  
    Course *new_course=(Course *)malloc(sizeof(Course));
        if(!new_course){
            return FAIL;
        }
    char *p_name=(char *)malloc((strlen(input_element->name)+1)*sizeof(char));
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
    char *p_name=(char *)malloc((strlen(input_element->name)+1)*sizeof(char));
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

    init_grades->student_list= list_init(&clone_student,
                                        &destroy_student);
    if(!init_grades->student_list){
        return NULL;
    }    
   
    return init_grades;
}

void grades_destroy(struct grades *grades){
    if(grades==NULL){
        return;
    }
    list_destroy(grades->student_list);
    free(grades);
}

int grades_add_student(struct grades *grades, const char *name, int id){
    if(grades ==NULL){
        return FAIL;
    }
    int status;
    Students new_student;
    Students *exists_student;
    //check if the name is valid
    if(name==NULL){
        return FAIL;
    }
    // check if studnet with the same ID is already exist

    for(struct iterator* it = list_begin(grades->student_list);
        it != NULL;
        it = list_next(it))
    {
        exists_student=(Students *)list_get(it);
        if(exists_student !=NULL && exists_student->ID ==id){
            return FAIL;
        }
    }
    //create a new studnet
    char *p_name=(char *)malloc((strlen(name))*sizeof(char)+1);
    if(p_name== NULL){
        return FAIL;
    }
    new_student.name=p_name;
    strcpy(new_student.name,name);    
    new_student.ID=id;
    status=list_push_back(grades->student_list, &new_student);
    free(p_name);
    if(status!=Success){
        return FAIL;    
    } else{
        return Success;
    }
}

int grades_add_grade(struct grades *grades,
                     const char *name, int id, int grade){
    
    if(grades==NULL){
        return FAIL;
    }
    struct iterator* curr=list_begin(grades->student_list);
    struct student* curr_student;
    //struct course* course;
       
    while(curr!=NULL){
        curr_student=list_get(curr);
        if(curr_student!=NULL && curr_student->ID==id){
           return add_grade(curr_student, grade, name); 
            //return 0;

        }
        curr=list_next(curr);
    }
    return FAIL;
 }

float grades_calc_avg(struct grades *grades, int id, char **out){
    //grade invalid
    if(grades==NULL){
        *out = NULL;
        return -1;
    }
    struct iterator* curr=list_begin(grades->student_list);
    struct student* curr_student=NULL;
    int found=0;
    float avg=0;
    float count=0;
    
    //serach for existed ID
    while(curr!=NULL){
        curr_student=list_get(curr);
        if(curr_student->ID==id){
            found=1;
            break;
        }
        curr=list_next(curr);
    }
    if(!found){
        *out=NULL;
        return -1;
    }
    
    curr=list_begin(curr_student->courses);
    struct course* curr_course;
    while(curr!=NULL){
        curr_course=list_get(curr);
        if(curr_course!=NULL){
            avg= avg+curr_course->grade;
            count++;
        }
        curr=list_next(curr);
    }

//allocating memory for out
    *out= (char*)malloc((strlen(curr_student->name)+1)*sizeof(char));
     if(*out == NULL){
        return -1;
    }
    strcpy(*out, curr_student->name);

    //courses are not null
    if(count!=0){
        avg=avg/count;
    }
    else
        return 0;
    return avg;

 }

 int add_grade(struct student* student,  int grade,const char* name){
    if(student==NULL  ||grade>100 || grade<0 || name==NULL){
        return FAIL;
    }
    //struct iterator* curr=list_begin(student->courses);
     //do we need to check if the course exists? it could appear twice ig
    int status=0;
    Course new_course;
    new_course.grade=grade;
    char *p_name=(char *)malloc((strlen(name)+1)*sizeof(char));    
    new_course.name=p_name;
    strcpy(new_course.name, name);
    status=list_push_back(student->courses, &new_course);
    free(p_name);
    if (status==Success) {
        return Success;
    }

    return FAIL;

 }

int student_print(struct student* student){
 if(student==NULL){
        return FAIL;
    }
    struct iterator* curr=list_begin(student->courses);
    struct course* course;
    int psik=0;
    printf("%s %d:", student->name, student->ID);
    while( curr!=NULL){
        course=list_get(curr);
        if(course!=NULL){
            if(psik){
                printf(",");
            }
            psik=1;
            printf(" %s %d", course->name, course->grade);
        }
        curr=list_next(curr);
    }
    printf("\n");
    return Success;        
}

int grades_print_student(struct grades* grades, int id){
    if(grades == NULL){
        return FAIL;
    }
        struct iterator* curr=list_begin(grades->student_list);
        struct student* curr_student;
        int found=0;
        while(curr!=NULL){
            curr_student= list_get(curr);
            if(curr_student->ID==id){
                found=1;
                break;
            }
            curr=list_next(curr);
        }
        if(found){
            student_print(curr_student);
            return Success;
        }
        return FAIL;      
}

int grades_print_all(struct grades *grades){
    if(grades == NULL){
        return FAIL;
    }
    struct iterator* curr= list_begin(grades->student_list);
    struct student* curr_student;
    while(curr!=NULL){
        curr_student=list_get(curr);
        student_print(curr_student);
        curr=list_next(curr);        
    }
    return Success;

}
