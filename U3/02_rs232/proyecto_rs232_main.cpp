#include <stdio.h>
#include <stdlib.h>
#include "./lib/rs232.h"

int main()
{
  int cport_nr=6,    /* /dev/ttyS0 (COM1 on windows) */
  bdrate=9600;       /* 9600 baud */
  long i=0,j=0;
              /*data-bits,parity,stop-bits,nulo*/
  char mode[]={'8','N','1',0};
  
  if(RS232_OpenComport(cport_nr, bdrate, mode)){
    printf("Can not open comport\n");
    return 0;
  }
  printf("strlen(mode)=%d",strlen(mode));
  printf("\nRS232_OpenComport(%d, %d, {%4c,%4c,%4c,%4c})=0\n",
  cport_nr, bdrate, mode[0],mode[1],mode[2],mode[3]);
  
  /* En RS232_OpenComport() se concatena mode_str con " dtr=on rts=on"*/
  RS232_disableDTR(cport_nr);   /* Data Terminal Ready */
  RS232_disableRTS(cport_nr);   /* Request To Send */

  byte DatoSend;
  unsigned char DatoRecibe[2];
  //while(i!=2000){
  while(i!=10){
    DatoSend=0;
    RS232_SendByte(cport_nr,DatoSend);
    printf("Dato enviado:%d\n",DatoSend);
    
	DatoSend=84;
    RS232_SendByte(cport_nr,DatoSend);
    printf("Dato enviado:%d\n",DatoSend);
    
	DatoSend=94;
    RS232_SendByte(cport_nr,DatoSend);
    printf("Dato enviado:%d\n",DatoSend);
    
    for(j=0;j<9000000;j++);
    
    RS232_PollComport(cport_nr,DatoRecibe,2);
    printf("%6s%6s%6s\n","i","DR[0]","DR[1]");
    printf("%6d%6d%6d\n",i,DatoRecibe[0],DatoRecibe[1]);
    i++;
  }//end while()
  RS232_CloseComport(cport_nr);
  return 0;
}//end main()


