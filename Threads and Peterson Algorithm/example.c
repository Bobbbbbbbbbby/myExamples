#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


void *threadA();
void *threadB();
void *thread(long *parameter);
int toAdd = 0;

#ifndef PASS_PARAMETER
int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, threadA, NULL);
    pthread_create(&thread2, NULL, threadB, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("result is: %d\n", toAdd);
    return 0;
}
#endif

#ifdef PASS_PARAMETER
int main()
{
    pthread_t pthread1;
    long a[5] = {1, 2, 3, 4, 5};
    long b = 5;
    long passA[2] = {(long)&b, (long)a};

    void *result;

    pthread_create(&pthread1, NULL, thread, passA);
    pthread_join(pthread1, &result);

    int *a1 = (int*) result;
    printf("%d\n", *a1);
    return 0;
}
#endif

#ifdef EASY
void* threadA()
{
    for (int i = 0; i < 1000000; i++)
    {
        toAdd++;
    }
}

void* threadB()
{
    for (int i = 0; i < 1000000; i++)
    {
        toAdd++;
    }
}
#endif

#ifdef PETERSON
int turn;
int flag[2];
void *threadA()
{
    for (int i0 = 0; i0 < 1000000; i0++)
    {
        flag[0] = 1;
        turn = 1;
        __sync_synchronize();
        while (flag[1] && (turn == 1))
            ;
        toAdd++;
        flag[0] = 0;
    }
}

void *threadB()
{
    for (int i1 = 0; i1 < 1000000; i1++)
    {
        flag[1] = 1;
        turn = 0;
        __sync_synchronize();
        while (flag[0] && (turn == 0))
            ;
        toAdd++;
        flag[1] = 0;
    }
}
#endif

#ifdef PASS_PARAMETER
void* thread(long* parameter)
{
    long *b = parameter[0];
    long *array = parameter[1];
    printf("%ld\n", *b);
    for (int i = 0; i < *b; i++)
    {
        printf("%ld\n", array[i]);
    }
    int *a = malloc(sizeof(int));
    *a = 5;
    return a;
}
#endif