x_data = deepest_snowfall_12['月・年']
y_data = deepest_snowfall_12['最深積雪'].astype(int)

import matplotlib.pyplot as plt
plt.scatter(x_data,y_data)
plt.xlabel('月・年')
plt.ylabel('最深積雪')
plt.ylim(0, deepest_snowfall_12['最深積雪'].astype(int).max()+10)
plt.show()