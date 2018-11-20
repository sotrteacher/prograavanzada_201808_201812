/************************************************************************************
 * NAME	: ComPortTest.cpp
 * DESC	: Support C++ file for SimpleCOM.cpp
 * DATE	: 7/15/2002
 * PGMR	: Y. Bai
 ***********************************************************************************/
//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "SimpleCOM.h"

ERR_CODE PortInitialize(LPTSTR lpszPortName, pSerialCreate pCreate)
{
	HANDLE		   hPort;
	DWORD		   dwError;
	DCB			   PortDCB;  
	ERR_CODE       ecStatus = OK;
	COMMTIMEOUTS   CommTimeouts;
	unsigned char  dBit;

	// Open the serial port.
	hPort = CreateFile(lpszPortName,  // Pointer to the name of the port
					   GENERIC_READ | GENERIC_WRITE, 
										// Access (read/write) mode
					   0,             // Share mode
					   NULL,          // Pointer to the security attribute
					   OPEN_EXISTING, // How to open the serial port
					   0,             // Port attributes
					   NULL);         // Handle to port with attribute to copy										
	
	// If it fails to open the port, return error.
	if ( hPort == INVALID_HANDLE_VALUE ) 
	{
        // Could not open the port.
		dwError = GetLastError();
		msg("Unable to open the port");
		//msg(_T("Unable to open the port"));
		CloseHandle(hPort);
		return EC_FOPEN;
	}
	  
	PortDCB.DCBlength = sizeof(DCB);     

	// Get the default port setting information.
	GetCommState(hPort, &PortDCB);
	  
	// Change the DCB structure settings.
	PortDCB.BaudRate = pCreate->lBaudRate;		// Current baud 
	PortDCB.fBinary  = TRUE;					// Binary mode; no EOF check 
	PortDCB.fParity  = TRUE;					// Enable parity checking. 
	PortDCB.fOutxCtsFlow = FALSE;				// No CTS output flow control 
	PortDCB.fOutxDsrFlow = FALSE;				// No DSR output flow control 
	PortDCB.fDtrControl = DTR_CONTROL_ENABLE;	// DTR_CONTROL
												// DTR flow control type 
	PortDCB.fDsrSensitivity = FALSE;			// DSR sensitivity 
	PortDCB.fTXContinueOnXoff = TRUE;			// XOFF continues Tx 
	PortDCB.fOutX = FALSE;						// No XON/XOFF out flow control 
	PortDCB.fInX  = FALSE;						// No XON/XOFF in flow control 
	PortDCB.fErrorChar = FALSE;					// Disable error replacement. 
	PortDCB.fNull = FALSE;						// Disable null stripping. 
	PortDCB.fRtsControl = RTS_CONTROL_ENABLE;	// RTS_CONTROL
												// RTS flow control 
	PortDCB.fAbortOnError = FALSE;				// Do not abort reads/writes on error.
	dBit = (unsigned char)pCreate->lDataBits;	
	PortDCB.ByteSize = dBit;				    // Number of bits/bytes, 4-8 
	PortDCB.Parity = NOPARITY;					// 0-4=no,odd,even,mark,space 
	PortDCB.StopBits = ONESTOPBIT;				// 0,1,2 = 1, 1.5, 2 

	// Configure the port according to the specifications of the DCB structure.
	if (!SetCommState (hPort, &PortDCB))
	{
		// Could not create the read thread.
		dwError = GetLastError();
		msg("Unable to configure the serial port");
		//msg(_T("Unable to configure the serial port"));
		return EC_INVAL_CONFIG;
	}

	// Retrieve the time-out parameters for all read and write operations on the port. 
	GetCommTimeouts(hPort, &CommTimeouts);

	// Change the COMMTIMEOUTS structure settings.
	CommTimeouts.ReadIntervalTimeout = MAXDWORD;  
	CommTimeouts.ReadTotalTimeoutMultiplier = 0;  
	CommTimeouts.ReadTotalTimeoutConstant = 0;    
	CommTimeouts.WriteTotalTimeoutMultiplier = 10;  
	CommTimeouts.WriteTotalTimeoutConstant = 1000;    

	// Set the time-out parameters for all read and write operations on the port. 
	if (!SetCommTimeouts (hPort, &CommTimeouts))
	{
		// Could not create the read thread.
		dwError = GetLastError();
		msg("Unable to set the time-out parameters");
		//msg(_T("Unable to set the time-out parameters"));
		return EC_TIMEOUT_SET;
	}

	EscapeCommFunction(hPort, SETDTR);
	EscapeCommFunction(hPort, SETRTS);
	pCreate->h_Port = hPort;

	return ecStatus;
}

ERR_CODE PortWrite(HANDLE handPort, BYTE bByte, int NumByte)
{
	  DWORD dwError;
      DWORD dwNumBytesWritten;
	  ERR_CODE ecStatus = OK;

	  if (!WriteFile (handPort,				// Port handle
					  &bByte,				// Pointer to the data to write 
					  NumByte,				// Number of bytes to write
					  &dwNumBytesWritten,	// Pointer to the number of bytes written
					  NULL))				// Must be NULL for Windows CE
	  {
		// WriteFile failed. Report error.
		dwError = GetLastError ();
		msg("ERROR in PortWrite ..");
		//msg(_T("ERROR in PortWrite .."));
		return EC_WRITE_FAIL;
	  }

	  return ecStatus;
}

ERR_CODE PortRead(CommPortClass *hCommPort)
{  
	  HANDLE hThread;			// handler for port read thread
	  DWORD  IDThread;
	  DWORD  Ret, ExitCode;
	  DWORD	 dTimeout = 5000;	// define time out value: 5 sec.
	  ERR_CODE ecStatus = OK;

	  if (!(hThread = CreateThread(NULL,			// no security attributes
				    0,					            // use default stack size
				    (LPTHREAD_START_ROUTINE) ThreadFunc,
				    (LPVOID)hCommPort,              // parameter to thread funciton
				    CREATE_SUSPENDED,	            // creation flag - suspended
				    &IDThread) ) )					// returns thread ID
      {
			msg("Create Read Thread failed");
		  //msg(_T("Create Read Thread failed"));
	 		return EC_CREATE_THREAD;
	  }

	  ResumeThread(hThread);		// start thread now
	  
	  Ret = WaitForSingleObject(hThread, dTimeout);
	  if (Ret == WAIT_OBJECT_0)
	  {
		  // data received & process it...
		  // Need to do nothing because the data has been stored in the hCommPort in Thread Func.
		  // close thread handle
		  CloseHandle(hThread);
	  }
	  else if (Ret == WAIT_TIMEOUT)
	  {
		  // time out happened, warning & kill thread
		  Ret = GetExitCodeThread(hThread, &ExitCode);
		  msg("Time out happened in PortRead() ");
		  //msg(_T("Time out happened in PortRead() "));
		  if (ExitCode == STILL_ACTIVE)
		  {
			  TerminateThread(hThread, ExitCode);
			  CloseHandle(hThread);
			  return EC_RECV_TIMEOUT;
		  }
		  else
		  {
			  CloseHandle(hThread);
			  msg("ERROR in GetExitCodeThread: != STILL_ACTIVE ");
			  //msg(_T("ERROR in GetExitCodeThread: != STILL_ACTIVE "));
			  ecStatus = EC_EXIT_CODE;
		  }
	  }
	  else
	  {
		  msg("ERROR in WaitFor SingleObject ");
		  //msg(_T("ERROR in WaitFor SingleObject "));
		  ecStatus = EC_WAIT_SINGLEOBJ;
	  }
	  
	  return ecStatus;
}

void WINAPI ThreadFunc(void* hCommPorts)
{
	  BYTE   Byte;
	  DWORD  dwError;
	  BOOL   bResult;
	  int	 nTotRead = 0;
 	  DWORD  dwCommModemStatus, dwBytesTransferred;
	  CommPortClass*  CommPorts;
	  ERR_CODE ecStatus = OK;
	
	  CommPorts = (CommPortClass* )hCommPorts;

	  // Specify a set of events to be monitored for the port.
 	  SetCommMask(CommPorts->handlePort, EV_RXCHAR | EV_CTS | EV_DSR | EV_RLSD | EV_RING);
		
	  // Wait for an event to occur for the port.
 	  WaitCommEvent(CommPorts->handlePort, &dwCommModemStatus, 0);		

 	  // Re-specify the set of events to be monitored for the port.
 	  SetCommMask(CommPorts->handlePort, EV_RXCHAR | EV_CTS | EV_DSR |EV_RLSD| EV_RING);
 
 	  if (dwCommModemStatus & EV_RXCHAR||dwCommModemStatus & EV_RLSD)	// received the char_event
	  {
 		  
 			// Read the data from the serial port.
 			bResult = ReadFile(CommPorts->handlePort, &Byte, 1, &dwBytesTransferred, 0);
 
 			if (!bResult)
			{
				printf("Unable to read the port\n");
				switch (dwError = GetLastError()) 
				{ 
					case ERROR_HANDLE_EOF: 
						printf("Serial Receive Failed\n");
						break;
				}
			}
			else
			{
            	// store the data read.
				CommPorts->bByte = Byte;
				nTotRead++;
			}
		}		

	return;
}



	
