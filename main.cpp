//vulnerable options that are not gets
//strcpy
//fget
//strcat
//scanf

//format strings
//printf
//sprintf

#include <iostream>
#include <stdlib.h>
void bufferOverflow(int bet){
    char spin[2];
    std::string result;
    std::string profit [3];
    std::string values[12]={"cherry","clover","7","coin","diamond","lemon","bar","heart","$","crown","bell","horseshoe"};
    printf("Please enter your lucky number to spin \n");
    std::cin>>spin;
    bool valid=0;
    std::cout<<" | ";
    for(int i=0;i<3;i++){
        result=values[std::rand()%12];
        profit[i]=result;
        printf("%s | ",result.c_str());
    }

    std::cout<<std::endl;
    for(int j=0;j< 3;j++){
        if(profit[j]==profit[j+1]){
            valid=1;
        }
        else{
            valid=0; //likely where I will do my exploitation
            break;
        }
    }

    if(valid==1){
        printf("Congrats, you have won %d",bet); //put in some sort of mechanism to prevent cheating, excessively
    }
    else{
        printf("Womp womp, you lose! Better luck next time");
    }
}

int main(){
    int bet;
    std::cout<<"Let's play some slots!"<<std::endl;
    std::cout<<"How much are you betting?"<<std::endl; //want to be able to overflow this so you can show with more money than inserted
    std::cin>>bet;

    bufferOverflow(bet);
    return 0;
    //some printfs or couts go here
    //printf("\nEnter the string to exploit the BOF.\n");
}
