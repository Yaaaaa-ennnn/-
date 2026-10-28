#include <iostream>
#include <conio.h>
#define row 10
#define col 10
#define space 0
#define human 1
#define box 2
#define target 3
#define wall 9
int map[row][col]{
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    {9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
};
void PrintMap()
{
    system("cls"); // 清屏
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            switch (map[i][j])
            {
            case space:
                std::cout << "  ";
                break;
            case human:
                std::cout << "人";
                break;
            case box:
                std::cout << "箱";
                break;
            case target:
                std::cout << "标";
                break;
            case wall:
                std::cout << "墙";
                break;
            }
        }
        std::cout << '\n';
    }

    bool operation(int key)
    {
        int x = 0, y = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (map[i][j] == human)
                {
                    x = i;
                    y = j;
                }
            }
        }
        if (key == 'w')
        {
            char *up1 = &map[x - 1][y];
            if (*up1 == space)
            {
                *up1 = human;
                map[x][y] = space;
                return true;
            }
            else if (*up1 == box)
            {
                char *up2 = &map[x - 2][y];
                if (*up2 == space)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
                else if (*up2 == target)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
            }
        }

        if (key == 's')
        {
            char *up1 = &map[x + 1][y];
            if (*up1 == space)
            {
                *up1 = human;
                map[x][y] = space;
            }
            else if (*up1 == box)
            {
                char *up2 = &map[x + 2][y];
                if (*up2 == space)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
                else if (*up2 == target)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
            }
        }
        if (key == 'D')
        {
            char *up1 = &map[x][y + 1];
            if (*up1 == space)
            {
                *up1 = human;
                map[x][y] = space;
            }
            else if (*up1 == box)
            {
                char *up2 = &map[x][y + 2];
                if (*up2 == space)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
                else if (*up2 == target)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
            }
        }
        if (key == 'A')
        {
            char *up1 = &map[x][y - 1];
            if (*up1 == space)
            {
                *up1 = human;
                map[x][y] = space;
            }
            else if (*up1 == box)
            {
                char *up2 = &map[x][y - 2];
                if (*up2 == space)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
                else if (*up2 == target)
                {
                    *up2 = box;
                    *up1 = human;
                    map[x][y] = space;
                }
            }
        }
        return false;
    }

    int main()
    {
        while (True)
        {
            PrintMap();
            int key = _getch();
            if (operation(key))
            {
                PrintMap();
                cout << "you win!" break;
            };
        }
    }
