%Get user-defined variables 

str = input('Enter formula for function ','s')
f = inline(str)
a = input('Enter left endpoint: ')
b = input('Enter right endpoint: ')
e = input('Enter error tolerance: ')
N = input('Enter the maximum number of times to loop through bisection algorithm: ')

%Compute and store f(a) and f(b)
format long
FA = f(a)
FB = f(b)

%User-inputed error checking
if a >= b or FA*FB
    disp('Error: either no zero exists in [a,b], or [a,b] is not well-defined!');
end

if isinf(FA)||isnan(FA)
    disp('f is not continuous at ') 
    disp(a) 
    disp('so f does not satisfy conditions of bisection algorithm on given interval!')
    return
end

if isinf(FB)||isnan(FB)
    disp('f is not continuous at ') 
    disp(b) 
    disp('so f does not satsify conditions of bisection algorithm on given interval!')
    return
end

%If no error was encountered, start Bisection Method Algorithm

for n=1:N
    format long
    d = (b-a)/2
    m = a+d
    FM = f(m)
    
    %If Bisection Method achieved error tolerance, given by [a_n,b_n] < e, 
    %we have computed a well-approximated zero of f, so we display the
    %number and end program.
    
    if d < e || FM == 0
        disp('the zero is ');
        format long
        disp(m);
        return
    
    %Otherewise, continue algorithm   
     
    else
        if FA*FM > 0
            a = m;
        else
            b = m;
        end
    end
end

%If Bisection Method Algorithm couldn't achieve [a_n,b_n] < e, give error
%message and end program

disp('Bisection Method Algorithm did not achieve error tolerance')
disp(e)
disp('after')
disp(N)
disp('iterations.')
format long
disp(m)
    


