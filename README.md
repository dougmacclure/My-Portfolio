# Machine Learning Projects


1) Flight Delay Jupyter Notebook

This is a Jupyter notebook consisting of Python3.7 code which performs data management and feature building and constructs an OLS regression model.  The resulting model is trained using Jan 2017 data and evaluated on the Jan 2017 validation data and Jan 2016 data. 

DATA SOURCES:

O'HARE DATA:
https://www.transtats.bts.gov/DL_SelectFields.asp?Table_ID=236

WEATHER DATA:
https://www.ncdc.noaa.gov/cdo-web/datasets

Model was inspired by  
https://aws.amazon.com/blogs/big-data/powering-amazon-redshift-analytics-with-apache-spark-and-amazon-machine-learning/

2) R Markdown Bank Client-Subscription Model

This is an R Markdown file consisting of R 3.6 code which executes all phases of model building from data extraction to model evaluation for a classification model and a corresponding html file.  The data and a detailed description of the data can be found here: https://archive.ics.uci.edu/ml/datasets/Bank+Marketing.  A brief description of the data from the website is as follows:

"The data is related with direct marketing campaigns of a Portuguese banking institution. The marketing campaigns were based on phone calls. Often, more than one contact to the same client was required, in order to access if the product (bank term deposit) would be ('yes') or not ('no') subscribed."

To view the report, see macclure_bankdepositsubscriptionmodel.md.  

3) R Markdown Movie Recommendation Random-Effects Model 

This is an R Markdown file consisting of R 3.6 code which executes all phases of model building from data extraction to model evaluation for a classification model and a corresponding html file.  The data comes from the movielens dataset found here: http://files.grouplens.org/datasets/movielens/ml-10m.zip.  This model is motivated by the "Netflix Challenge".  To view the report, see macclure_movielens.md.  


4) Fruit Classification Jupyter Notebook

This is a Jupyter notebook consisting of Python3.6 code which utilizes TensorFlow to build a Deep Neural Network (activation function is ReLU (i.e., Max(0,z)) which is trained to classify a 100X100 3-channel color picture of one of 83 types of fruit.  We are using sparse_softmax_cross_entropy_with_logits to handle floating-point rounding errors.  Further model evaluation and alteration of hyperparameters will be coming soon.  

DATA SOURCE: https://www.kaggle.com/moltean/fruits

5) Fraud Detection Jupyter Notebook Part 1

This is a Jupyter notebook consisting of Python3.7 code which constructs a binary classification model.  Ensemble models are considered and evaluated.

DATA SOURCE: https://www.kaggle.com/mlg-ulb/creditcardfraud

6) Fraud Detection Jupyter Notebook Part 2

Same data source as 3) except other classification models are considered including Stochastic Gradient Descent with k-fold Cross Validation (including maximizing model precision and recall via threshold), Gaussian Naive Bayes Classification, Support Vector Machines, and grid search with cross-validation of hyper-paramaters of random forest classification models.  Further evaluation of SVMs will be considered.  The latter model was the most computationally expensive model.  Further research on using Python on an EMR cluster will be considered.  

# AIC Presentation

This is a presentation designed for an audience with casual familiarity with machine learning.  This presentation briefly describes one of two projects I've undertaken during my internship with Inte Q.  The other project involved helping build and package a customer segmentation (using k-means).

# Data Structures and Algorithm Analysis

Contains 10 programs written in the C++ language in a UNIX environment including:
1) Program 11 - Generates and traverses a weighted directed graph in various ways.
2) Program 10 - Generates a sorted database via hashtables and linear probes.
3) Program 9  - Generates and sorts heap tables in various ways.
4) Program 8  - Generates a binary tree initialized with random integers, and then removes the leaves from the tree until empty.
5) Program 7  - Generates several binary trees and prints some attributes of them.
6) Program 6  - Generates several binary trees and prints their leaves in various orders (inorder, preorder and postorder)
7) Program 5  - Generates a store simulation where customers enter and leave the store.  Various metrics are computed including number of departures, min/max shopping time, average shopping time and total simulation time.  
8) Program 4  - Isolates individual words from user input, cleaning them of non-alphanumeric characters, 
and provide various metrics on the words contained in the input.  
9) Program 3  - Uses a seive algorithm to display all primes up to the integer N, which is given by the user.
10) Program 2 - Sorts random integers based on linear and binary searches and compares percent of successful searches.

# Code For Fractal Diagrams

This code was written in Python 2.7 with weave.inline (for including C++ code to speed up computations) for research purposes.  

# MATLAB Code

Various MATLAB projects are included, including an LU-decomposition algorithm, Newton's Method and Extended Secant Method for finding the zeros of a function, Lagrange polynomial interpolation and various other projects.  

# UNIX Scripts

Various UNIX shell scripts and C++ code for various server administrative tasks.

1) Assign12 - Build a TCP server that is designed to handle multiple requests for directory access of a specified path.  Client is able to list directory contents and view file contents.
2) Assign11 - Build a UDP program which accesses a credit card server, sends it a credit card transaction and receives a message from the server.
3) Assign10 - Create a pipe shell where within a loop, we query the user for two commands which are piped together with resulting output printed to cout
4) Assign9  - A program which emulates the UNIX command "tee".  It takes input from standard input and copies it into multiple files.
5) Assign8 and Assign7  - An awk script which is used to process a sales report log, and prints total sales for each employee
6) Assign6 - UNIX script for four commands:  
  a) new -    Allows user to create a new database
  b) add -    Allows user to add new records into database file
  c) show -   Allows user to view specific records within database
  d) delete - Allows user to remove records from database
7) Assign5 - A UNIX Spell-Checker bash script


# Intermediate C++ Programs

A collection of 9 intermediate C++ programs.

1) Assign9 - Build and sort lists using quicksort algorithm
2) Assign8 - Tests the functionality of the Deque template class
3) Assign7 - Tests the functionality of the Queue template class
4) Assign6 - Tests the functionality of the Stack class
5) Assign5 & Assign4 - Tests the functionality of the MyString class and friend functions
6) Assign3 - Tests the functionality of the Verifier class
7) Assign2 - Creates a store object which is used to process orders given in a txt file
8) Assign1 - Converts user input into an integer - fun with numerology.  
