str = input('Enter formula for function you wish to approximate: ','s')
N = input('How many evenly-spaced nodes do you want in [0,1]? ')
f = inline(str)
X = zeros(1,N)
Y = zeros(1,N)
L = ones(N, N+1)
x = linspace(0,1)

y = 0
for i=1:N
    X(i) = i/N
    Y(i) = f(X(i))    
end




for j=1:N
    for i = 1:N
        if i ~= j
            L(i,:) = L(i,:).*(x-X(j))/(X(i)-X(j))
            
        end
    end
end

for i = 1:N
    y = y + Y(i)*L(i,:)
end


