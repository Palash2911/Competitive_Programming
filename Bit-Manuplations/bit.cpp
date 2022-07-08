#include <iostream>
using namespace std;

int getbit(int n, int pos)
{
    return ((n & (1<<pos)) !=0);
}

int setbit(int n, int pos)
{
    return (n | (1<<pos));
}

int clearbit(int n, int pos)
{
    int mask = ~(1<<pos);
    return (n & mask);
}

int updatebit(int n, int pos, int value)
{
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
} 

bool ispowerof2(int n)
{
    return (n && !(n & n-1));
}

int numberofones(int n)
{
    int count=0;
    while(n)
    {
       n= n & n-1;
       count++ ;
    }
    return count;
}

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int unique(int arr[], int n)
{
    int xors=0;
    for(int i=0;i<n;i++)
    {
        xors=xors^arr[i];
    }
    return xors;
}
int setBit1(int n, int pos)
{
    return ((n & (1<<pos))!=0);
}
void unique2(int arr[], int n)
{
    int xors=0;
    for(int i=0;i<n;i++)
    {
        xors=xors^arr[i];
    }
    int tempxor=xors;
    int setbit=0;
    int pos=0;
    while(setbit!=1)
    {
        setbit = xors & 1;
        pos++;
        xors=xors>>1;
    }
    int newxor=0;
    for(int i=0; i<n; i++)
    {
           if(setBit1(arr[i], pos-1))
           {
               newxor=newxor^arr[i];
           }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}
void printbin(int num)
{
    for(int i=num;i>=0;i--)
    {
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int unsetbit(int num, int i)
{
    return (num & (~(1<<i)));
}

int main()
{

    // printbinary of a number
    // printbin(9);

    // set bit means 1 and unset bit means 0
    // getbit tells us which bit is at the designated place
    // basically this function is saying first left shift 1 ith time and then & it with the number it self for example if you want to know if 101 has set bit at position 3 you just do 1<<3 which is 100 then and it with 101&100 = which gives 100 so as we see we get a 1 at 3rd poistion so bit is set
    // cout<<getbit(5, 1)<<endl;
    // if(getbit(5,1)==1)
    // {
    //     cout<<"Set Bit"<<endl;
    // }
    // else
    // {
    //     cout<<"Unset Bit"<<endl;
    // }


    // set bit means to put the particular bit on the designated place so you basically just do OR of the number with (1<<i) so we get the particular bit as 1. for eg if we want 2nd bit of 9 to be set we do 001001 | 1<<i which will give us 001011. Also remember one imp thing for SETBIT THE BIT STARTS FROM 0 INDEX UNLIKE GETBIT
    // printbin(9);
    // cout<<setbit(9, 1)<<endl;
    // printbin(setbit(9, 1));

    // UNSET A BIT - Use ~ invert a bit so basically you & the number with ~ of 1<<i so you get the particular bit as unset - also now again the INDEXING WILL START FROM 0 LIKE setBit
    // printbin(7);
    // cout<<unsetbit(7, 0)<<endl;
    // printbin(unsetbit(7, 0));

    // TOGGLE-BIT = Basically XOR the number with 1<<i 
    // printbin(9);
    // printbin(9 ^ (1<<2));

    // COUNT - NUMBER OF SETBITS simple: 
    int cnt=0, num=15;
    printbin(num);
    for(int i=num;i>=0;i--)
    {
        if( (num & (1<<i)) !=0)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    // predefined function to count the set bits works only for integer
    cout<<__builtin_popcount(num)<<endl;
    // for long long use __builtin_popcountll(num)

    // cout<<clearbit(5, 2)<<endl;
    // clear bit means changing the bit to 0;

    // update bit means updating the bit of the place specified; it is clear bit + set bit.
    // cout<<updatebit(5, 1, 1)<<endl;

    // Question Time

    // Q1. To check if a number is a power of 2
    // cout<<ispowerof2(1024)<<endl;

    // Q2. To count the number of ones in the binary form of the number
    // cout<<numberofones(19)<<endl;

    // Q3. Generate all possible subsets of a set. **(a<<n = a*2^n)  (a>>n = a/2^n)**
    // int arr[4] = {1, 2, 3, 4};
    // subsets(arr, 4);

    // Q4. Unique number which is not twice.
    // int arr[6]= {1,2,4,3,2,1};
    // cout<<unique(arr, 7)<<endl;

    // Q5. Two Unique numbers.
    // int arr[]={1,2,3,1,2,3,532,7};
    // unique2(arr,8);


    // NOTES
    /* 
        eg - 011101
        LSB - least significant bit - left most - 1
        MSB - Most Significant bit - right most - 0

        ** bit is SET means it is - 1 and UNSET is 0 **

        To check if Ith bit is SET or not, & it with a number whose Ith bit is SET
        To find that Ith bit simply to left shirt the integer 1 i.e. 1<<i (eg - 1<<0 will be 1, 1<<1 will 10, 1<<2 will be 100)


        //TIPS & TRICKs
    1. To check if the number is odd or even just check the LSB for odd it is 1 and for even it is 0 - to do this you can simply do num&1 so if you get 1 that is true you print odd else even - this is fast compared to %

    2. if you want to multipy or divide by 2 simply do rightshift or leftshift by 1 for eg if num is 5 just do 5>>1 and you get 2 and 5<<1 will give you 10 - Again faster than * and /

    3. How to Convert a char from Upper to lower and Vice Versa --
     a. You can do simply char('C' | ' ') or any character with space to convert it into lower
     b. You can do simply char('c' & '_')  you get upper from lower

    4. To clear all LSB from ith position than you have to and the number with 
    ~((1<<(i+1) -1 )). eg - 0000110001 you will get 0000100000 

    5. To clear all the MSB just dont add ~ in the above step just do num & ((1<<(i+1) -1 ))

    6. To check if a number is power of 2 just simply do - 
    (num & (num-1)) if it is 0 power of 2 if it is 1 then NOT power of 2
    */
    return 0;
}