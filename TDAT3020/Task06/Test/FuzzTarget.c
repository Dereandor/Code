#include <stddef.h>
#include <stdint.h>
#include "main.h"

//Test push for CI

int LLVMFuzzerTestOneInput(const uint8_t * data, size_t size){
    printf("%zu\n", size);
    replace_chars((char*)data, size);
    return 0;
}
