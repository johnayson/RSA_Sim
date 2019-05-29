#include <stdio.h>
#include <string.h>

char * lettersToBinary(char recv);
void  blocker (char * toBlock);

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
		printf("hey");
		printf("%c\n", encodedMessage[k]);
	}

	char buffer[10];
	//int value = 234452;
	int value = 10;
	//converts integer to string
	snprintf(buffer, 10, "%d", value);
	
	blocker(encodedMessage);
	//printf("%s",buffer);
	//printf("%c", *charPtr);

	

	//for every character encode it
	return 0;
}

void  blocker (char* toBlock)
{
	int elements_cnt = strlen(toBlock);//sizeof(toBlock) / sizeof(toBlock[0]);
	printf("toBlcokk\n");
	int block_size = 4;
	int num_blocks = 10;
	char arr[num_blocks][block_size];

	for (int i = 0,j=0,k=0; i < elements_cnt; i++)
	{
		//j = 0;
		//k = 0;
		//printf("%c\n" , toBlock[i]);
		//printf("%c\n", arr[j][k]);
		arr[j][k]= toBlock[i];
		//printf("%c\n", arr[j][k]);
		//j++;
		k++;
		if(k == 4)
		{
		   j++;
		   k = 0;			
		}
	}
	
	//printf("%d\n", elements_cnt);
	//printf("%c\n" , arr[1][1]);
	//printf("\nheyy");
	//char * this_charPtr = &arr[0][1];
	//printf("%c", this_charPtr);
	//printf("%lu\n", strlen(arr));

	int str_cnt = 0;
	int full = 0;
	printf("start\n");
	for(int ii = 0; ii < num_blocks; ii++)
	{
	   for(int jj =0; jj < block_size; jj++)
	   {	
		printf("--");
		printf("%c\n", arr[ii][jj]);
		str_cnt++;
		if(str_cnt == elements_cnt)
		{
			full = 1;
			break;

		}

	   }
	   if (full == 1)
		break;

	}
	
	//return "a";
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

