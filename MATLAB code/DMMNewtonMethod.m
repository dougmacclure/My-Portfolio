%get user defined functions and variables

str = input('Enter formula for function: ','s')
Dstr = input('Enter formula for derivative function: ','s')
x0 = input('Enter initial guess for zero: ')
N = input('Enter maximum number of iterations of Newton method: ')
e = input('Enter error tolerance: ')

%convert user input string into a MATHLAB function
f = inline(str)
Df = inline(Dstr)

%compute initial values for Newton's Method
y = f(x0)
Dy = Df(x0)

%if initial guess is within user-prescribed error tolerance, we're done
if abs(y) < e
    disp('Good guess!')
    return

end


%otherwise, start Newton's method, and iterate at most N times through it 
for n=1:N
    x1 = x0-y./(Dy)
    y = f(x1)
    disp(n)
    disp(x1)
    disp(y)
    
    %if either the differences between x_n and x_(n+1) are within error
    %tolerance or f(x_(n+1)) is within error tolerance to zero, we're done.
    %Display the approximate zero
    if abs(x1-x0)< e || abs(y)<e
        
        disp('The zero is approximately')
        format long
        disp(x1)
        return
    end
    x0 = x1
    Dy = Df(x0)
      
end

if abs(y) > e
    disp('Error: could not achieve error tolerance after')
    disp(N)
    disp('iterations!')
    return
end

%with error tolerance 10^(-16), after 5 iterations, the algorithm shows the
%solution to x = tan(x) closest to 4.5 is approximately 4.493409457909064 and after 7
%iterations, the solution closest to 7.7 is approximately 7.725251836937707
