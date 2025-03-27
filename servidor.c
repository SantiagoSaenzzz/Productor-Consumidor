/*
PONTIFICIA UNIVERSIDAD JAVERIANA
Autor: J. Vargas
Materia: Sistemas Operativos
Clase: 2154
Descripción: Archivo Servidor
Implementación del paradigma Productor-Consumidor usando FIFO. El cliente actúa como
productor enviando cadenas, y el servidor como consumidor que las procesa e invierte. 
La FIFO permite la comunicación entre procesos de forma sincronizada entre ambos codigos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "servidor_utils.h"

#define FIFO_FILE "/tmp/fifo_twoway"

int main() {
   int fd;
   char readbuf[80]; //Bus de lectura en chat: Lector de palabras de hasta 80 caracteres
   char end[10];     //Bus de final: Maximo 10 caracteres
   int to_end;
   int read_bytes;

   /* Create the FIFO if it does not exist */
   mkfifo(FIFO_FILE, 0640);  //Crea un  ducto o conducto o pasaje de comunicación
   strcpy(end, "end"); //Copia al final del vector de caracteres la palabra end
   fd = open(FIFO_FILE, O_RDWR);
   while (1) {
      read_bytes = read(fd, readbuf, sizeof(readbuf));
      readbuf[read_bytes] = '\0';
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      to_end = strcmp(readbuf, end);

      if (to_end == 0) {
         close(fd);
         break;
      }
      reverse_string(readbuf);
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));
      write(fd, readbuf, strlen(readbuf));
      sleep(2);
   }
   return 0;
}
