a = sqrt(3);
%line=@(x,y,z)[x, 0, ax];
x = (1/(2+2*a)):.001:3;
f = .5*pi*sin((5*atan(1/a))/((5/pi)*atan(1/a)));
g = log(((1+a^2)^(5/2))*x.^5)+asinh(1)-.5+5*atan(1/a)/pi;
la = sin(f).*cosh(g);
h5x = cos(f).*sinh(g);
figure
plot(x, a.*x, la, h5x);

%hline = @(x,y,z)[sin(f)*cosh(g),0,cos(f)*sinh(g)];
