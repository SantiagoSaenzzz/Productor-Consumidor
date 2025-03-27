/*
PONTIFICIA UNIVERSIDAD JAVERIANA  
Autor: J. Vargas  
Materia: Sistemas Operativos  
Clase: 2154  
Descripción: Archivo Cliente  
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_FILE "/tmp/fifo_twoway"

int main() {
   int fd;
   int end_process;
   int stringlen;
   int read_bytes;
   char readbuf[80];
   char end_str[5];

   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

   fd = open(FIFO_FILE, O_CREAT | O_RDWR);
   if (fd == -1) {
      perror("Error opening FIFO");
      exit(EXIT_FAILURE);
   }

   strcpy(end_str, "end");

   while (1) {
      printf("Enter string: ");
      fgets(readbuf, sizeof(readbuf), stdin);
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0'; // Elimina el salto de línea
      end_process = strcmp(readbuf, end_str);

      if (end_process != 0) {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         read_bytes = read(fd, readbuf, sizeof(readbuf));
         readbuf[read_bytes] = '\0';
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      } else {
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);
         break;
      }
   }

   return 0;
}

