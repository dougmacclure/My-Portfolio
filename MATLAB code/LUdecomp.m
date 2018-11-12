disp('Welcome to an LU-decomposition program.')
disp('Make sure to have a nonsingular square nXn matrix with nonsingular k-leading principle minors handy.')

n=input('order of your square matrix is? ')
    for i=1:n^2;
    a(i)=input('elements: ');
    end
    A=reshape(a,n,n)'
     
L = zeros(n:n);
U = zeros(n:n);
      for k=1:n
          L(k,k) = 1
                             
          for j=k:n
            y = 0
            for s = 1:k-1
                y = y + L(k,s)*U(s,j)
            end
            U(k,j) = A(k,j)- y
          end
       for i = k+1:n
           y = 0
           for s = 1:k-1
               y = y+L(i,s)*U(s,k)
           end
           L(i,k) = (A(i,k) - y)/U(k,k)
       end
      end
disp(U)
disp(L)

for i = 1:n
    b(i) = input('Next, enter the elements of vector b in the equation Ax = b: ')
end
x = zeros(n)
w = zeros(n)
w(1) = b(1)/L(1,1)
for i = 2:n
    y = 0
    for j = 1:i-1
        y = y + L(i,j)*x(j)
    end
    w(i) = (b(i)-y)/L(i,i)
end

x(n) = w(n)/U(n,n)

for i=n-1:1 
    y = 0
    for j = i+1:n
        y = y + U(i,j)*x(j)
    end
    x(i) = (w(i) - y)/U(i,i)
end

disp('x = ')
disp(x)