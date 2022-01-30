#include <stdio.h>
int playSticks(int n_sticks,int t_sticks)
{
    if(t_sticks%(n_sticks+1)!=1)
    {
        printf("Cannot be played!");
        return 0;
    }
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
    playSticks(4,22);
    return 0;
}
