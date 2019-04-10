# Machine-Learning
This repository is a set of programs and small projects, done mostly in Python, exploring various machine learning-based techniques commonly used in data science.
### Cryptography in Python
The file crypto.py is a simple Python program that can take in a string or strings of words as input. The phrase can either be an already encrypted phrase to be decrypted, or a phrase to encrypt. The program has various encryption schemes, such as Atbash, Caesar, and N-Shift. 
### Cryptography in C++
The file cryptography.cpp is a similar file as the one in Python, however extended to be in C++. The program runs in a simila way, allowing the choice of encrytpion or decryption of various methods. When decryption is selected, the cypher key is also availble to be printed along with the message text.
### Feature Extraction in C++
The program word_detection.cpp and along with the file of .txt files attempts to use what it learns from reading a corpus of short stories to try and predict how a message is encrypted. The program reads in over 20 stories (a relatively small training set for text based models) and analyzes the construction. That is, it determines the most and least commons letters by percentage, for example 'e' is the most common letter at roughly 12.5% of all used letter. It also "learns" relationships between letters and stores this as a grid. It learns to understand that "q" could be preceeded by "u", but is always followed by "u", and abstractly understands the rules of vowels and consonants. Based on this, it then takes in a cipher text, here one of the short stories used to train that has been passed through one of a selection of cipher schemes. It then tries to go about the same relational understanding of the letters such as which were most common in the cipher text, and tries to correctly match the cipher alphabet to the real alphabet, creating a cipher key. The program is able to do so with remarkable accuracy, only struggling with the lesser common letters at times, such as "x", "j", or say "q" because of the very small margin in percent occurence.
### Regression in Python
The files Lasso_eslasticnet.py and Ridg_Regr.py are classifiers that are regularized by the Lasso and Ridge regression methods respectively. That is, they are penalized by the L1 and L2 norm respectively. The Lasso file does also have a section encorporating an elastic net which is using both penalties.

The file diabetes_linearreg.py also uses regression, but here linear regression.
### Classification in Python
The file iris_ml.py studies the commonly used iris data set under a set of different classifiers. The code uses K-nearest neighbors, logistic and linear regresion, linear discriminant analysis, as well as a decision tree.
