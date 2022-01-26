#include <stdio.h>
int playSticks(int n_sticks,int t_sticks)
{
    for (int i = 0; i < t_sticks-(n_sticks+1) ; i+=(n_sticks+1))
    {
        printf("Sticks left : %d\n",t_sticks-i);
        printf("pick from 1 to %d :",n_sticks);
        int uin=0;
        scanf("%d",&uin);
        int pin=(n_sticks+1)-uin;
        printf("I pick %d\n",pin);

    }
    printf("You lose lol 1 stick left\n");
}
int main()
{
    playSticks(14,101);
    return 0;
}
