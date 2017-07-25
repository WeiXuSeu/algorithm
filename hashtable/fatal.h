#include<stdio.h>
#include<stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) fprintf(stderr,"%s\n",str),exit(1)