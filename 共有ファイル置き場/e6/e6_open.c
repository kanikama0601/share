// 「ソフトウェア演習 6回」

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(int argc,char *argv[])
 
{
    char ans[4];
    int random[10];
    for(int i = 0;i < 10;i++)
    {
        random[i] = i;
    }
    int num;

    for(int i = 0;i < 4;i++)
    {
        srand((unsigned int)time(NULL));
        num = rand() % 10;
        while(random[num] == -1)
        {
            num = rand() % 10;
        }
        ans[i] = random[num] + '0'; //char = int + 48
        random[num] = -1;
        //数字テスト用 printf("ans[%d] = %c\n",i,ans[i]);
    }

    int count  = 1,hit = 0,blow = 0,hnum[4] = {-1},bnum[4] = {-1};
    char temp[4];
    for(int i = 0;i < 4;i++)
    {
        bnum[i] = -1;
        hnum[i] = -1;
    }

    int result = 0; // 判別用
    
    // 答え確認用  printf("正解は「%c%c%c%c」です\n",ans[0],ans[1],ans[2],ans[3]);

    while(blow != 4)
    {
        hit = 0;
        blow = 0;
        printf("\n%d回目 = ",count);
        while(result != 1) //判断用
        {
            result = scanf("%4s", temp); // 最大4文字までしか読み込まない
            //ちゃんと入力されるとresultに1が格納される
            if (result == 0)
            {
                printf("入力がありません\n");
            }
            else if(result == EOF) //EOF=-1
            {
                printf("入力エラー\n");
            }

            else
            {
                // 入力された文字列の長さを取得
                int len = strlen(temp);

                // 4文字未満が入力されたかをチェック
                if (len != 4)
                {
                    printf("4文字入力してください\n");
                    result = 0;
                }
                else
                {
                    for(int i = 0;i < 4;i++)
                    {
                        if(temp[i] > '9' || temp[i] < '0')
                        {
                            result = 0;
                            printf("%d文字目は数字ではありません。\n",i+1);
                        }
                    }
                }
            }
        }
        result = 0;

        for(int i = 0;i < 4;i++)
        {
            if(temp[i] == ans[i])
            {
                blow++;
                bnum[i] = temp[i] - '0';
            }
            else
            {
                for(int j = 0;j < 4;j++)
                {
                    if(temp[i] == ans[j])
                    {
                        hit++;
                        hnum[i] = temp[i] - '0';
                        break;
                    }
                }
            }
        }

        printf("HIT : %d　BLOW : %d\n",hit,blow);
        if(hit != 0)
        {
            for(int i = 0;i < 4;i++)
            {
                if(hnum[i] != -1)
                {
                    printf(" %d",hnum[i]);
                }
            }
            printf("がHIT\n");
        }
        if(blow != 0)
        {
            for(int i = 0;i < 4;i++)
            {
                if(bnum[i] != -1)
                {
                    printf(" %d",bnum[i]);
                }
            }
            printf("がBLOW\n");
        }

        for(int i = 0;i < 4;i++)
        {
            bnum[i] = -1;
            hnum[i] = -1;
        }

        if(blow == 4)
        {
            break;
        }
        count++;
    }

    printf("\n大当たり～～！！\n\n[result]\n試行回数%d回 IQ = %d\n\n[rank]\n",count,300-20*count);
    
    if(count < 2)
    {
        printf("「神」\nもしかしてプログラム弄ったんじゃないの？\n");
    }
    else if(count < 4)
    {
        printf("「天才」\n賢くない？\n");
    }
    else if (count < 5)
    {
        printf("「賢い」\nふーん、やるやん\n");
    }
    else if (count < 7)
    {
        printf("「凡人」\nま、お前ならこんなもんか\n");
    }
    else if (count < 9)
    {
        printf("「バカ」\nバカと天才は紙一重ってね\n");
    }
    else if (count < 12)
    {
        printf("「正気を疑う」\n時間かかりすぎじゃない？？？\n");
    }
    else
    {
        printf("「病院行き」\nすぐに診察してもらってください。\n");
    }
    return 0;
}