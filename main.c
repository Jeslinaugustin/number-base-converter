
//Base converter
//Author Jeslin Augustin

# include <stdio.h>
# include <string.h>

//function to convert the entered string into equivalent decimal number
int toDecimal(char [], int);

//function to convert a character to a string
int charToDigit(char);

//function to convert the decimal number into required output base
void toOutBase(int,int);

//function to convert an integer to equivalent character
char intToChar(int);

int main()
{
	char inputNumber[100];
	int inputBase;
	int outputBase;
	char outputNumber[150];

	printf("Enter the number: ");
	gets(inputNumber);

	printf("Enter the input base: ");
	scanf("%d", &inputBase);

	printf("Enter the ouput base: ");
	scanf("%d", &outputBase);

	int outnum = toDecimal(inputNumber,inputBase);
    toOutBase(outnum,outputBase);
    
	return 0;
}

//function to convert the entered string into equivalent decimal number
int toDecimal(char number[], int base)
{
    int decimalNumber= 0;
    
    for (int i=1;number[i-1] != '\0';i++)
    {
        int posValue = charToDigit(number[i-1]);
        
        // check the entered number is valid or not
        if(posValue<base)
        {
            decimalNumber += posValue * (base ^ (i-1));
        }
        else
        {
            printf("Check the entered number.");
        }
    }
    return decimalNumber;
}

//function to convert character to digit
int charToDigit(char a)
{
    int output;
     
    if (a>='0' && a<='9')
    {
        output = (int)(a-'0');
    }
    else
    {
        output = (int)(a-'A')+10;
    }
    
    return output;
}

//function to convert decimal number to equivalent number in the output base
void toOutBase(int number, int base)
{
    char temp[150];
    int index =0;
   
   //take each digit and convert it into a character and store it a character array
    while(number>0)
    {
        temp[index]= intToChar(number%base);
        number = number/base;
        index= index+1;
    }
    
    temp[index]='\0';
   
    int strlength = strlen(temp);
    
    //reverse the output character array to disply it properly
    for (int i=0;i<strlength/2 ;i++)
    {
        tempc = temp[i];
        temp[i] = temp[strlength-1-i];
        temp[strlength-1-i] = tempc;
        
    }
    
    printf("Converted number is %s", temp);
    
}

//function to convert integer to character
char intToChar(int a)
{
    char text ;
    if(a>=0 && a<=9)
    {
        text = (char)(a+48);
    }
    else
    {
        text = (char)(a - 10 + 65);
    }a
    return text;
}