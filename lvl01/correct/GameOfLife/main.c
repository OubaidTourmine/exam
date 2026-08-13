#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

void init_g(int w, int h, int arr[h][w])
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            arr[i][j] = 0;
}

void copy_g(int w, int h, int arr[h][w], int next[h][w])
{
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            arr[i][j] = next[i][j];
}

void read_g(int w, int h, int arr[h][w])
{
    char c;
    int x = 0, y = 0, pen = 0;
    while (read(0, &c, 1) > 0)
    {
        if(c == 'w' && y > 0) y--;
        else if(c == 's' && y < h - 1) y++;
        else if(c == 'a' && x > 0) x--;
        else if(c == 'd' && x < w - 1) x++;
        else if(c == 'x') pen = !pen;
        if(pen) arr[y][x] = 1;
    }
}

int count_next(int w, int h, int arr[h][w], int i, int j)
{
    int n = 0;
    for(int di = -1; di <= 1; di++)
    {
        for(int dj = -1; dj <= 1; dj++)
        {
            if((di || dj) && di+i >= 0 && di+i < h && dj+j >= 0 &&dj+j <w)
                n += arr[di+i][dj+j];
        }
    }
    return n;
}

void count_nbhr(int w, int h, int arr[h][w], int next[h][w])
{
    int n = 0;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            n = count_next(w, h, arr, i ,j);
            next[i][j] = (((arr[i][j]) && (n == 2 || n == 3)) || ((!arr[i][j]) && (n == 3)));
        }
    }
}

void run_sim(int w, int h, int iter, int arr[h][w], int next[h][w])
{
    for(int t = 0; t < iter; t++)
    {
        count_nbhr(w, h, arr, next);
        copy_g(w, h, arr, next);
    }
}

void print_g(int w, int h, int arr[h][w])
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(arr[i][j]) putchar('O');
            else putchar(' ');
        }
        putchar('\n');
    }
}

int main (int ac, char **av)
{
    if (ac != 4)
         return 1;
    int w = atoi(av[1]);
    int h = atoi(av[2]);
    int iter = atoi(av[3]);

    int arr[h][w];
    int next[h][w];

    init_g(w, h, arr);
    read_g(w, h, arr);
    run_sim(w, h, iter, arr, next);
    print_g(w, h, arr);
}