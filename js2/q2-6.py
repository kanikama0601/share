x_data = deepest_snowfall_12['月・年']
# 最深積雪をstr → intに変換
y_data = deepest_snowfall_12['最深積雪'].astype(int)

import matplotlib.pyplot as plt
plt.scatter(x_data,y_data)
plt.xlabel('月・年')
plt.ylabel('最深積雪')
plt.show()




# このままではグラフの日本語が文字化けするので、
# 別のコードに
# !pip install japanize_matplotlib
# これを入れ実行した後、

# import japanize_matplotlib
# これを入れると文字化けが解消されます