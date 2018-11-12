x0 = 1.50316;
k = 1000;
t = -k+x0:k/500:k+x0
x = 2.*atan(sqrt(1/k^2-(t-x0).^2)./t)./pi;
y = 0.*t;
z = log(1/k^2+2*x0.*t-x0^2);
x1 = pi.*sin(pi*x);
z1 = z + x + asinh(1)-.5;
x2= sin(x1).*cosh(z1);
z2 = cos(x1).*sinh(z1);
plot3(t,x2, z2)