#include "Map.h"
/* chieu rong 83
   chieu dai 17
*/
void drawCrossRoad(int x, int y, CConsole* handle)
{
    handle->TextColor(Color_Red);
    handle->GotoXY(x, y);
    cout << "  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$ " << endl;
    handle->GotoXY(x, y + 1);
    cout << " /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$ /$$__  $$|_  $$_/| $$$ | $$ /$$__  $$" << endl;
    handle->GotoXY(x, y + 2);
    cout << "| $$  \\__/| $$  \\ $$| $$  \\ $$| $$  \\__/| $$  \\__/  | $$  | $$$$| $$| $$  \\__/" << endl;
    handle->GotoXY(x, y + 3);
    cout << "| $$      | $$$$$$$/| $$  | $$|  $$$$$$ |  $$$$$$   | $$  | $$ $$ $$| $$ /$$$$" << endl;
    handle->GotoXY(x, y + 4);
    cout << "| $$      | $$__  $$| $$  | $$ \\____  $$ \\____  $$  | $$  | $$  $$$$| $$|_  $$" << endl;
    handle->GotoXY(x, y + 5);
    cout << "| $$    $$| $$  \\ $$| $$  | $$ /$$  \\ $$ /$$  \\ $$  | $$  | $$\\  $$$| $$  \\ $$" << endl;
    handle->GotoXY(x, y + 6);
    cout << "|  $$$$$$/| $$  | $$|  $$$$$$/|  $$$$$$/|  $$$$$$/ /$$$$$$| $$ \\  $$|  $$$$$$/" << endl;
    handle->GotoXY(x, y + 7);
    cout << " \\______/ |__/  |__/ \\______/  \\______/  \\______/ |______/|__/  \\__/ \\______/" << endl;

    handle->TextColor(Color_Red);
    handle->GotoXY(x + 55, y + 9);
    cout << " /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$ " << endl;
    handle->GotoXY(x + 55, y + 9 + 1);
    cout << "| $$__  $$ /$$__  $$ /$$__  $$| $$__  $$" << endl;
    handle->GotoXY(x + 55, y + 9 + 2);
    cout << "| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$  \\ $$" << endl;
    handle->GotoXY(x + 55, y + 9 + 3);
    cout << "| $$$$$$$/| $$  | $$| $$$$$$$$| $$  | $$" << endl;
    handle->GotoXY(x + 55, y + 9 + 4);
    cout << "| $$__  $$| $$  | $$| $$__  $$| $$  | $$" << endl;
    handle->GotoXY(x + 55, y + 9 + 5);
    cout << "| $$  \\ $$| $$  | $$| $$  | $$| $$  | $$" << endl;
    handle->GotoXY(x + 55, y + 9 + 6);
    cout << "| $$  | $$|  $$$$$$/| $$  | $$| $$$$$$$/" << endl;
    handle->GotoXY(x + 55, y + 9 + 7);
    cout << "|__/  |__/ \______/ |__/  |__/|_______/" << endl;
    handle->GotoXY(x + 55, y + 9 + 8);
}

/* chieu rong  max 26
   chieu dai 12 */
void drawWarrior(int x, int y, int color, CConsole* handle)
{
    handle->TextColor(color);
    handle->GotoXY(x + 4, y);
    cout << "_____" << endl;
    handle->GotoXY(x + 4, y + 1);
    cout << ")\\ __\\     _____" << endl;
    handle->GotoXY(x + 3, y + 2);
    cout << "/ /  .´    /  _  \\" << endl;
    handle->GotoXY(x + 2, y + 3);
    cout << "/ /  /     | () ]  |" << endl;
    handle->GotoXY(x + 1, y + 4);
    cout << "/ /,-/    .-|¯     .---." << endl;
    handle->GotoXY(x, y + 5);
    cout << "| /  \\_  /  /-----/ /   `\\" << endl;
    handle->GotoXY(x + 1, y + 6);
    cout << "'--´|`,) \\ (      \\ ` ,'/" << endl;
    handle->GotoXY(x + 5, y + 7);
    cout << "\\ \\\\.´`-\\  `   `---´" << endl;
    handle->GotoXY(x + 5 + 1, y + 8);
    cout << "\\ \\\\  / )'|`  /  |" << endl;
    handle->GotoXY(x + 5 + 2, y + 9);
    cout << "\\ \\\\´  |_ _ |  /" << endl;
    handle->GotoXY(x + 5 + 3, y + 10);
    cout << "\\/\\\\ [___ .' /" << endl;
    handle->GotoXY(x + 5 + 3 + 2, y + 11);
    cout << "\\/  .´ .'\\" << endl;

}

void eraseDraw(int x, int y, int height, int width, CConsole* handle)
{
    for (int i = 0; i < height; i++)
    {
        handle->GotoXY(x, y + i);
        for (int j = 0; j < width; j++)
        {
            handle->GotoXY(x + j, y + i);
            cout << ' ';
        }
    }
}

void drawShape(char** frame, int height, int width, int x, int y, CConsole* handle)
{

    char** a = frame;
    for (int i = 0; i < height; i++)
    {
        handle->GotoXY(x, y + i);
        for (int j = 0; j < width; j++)
        {
            handle->GotoXY(x + j, y + i);
            cout << a[i][j];
        }
    }
}

// ham nay co the lam thay doi con tro man hinh
void drawProgressBar(int xC, int yC, CConsole * handle)
{
    /*ham nay neu ranh chinh lai toa do nha neu nhin ko dep*/
    int length = 50;
    handle->GotoXY(xC, yC + 16);
    handle->SetBackGroundTextColor(0, 4);
    cout << "LOADING......." << endl;

    Point p(0, 0);
    CVEHICLE* car = new CCar(p, 1, 3, 8);

    for (int i = 0; i < length; i++)
    {
        handle->TextColor(i);
        drawSupperCar(xC + 10, yC, handle);

        car->setX(xC + i);
        car->setY(yC + 1);
        p = car->getPosition();
        handle->SetBackGroundTextColor(0, 11);
        drawShape(car->shapeHevicle(), car->getHeight(), car->getWidth(), p.getX(), p.getY(),handle);
        eraseDraw(p.getX(), p.getY(), car->getHeight(), 1,handle);
        drawShape(car->shapeHevicle(), car->getHeight(), car->getWidth(), p.getX() + 1, p.getY(),handle);

        if (i % 2 == 0)
        {
            handle->GotoXY(xC + i, yC + 3);
            cout << char(240);
        }

        handle->GotoXY(xC + length - 3, yC);
        handle->SetBackGroundTextColor(0, 4);
        //printf_s("%3d", int((i + 1)/ length * 100));
        cout << i * 2 << "%";
        Sleep(1000 / length);

    }

    //system("cls");
}

void drawTitle(int x, int y, CConsole* handle)
{

    drawCrossRoad(x, y, handle);
    drawProgressBar(x, y + 20, handle);
}

void drawSupperCar(int x, int y,CConsole* handle)
{
    handle->GotoXY(x + 16, y);
    cout << "_____________________" << endl;
    handle->GotoXY(x + 15, y + 1);
    cout << "(<$$$$$$>#####<::::::>)" << endl;
    handle->GotoXY(x + 13, y + 2);
    cout << "_/~~~~~~~~~~~~~~~~~~~~~~~~~\\" << endl;
    handle->GotoXY(x + 10, y + 3);
    cout << "/~                             ~\\" << endl;
    handle->GotoXY(x + 8, y + 4);
    cout << ".~                                 ~" << endl;
    handle->GotoXY(x + 4, y + 5);
    cout << "()\\/_____                           _____\\/()" << endl;
    handle->GotoXY(x + 4, y + 6);
    cout << ".-''      ~~~~~~~~~~~~~~~~~~~~~~~~~~~     ``-." << endl;
    handle->GotoXY(x + 3, y + 7);
    cout << ".-~              __________________              ~-." << endl;
    handle->GotoXY(x, y + 8);
    cout << "`~~/~~~~~~~~~~~~TTTTTTTTTTTTTTTTTTTT~~~~~~~~~~~~\\~~'" << endl;
    handle->GotoXY(x, y + 9);
    cout << "| | | #### #### || | | | [] | | | || #### #### | | |" << endl;
    handle->GotoXY(x, y + 10);
    cout << ";__\\|___________|++++++++++++++++++|___________|/__;" << endl;
    handle->GotoXY(x + 1, y + 11);
    cout << "(~~====___________________________________====~~~)" << endl;
    handle->GotoXY(x + 2, y + 12);
    cout << "\\------_____________[CHIP 911]__________-------/" << endl;
    handle->GotoXY(x + 5, y + 13);
    cout << "|      ||         ~~~~~~~~       ||      |" << endl;
    handle->GotoXY(x + 6, y + 14);
    cout << "\\_____/                          \\_____/" << endl;
}

/*
chieu rong 50
chieu dai 8
*/
string* drawLose()
{
    /*
        cai nay sau khi thua se hien len trong battlefile
        sau do chi can xuat hien cai bang load game th canh vi tri x y
    */
    ifstream fin;
    fin.open("Impact.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file" << endl;
        return NULL;
    }
    else
    {
        string* line;
        line = new string[8];
        for (int i = 0; i < 8; i++)
        {
            getline(fin, line[i]);
        }
        return line;
        delete[] line;
        fin.close();
    }
}

/*
chieu rong 32
chieu dai 23
*/
string* drawSkull()
{
    ifstream fin;
    fin.open("skull.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file" << endl;
        return NULL;
    }
    else
    {
        string* line;
        line = new string[23];
        for (int i = 0; i < 23; i++)
        {
            getline(fin, line[i]);
        }
        return line;
        delete[] line;
        fin.close();
    }
}

/*
chieu rong 31
chieu dai 4
*/
string* drawWin()
{
    /*
    * cai nay cung tuong tu phan lose th
    */
    ifstream fin;
    fin.open("win.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file" << endl;
        return NULL;
    }
    else
    {
        string* line;
        line = new string[4];
        for (int i = 0; i < 4; i++)
        {
            getline(fin, line[i]);
        }
        return line;
        delete[] line;
        fin.close();
    }
}

/*
chieu rong 106
chieu dai 6
*/
string* drawEndGame()
{
    ifstream fin;
    fin.open("endgame.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file" << endl;
        return NULL;
    }
    else
    {
        string* line;
        line = new string[6];
        for (int i = 0; i < 6; i++)
        {
            getline(fin, line[i]);
        }
        return line;
        delete[] line;
        fin.close();
    }
}

/*
chieu rong 53
chieu dai 13
*/
string* drawGuidelines()
{
    ifstream fin;
    fin.open("instruction.txt");
    if (!fin.is_open())
    {
        cout << "Can't open file" << endl;
        return NULL;
    }
    else
    {
        string* line;
        line = new string[13];
        for (int i = 0; i < 13; i++)
        {
            getline(fin, line[i]);
        }
        return line;
        delete[] line;
        fin.close();
    }
}