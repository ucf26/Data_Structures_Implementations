#include <stdio.h>
#include "std_types.h"
#include "stack_dynamic.h"



Stack_t *stack1;
uint32_t max_size;

uint32_t var1 =55;
float var2 = 5.66;
char var3 = 'd';
void* stack_ret = NULL;
uint32_t stack_count = 0;
void *data=NULL;


int main(){

    StackStatus_t stack_status = STACK_NOK ;
    printf("Enter stack max size !! \n");
    scanf("%i",&max_size);

    stack1= CreateStack(max_size, &stack_status);
    if(stack1){
        printf("Stack has been created. \n");
    }
    stack_status = PushStack(stack1, &var1); printf("stack status = %i \n",stack_status);
    stack_status = PushStack(stack1, &var2); printf("stack status = %i \n",stack_status);
    stack_status = PushStack(stack1, &var3); printf("stack status = %i \n",stack_status);
    stack_status = PushStack(stack1, &var3); printf("stack status = %i \n",stack_status);

    stack_status = Stack_Count(stack1, &stack_count); printf("stack status = %i \n",stack_status);
    printf("Stack count = %i \n", stack_count);

    data = StackTop(stack1 , &stack_status);
    printf("%c \n" , *((char *)data));




    stack_ret = PopStack(stack1,&stack_status); printf("stack status = %i \n",stack_status);
    printf("stack top = %c \n",*((char*)stack_ret));
    stack_ret = PopStack(stack1,&stack_status); printf("stack status = %i \n",stack_status);
    printf("stack top = %f \n",*((float*)stack_ret));
    stack_ret = PopStack(stack1,&stack_status); printf("stack status = %i \n",stack_status);
    printf("stack top = %c \n",*((uint32_t*)stack_ret));

    stack_ret = PopStack(stack1,&stack_status); printf("stack status = %i \n",stack_status); 


    stack1=DestroyStack(stack1, &stack_status);
    
    
    if (NULL == stack1)
    {
        
    }
    
    
    
}