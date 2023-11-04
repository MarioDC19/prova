#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define n 5

// per compilare il file sorgente in file oggetto: !gcc -O2 -Wall -c ompparallel.c -o ompparallel.o -fopenmp
// per linkare: !gcc -o ompparallel ompparallel.o -fopenmp
// !export OMP_NUM_THREADS=4
// !echo $OMP_NUM_THREADS
// ./ompparallel

// in windows in shell bash 
// set %nomevar% 

// in colab:
// import os
// os.environ['OMP_NUM_THREADS']='4'
int main (int argc, char * argv[]){
    #pragma omp parallel
    {
        printf ("Parallel Region executed by %d thread\n",
            omp_get_thread_num());
        if (omp_get_thread_num() == 1)
            printf(" I'm thread %d and I'm different\n",
                omp_get_thread_num());
    } //end of parallel region
}