temp = ssdse_f.loc[0]
deepest_snowfall = ssdse_f.copy()
deepest_snowfall.columns = temp
deepest_snowfall = deepest_snowfall[["地域コード",'都道府県','月・年','平均気温','最深積雪']]
deepest_snowfall = deepest_snowfall.drop(0)
deepest_snowfall