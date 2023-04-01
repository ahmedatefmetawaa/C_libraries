/***********************************************************************
 * @file : hello.c
 * @author : ahmed atef ahmed
 * @brief : implement string library functions (memset - memcpy - memcmp)
 * ********************************************************************
 */
/********************Include section****************************/
#include <stdio.h>
#include <stdlib.h>
/********************Datatype decleration sction*********************/
unsigned int ret;
char arr1[30] = "embedded system diploma";
char arr2[30];
char array_1[5] = {1, 2, 3, 4, 5};
char array_2[5] = {1, 2, 3, 4, 5};
/********************Function decleration sction*********************/
void *my_memset(void *start_address, unsigned char value, unsigned int length);
void *my_memcpy(void *dest_adress, void *src_address, unsigned int length);
int my_memcmp(void *str1, void *str2, unsigned int length);

int main()
{
    /*TEST FUNCTIONALITY OF MEMSET*/
    printf("array -> %s\n", arr2);
    my_memcpy(arr2, arr1, 23);
    printf("array -> %s\n", arr2);
    /*TEST FUNCTIONALITY OF MEMCPY*/
    printf("array -> %s\n", arr2);
    my_memcpy(arr2, arr1, 23);
    printf("array -> %s\n", arr2);
    /*TEST FUNCTIONALITY OF MEMCPY*/
    ret = my_memcmp(array_1, array_2, 5);
    printf("return value = %d\n", ret);
    return 0;
}
/**
 * @param : start_address -> is a pointer points to the start address of selected memory location.
 * value -> data to be write in memory location
 * length -> length of memory
 * @return : start address
 * @brief :  write data from start address of selected memory location till end of input length
 */
void *my_memset(void *start_address, unsigned char value, unsigned int length)
{
    unsigned char *tempptr = start_address;
    if (NULL == start_address)
    {
        printf("failed to memset data due to null pinter or not valid address!");
    }
    else
    {
        while (length--)
        {
            *tempptr = value;
            tempptr++;
        }
    }
    return start_address;
}
/**
 * @param : src_address -> is a pointer points to the source address of selected memory location.
 * dest_adress -> is a pointer points to the destination address of selected memory location.
 * length -> length of copied data.
 * @return : destination address.
 * @brief :  copy data from source address of selected memory in the destination address.
 */
void *my_memcpy(void *dest_adress, void *src_address, unsigned int length)
{
    unsigned char *tempdest_adress = dest_adress;
    unsigned char *tempsrc_address = src_address;
    if ((NULL == dest_adress) || (NULL == src_address))
    {
        printf("failed to memcpy data due to null pinter or not valid address!");
    }
    else
    {
        while (length)
        {
            *tempdest_adress++ = *tempsrc_address++;
            length--;
        }
    }
    return dest_adress;
}
/**
 * @param : str1 -> is a pointer points to the start address of selected memory location.
 * str2 -> is a pointer points to the other address of selected memory location.
 * length -> length of memory.
 * @return : retvalue <0 , 1 ,-1>.
 * @brief :  compare data from start address of selected memory location with other memory location.
 */

int my_memcmp(void *str1, void *str2, unsigned int length)
{
    unsigned int retValue = 0; /*indicates that 2 strings are  equal*/
    unsigned char *tempFaddress = str1;
    unsigned char *tempSaddress = str2;
    if ((NULL == str1) || (NULL == str2))
    {
        printf("failed to memcpy data due to null pinter or not valid address!");
    }
    else
    {
        if (tempFaddress == tempSaddress)
        {
            retValue = 0;
        }
        else
        {
            while (length)
            {
                if (*tempFaddress != *tempSaddress)
                {
                    retValue = (*tempFaddress > *tempSaddress) ? 1 : -1;
                    break;
                }
                else
                {
                    tempFaddress++;
                    tempSaddress++;
                    length--;
                }
            }
        }
    }
    return retValue;
}