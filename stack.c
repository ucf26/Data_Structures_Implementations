#include <stdio.h>
#include "stack.h"

/**
 * @brief function to initialize the stack
 * @param ptr_to_stack pointer to the stack to be initialized
 * @return ret status of the initilization process
 */
return_status stack_init(stack_t* ptr_to_stack)
{
    return_status ret = R_NOK;
    if(NULL == ptr_to_stack)
    {
        ret = R_NOK;
    }
    else
    {
        ret = R_OK;
        ptr_to_stack->stack_ptr=-1;
    }
    return ret;
}

/**
 * @brief function to check the status of the stack
 * @param ptr_to_stack pointer to the stack to be initialized
 * @return ret status of the stack
 */
static stack_status stack_empty(stack_t* ptr_to_stack)
{
    if(ptr_to_stack->stack_ptr == -1)
    {
        return STACK_EMPTY;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}


/**
 * @brief function to check the status of the stack
 * @param ptr_to_stack pointer to the stack to be initialized
 * @return ret status of the stack
 */
static stack_status stack_full(stack_t* ptr_to_stack)
{
    if(ptr_to_stack->stack_ptr == STACK_MAX_SIZE-1)
    {
        return STACK_FULL;
    }
    else
    {
        return STACK_NOT_FULL;
    }
}

/**
 * @brief function to push elements to the stack
 * @param ptr_to_stack pointer to the stack
 * @return ret status of the stack
 */
return_status stack_push(stack_t* ptr_to_stack , uint32_t value)
{
    return_status ret = R_NOK;
    if(NULL == ptr_to_stack || STACK_FULL == stack_full(ptr_to_stack))
    {
        printf("Error, value (%i) can’t be pushed !!",value);
    }
    else
    {
        ptr_to_stack->stack_ptr++;
        ptr_to_stack->data[ptr_to_stack->stack_ptr] = value;
        ret = R_OK;
    }
    return ret;
}

/**
 * @brief function to pop elements from the stack
 * @param ptr_to_stack pointer to the stack
 *        *value pointer to where the top be stored
 * @return ret status of the stack
 */
return_status stack_pop(stack_t* ptr_to_stack, uint32_t* value)
{
    return_status ret = R_NOK;
    if( (NULL == ptr_to_stack) || (STACK_EMPTY == stack_empty(ptr_to_stack)) || ( NULL == value) )
    {
        printf("Error, stack can’t be poped !!");
    }
    else
    {
        ptr_to_stack->data[ptr_to_stack->stack_ptr] = *value;
        ptr_to_stack->stack_ptr--;
        ret = R_OK;
    }
    return ret;
}

/**
 * @brief function to return the size of the stack (number of elements)
 * @param ptr_to_stack pointer to the stack
 *        *size pointer to where the size be stored
 * @return ret status of the stack
 */
return_status stack_size(stack_t* ptr_to_stack, uint32_t* size)
{
    return_status ret = R_NOK;
    if( (NULL == ptr_to_stack) || ( NULL == size) )
    {
        printf("Error !!");
    }
    else
    {
        *size = ptr_to_stack->stack_ptr + 1 ;
        ret = R_OK;
    }
    return ret;
}

/**
 * @brief function to return the top of the stack
 * @param ptr_to_stack pointer to the stack
 *        *value pointer to where the top be stored
 * @return ret status of the stack
 */
return_status stack_top(stack_t* ptr_to_stack, uint32_t* value)
{
    return_status ret = R_NOK;
    if( (NULL == ptr_to_stack) || ( NULL == value) || (STACK_EMPTY == stack_empty(ptr_to_stack)))
    {
        printf("Error !!");
    }
    else
    {
        *value = ptr_to_stack->data[ptr_to_stack->stack_ptr];
        ret = R_OK;
    }
    return ret;
}

/**
 * @brief function to diplay elements of the stack
 * @param ptr_to_stack pointer to the stack
 * @return ret status of the stack
 */
return_status stack_display(stack_t* ptr_to_stack)
{
    return_status ret = R_NOK;
    if(NULL == ptr_to_stack)
    {
        printf("Error !! \n");
    }
    else if( STACK_EMPTY == stack_empty(ptr_to_stack) )
    {
        printf("stack is empty !! \n");
    }
    else
    {
        sint32_t cnt=ptr_to_stack->stack_ptr;
        while(cnt >=0)
        {
            printf("%i\t",ptr_to_stack->data[cnt]);
            cnt--;
        }
        printf("\n");
        ret=R_OK;

    }
    return ret;
}
