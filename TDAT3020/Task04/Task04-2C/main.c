#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *input, char *replace, char *with) {
    char *result;
    char *insert;
    char *temp;
    int l_front;
    int count;
    int l_replace = strlen(replace);
    int l_with = strlen(with);

    //Teller hvor mye større strengen blir
    insert = input;
    for(count = 0; (temp = strstr(insert, replace)); ++count) {
        insert = temp + l_replace;
    }
    //allokerer minneplass
    temp = result = malloc(strlen(input) + (l_with - l_replace) * count + 1);

    if(!result)
        return NULL;

    while (count--) {
        insert = strstr(input, replace);
        l_front = insert - input;
        temp = strncpy(temp, input, l_front) + l_front;
        temp = strcpy(temp, with) + l_with;
        input += l_front + l_replace;
    }
    strcpy(temp, input);
    return result;
}

char *replacer(char *message) {
    message = replace(message, "&", "&amp");
    message = replace(message, "<", "&lt");
    message = replace(message, ">", "&gt");
    return message;
}

int main() {
    char *str = "Hello & welcome < user >";
    printf("%s\n", str);
    printf("%s\n", replacer(str));
}