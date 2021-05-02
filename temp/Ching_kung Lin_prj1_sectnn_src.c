#include <stdio.h> 
#include <fcntl.h>  
/*#include <unishtd.h> */ 

int main(int argc, char* argv[])
{
    /*1: 
    open the same file twice and read to different fd only
    if file can't open, then terminate
    */
    int fd1, fd2;
    fd1 = open("Text2.txt", O_RDONLY);
    fd2 = open("Text2.txt", O_RDONLY);

    if (fd1 == -1 && fd2 == -1) { 
        exit(1); 
    }

    /*
    2. get size and create a new file to store output. 
    */
    //use the index of fd1 to find the data size, then
    //reset the index and let its pointer back to the first character
    int get_size = lseek(fd1, 0, SEEK_END);
    lseek(fd1, 0, SEEK_SET);

    int fd3;
    fd3 = open("ChingKung_Lin_prj1_sectnn_out.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
    
    /*
    3. setting variables
    */
    //file tracker
    int count = 0;              
    int start = get_size - 1;    
    
    //to store the character from the file                             
    char buffer1[32];
    char buffer2[32];

    //store difference
    int store_number[32];       
    char store_fd1[32];         
    char store_fd2[32];     
    int s_tracker = 0;

    write(1, "\n", 1);
    write(fd3, "\n", 1);

    /*
    4. compare fd1 & fd2
    fd1's tracker will set to 0 at first read and then increment by 1
    read from "fd1" and then put into "buffer1", only read 1 character
    fd1's tracker will set to 0 at first read and then decrement by 1
    read from "fd2" and then put into "buffer2", only read 1 character
    */
     while (count < get_size)
    {
        
        lseek(fd1, count++, SEEK_SET);  
        read(fd1, &buffer1, 1);         
        lseek(fd2, start--, SEEK_SET);  
        read(fd2, &buffer2, 1);         

        if (*buffer1 == *buffer2)      //if buffer1 and beffer2 has same character then 
        {
            write(1, "0", 1);          
            write(fd3, "0", 1);
        }
        else
        {                               
            write(1, "1", 1);           
            write(fd3, "1", 1);
       
            store_number[s_tracker] = count;    
            store_fd1[s_tracker] = *buffer1;    
            store_fd2[s_tracker] = *buffer2;    
            s_tracker++;
        }     
    }
     
     //write a newline 
     write(1, "\n", 1);
     write(fd3, "\n", 1);
     write(1, "\n", 1);
     write(fd3, "\n", 1);

     /*
     5. display difference to file and console. 
     */
     int storeN;
     int storeFd1;
     int storeFd2;
     for (int i = 0; i < s_tracker; i++)
     {
         
         if (store_number[i] < 10)
         {
             //if it's single digit
             storeN = store_number[i] + '0';
             write(fd3, &storeN, sizeof(storeN));
             write(fd3, " ", 1);
             write(1, &storeN, sizeof(storeN));
             write(1, " ", 1);
         }
         else if (store_number[i] >= 10 && store_number[i] < 100)
         {
             //if it's two digits
             int ones = store_number[i] % 10;
             int tens = (store_number[i] / 10) % 10; 
             int* ones_char = ones + '0';
             int* tens_char = tens + '0';
             write(fd3, &tens_char, sizeof(tens_char));
             write(fd3, &ones_char, sizeof(ones_char));
             write(fd3, " ", 1);
             write(1, &tens_char, sizeof(tens_char));
             write(1, &ones_char, sizeof(ones_char));
             write(1, " ", 1);
         }
         else {
             //if it's three digits
             int ones = store_number[i] % 10;
             int tens = ( store_number[i] / 10 ) % 10;
             int hundreds = store_number[i] / 100;
             int* ones_char = ones + '0';
             int* tens_char = tens + '0';
             int* hundreds_char = hundreds + '0';

             write(fd3, &hundreds_char, sizeof(hundreds_char));
             write(fd3, &tens_char, sizeof(tens_char));
             write(fd3, &ones_char, sizeof(ones_char));
             write(fd3, " ", 1);
             write(1, &hundreds_char, sizeof(hundreds_char));
             write(1, &tens_char, sizeof(tens_char));
             write(1, &ones_char, sizeof(ones_char));
             write(1, " ", 1);
         }

         storeFd1 = store_fd1[i];
         write(fd3, &storeFd1, 1);
         write(fd3, " ", 1);
         write(1, &storeFd1, 1);
         write(1, " ", 1);
       
         storeFd2 = store_fd2[i];
         write(fd3, &storeFd2, 1);
         write(fd3, " ", 1);
         write(1, &storeFd2, 1);
         write(1, " ", 1);
     
         write(fd3, "\n", 1);
         write(1, "\n", 1);

     }
          
    write(fd3, "\n", 1);
    write(1, "\n", 1);   
    
    //display the total to file and console
    write(fd3, "Total: ", 6);
    write(1, "Total: ", 6);
    
    
    if (s_tracker < 10)
    {
        //if total nunber is 1 digit
        int* num = s_tracker + '0';
        write(fd3, &num, sizeof(num));
        write(1, &num, sizeof(num));
        write(1, " ", 1);
    }
    else if (s_tracker >= 10 && s_tracker < 100 )
    {
        //if total nunber is over 1 digit
        int total_ones = s_tracker % 10;
        int total_tens = ( s_tracker / 10 ) % 10;
        int* total_ones_char = total_ones + '0';
        int* total_tens_char = total_tens + '0';
       
        write(fd3, &total_tens_char, sizeof(total_tens_char));
        write(fd3, &total_ones_char, sizeof(total_ones_char));
        write(1, &total_tens_char, sizeof(total_tens_char));
        write(1, &total_ones_char, sizeof(total_ones_char));
        write(1, " ", 1);
    }
    else {
        //if total nunber is 3 digit
        int total_ones = s_tracker % 10;
        int total_tens = (s_tracker / 10) % 10;
        int total_hundreds = s_tracker / 100;
        int* total_ones_char = total_ones + '0';
        int* total_tens_char = total_tens + '0';
        int* total_hundreds_char = total_hundreds + '0';

        write(fd3, &total_hundreds_char, sizeof(total_hundreds_char));
        write(fd3, &total_tens_char, sizeof(total_tens_char));
        write(fd3, &total_ones_char, sizeof(total_ones_char));
        write(1, &total_hundreds_char, sizeof(total_hundreds_char));
        write(1, &total_tens_char, sizeof(total_tens_char));
        write(1, &total_ones_char, sizeof(total_ones_char));
        write(1, " ", 1);
    }
   
    write(fd3, "charater positions differ.", 27);
    write(1, "charater positions differ.", 27);

    return 0;  
}
