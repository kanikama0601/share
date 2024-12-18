#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NODE *head = NULL;
char data[20];
char delete_str[20];
char after[20];
int n = 0;

int main(){
    int loop=1;

    while (loop)
    {
        printf("----------------------------\n");
        printf("0) 終了\n1) 先頭にノードを追加\n2) 任意の位置にノードを挿入\n3) 指定のノードを削除\n4) 全ノードの削除\n5) 指定のデータのノードを削除\n6) ノードの数をカウント\n7) 指定の名前のデータを別名に変更");
        printf("\n何番の処理を行いますか？:");
        scanf("%d",&loop);
        switch (loop)
        {
        case 0:
            printf("終了します\n");
            break;
        case 1:
            printf("先頭にノードを追加\n");
            printf("追加するデータ : ");
            char data[20];
            scanf("%s",data);
            head = add(data,head);
            break;
        case 2:
            printf("任意の位置にノードを挿入\n");
            printf("挿入するデータ : ");
            scanf("%s",data);
            printf("何番目の後に : ");
            int n;
            scanf("%d",&n);
            insert(n,data,&head);
            break;
        case 3:
            printf("指定のノードを削除\n");
            printf("削除するデータ : ");
            scanf("%d",&n);
            delete(n,&head);
            break;
        case 4:
            printf("全ノードの削除\n");
            free_list(&head);
            break;
        case 5:
            printf("指定のデータのノードを削除\n");
            printf("削除するデータ : ");
            scanf("%s",delete_str);
            delete_name(delete_str,&head);
            break;
        case 6:
            printf("ノードの数をカウント\n");
            count_node(head);
            break;
        case 7:
            printf("指定の名前のデータを別名に変更\n");
            printf("変更するデータ : ");
            scanf("%s",data);
            printf("別名 : ");
            scanf("%s",after);
            replace(data,after,head);
            break;

        default:
            break;
        }
        print(head);
    }
    
    return 0;
}

/* 実行結果 
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:1
先頭にノードを追加
追加するデータ : tabuchi
tabuchi->NULL
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:3
指定のノードを削除
削除するデータ : 0
p->name = tabuchi
NULL
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:1
先頭にノードを追加
追加するデータ : tabuchi
tabuchi->NULL
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:1    
先頭にノードを追加
追加するデータ : sawai
sawai->tabuchi->NULL
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:5
指定のデータのノードを削除
削除するデータ : tabuchi
sawai->NULL
----------------------------
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除

何番の処理を行いますか？:0
終了します
sawai->NULL
*/