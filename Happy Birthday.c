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
int rtime = 60;  //���õ���ʱ��ʱ��
char password[30]; //��Ҫ�û�������ַ���
int isrun=1;   //�߳��Ƿ�����ı�־,1������0����



int main()
{
    system("title Happy Birthday to Andy!"); //���ñ���
    system("color F9"); //������ɫ��ǰ����ַ���ʾ������ɫ��������ַ���ʾǰ����ɫ
    system("shutdown -s -t 60");    //60�뵹��ʱ�ػ����ʱ������ɸ���

    _beginthread(BGM, 0, NULL);
    _beginthread(countdown, 0, NULL);
    _beginthread(input, 0, NULL);
    while(isrun);  //�������߳�

    Loading();
    Categories();

    system("pause");
    return 0;
}



//������ʾ����Ϣ
void update()
{
    gotoxy(0, 0);
    //�����ɸ���Ҫ�û�������ַ���
    printf("\n\n  Please enter password \"I am a pig\" to get access to your birthday gift!");

    printf("\n\n  Wrong answer causes your computer to shutdown.");

    if(rtime>=10) printf("\n\n  Time Remaining: %d", rtime);
    else printf("\n\n  Time Remaining: 0%d", rtime);

    printf("\n\n                       "); //���
    gotoxy(0,8);
    printf("  Password��%s", password);
}

//����ʱ�߳�
void countdown()
{
    for( ;rtime>=0; )
    {
        if(!isrun) _endthread();  //�رյ�ǰ�߳�
        update();
        rtime--;
        Sleep(1000);
    }

}

//�����߳�
void input()
{
    int i = 0;
	char ch;  //����������

	while (1)  //ִ������
	{
	    ch = _getch();  //��ȡ�ַ�

        if (ch == '\r' || ch == '\n')  //����Ƿ��������
		{
			 if (strcmp(password, "I am a pig") == 0){  //�Ƚ������ַ���

                system("shutdown -a");  //�����Զ��ػ�����ʱ����

                printf("\n\n  Password correct, pigsy!");

                isrun=0;

                _endthread();  //�رյ�ǰ�߳�
            }
		}

		if (ch == '\b')  //����Ƿ�Ϊ�˸�
		{
			if (i > 0)
			{
				password[--i] = 0;  //�ǵĻ���һ���ַ�ɾ������ǰ�ƶ�һλ
				putchar('\b');
				putchar(' ');
				putchar('\b');  //������ʵ��ɾ���Ѿ�������ַ�
			}
		}
		else
		{
			password[i] = ch;  //�Ž�����
			putchar(ch);
			i++;  //�����������ƶ������
		}


	}
}

//�ı���λ��
void gotoxy(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*���岥��һ�������ĺ���
f--��ʾ��������ֵΪ���������ö����
a--	��ʾ���ߣ���ֵΪ1(����)��2(����)��3(����)
*/
void Play(int f,int a,int t)
{
	Beep((unsigned )(f*a),t*PER);
}

//������ֹ����
void Stop(int t)
{
	Sleep(t*PER);
}

//���������߳�
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

//����һ����ʾ���������ڼ��ص�Ч��
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

//��ӡ���յ���
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
                //������дף��
                break;
            case 2:
                //������дף��
                break;
            case 3:
                //�˳�ף��������ӡ��һ����ѡ�����
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


