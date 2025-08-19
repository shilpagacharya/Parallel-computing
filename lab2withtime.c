#include <stdio.h>
#include <omp.h>

int fib(int n) {
    int i, j;
    if (n < 2)
        return n;
    else {
        #pragma omp task shared(i)
        i = fib(n - 1);
        #pragma omp task shared(j)
        j = fib(n - 2);
        #pragma omp taskwait
        return i + j;
    }
}

int main() {
    int n;
    double t1, t0;
    printf("Enter the Fibonacci number to calculate: ");
    scanf("%d", &n);

    omp_set_dynamic(0);
    omp_set_num_threads(4);

    int result;
    #pragma omp parallel shared(n)
    {
        #pragma omp single
        {
            t0 = omp_get_wtime();
            result = fib(n);
            t1 = omp_get_wtime();
            printf("fib(%d) = %d, time = %f sec\n", n, result, t1 - t0);
        }
    }

    return 0;
}