#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

#include "rep.c"

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    str_replace((const char *)data);

    return 0;
}
