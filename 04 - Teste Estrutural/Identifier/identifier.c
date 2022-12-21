int validateIdentifier(char* s) { 
   char achar; 
   int i, valid_id = FALSE; 
   if (strlen(s) > 0) { 
      achar = s[0]; 
      valid_id = valid_s(achar); 
      if (strlen(s) > 1) { 
         achar = s[1]; 
         i = 1; 
         while (i < strlen(s)) { 
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