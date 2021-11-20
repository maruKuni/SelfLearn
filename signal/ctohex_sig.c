#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <strings.h>
#define ERR -1
#define CTRLA '\01'
void usage();
struct termio tbufsave;
short char_to_hexstr(char c);
void sigend(void);
int main(int argc, char *argv[])
{
    struct termio tbufin;
    char in;
    char out;
    short hex;

    if (signal(SIGINT, (void *)sigend) == SIG_ERR)
    {
        perror("signal");
        exit(1);
    }
    if (ioctl(0, TCGETA, &tbufin) == ERR)
    {
        perror("ioctl");
        exit(1);
    }
    tbufsave = tbufin;

    tbufin.c_lflag &= ~ICANON;
    tbufin.c_cc[4] = 1;
    if (ioctl(0, TCSETAF, &tbufin) == ERR)
    {
        perror("ioctl");
        exit(1);
    }
    while ((in = getchar()) != CTRLA)
    {
        hex = char_to_hexstr(in);
        out = (char)((hex & 0xff00) >> 8);
        putchar(out);
        out = (char)(hex & 0x00ff);
        putchar(out);
    }
    if (ioctl(0, TCSETAF, &tbufsave) == ERR)
    {
        perror("ioctl");
        exit(1);
    }
    exit(0);
}

short char_to_hexstr(char c)
{
    int hex;
    short upper;
    short lower;
    upper = ((c & 0xf0) >> 4) + '0';
    lower = c & 0x0f;
    if (lower < 10)
        lower += '0';
    else
        lower += ('a' - 10);
    hex = (upper << 8) | lower;
    return (hex);
}
void sigend(void){
    if(ioctl(0, TCSETAF, &tbufsave)  == ERR){
        perror("ioctl");
        exit(1);
    }
    printf("\n");
    exit(2);
}