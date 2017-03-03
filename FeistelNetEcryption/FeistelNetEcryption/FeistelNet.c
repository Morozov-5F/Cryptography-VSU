/*
 *  FeistelNet.c
 *  FeistelNetEcryption
 *
 *  Created by Evgeniy Morozov on 03.03.17.
 *  Copyright © 2017 Evgeniy Morozov. All rights reserved.
 */

#include "FeistelNet.h"

#include <stdlib.h>

struct feist_block_s
{
    uint16_t fnb_sub_1;
    uint16_t fnb_sub_2;
    uint16_t fnb_sub_3;
    uint16_t fnb_sub_4;
};

struct feist_ctx_s
{
    uint64_t        * fnc_keys;
    feist_keygen_cb   fnc_key_generator;
    feist_round_fn_cb fnc_round_fn;
    size_t            fnc_rounds;
};

uint64_t s_feist_default_keygen(uint64_t start_key, size_t round)
{
    return ROR(start_key, round * 3);
}

uint64_t s_feist_default_round_fn(uint64_t x1, uint64_t x2,
                                  uint64_t x3, uint64_t k)
{
    return ROL(x1, 9) ^ (~(ROR(k, 11) ^ x2)) ^ x3;
}

feist_ctx_t * feist_init(size_t rounds, uint64_t init_key,
                         feist_keygen_cb key_generator_cb,
                         feist_round_fn_cb round_fn_cb)
{
    feist_ctx_t * context = NULL;
    
    context = calloc(sizeof(feist_ctx_t), 1);
    assert(NULL != context);
    
    context->fnc_rounds = rounds;
    
    context->fnc_keys = calloc(sizeof(uint64_t), rounds);
    assert(NULL != context->fnc_keys);
    
    context->fnc_keys[0] = init_key;
    
    if (NULL == key_generator_cb)
    {
        key_generator_cb = s_feist_default_keygen;
    }
    context->fnc_key_generator = key_generator_cb;
    
    if (NULL == round_fn_cb)
    {
        round_fn_cb = s_feist_default_round_fn;
    }
    context->fnc_round_fn = round_fn_cb;
    
    return context;
}

char * feist_encrypt(feist_ctx_t * ctx, const char message[],
                     size_t * message_len)
{
    feist_block_t * encr_message = NULL;
    
    assert(NULL != ctx);
    assert(NULL != message);
    assert(NULL != message_len);
    
    return (char *)encr_message;
}

char * feist_decrypt(feist_ctx_t * ctx, const char message[],
                     size_t * message_len)
{
    feist_block_t * encr_message = NULL;
    
    assert(NULL != ctx);
    assert(NULL != message);
    assert(NULL != message_len);
    
    return (char *)encr_message;
}

