# -*- coding: utf-8 -*-
"""
Created on Sun Jun 28 11:47:03 2020

@author: H235030
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import PolynomialFeatures
from sklearn.metrics import mean_squared_error
import seaborn as sns

import warnings
warnings.filterwarnings('ignore')

data = pd.read_csv("RegresiPositive.csv")
data.head()

print('loading tunggu sabar bos tergantung devicenya...')
data['Positive'] = data['Positive'].str.replace(',', '')
# data['Hari'] = data['Hari'].str.replace(',', '')

data['Positive'] = pd.to_numeric(data['Positive'])
data['Hari'] = pd.to_numeric(data['Hari'])

print(data.info())
data_numeric = data.select_dtypes(include=['float64', 'int64'])
plt.figure(figsize=(4, 2))
sns.pairplot(data_numeric)
plt.show()

plt.figure(figsize=(4, 2))
plt.scatter(
    data['Hari'],
    data['Positive'],

    c='blue'
)

plt.axis('scaled')
plt.xlabel("Hari")
plt.ylabel("Positive")
plt.show()

X = data['Hari'].values.reshape(-1,1)
y = data['Positive'].values.reshape(-1,1)
#X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=0)
reg = LinearRegression()
reg.fit(X, y)
print("The linear model is: Y = {:.5} + {:.5}X".format(reg.intercept_[0], reg.coef_[0][0]))
predictions = reg.predict(X)

actvspred = pd.DataFrame({'Actual': y.flatten(), 'Predicted': predictions.flatten()})

plt.figure(figsize=(4, 2))
plt.scatter(
    X,
    y,
    c='blue'
)

plt.plot(
    X,
    predictions,
    c='red',
    linewidth = 3
)
plt.xlabel("Hari")
plt.ylabel("Positive")
plt.show()

print('RMSE for Linear Regression=>',np.sqrt(mean_squared_error(y,predictions)))