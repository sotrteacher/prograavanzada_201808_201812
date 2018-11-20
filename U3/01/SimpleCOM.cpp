/***********************************************************************************
 * NAME	: SimpleCOM.cpp
 * DESC	: Simple serial port test program - single loop
 * DATE	: 7/15/2002
 * PGMR	: Y. Bai
 **********************************************************************************/
#include "stdafx.h"
#include <string.h>
#include <ctype.h>
#include "SimpleCOM.h"
#include "Menu.h"

//void main()
int main()
{
	int   index;
	bool  select = TRUE;
	//char* userInput;
	char userInput[32];
	char* comPort;
	ERR_CODE  ecRet = OK;
	unsigned char cPort;

	TestPassed = FALSE;
	while(select)
	{
		printf("\n");
		for (index = 0; index < MAX_MENU; index++)
		{
			PortCreateflg[index] = FALSE;
			printf(menuData[index]);
		}

		printf(menuTitle[0]);
		//scanf("%s", userInput);
		scanf_s("%s",userInput,sizeof(userInput));
		//userInput = strlwr(userInput);
		for (size_t i = 0; i < 32; i++)
		{
			userInput[i] = tolower(userInput[i]);
		}
		cPort = (unsigned char)userInput[0];
		comPort = getMenuItem(cPort);
		printf("select = %s\n", comPort);
		if (strcmp(comPort, "EXIT") == 0 || strcmp(comPort, "NULL") == 0)
			select = FALSE;
		else
		{
			ecRet = SetupPort(comPort, (int)cPort);
			if (ecRet)
			{
				select = FALSE;
				break;
			}
			ecRet = TestPort(comPort, 1);
			if (ecRet)
			{
				select = FALSE;
				break;
			}
			if (TestPassed)
				printf("\n**** %s TEST PASSED ***\n", comPort);
		}
	}

	//return;
	return 0;
}
/*
const char * portName = "";
sprintf_s( portName, sizeof( portName ), "\\\\.\\COM%i", portNum );

LPCSTR lpPortName = portName;

CreateFile(lpPortName...
*/
ERR_CODE SetupPort(char* cPort, int nPort)
{
	ERR_CODE ecRet = OK;
	pSerialCreate  pParam;

	pParam = new SerialCreate;

	pParam->lBaudRate = BAUD_RATE;
	pParam->lDataBits = NUM_BITS;
	pParam->lTimeout  = TIME_OUT;

	if (PortCreateflg[nPort])
		return ecRet;

	//ecRet = PortInitialize(cPort, pParam);
	ecRet = PortInitialize((LPTSTR)cPort, pParam);
	if (ecRet != OK)
		printf("ERROR in [SimpleCOM.cpp]PortInitialize()!\n");
	else
	{
		PortCreateflg[nPort] = true;
		hPort = pParam->h_Port;
	}

	delete pParam;

	return ecRet;
}

ERR_CODE TestPort(char* cPort, BOOL display)
{
	BYTE   sByte;
	int    numByte = NUM_BYTE, MaxByte = MAX_BYTE;
	ERR_CODE ecRet = OK;
	CommPortClass* comPort = new CommPortClass;

	comPort->handlePort = hPort;
	comPort->iMaxChars  = NUM_BYTE;

	for (sByte = START_BYTE; sByte <= MaxByte; sByte++)
	{
		ecRet = PortWrite(hPort, sByte, numByte);
		if (ecRet)
		{
			printf("PortWrite() is failed\n");
			TestPassed = FALSE;
			CloseHandle(hPort);
			return EC_WRITE_FAIL;
		}
		if (display)
			printf("%s Port Sending:  = %c\n", cPort, sByte);

		ecRet = PortRead(comPort);
		if (ecRet)
		{
			printf("PortRead() is failed\n");
			TestPassed = FALSE;
			CloseHandle(hPort);
			return EC_READ_FAIL;
		}
		if (display)
			printf("%s Port Received: = %c\n", cPort, comPort->bByte);

		if (sByte != comPort->bByte)
		{
			TestPassed = FALSE;
			return EC_TEST_FAIL;
		}
	}
	TestPassed = TRUE;

	delete comPort;

	return ecRet;
}

char* getMenuItem(unsigned char mPort)
{
	char*    ret;
	ret = new char[5];
	ret[0] = 'C'; ret[1] = 'O'; ret[2] = 'M'; ret[4] = '\0';
	switch (mPort)
	{
	case 'a': //ret = "COM1";
		ret[3] = '1';
		break;
	case 'b': //ret = "COM2";
		ret[3] = '2';
		break;
	case 'c': //ret = "COM3";
		ret[3] = '3';
		break;
	case 'd': //ret = "COM4";
		ret[3] = '4';
		break;
	case 'e': //ret = "COM5";
		ret[3] = '5';
		break;
	case 'f': //ret = "COM6";
		ret[3] = '6';
		break;
	case 'g': //ret = "COM7";
		ret[3] = '7';
		break;
	case 'h': //ret = "COM8";
		ret[3] = '8';
		break;
	case 'x': //ret = "EXIT";
		ret[0] = 'E'; ret[1] = 'X'; 
		ret[2] = 'I'; ret[3] = 'T'; ret[4] = '\0';
		break;
	default: printf("Invalid Selection\n");
		//ret = "NULL";
		ret[0] = 'N'; ret[1] = 'U';
		ret[2] = 'L'; ret[3] = 'L'; ret[4] = '\0';
	}
	return ret;
}
