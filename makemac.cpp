#include <iostream>
#include "header.h"
using namespace std;

#define random_Addr                switch(temp_addr%16) \
{   \
    case 0 : strcat(hw_addr[i],"0"); break; \
    case 1 : strcat(hw_addr[i],"1"); break; \
    case 2 : strcat(hw_addr[i],"2"); break; \
    case 3 : strcat(hw_addr[i],"3"); break; \
    case 4 : strcat(hw_addr[i],"4"); break; \
    case 5 : strcat(hw_addr[i],"5"); break; \
    case 6 : strcat(hw_addr[i],"6"); break; \
    case 7 : strcat(hw_addr[i],"7"); break; \
    case 8 : strcat(hw_addr[i],"8"); break; \
    case 9 : strcat(hw_addr[i],"9"); break; \
    case 10 : strcat(hw_addr[i],"A"); break;    \
    case 11 : strcat(hw_addr[i],"B"); break;    \
    case 12 : strcat(hw_addr[i],"C"); break;    \
    case 13 : strcat(hw_addr[i],"D"); break;    \
    case 14 : strcat(hw_addr[i],"E"); break;    \
    case 15 : strcat(hw_addr[i],"F"); break;    \
}   \


int makemac(int count_ssid, char(*hw_addr)[hw_addr_len])
{
    int i=0,j=0;
    int temp_addr;
    srand(time(NULL));


   // associate random Mac_Addr
   for(i=0;i<count_ssid;i++)
   {
       hw_addr[i][0] = '\0';

       for(j=0;j<(hw_addr_len-1);j++)
       {
           temp_addr = rand()%16;
           if((j%3) == 0)
               random_Addr
           else if((j+2)%3 == 0)
               random_Addr
           else
               strcat(hw_addr[i],":");
       }
       hw_addr[i][17] = '\0';
   }

    return 0;
}
