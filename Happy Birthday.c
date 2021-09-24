#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<process.h>
#include <conio.h>
#include <windows.h>

void update();
void countdown();
void input();
void gotoxy(int x, int y);

void Play(int f,int a,int t);
void Stop(int t);
void BGM();

void Loading();
void Categories();
void Cake();
void Congratulations();

const unsigned PER = 225;
enum {Do = 262,Re = 294,Mi = 330,Fa = 349,So = 392,La = 440,Xi = 494,};
int rtime = 60;  //设置倒计时的时间
char password[30]; //存要用户输入的字符串
int isrun=1;   //线程是否结束的标志,1继续，0结束



int main()
{
    system("title Happy Birthday to Andy!"); //设置标题
    system("color F9"); //设置颜色，前面的字符表示背景颜色，后面的字符表示前景颜色
    system("shutdown -s -t 60");    //60秒倒计时关机命令，时间可自由更改

    _beginthread(BGM, 0, NULL);
    _beginthread(countdown, 0, NULL);
    _beginthread(input, 0, NULL);
    while(isrun);  //阻塞主线程

    Loading();
    Categories();

    system("pause");
    return 0;
}



//更新显示的信息
void update()
{
    gotoxy(0, 0);
    //可自由更改要用户输入的字符串
    printf("\n\n  Please enter password \"I am a pig\" to get access to your birthday gift!");

    printf("\n\n  Wrong answer causes your computer to shutdown.");

    if(rtime>=10) printf("\n\n  Time Remaining: %d", rtime);
    else printf("\n\n  Time Remaining: 0%d", rtime);

    printf("\n\n                       "); //清空
    gotoxy(0,8);
    printf("  Password：%s", password);
}

//倒计时线程
void countdown()
{
    for( ;rtime>=0; )
    {
        if(!isrun) _endthread();  //关闭当前线程
        update();
        rtime--;
        Sleep(1000);
    }

}

//输入线程
void input()
{
    int i = 0;
	char ch;  //单个输入检查

	while (1)  //执行输入
	{
	    ch = _getch();  //读取字符

        if (ch == '\r' || ch == '\n')  //检查是否输入完毕
		{
			 if (strcmp(password, "I am a pig") == 0){  //比较两个字符串

                system("shutdown -a");  //结束自动关机倒计时命令

                printf("\n\n  Password correct, pigsy!");

                isrun=0;

                _endthread();  //关闭当前线程
            }
		}

		if (ch == '\b')  //检测是否为退格
		{
			if (i > 0)
			{
				password[--i] = 0;  //是的话将一个字符删掉并向前移动一位
				putchar('\b');
				putchar(' ');
				putchar('\b');  //这三句实现删掉已经输出的字符
			}
		}
		else
		{
			password[i] = ch;  //放进数组
			putchar(ch);
			i++;  //不是则向下移动并输出
		}


	}
}

//改变光标位置
void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*定义播放一节音符的函数
f--表示音符，其值为上述定义的枚举型
a--	表示音高，其值为1(低音)、2(中音)、3(高音)
*/
void Play(int f,int a,int t)
{
	Beep((unsigned )(f*a),t*PER);
}

//定义休止函数
void Stop(int t)
{
	Sleep(t*PER);
}

//背景音乐线程
void BGM()
{
	int i=0;
    for(i=0;i<2;i++)
	{
 		Play(So,1,2); Play(So,1,2); Play(La,1,3); Play(So,1,3);Play(Do,2,4); Play(Xi,1,4);

		Play(So,1,2); Play(So,1,2); Play(La,1,3); Play(So,1,3);Play(Re,2,4); Play(Do,2,4);

		Play(So,1,2); Play(So,1,2); Play(So,2,3); Play(Mi,2,3);Play(Do,2,4); Play(Xi,1,4); Play(La,1,4);

		Play(Fa,2,2); Play(Fa,2,2); Play(Mi,2,3); Play(Do,2,3);Play(Re,2,4); Play(Do,2,5);

		Sleep(1);
	}
	Stop(0);
}

//设置一个显示出礼物正在加载的效果
void Loading()
{
    Sleep(2000);
    printf("\n  Your birthday gift is loading....");
    Sleep(2000);
    system("cls");
    Sleep(2000);
}

void Categories()
{
    int choice=0;

    printf("\nWelcome to your birthday party, XXX\n");
    Sleep(3000);
    printf("\nThere are two gifts for you, which are designed by XXX\n");
    Sleep(4000);
    printf("\nNow choose the number before the gift to unpack it!\n\n");
    Sleep(3000);

    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("**                                             **\n");
    printf("**              1.Birthday cake                **\n");
    printf("**                                             **\n");
    printf("**            2.Some words for you             **\n");
    printf("**                                             **\n");
    printf("**              3.Exit the system              **\n");
    printf("**                                             **\n");
    printf("*************************************************\n");
    printf("*************************************************\n");

    while(choice != 3)
    {
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                Cake();
                break;
            case 2:
                Congratulations();
                break;
            case 3:
                printf("\nHappy birthday!\n");
                Sleep(2000);
                printf("\nHave a good day!\n");
                Sleep(2000);
                printf("\nFrom XXX\n");
                Sleep(2000);
                printf("\nTime: XXX\n");
                break;
            default:
                continue;
        }
    }
}

//打印生日蛋糕
void Cake()
{
	printf("\n\n");
    printf("             *           *\n");
    printf("       *    * *         * *    *\n");
    printf("      * *  *   *       *   *  * *\n");
    printf("     *   *  * *         * *  *   *\n");
    printf("      * *   ***   ****  ***   * * \n");
    printf("      ***   ***         ***   *** \n");
    printf("   ** ***   ***         ***   *** **\n");
    printf(" **   ***   ***         ***   ***   **\n");
    printf("**    ***   ***         ***   ***    **\n");
    printf("***   ***                     ***   ***\n");
    printf("*  **                             **  *\n");
    printf("*     ****                    ****    *\n");
    printf("*             **********              *\n");
    printf("*                                     *\n");
	printf("*                                     *\n");
	printf("*          *******   *****            *\n");
	printf("*               *    *    *           *\n");
	printf("*             *      *****            *\n");
	printf("*           *        *    *           *\n");
	printf("*          *******   *****            *\n");
	printf("*                                     *\n");
	printf("   **                              **  \n");
    printf("      ****                    ****     \n");
    printf("              **********               \n");
}

void Congratulations()
{
    int choice=0;
    int i=0;
    printf("\n");
    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("**                                             **\n");
    printf("**           1.XXX's congratulation            **\n");
    printf("**                                             **\n");
    printf("**           2.XXX's congratulation            **\n");
    printf("**                                             **\n");
    printf("**             3.Exit the function             **\n");
    printf("**                                             **\n");
    printf("*************************************************\n");
    printf("*************************************************\n");

    while(choice != 3)
    {
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                //自行填写祝语
                break;
            case 2:
                //自行填写祝语
                break;
            case 3:
                //退出祝语界面则打印上一级的选择界面
                printf("*************************************************\n");
                printf("*************************************************\n");
                printf("**                                             **\n");
                printf("**              1.Birthday cake                **\n");
                printf("**                                             **\n");
                printf("**            2.Some words for you             **\n");
                printf("**                                             **\n");
                printf("**              3.Exit the system              **\n");
                printf("**                                             **\n");
                printf("*************************************************\n");
                printf("*************************************************\n");
                break;
            default:
                continue;
        }
    }

}


