#include <stdio.h>

char get_choice(void);
char get_first(void);
void count(void);

int main(void){
    int choice; 

    while((choice = get_choice())!='q'){
        switch(choice){
            case 'a':  
                printf("Buy low, sell high \n");
                break;
            case 'b': 
                putchar('\a');
                break;
            case 'c': 
                count();
                break;
            default:   
                printf("Program error! \n");
                break;
        }
    }
}

char get_choice(void){
    int ch; 

    printf("Enter the letter of your choice: \n");
    printf("a. advice           b.bell \n");
    printf("c. count            d.quit \n");
    ch = get_first();
    while((ch < 'a' || ch > 'c' ) && ch != 'q'){
        printf("Please respond with a,b,c, or q. \n");
        ch = get_first();
    }
    return ch;
}

char get_first(void){
    int ch;
    ch = getchar(); 

    if(ch == '\n'){
        ch = getchar();
    }

    while(getchar() != '\n'){
        continue;
    }
    return ch;
}

void count(){
    int n,i; 
    printf("Count how far? Enter an integer: \n");
    while(scanf("%d", &n)!= 1){
        while(getchar()!= '\n');
        printf("That is not an integer. Enter an integer such as 1,2, or 3 \n");
    }
    if(n<=0){
        printf("I cant count backwards! Enter a positive integer. Try again from the menu.\n");
    }else{
        for(i = 1; i<=n ; i++){
            printf("%d\n",i);
        }
    }
}