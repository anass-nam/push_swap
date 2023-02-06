#include <unistd.h>

int main(int argc, char const *argv[])
{
    
    return 0;
}


/*
    A="1 2 3"; awk 'BEGIN { printf "" }' | ./checker_linux $A
    A="2 3 1"; awk 'BEGIN { printf "rra\n" }' | ./checker_linux $A
    A="3 1 2"; awk 'BEGIN { printf "ra\n" }' | ./checker_linux $A
    A="1 3 2"; awk 'BEGIN { printf "sa\nra\n" }' | ./checker_linux $A
    A="2 1 3"; awk 'BEGIN { printf "sa\n" }' | ./checker_linux $A
    A="3 2 1"; awk 'BEGIN { printf "ra\nsa\n" }' | ./checker_linux $A
    A="3 2 1"; awk 'BEGIN { printf "sa\nrra\n" }' | ./checker_linux $A

>> order >>
[1] [2] [3]
 |
 Top of Stack
______________________
[2] [3] [1] => rra
[3] [1] [2] => ra
[1] [3] [2] => sa | ra
[2] [1] [3] => sa
[3] [2] [1] => ra | sa
[3] [2] [1] => sa | rra
 


*/