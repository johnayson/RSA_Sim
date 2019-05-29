#include <stdio.h>
#include <string.h>

char * lettersToBinary(char recv);

//%c for char %d for ints
int main(void)
{
	char message[1000];
	char encodedMessage[100];
	int *intPtr;
	char *charPtr;
	printf("What is the message that you want to be encrypted?\n");
	scanf("%[a-zA-Z ]", message); //reads a-z and spaces
	printf("You entered: %s \n",message );

	charPtr = &message[0];
	int counter = 0;
	
	for(int i = 0; i < strlen(message); i++)
	{
		//printf("%d", i);
		//char numEncode[10];
		char *retCharPtr;
		int j;
		retCharPtr = lettersToBinary(*charPtr);
		//printf("%s\n",retCharPtr );
		//printf("%d\n", strlen(retCharPtr));
		//print("%c\n", numEncode);
		int stopper = counter +strlen(retCharPtr);
		for(j = counter; j < stopper; j++)
		{
			encodedMessage[j] = *retCharPtr;
			//when you print the first one its prints the hwole thing but you only inserted the first one
			//printf("%s\n", retCharPtr);
			retCharPtr++;
		}

		counter = j;
		//strcpy(encodedMessage[i], lettersToBinary(*charPtr));
		//printf("%c\n", numEncode );
		charPtr++;

	}

	//all the encrypted message
	for(int k = 0; k < strlen(encodedMessage); k++)
	{
		printf("%c\n", encodedMessage[k]);
	}

	char buffer[10];
	int value = 234452;
	//converts integer to string
	snprintf(buffer, 10, "%d", value);
	//printf("%s",buffer);
	//printf("%c", *charPtr);

	//for every character encode it
	return 0;
}

char * lettersToBinary(char recv)
{
	
	switch(recv) {
		case 'a':
		case 'A':
			//printf("%d\n", 0);
			return "00";
		case 'b':
		case 'B':
			return "01";
		case 'c':
		case 'C':
			return "02";
		case 'd':
		case 'D':
			return "03";
		case 'e':
		case 'E':
			return "04";
		case 'f':
		case 'F':
			return "05";
		case 'g':
		case 'G':
			return "06";
		case 'h':
		case 'H':
			return "07";
		case 'i':
		case 'I':
			return "08";
		case 'j':
		case 'J':
			return "09";
		case 'k':
		case 'K':
			return "10";
		case 'l':
		case 'L':
			return "11";
		case 'm':
		case 'M':
			return "12";
		case 'n':
		case 'N':
			return "13";
		case 'o':
		case 'O':
			return "14";
		case 'p':
		case 'P':
			return "15";
		case 'q':
		case 'Q':
			return "16";
		case 'r':
		case 'R':
			return "17";
		case 's':
		case 'S':
			return "18";
		case 't':
		case 'T':
			return "19";
		case 'u':
		case 'U':
			return "20";
		case 'v':
		case 'V':
			return "21";
		case 'w':
		case 'W':
			return "22";
		case 'x':
		case 'X':
			return "23";
		case 'y':
		case 'Y':
			return "24";
		case 'z':
		case 'Z':
			return "25";


		default :
         //printf("Invalid letter\n" );
         return "";

	}

}

