//
//  main.c
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#include <stdio.h>

#include "generator.h"
#include "tests.h"

int main(int argc, const char * argv[])
{
    double mean = 0, dispersion = 0;
    mean = test_find_mean_dispersion(0.5, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.5, 11, mean, dispersion);
    mean = test_find_mean_dispersion(0.002, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.002, 11, mean, dispersion);
    mean = test_find_mean_dispersion(0.1, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.1, 11, mean, dispersion);
    mean = test_find_mean_dispersion(1.3, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 1.3, 11, mean, dispersion);
    
    mean = test_find_mean_dispersion(0.5, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.5, 79, mean, dispersion);
    mean = test_find_mean_dispersion(0.002, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.002, 79, mean, dispersion);
    mean = test_find_mean_dispersion(0.1, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 0.1, 79, mean, dispersion);
    mean = test_find_mean_dispersion(1.3, 11, 100000, &dispersion);
    printf("Seed: %f, param: %d, mean: %e, dispersion: %e\n", 1.3, 79, mean, dispersion);
    
    test_create_histogram(0.1, 79, 10   , 100000, "hist.dat");
    
    return 0;
}
