//
//  generator.c
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#include "generator.h"

#include <stdlib.h>
#include <math.h>

#include <assert.h>

struct rand_ctx_s
{
    double rctx_seed;
    double rctx_prev_val;
    double rctx_param;
};

rand_ctx_t * rand_init(double seed, double param)
{
    rand_ctx_t * ctx = NULL;
    ctx = calloc(1, sizeof(rand_ctx_t));
    
    assert(NULL != ctx);
    
    ctx->rctx_prev_val = seed;
    ctx->rctx_seed     = seed;
    ctx->rctx_param    = param;
 
    return ctx;
}

double rand_next(rand_ctx_t * ctx)
{
    double integer_part = 0;
    double next         = 0;
    
    assert(NULL != ctx);
    
    next = modf(ctx->rctx_prev_val * ctx->rctx_param + M_PI, &integer_part);
    ctx->rctx_prev_val = next;
    
    return next;
}
