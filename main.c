#include "queue.h"
#include <stdio.h>
//如果一开始拿到的queue是NULL,那么下面的函数都是在对空指针做事
int main(void)
{
    Queue *queue = queue_create();
    if (queue == NULL)
    {
        fprintf(stderr, "Failed to create queue.\n");
        return 1;
    }

    for (int i = 0; i < 100; ++i)
    {
        push(queue, i * 10);
        printf("%f\n", back(queue));
    }

    queue_free(queue);
    return 0;
}