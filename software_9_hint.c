#include <stdio.h>
#include <stdbool.h>
int main(void)
 
{
    int max = 20;
    printf("まず、すべて素数と考える\n");
    bool a[max+1]; //trueかfalseか
    for(int i = 1;i <= max;i++)
    {
        a[i] = true; //trueで素数 falseで素数じゃない
    }
    //わかりやすくする為に1増やしています
    for(int i = 1;i <= max;i++)
    {
        printf("%d = %s\n",i,a[i]? "true" : "false");
    }
    printf("もし素数じゃない場合、aをfalseにする\n\n");

    printf("まず、1を除外(1は素数ではない)\n\n");
    a[1] = false;
    printf("1 =  %s\n\n",a[1]? "true" : "false");

    int count = 0;
    printf("次に、iが素数の時、iの倍数を全部falseにする\n");
    for(int i = 2;i * i <= max;i++)
    {
        if(a[i] == true)
        {
            count++;
            printf("\n%d回目\n",count);
            for(int j = i*i;j <= max;j += i)
            {
                a[j] = false;
            }
        }
        else if(a[i] == false)
        {
            printf("\n%dは素数じゃないので、スキップ\n",i);
        }

        for(int i = 1;i <= max;i++)
        {
            printf("%d = %s\n",i,a[i]? "true" : "false");
        }
        
    }

    printf("\n\nこれで素数の表が完成する\n後はn～2nの間にtrueが無いならreturn 1でエラー表示にするだけ\n");
    printf("なんでそんなこと知ってるの\n");
    printf("＿人人人人人人人人人人人人人人人人＿\n");
    printf("＞　カイトをフォローしているから　＜\n");
    printf("￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y￣\n");
    return 0;
}

/*実行結果
まず、すべて素数と考える
1 = true
2 = true
3 = true
4 = true
5 = true
6 = true
7 = true
8 = true
9 = true
10 = true
11 = true
12 = true
13 = true
14 = true
15 = true
16 = true
17 = true
18 = true
19 = true
20 = true
もし素数じゃない場合、aをfalseにする

まず、1を除外(1は素数ではない)

1 =  false

次に、iが素数の時、iの倍数を全部falseにする

1回目
1 = false
2 = true
3 = true
4 = false
5 = true
6 = false
7 = true
8 = false
9 = true
10 = false
11 = true
12 = false
13 = true
14 = false
15 = true
16 = false
17 = true
18 = false
19 = true
20 = false

2回目
1 = false
2 = true
3 = true
4 = false
5 = true
6 = false
7 = true
8 = false
9 = false
10 = false
11 = true
12 = false
13 = true
14 = false
15 = false
16 = false
17 = true
18 = false
19 = true
20 = false

4は素数じゃないので、スキップ
1 = false
2 = true
3 = true
4 = false
5 = true
6 = false
7 = true
8 = false
9 = false
10 = false
11 = true
12 = false
13 = true
14 = false
15 = false
16 = false
17 = true
18 = false
19 = true
20 = false


これで素数の表が完成する
後はn～2nの間にtrueが無いならreturn 1でエラー表示にするだけ
なんでそんなこと知ってるの
＿人人人人人人人人人人人人人人人人＿
＞　カイトをフォローしているから　＜
￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y￣
*/