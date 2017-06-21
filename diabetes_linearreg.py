print(__doc__)

import matplotlib.pyplot as plt
import numpy as np
from sklearn import datasets, linear_model

#Load the dataset
diabetes = datasets.load_diabetes()
#Use only one aspect
diabetes_X = diabetes.data[:,np.newaxis,2]

#Split data into training and testing sets
diabetes_X_train = diabetes_X[:-20]
diabetes_X_test = diabetes_X[-20:]
#Split targets into training and testing sets
diabetes_y_train = diabetes.target[:-20]
diabetes_y_test = diabetes.target[-20:]

#Create a linear regression object
regr = linear_model.LinearRegression()
#Train the model using the training
regr.fit(diabetes_X_train,diabetes_y_train)

#Regression coefficients
print('Coefficients: \n', regr.coef_)
#Mean squared error
print("Mean squared error: %.2f" % np.mean((regr.predict(diabetes_X_test) - diabetes_y_test) ** 2))
#Variance score for test set
print('Variance score: %.2f' % regr.score(diabetes_X_test, diabetes_y_test))

#Plots
plt.scatter(diabetes_X_test,diabetes_y_test,color='black')
plt.plot(diabetes_X_test,regr.predict(diabetes_X_test),color='blue',linewidth=3)

plt.xticks(())
plt.yticks(())
plt.show()





