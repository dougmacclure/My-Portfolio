%Doug MacClure
%M662 - Bellout

%Using f(x) = exp(x), and n = 10, max error ||p-f|| = 1.8474e-13, for n =
%4, ||p-f|| = 5.2616e-05
%Using f(x) = sin(20x), and n = 4, max error ||p-f|| is 2.0339, for n = 10,
%||p-f|| = 3.5994
str = input('Which function are we interpolating? ', 's')
f = inline(str)
N = input('How many evenly-spaced nodes do you want in [0,1]? ')


for i=1:N+1
    X(i) = (i-1)/N
    w = X(i)
    Y(i) = f(w)    
end

x = linspace(0,1)
p = zeros(size(x))

for i=1:N+1
    L = ones(size(x))
    for j = 1:N+1
        if j~= i
            L = (x-X(j))./(X(i)-X(j)).*L;
        end
    
    end
    p = p + L*Y(i)
end

y = f(x)

error = max(abs(p-y))
disp('Maximum error in interpolation is ')
disp(error)

plot(x,p,'color','r')
hold on
plot(x,y,'color','b')
legend('p', str)