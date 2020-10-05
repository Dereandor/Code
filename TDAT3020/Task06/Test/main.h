#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

/* Changes &, <, > with &amp;, &lt;, and &gt; respectively*/
char* replace_chars(const char* string, size_t len){
    if(!string || len == 0){
        return NULL;
    }
    const char* and_replace = "&amp;";
    const char* lt_replace = "&lt;";
    const char* gt_replace = "&gt;";

    //Count occurances of the to-be-replaced values in order to determine new string size
    size_t and_count = 0;
    size_t other_count = 0;
    for(size_t i = 0; i < len; i++)
    {
        if(*(string+i) == '&') and_count++;
        else if(*(string+i) == '<' || *(string+i) == '>') other_count++;
    }

    //Create the new string with the required size
    size_t new_size = len + (and_count*(strlen(and_replace)-1))+(other_count*(strlen(lt_replace)-1));
    char* new_string = (char*)malloc(new_size);
    if(!new_string) return NULL;
    new_string[new_size-1] = '\0';
    
    size_t charfarter = 0;
    size_t new_string_index = 0;
    while(charfarter < (len) && *(string+charfarter) != '\0'){
        if(*(string+charfarter) == '&'){
            memcpy(new_string+new_string_index, and_replace, strlen(and_replace));
            new_string_index += strlen(and_replace);
        }
        else if(*(string+charfarter) == '<'){
            memcpy(new_string+new_string_index, lt_replace, strlen(lt_replace));
            new_string_index += strlen(lt_replace);
        }
        else if(*(string+charfarter) == '>'){
            memcpy(new_string+new_string_index, gt_replace, strlen(gt_replace));
            new_string_index += strlen(gt_replace);
        }
        else{
            *(new_string+new_string_index) = *(string+charfarter);
            new_string_index++;
        }
        charfarter++;
    }
    free(new_string); //Only to appease ASAN, obviously the caller should free the resource
    return new_string;
}
