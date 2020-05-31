//This program gets command line arguments from the user. 
//The first argument is the base the number is in
//The second is the number in that particular base
//The third is the base the user wants to convert to
//The program uses this info to convert the number from its original 
//input base to get a new number in the output
//base number

#include<iostream>
#include<sstream>

using namespace std;

long int digit_conversion (char);
int main (int argc, char * argv[])
{
    int inbase;           //input base
    long int num1;       //input number
    int outbase;        //output base
    long int this_digit;
    char table[]={'0','1','2','3','4','5','6','7','8','9','A','B','C',
                  'D','E','F','G','H','I','J','K','L','M','N','O',
                  'P','Q','R','S','T','U','V','W','X','Z'};             //lookuptable

    //get the first argument which is the input base                            
    stringstream ss(argv[1]);
    ss>>inbase;

    //get the second argument which is the input number
    stringstream bb(argv[2]);
    ss>>num1;

    //get the third argument which is the output base
    stringstream aa(argv[3]);
    aa>>outbase;


    long int digits = strlen(argv[2]);       //determines length of input number
    long int total = 0;

    //Checks to see if output base is in range
    //Loop iterates through and find the integer equavelent of each character
    if(inbase>=2 && inbase <= 36)
    {
        for(int i=0; i< digits; i++)
        {
            this_digit = digit_conversion(argv[2][i]);
            total = total * inbase + this_digit;
        }
    }

    else
    {
        cout<<"Invalid: input base is out of range"<<endl;
    }
    

    long int places = 0;
    long int totalcp = total;

    //Checks to see if output base is in range
    //If it is  find out how many times the number 
    //needs divided by the base until it reaches 0
    if(outbase>=2 && outbase <= 36)
    {
        while(totalcp > 0)
        {
            totalcp /= outbase;
            places ++;
        }  
    }

    else
    {
        cout<<"Invalid: output base is out of range"<<endl;
    }

    long int output[places];
    char result[places];
    
    //iterates to find the output number and converts it from integer
    //to a character and saves it to another array 
    for(int j=0; j<places; j++)
    {
        output[places] = total % outbase;
        total /= outbase;
        result[j]=table[output[places]];
    }

    //print the result array in reverse order
    for(int j=places-1; j>=0; j--)
    {
        cout<<result[j];
    }

    cout<<endl;
    
    return 0;
}

//This function finds the equivalent integer for each character 
//of the input number
long int digit_conversion(char c)
{
    if('0'<= c && c <= '9')
    {
        c = c-'0';
    }
    else
    {
        c = c - 'A' + 10;
    }
    return c ;
}
