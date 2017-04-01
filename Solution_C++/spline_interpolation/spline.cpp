#include <cstdio>
#include <cstdlib>
#include <vector>
#include "spline.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {


   static const double arr1[] = {0, 187, 300, 540, 1030, 1810, 2775, 3790, 4800, 5470, 6000, 7200};
   static const double arr2[] = {0, 60, 120, 221, 515, 1054, 2042, 3242, 5000 , 6323, 8000, 15000};

   vector<double> X (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );  //vector from array!
   vector<double> D (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

    tk::spline s;
    s.set_points(X,D);    // currently it is required that X is already sorted

    double x=300;

    printf("spline at %f is %f\n", x, s(x));

   // return EXIT_SUCCESS;
   return 0;
}
