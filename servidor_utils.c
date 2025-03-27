/*
PONTIFICIA UNIVERSIDAD JAVERIANA
Autor: J. Vargas
Materia: Sistemas Operativos
Clase: 2154
Descripción: Archivo Servidor_Utils
*/

#include <string.h>
#include "servidor_utils.h"

void reverse_string(char *str) {
   int first = 0;
   int last = strlen(str) - 1;
   char temp;

   while (first < last) {
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;
      first++;
      last--;
   }
}
