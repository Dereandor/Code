#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_replace(const char *text)
{
  int orig_len = strlen(text);
  int res_len = orig_len;

  for (int i = 0; i < orig_len; i++)
  {
    if (memcmp(&text[i], "&", 1) == 0)
    {
      res_len += strlen("&amp");
    }
    else if (memcmp(&text[i], "<", 1) == 0)
    {
      res_len += strlen("&lt");
    }
    else if (memcmp(&text[i], ">", 1) == 0)
    {
      res_len += strlen("&gt");
    }
    else
    {
      res_len++;
    }
  }

  //char *res = (char *)malloc(sizeof(char) * res_len + 1);

  // Nothing guarantees that this won't be overwritten.
  // Alternative: call free() in fuzzing
  // If it is used directly after return it should be "safe"
  char res[res_len + 1];

  int temp_index = 0;

  for (int i = 0; i < orig_len; i++)
  {
    if (memcmp(&text[i], "&", 1) == 0)
    {
      memcpy(&res[temp_index], "&amp", strlen("&amp"));
      temp_index += strlen("&amp");
    }
    else if (memcmp(&text[i], "<", 1) == 0)
    {
      memcpy(&res[temp_index], "&lt", strlen("&lt"));
      temp_index += strlen("&lt");
    }
    else if (memcmp(&text[i], ">", 1) == 0)
    {
      memcpy(&res[temp_index], "&gt", strlen("&gt"));
      temp_index += strlen("&gt");
    }
    else
    {
      memcpy(&res[temp_index], &text[i], sizeof(char));
      temp_index++;
    }
  }

  return res;
}
