//
//  main.c
//  RandomGenerator
//
//  Created by Evgeniy Morozov on 28.03.17.
//  Copyright © 2017 Evgeniy Morozov. All rights reserved.
//

#include <stdio.h>

#include "generator.h"

int main(int argc, const char * argv[])
{
    int i = 0;
    rand_ctx_t * rand_ctx = NULL;
    
    rand_ctx = rand_init(0.5, RAND_CONST_DEFAULT);
    
    for (i = 0; i < 50; ++i)
    {
        printf("%f\n", rand_next(rand_ctx));
    }
    return 0;
}
