//
//  generator.h
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdio.h>

#define RAND_CONST_DEFAULT                  (11)

typedef struct rand_ctx_s rand_ctx_t;

rand_ctx_t * rand_init(double seed, double param);

double rand_next(rand_ctx_t * rand_ctx_t);

#endif /* GENERATOR_H */
