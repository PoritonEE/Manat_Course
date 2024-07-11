#include "stack.h"
#include "common.h"
#include <stdio.h>

struct stack{
    elem_t *data;    // Array of void pointers to hold the stack elements
    int max_size;     // Maximum size of the stack
    int current_size;    // current size
    clone_t cloneFunc;  // Function to clone an element
    destroy_t destroyFunc; // Function to destroy an element
    print_t printFunc;  // Function to print an element 

};


void* stack_create(int max_size, void *student_clone,
                    void *student_destroy,
                    void *student_print){
    //allocate memory
    struct stack *newStack = (struct stack*)malloc(sizeof(struct stack));
    if(!newStack){
        return NULL;
    }
    //build the stack
    newStack->data = (elem_t*)malloc(max_size * sizeof(elem_t));
    if (!newStack->data) {
        free(newStack); // Free the stack structure memory before returning
        return NULL; // Allocation failed
    }

    // Initialize the stack fields
    newStack->current_size = 0;
    newStack->max_size= max_size;
    newStack->cloneFunc= student_clone;
    newStack->destroyFunc=student_destroy;
    newStack->printFunc=student_print;
    return newStack;
}

void stack_destroy(void *stack){
    struct stack *stack_d= (struct stack*) stack;
      // Destroy each element in the stack if destroyFunc is provided
    if (stack_d->destroyFunc) {
        for (int i = 0; i < stack_d->current_size; i++) {
            stack_d->destroyFunc(stack_d->data[i]);
        }
    } 

     // Free the array of elements
    free(stack_d->data);

    // Free the stack structure itself
    free(stack);
}

int stack_push(void *stack, elem_t e){
    if( stack==NULL){
        return FAIL;
    }
    struct stack *stack_p= (struct stack*) stack;
    if((stack_p->current_size)==(stack_p->max_size)){
        return FAIL;
    } else{
        clone_t clonedElement=stack_p->cloneFunc(e);
        if(!clonedElement){
            return FAIL;
        }
        stack_p->data[stack_p->current_size]= clonedElement;
        stack_p->current_size++;
        return SUCCESS;
    }
}
void stack_pop(void *stack){
      if( stack==NULL){
        return;
    }
    struct stack *stack_p= (struct stack*) stack;
    if(stack_is_empty(stack_p)){
        return;
    } else{
    stack_p->current_size--;
    stack_p->destroyFunc(stack_p->data[stack_p->current_size]);    
    }
}

void* stack_peek(void *stack){
    if(stack==NULL || stack_is_empty(stack)){
        return NULL;
    } else{
        struct stack *stack_p= (struct stack*) stack;
        elem_t peek_val= stack_p->data[(stack_p->current_size)-1];
        return peek_val; 
    }    
}

int stack_size(void *stack){
      if( stack==NULL){
        return FAIL;
    }
    struct stack *stack_s= (struct stack*) stack;
    return stack_s->current_size;
}

bool stack_is_empty(void *stack){
    struct stack *stack_e= (struct stack*) stack;
    int ans= stack_e->current_size;
    if(ans!=0){
        return false; 
    } else{
       return true;
    }
}

int stack_capacity(void *stack){
    if( stack==NULL){
        return FAIL;
    }
    struct stack *stack_c= (struct stack*) stack;
    return (stack_c->max_size - stack_c->current_size);
}

void stack_print(void *stack){
      if( stack==NULL){
        return;
    }
    struct stack *stack_p= (struct stack*) stack;
   int size= stack_p->current_size;
   for(int i=size-1;i>=0; i--){
        stack_p->printFunc(stack_p->data[i]);
   } 
}
