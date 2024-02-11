#include <stdio.h>
#include "my_mat.h"
int main()
{
    char x = 0;
    int flag = 1;
    while (flag == 1)
    {
        scanf(" %c", &x);
        if (x == 'A')
        {
            A = a_func(1);
        }
        if (x == 'B')
        {
            scanf(" %d%d", &q, &y);
            B = b_func(q, y);
        }
        if (x == 'C')
        {
            scanf(" %d%d", &q, &y);
            C = c_func(q, y);
            printf("%d\n", C);
        }
        if (x == 'D')
        {
            flag = -1;
        }
    }
    return 0;
}
