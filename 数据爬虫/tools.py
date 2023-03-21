import pandas as pd
import numpy as np


# 转换excel为csv
def e2c():
    file = "../books.xlsx"

    data = pd.read_excel(file)

    data.to_csv("books.csv", index=False)


if __name__ == '__main__':
    e2c()
