Movie Recommendation Model
================
Doug MacClure
5/1/2019

## Introduction

In this report, we analyze the movielens data set (found here:
<http://files.grouplens.org/datasets/movielens/ml-10m.zip>) and
construct various bias/effects-based recommendation algorithms using 90%
of the movielens dataset. Other potential recommendation algorithms are
discussed, and our approach using bias/effects instead is justified.

This project is done for the Data Science Capstone assignment via
HarvardX. HarvardX has provided code up to creating training and
validation datasets. The goal of this model is to create a
recommendation model which predicts user-defined movie ratings evaluated
on a validation dataset with root-mean squared error less than 0.87750.

To begin, perform the following steps: install (if necessary) and load
the required packages to run the R code: caret, lubridate and tidyverse.
Next, download the required data, and wrangle/coerce data for analysis.
Finally, split the prepared data into training and validation datasets.

We begin our analysis of the data by noting which potential predictive
variables we have to work with.

Note that the purpose of this model is to predict the rating a user
would give for a given movie. Hence, we wish to build a model which
predicts a movie rating given a userId and movieId. There are other
predictors we can consider. Consider the following frequency histogram
for number of movies rated per
user.

![](macclure_movielens_files/figure-gfm/user%20quantity%20rating%20avg%20histogram-1.png)<!-- -->

Most users rate less than 500 movies, and some users rate many movies.
However, the average number of movies rated is:

    ## [1] 128.7968

Hence, we have enough data and variation in the data to build a movie
recommendation model, which is further verified by considering the
movie-rating
distribution.

![](macclure_movielens_files/figure-gfm/rating%20avg%20histogram-1.png)<!-- -->

## Model Construction and Analysis

Now, note that the approach discussed here will utilize a random-effects
approach, where the predictors are considered random variables, which
depend on userId and movieId, as opposed to fixed quantities. The author
has considered regression and classification models, but the structure
of the data is inappropriate for such analysis, particularly on laptops,
due to memory constraints.

We begin by considering movie and user effects on the variable we wish
to predict: rating.

Now, lets analyze the following potential random-effects model:
\[Y_{u,i} = \mu + b_i + b_u,\] where \(\mu\) is a constant which
represents the overall mean movie rating from all users for all movies.
Here, \(b_i\) is the movie and \(b_u\) are random variables, dependent
upon a user \(u\) and movie \(i\). To be more specific, \(b_i\) is the
average difference between a movie rating for movie \(i\) and the
overall average movie rating for all movies (i.e., the movie effect),
while \(b_u\) is the average difference between movies \(i\) rated by
user \(u\) and the sum of \(\mu\) and \(b_i\) (i.e., the user effect).

Using R version 3.6, we have a RMSE score of 0.8655329. The author has
observed other RMSE scores by running the code with R version 3.5.2. We
can also determine how the model is performing by considering the
residual distribution. Note that the mean is centered at zero and the
distribution is approximately normal. This is a good indication that the
model is neither over-estimating nor under-estimating on
average.

![](macclure_movielens_files/figure-gfm/movie-user%20residual%20histogram-1.png)<!-- -->

Next, we consider incorporating genres-effects into our random-effects
model. Do we see an improvement in RMSE? Our new model is:
\[Y_{u,i} = \mu + b_i + b_u + g_{u,i}.\] Observe the new residual
distribution is essentially the same as before. Hence, we are starting
to see diminishing returns in including more random-effects variables
into our model.

![](macclure_movielens_files/figure-gfm/with%20genres-1.png)<!-- -->
Despite diminishing returns, we do see a decrease in RMSE of
\(\approx 0.0003\). To finish, we incorporate time effects. However,
before we do so, we need to note that timestamp is a number representing
the number of minute since 01-01-1970 00:00. Note that we need to reduce
the granularity of such a variable, since each particular timestamp will
be associated with a small number of ratings, which we observe after
computing the number of distinct timestamps and the total numer of
observations we are considering.

Hence, the granularity of the time effect is by week. Further, observe
that the new residual histogram is again essentially the same as before.

![](macclure_movielens_files/figure-gfm/time%20effects-1.png)<!-- -->

## Results

Finally, we compare the RMSE of each random-effects model to determine
the best model, and if this model is satisfactory.

| method                                    |      RMSE |
| :---------------------------------------- | --------: |
| Movie + User Effects Model                | 0.8655329 |
| Movie + User + Genre Effects Model        | 0.8651946 |
| Movie + User + Genre + Time Effects Model | 0.8650986 |

We see that for \(d_{u,i}\) denoting the random variable associated with
the average rating of movie \(u\) by user \(i\) during a given week, the
best performing model of the three is model 3:
\[Y_{u,i} \approx \mu + b_u + b_i + g_{u,i} + d_{u,i}.\] Here, the RMSE
is 0.8650986., which is well below the target RMSE of 0.87750.

Now, note that the author has considered generative model techniques as
well. However, using Naive Bayes thus far has been unable to yield a
model with RMSE below 1.1 and accuracy greater than 35%.

## Conclusion

In conclusion, we have shown that a random-effects modeling approach is
most appropriate given the data we have to work with. We have generated
a model which meets the initial goal of having the predictive power
where the RMSE is below 0.8775.

There is room for further improvement in this model. The author would
like to eventually try ensemble models, where regression and
classification are done on smaller and more computable subsets.
