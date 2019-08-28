#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("Sizes:"
           "\n\tint: %lu,"
           "\n\tfloat: %lu,"
           "\n\tdouble: %lu\n"
           "Max values:"
           "\n\tint: %d,\n\tfloat: %f,\n\tdouble: %f\n",
           sizeof a, sizeof b, sizeof c,
           a, b, c
           );





}
