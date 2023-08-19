#ifndef _STACK_H
#define _STACK_H

#include "std_types.h"

#define STACK_MAX_SIZE 5

typedef struct stack_t{
    uint32_t stack_ptr;
    uint32_t data[STACK_MAX_SIZE];
}stack_t;

typedef enum stack_status{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_FULL
}stack_status;

/**
 * @brief function to initialize the stack
 * @param ptr_to_stack pointer to the stack to be initialized
 * @return ret status of the initilization process
 */
return_status stack_init(stack_t* ptr_to_stack);

/**
 * @brief function to push elements to the stack
 * @param ptr_to_stack pointer to the stack
 * @return ret status of the stack
 */
return_status stack_push(stack_t* ptr_to_stack , uint32_t value);

/**
 * @brief function to pop elements from the stack
 * @param ptr_to_stack pointer to the stack
 *        *value pointer to where the top be stored
 * @return ret status of the stack
 */
return_status stack_pop(stack_t* ptr_to_stack, uint32_t* value);

/**
 * @brief function to return the size of the stack (number of elements)
 * @param ptr_to_stack pointer to the stack
 *        *size pointer to where the size be stored
 * @return ret status of the stack
 */
return_status stack_size(stack_t* ptr_to_stack, uint32_t* size);

/**
 * @brief function to return the top of the stack
 * @param ptr_to_stack pointer to the stack
 *        *value pointer to where the top be stored
 * @return ret status of the stack
 */
return_status stack_top(stack_t* ptr_to_stack, uint32_t* value);

/**
 * @brief function to diplay elements of the stack
 * @param ptr_to_stack pointer to the stack
 * @return ret status of the stack
 */
return_status stack_display(stack_t* ptr_to_stack);

#endif
