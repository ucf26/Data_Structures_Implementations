

#include <stdio.h>
#include "stack.h"
#include "std_types.h"

stack_t stack1;
uint32_t val;
uint32_t size;

int main()
{
    return_status ret_init = stack_init(&stack1); 

    ret_init = stack_size(&stack1, &size);

    ret_init = stack_push(&stack1,11); /* pushing to the stack */
    ret_init = stack_push(&stack1,22);

    ret_init = stack_top(&stack1, &val); /* accessing stack top */
    printf("stack top = %i \n",val); 

    ret_init = stack_push(&stack1,33);
    ret_init = stack_push(&stack1,44);
    ret_init = stack_push(&stack1,55);
    ret_init = stack_size(&stack1, &size); /* size after pushing */
    printf("size after pushing = %i\n",size);
    
    ret_init = stack_display(&stack1); /* diplaying the stack */
    
    ret_init = stack_pop(&stack1 , &val); /* poping from the stack */
    ret_init = stack_pop(&stack1 , &val);
    ret_init = stack_pop(&stack1 , &val);
    ret_init = stack_pop(&stack1 , &val);
    ret_init = stack_pop(&stack1 , &val);

    ret_init = stack_size(&stack1, &size); /* size after poping */
    printf("size after poping = %i\n",size);
    
    return 0;
}
