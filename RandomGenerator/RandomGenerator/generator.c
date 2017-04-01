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

void rand_reset(rand_ctx_t * rand_ctx)
{
    assert(NULL != rand_ctx);
    
    rand_ctx->rctx_prev_val = rand_ctx->rctx_seed;
}

void rand_deinit(rand_ctx_t * rand_ctx)
{
    free(rand_ctx);
}

double rand_next(rand_ctx_t * ctx)
{
    double next         = 0;
    double val          = 0;
    
    assert(NULL != ctx);
    
    val = ctx->rctx_prev_val * ctx->rctx_param + M_PI;
    
    next = val - (int)(val);
    ctx->rctx_prev_val = next;
    
    return next;
}
