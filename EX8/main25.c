#include <stdio.h>

int main()
{
    int var = 20;
    int* ip;
    
    ip = &var;
    printf("Addrss ot var: %p\n", &var);
    printf("Valeu of ip: %p\n", ip);
    printf("Address of ip: %p\n", &ip);
    printf("Value of *ip: %d\n", *ip);
    return 0;
}
