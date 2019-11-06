#include <stdio.h>
#include <string.h>
#include <math.h>

int gcd (int a,int b);
char * lettersToBinary(char recv);
int *  blocker (char * toBlock);
//int gcd (int a,int b);

//RSA formula values
double e = 7; //public key
double p = 3;  //prime #1
double q = 5; //prime #2
int int_blocks[10]; //integer blocks
int int_blk_size = 0; //how many integer blocks are use

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
		int stopper = counter +strlen(retCharPtr);
		for(j = counter; j < stopper; j++)
		{
			encodedMessage[j] = *retCharPtr;
			retCharPtr++;
		}

		counter = j;
		charPtr++;

	}

	//all the encrypted message
	for(int k = 0; k < strlen(encodedMessage); k++)
	{
		//each number representation
		//printf("%c\n", encodedMessage[k]);
	}

	char buffer[10];
	//int value = 234452;
	int value = 10;
	//converts integer to string
	snprintf(buffer, 10, "%d", value);
	
	int * enc_ptr;	
	enc_ptr = blocker(encodedMessage);


       // for( int l = 0; l < int_blk_size ;  )
        //{
          //a =  (int) pow(int_blocks[i],3) % (int) 2537;
          //printf("%d\n" , i);
	  //i+=1;
      int l = 0;
      while(l < int_blk_size)
      {
          printf("Encrypted Values: %d\n" , enc_ptr[l] );
	  l++;
      }

          //enc = (double) pow((double)int_blocks[i],13.0) % 2537.0;
          //printf("%i\n",enc);

        //}
        

	//for every character encode it
	return 0;
}

int gcd(int a,int b)
{
  while(a!=b)
  {
        if(a > b)
            a -= b;
        else
            b -= a;
  }

  return a;

}

int * blocker (char* toBlock)
{
	
	double n=p*q;
	double totient = (p-1)*(q-1);

	//printf("GCD = %d",a);
	//Per the RSA Cryptosystem GCD of e and totient has to be 1
        if(gcd(e,totient)!= 1)
        {
		printf("r and totient and gcd are not 1. Exiting...");
		exit(0);
	}     
        //printf("bruhhhhhhh  %i\n",bruh);

	
	int elements_cnt = strlen(toBlock);//sizeof(toBlock) / sizeof(toBlock[0]);
	//printf("toBlcokk\n");
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
	//int int_blocks[10];
	//int int_blk_size = 0;
	for(int ii = 0; ii < num_blocks; ii++)
	{
	   printf("block start \n");
	   char buffer[4] = {0};
	   //buffer[0] = '\0';
	   for(int jj =0; jj < block_size; jj++)
	   {	

		buffer[jj] = arr[ii][jj]; 
		//printf("block start \n");	
		printf("--");
		printf("%c\n", arr[ii][jj]);
		str_cnt++;
		if(str_cnt == elements_cnt)
		{
			full = 1;
			break;

		}

	   }
	   int int_val = atoi(buffer);
	   int_blocks[ii] = int_val;
	   printf("int_val is %i\n",int_val);
	   if (full == 1)
	   {
		int_blk_size=ii+1; //filled up to this point
		break;
	    }

	}

	
	//checking int array
	int enc = 0;
        unsigned int a = 0;
        static int  encrypted[10];
	for( int i = 0; i < int_blk_size ; i++)
	{
          //a =  (int) pow(int_blocks[i],3) % (int) 2537;
	  a = fmod(pow((double)int_blocks[i],e),(double) 2537); 
	  //printf("%i\n" , int_blocks[i]);
	  //printf("Encrypted%d\n",a);
          encrypted[i]= a;
          //printf("check enc %i\n", encrypted[i]);
	  //enc = (double) pow((double)int_blocks[i],13.0) % 2537.0;
	  //printf("%i\n",enc);

	}

	
	return encrypted;
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

