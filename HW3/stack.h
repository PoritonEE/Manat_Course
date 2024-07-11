#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "common.h"

typedef struct stack* Stack;
typedef elem_t (*clone_t)(elem_t e); 
typedef void (*destroy_t)(elem_t e);
typedef void (*print_t)(elem_t e);

/**
 * @brief create the stack
 * @param max_size gives the maximum elements in the new stack
 * @param student_clone gives the element the necassary pointer
 * @param student_destroy gives the necassary pointer for the earsment 
 * @param student_print gives the necassary pointer to print the element
 */
void* stack_create(int max_size, void *student_clone,
                    void *student_destroy,
                    void *student_print);
void stack_destroy(void *stack);
int stack_push(void *stack, elem_t e);
void stack_pop(void *stack);
void* stack_peek(void *stack);
int stack_size(void *stack);
bool stack_is_empty(void *stack);
int stack_capacity(void *stack);
void stack_print(void *stack);


#endif