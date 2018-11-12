%Doug MacClure
%M662 - Bellout
%HW3 
%I tested this algorithm on f(x) = x^3 + x - 1, with intial guesses 0 and
%0.5, error tolerance 10^(-16), and 100 maximum iterations.  After 10
%iterations, the algorithm achieved prescribed tolerance, with the zero
%being approximately  0.682327803828019

%get user defined functions and variables

str = input('Enter formula for function: ','s')
x0 = input('Enter first initial guess for the zero: ')
x1 = input('Enter second guess for the zero which is close, but not equal to your first guess: ')
N = input('Enter maximum number of iterations of revised secant method: ')
e = input('Enter error tolerance for the zero: ')
d = input('Enter error tolerance for |x_{n+1}-x_n|: ')

%convert user input string into a MATHLAB function
f = inline(str)
fx0 = f(x0)
fx1 = f(x1)
%get third x-value for revised secant method
x2 = x1 - fx1.*(x1-x0)./(fx1-fx0)
fx2 = f(x2)
%here, we set x+h = x2, x+k = x1, and x = x0
disp(x2)
for k = 2:N
    
    a = fx2*(x1-x2)*(x2-x0)*(x1-x0)
    b = fx2*(x1-x0)*(x1-x0)-fx1*(x2-x0)*(x2-x0)+fx0*((x2-x0)*(x2-x0)-(x1-x0)*(x1-x0))
    c = x2 - a/b
    x0 = x1
    x1 = x2
    x2 = c
    fx0 = f(x0)
    fx1 = f(x1)
    fx2 = f(x2)
    if abs(fx2)<e 
       disp('After ')
       disp(k)
       disp('iterations, we have found that')
       disp('the zero of your function is approximately')
       format long
       disp(x2)
       return
    end
    if abs(x2-x1) < d
       disp('Error, the difference between x_{n+1} and x_n is very small,')
       disp('but f(x_{n+1}) is within error tolerance of zero.')
       return
    end
end    
disp('Error, could not find zero of f within prescribed error tolerance after')
disp(N)
disp('iterations of revised secant method.')
