import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

plt.clf()
#X is a 10x10 Hilbert matrix
X = 1. / (np.arange(1,11) + np.arange(0,10)[:, np.newaxis])
y = np.ones(10)

#Computing paths
n_alphas = 200
alphas = np.logspace(-10,-2,n_alphas)
clf = linear_model.Ridge(fit_intercept=False)

coefs = []
for a in alphas:
    clf.set_params(alpha=a)
    clf.fit(X,y)
    coefs.append(clf.coef_)

ax = plt.gca()

ax.plot(alphas,coefs)
ax.set_xscale('log')
#Reverse axis
ax.set_xlim(ax.get_xlim()[::-1])
plt.xlabel('Alphas')
plt.ylabel('Weights')
plt.title('Ridge coefficients as a function of regularization')
plt.axis('tight')
plt.show()


