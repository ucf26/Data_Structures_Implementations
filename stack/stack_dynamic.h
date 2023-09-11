#ifndef STACK_DYNAMYC_H
#define STACK_DYNAMYC_H


#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"


typedef struct {
    void** StackArray;
    uint32_t StackMaxSize;
    uint32_t ElementCount;
    sint32_t StackTop;
}Stack_t;

typedef enum{
    STACK_NOK,
    STACK_OK,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_POINTER
}StackStatus_t;


Stack_t* CreateStack(uint32_t MaxSize, StackStatus_t* ret_status);
Stack_t* DestroyStack(Stack_t* stack_obj, StackStatus_t* ret_status);
StackStatus_t PushStack(Stack_t* stack_obj, void* itemptr);
void* PopStack(Stack_t* stack_obj, StackStatus_t* rer_status);
void* StackTop(Stack_t* stack_obj, StackStatus_t* rer_status);
StackStatus_t Stack_Count(Stack_t* stack_obj, uint32_t* stack_count);


#endif