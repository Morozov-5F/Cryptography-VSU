/**
 *  main.c
 *  FeistelNetEcryption
 *
 *  Created by Evgeniy Morozov on 03.03.17.
 *  Copyright © 2017 Evgeniy Morozov. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "FeistelNet.h"

#include <string.h>

int main(int argc, const char * argv[])
{
    char message[256] = "1234567";
    size_t message_size = 0;
    char * encrypted = NULL;
    char * decrypted = NULL;
    printf("Input message > ");
    scanf("%[^\n]s", message);
    message_size = strlen(message);
    feist_ctx_t * context = feist_init(10, 0xDEAD, NULL, NULL);
    printf("Source message: %s\n", message);
    encrypted = feist_encrypt(context, message, &message_size);
    printf("Encrypted message: %s\n", encrypted);
    decrypted = feist_decrypt(context, encrypted, &message_size);
    printf("Decrypted message: %s\n", decrypted);
    
    
    free(encrypted);
    free(decrypted);
    free(context);
    return 0;
}
