//This program finds unsigned, signed magnitude, 1's compliment
//2's compliment of the binary value and converts it to a
//decimal value

#include<iostream>
#include<sstream>

using namespace std;

//Prototypes declared below
int digit_conversion (char);
void unsigned_result(int, int, int[]);
void signed_mag(int, int, int[]);
void ones_compliment(int, int, int[]);
void twos_compliment(int, int, int[]);
int main (int argc, char * argv[])
{
    //variables declared below;
    int inbase=2;
    int this_digit;
    
    //get command line argument
    stringstream ss(argv[1]);

    int digits = strlen(argv[1]);   //determines length of the string
    int binary[10] = {0};
    int one_c[10] = {0};
    int two_c[10] = {0};

    for(int i=0; i< digits; i++)
    {
        this_digit = digit_conversion(argv[1][i]);
        binary[i]= this_digit;
    }

    //Make a  copy of the string to get passed for
    //one's compliment
    for(int i=0; i< digits; i++)
    {
        this_digit = digit_conversion(argv[1][i]);
        one_c[i]= this_digit;
    }

    //Make a  copy of the string to get passed for
    //two's compliment
    for(int i=0; i< digits; i++)
    {
        this_digit = digit_conversion(argv[1][i]);
        two_c[i]= this_digit;
    }


    //function calls below
    unsigned_result(inbase,digits,binary);

    signed_mag(inbase,digits,binary);

    ones_compliment(inbase, digits, one_c);

    twos_compliment(inbase, digits, two_c);

    cout<<endl;

    return 0;
}

//This function converts char to integer
int digit_conversion(char c)
{
    if(c =='0')
    {
        c = 0;
    }
    else
    {
        c = 1;
    }
    return c ;
}

//This function finds the unsigned of the decimal value
void unsigned_result(int base,int x, int num[])
{
    
    int total=0;

    for(int i=0; i< x; i++)
    {
        total = total * base + num[i];
    }
     cout<<total<<" ";

    EXIT_SUCCESS;
    
}

//This function finds the signed magnitude of the decimal value
void signed_mag(int base, int x, int num[])
{
    if(num[0] == 0)
        cout<<"+";
    else
    {
        cout<<"-";
    }

    int total = 0;

    for(int i=1; i<x; i++)
    {
        total = total * base + num[i];   
    }
    cout<<total<<" ";

    EXIT_SUCCESS;
}

//This function find the 1's compliment of the decimal value
void ones_compliment(int base, int x, int num[])
{

    if(num[0]==0)
    {
        cout<<"+";
    }

    else
    {
        cout<<"-";
        for(int i=0; i<x; i++)
        {
            if(num[i]==0)
            {
                num[i]=1;
            }
        else
            {
                num[i]=0;
            }
        }
    }

    int total = 0;

    for(int j=1; j<x; j++)
    {
        total = total * base + num[j];   
    }
    cout<<total<<" ";
    
    EXIT_SUCCESS;
}

//This function finds the 2's compliment decimal value
void twos_compliment(int base, int x, int num[])
{
    int total = 0;
    if(num[0]==0)
    {
        cout<<"+";
        for(int j=1; j<x; j++)
        {
            total = total * base + num[j];   
        }
        cout<<total<<" ";
    }

    else
    {
        cout<<"-";
        for(int i=0; i<x; i++)
        {
            if(num[i]==0)
            {
                num[i]=1;
            }
            else
            {
                num[i]=0;
            }
        }

        for(int j=1; j<x; j++)
        {
            total = total * base + num[j];   
        }
            cout<<total+1<<" ";
    }

    EXIT_SUCCESS;
}