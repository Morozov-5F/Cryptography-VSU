//
//  tests.h
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#ifndef tests_h
#define tests_h

#include <stdlib.h>

double test_find_mean_dispersion(double seed, double param, size_t length,
                                 double * dispersion);

void test_create_histogram(double seed, double param, size_t intervals,
                             size_t length, const char * file_name);

#endif /* tests_h */
