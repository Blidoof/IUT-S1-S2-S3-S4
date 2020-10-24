#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>

int main()
{
    int pipedes[2];
    char cenvoi;
    char crecu;


    pipe(pipedes);
    int fils = fork();

    switch (fils)
    {
    case -1:
        exit(EXIT_FAILURE);
    case 0:

        while (read(pipedes[0], &crecu, sizeof(char)) != 0) {

            //toupper renvoie la variable en majuscule
            crecu = toupper(crecu);

            if (crecu != EOF)
            {
                printf("%c\n", crecu);
            }

        }

        close(pipedes[0]);

        exit(EXIT_SUCCESS);

        break;

    default:

        while (cenvoi != EOF)
        {
            cenvoi = getchar();
            write(pipedes[1], &cenvoi, sizeof(char));
        }

        if (close(pipedes[1]) == 0)
        {
            printf("fin de transfert\n");
        }

        break;
    }


    return 0;
}
