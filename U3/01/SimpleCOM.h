/********************************************************************************
 * NAME	: SimpleCOM.h
 * DESC	: Header file for SimpleCOM.cpp
 * DATE	: 7/15/2002
 * PGMR	: Y. Bai
 ********************************************************************************/
#ifndef SIMPLECOM_H_
#define SIMPLECOM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_MENU				9
#define MAX_STRING				256
#define NOPARITY				0
#define ONESTOPBIT				0
//#define RTS_CONTROL_DISABLE     0x00
//#define RTS_CONTROL_ENABLE      0x01
//#define DTR_CONTROL_DISABLE     0x00
//#define DTR_CONTROL_ENABLE      0x01

#define msg(info)	MessageBox(NULL, info, "", MB_OK)
//#define msg(info)	MessageBox(NULL, info, _T(""), MB_OK)

typedef struct
{
    unsigned long   ulCtrlerID;
    char            cEcho;
    char            cEORChar;
    long            lTimeout;
    long            lBaudRate;
    long            lDataBits;
	HANDLE          h_Port;
}SerialCreate, *pSerialCreate;
		
typedef struct
{
    char   *pcBuffer; 
	BYTE   bByte;
    int    iMaxChars;         
    int    piNumRcvd;          
	char   cTermChar;	
	HANDLE handlePort;
}CommPortClass;

typedef enum
{
    OK					= 0,		 /* no error */
    EC_TIMEOUT,
	EC_FOPEN,
	EC_INVAL_CONFIG,
	EC_TIMEOUT_SET,
	EC_RECV_TIMEOUT,
	EC_EXIT_CODE,
	EC_WAIT_SINGLEOBJ,
	EC_INVALIDPORT,
	EC_WRITE_FAIL,
	EC_READ_FAIL,
	EC_TEST_FAIL,
	EC_CREATE_THREAD,
	EC_PORT_INITDONE,	
	EC_UNKNOWNERROR
}ERR_CODE;

ERR_CODE PortInitialize(LPTSTR lpszPortName, pSerialCreate pCreate);
ERR_CODE PortWrite(HANDLE handPort, BYTE bByte, int NumByte);
ERR_CODE PortRead(CommPortClass *hCommPort);
void WINAPI ThreadFunc(void* hCommPorts);


char* getMenuItem(unsigned char mPort);
//char* getMenuItem(char* mPort);
ERR_CODE SetupPort(char* cPort, int nPort);
ERR_CODE TestPort(char* cPort, BOOL display);

#endif
