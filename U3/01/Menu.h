/*********************************************************************************
 * NAME	: Menu.h
 * DESC	: Header file for the manu input and menu display
 * DATE	: 7/16/2002
 * PGMR	: Y. Bai
 ********************************************************************************/

#define NUM_BYTE	1
#define MAX_BYTE	90
#define START_BYTE	48
#define	BAUD_RATE	9600
#define	NUM_BITS	8
#define	TIME_OUT	3000

HANDLE	hPort;
bool    TestPassed;
bool    PortCreateflg[9];

//char* menuData[] =
//{   {"A   Test Port COM 1\n"},
//	{"B   Test Port COM 2\n"},
//	{"C   Test Port COM 3\n"},
//    {"D   Test Port COM 4\n"},
//	{"E   Test Port COM 5\n"},
//	{"F   Test Port COM 6\n"},
//	{"G   Test Port COM 7\n"},
//    {"H   Test Port COM 8\n"},
//    {"X   EXIT\n\n"}
//};
char menuData[][32] ={ 
{ "A   Test Port COM 1\n" },
{ "B   Test Port COM 2\n" },
{ "C   Test Port COM 3\n" },
{ "D   Test Port COM 4\n" },
{ "E   Test Port COM 5\n" },
{ "F   Test Port COM 6\n" },
{ "G   Test Port COM 7\n" },
{ "H   Test Port COM 8\n" },
{ "X   EXIT\n\n" }
};

//char* menuTitle[] =
//{   {"SERIAL PORT TESTING  - Enter Selection > \n\n"}
//};
char menuTitle[][64] ={ 
	{ "SERIAL PORT TESTING  - Enter Selection > \n\n" }
};

