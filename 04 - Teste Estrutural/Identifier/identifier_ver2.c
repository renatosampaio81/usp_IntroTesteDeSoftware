#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int validateIdentifier(char* s);
int valid_s(char ch);
int valid_f(char ch);

int validateIdentifier(char* s) {
   char achar;
   int i, valid_id = FALSE;
   if (strlen(s) > 0) {
      achar = s[0];
      valid_id = valid_s(achar);
      if (strlen(s) > 1) {
         achar = s[1];
         i = 1;
         while (i < strlen(s) - 1) {
            achar = s[i];
            if (!valid_f(achar))
               valid_id = FALSE;
            i++;
         }
      }
   }

   if (valid_id && (strlen(s) >= 1) && (strlen(s) < 6))
      return TRUE;
   else
      return FALSE;
}

int valid_s(char ch) {
   if (((ch >= 'A') && (ch <= 'Z'))
         || ((ch >= 'a') && (ch <= 'z')))
      return TRUE;
   else
      return FALSE;
}

int valid_f(char ch) {
   if (((ch >= 'A') && (ch <= 'Z'))
         || ((ch >= 'a') && (ch <= 'z'))
         || ((ch >= '0') && (ch <= '9')))
      return TRUE;
   else
      return FALSE;
}

int main(int argc, char** argv) {
   if (argc == 1) {
      printf("Usage: identifier <string>\n");
   } else {
      if (validateIdentifier(argv[1])) {
         printf("Valid\n");
      } else {
         printf("Invalid\n");
      }
   }
}