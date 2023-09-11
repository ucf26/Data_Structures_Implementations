#include "stack_dynamic.h"

/************************ Helper functions prototypes ************************/

static uint16_t StackIsEmpty(Stack_t* stack_obj);
static uint16_t StackIsFull(Stack_t* stack_obj);


Stack_t* CreateStack(uint32_t MaxSize, StackStatus_t* ret_status){
    Stack_t *my_stack = NULL;
    if( NULL == ret_status){
        *ret_status = STACK_NULL_POINTER;
        my_stack = NULL;
    }
    else {
        my_stack = (Stack_t*)malloc(sizeof(Stack_t));
        if(NULL == my_stack){
            *ret_status = STACK_NOK;
            my_stack = NULL;
        }
        else {
            my_stack->ElementCount=0;
            my_stack->StackTop=-1;
            my_stack->StackMaxSize = MaxSize;
            my_stack->StackArray=(void**)calloc(my_stack->StackMaxSize,sizeof(void*));
            if(NULL == my_stack->StackArray){
                free(my_stack);
                *ret_status = STACK_NOK;
                my_stack = NULL;
            }
            else {
                *ret_status = STACK_OK;
            }
        }
    }
    return my_stack;
}


Stack_t* DestroyStack(Stack_t* stack_obj, StackStatus_t* ret_status){
    if( (NULL == ret_status || (NULL == stack_obj))){
        *ret_status = STACK_NULL_POINTER;
    }
    else {
        free(stack_obj->StackArray);
        free(stack_obj);
        *ret_status = STACK_OK;
    }
    return NULL;
}


StackStatus_t PushStack(Stack_t* stack_obj, void* itemptr){
    StackStatus_t stackstatus = STACK_NOK;
    if( (NULL == itemptr || (NULL == stack_obj))){
        stackstatus = STACK_NULL_POINTER;
    }
    else {
        if(StackIsFull(stack_obj)){
            stackstatus = STACK_FULL;
        }
        else {
            (stack_obj->StackTop)++;
            stack_obj->StackArray[stack_obj->StackTop] = itemptr;
            (stack_obj->ElementCount)++;
            stackstatus = STACK_OK ;
        }
    }
    return stackstatus;
}


void* PopStack(Stack_t* stack_obj, StackStatus_t* ret_status){
    void* data_ptr = NULL;
    if( (NULL == ret_status || (NULL == stack_obj))){
        *ret_status = STACK_NULL_POINTER;
        data_ptr = NULL;
    }
    else {
        if(StackIsEmpty(stack_obj)){
            *ret_status = STACK_EMPTY;
            data_ptr = NULL;
        }
        else {
            data_ptr = stack_obj->StackArray[stack_obj->StackTop];
            (stack_obj->StackTop)--;
            (stack_obj->ElementCount)--;
            *ret_status = STACK_OK;
        }
    }
    return data_ptr;
}


void* StackTop(Stack_t* stack_obj, StackStatus_t* ret_status){
    void* data_ptr = NULL;
    if( (NULL == ret_status || (NULL == stack_obj))){
        *ret_status = STACK_NULL_POINTER;
        data_ptr = NULL;
    }
    else {
        if(StackIsEmpty(stack_obj)){
            *ret_status = STACK_EMPTY;
            data_ptr = NULL;
        } 
        else {
            data_ptr = stack_obj->StackArray[stack_obj->StackTop];
            *ret_status = STACK_OK;
        }
    }
    return data_ptr;
}


StackStatus_t Stack_Count(Stack_t* stack_obj, uint32_t* stack_count){
    StackStatus_t stackstatus = STACK_NOK;
    if( (NULL == stack_count || (NULL == stack_obj))){
        stackstatus = STACK_NULL_POINTER;
    }
    else {
        *stack_count = stack_obj->ElementCount;
    }
    return stackstatus;
}


static uint16_t StackIsEmpty(Stack_t* stack_obj){
    return (stack_obj->ElementCount == ZERO);
}

static uint16_t StackIsFull(Stack_t* stack_obj){
    return (stack_obj->ElementCount == stack_obj->StackMaxSize);
}