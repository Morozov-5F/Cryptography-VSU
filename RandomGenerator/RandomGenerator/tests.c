//
//  tests.c
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#include <assert.h>
#include <math.h>

#include "tests.h"
#include "generator.h"

#define EPS (1e-15)

double test_find_mean_dispersion(double seed, double param, size_t length,
                                 double * dispersion)
{
    rand_ctx_t * context = NULL;
    double local_dispersion = 0;
    double mean             = 0;
    size_t i = 0;
    
    context = rand_init(seed, param);
    
    assert(NULL != context);
    assert(NULL != dispersion);
    assert(0    != length);
    
    for (i = 0; i < length; ++i)
    {
        mean += rand_next(context);
    }
    
    mean /= (double)length;
    
    rand_reset(context);
    
    for (i = 0; i < length; ++i)
    {
        double next = rand_next(context);
        local_dispersion += (next - mean) * (next - mean);
    }
    local_dispersion /= (double)(length - 1);
    *dispersion = local_dispersion;
    
    return mean;
}

void test_create_histogram(double seed, double param, size_t intervals,
                           size_t length, const char * file_name)
{
    size_t * histogram = NULL;
    size_t i = 0;
    size_t max = 0;
    rand_ctx_t * ctx = NULL;
    FILE * output = NULL;
    
    assert(NULL != file_name);
    assert(0 != length);
    
    ctx = rand_init(seed, param);
    assert(NULL != ctx);
    
    histogram = calloc(intervals, sizeof(size_t));
    assert(NULL != histogram);
    
    for (i = 0; i < length; ++i)
    {
        size_t ind = (size_t)(rand_next(ctx) * intervals);
        ++histogram[ind];
        if (histogram[ind] > max)
        {
            max = histogram[ind];
        }
    }
    
    output = fopen(file_name, "w");
    assert(NULL != output);
    
    fprintf(output, "# Histogram of random number generator\n");
    fprintf(output, "# Parameters: seed %f parameter %f\n", seed, param);
    
    for (i = 0; i < intervals; ++i)
    {
        fprintf(output, "%f %f\n", (double)i / intervals, (double)histogram[i] / max / 2);
    }
    fclose(output);
}
