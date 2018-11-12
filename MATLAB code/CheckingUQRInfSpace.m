alpha = (1 + sqrt(2));
a = 1.0;
b = -2*exp(1/2)/alpha;
f = -exp(1)/(alpha^2);
p1 = -27*b^2*f;
p2 = p1 + sqrt(-4.0*(12*a*f)^3+p1^2);
p3 = 12*a*f/(3*(p2/2)^(1/3))+(p2/2)^(1/3)/3;
p4 = sqrt(b^2/4+p3);
p5 = b^2/2-p3;
p6 = (-1.0*b^3)/(4*p4);

%The zeros of h_2((0,0,z))-z
z1 = -1.0*b/4-p4/2-sqrt(p5-p6)/2;
z2 = -1.0*b/4-p4/2+sqrt(p5-p6)/2;
z3 = -1.0*b/4+p4/2-sqrt(p5-p6)/2;
z4 = -1.0*b/4+p4/2+sqrt(p5-p6)/2;

%Put together derivative matrix for h_2

f = @(x,y,z)2*atan(sqrt((x^2+y^2)/(z^2)))/(pi);
g = @(x,y,z)log((x^2+y^2+z^2));
F1 = @(x,y,z)(pi/2)*abs(sin(pi*f(x,y,z)));
F2 = @(x,y,z)g(x,y,z) + f(x,y,z)-asinh(1)-.5;




pfx = @(x,y,z)(2*x*abs(z)^3)/((sqrt(x^2+y^2))*(x^2+y^2+z^2));
pfy = @(x,y,z)(2*y*abs(z)^3)/((sqrt(x^2+y^2))*(x^2+y^2+z^2));
pfz = @(x,y,z)-2.0*sqrt(x^2+y^2)/(x^2+y^2+z^2);

pgx = @(x,y,z)2*x/(x^2+y^2+z^2);
pgy = @(x,y,z)2*y/(x^2+y^2+z^2);
pgz = @(x,y,z)2*z/(x^2+y^2+z^2);

pF1x = @(x,y,z)pi^2*cos(pi*f(x,y,z))*pfx(x,y,z)/2;
pF1y = @(x,y,z)pi^2*cos(pi*f(x,y,z))*pfy(x,y,z)/2;
pF1z = @(x,y,z)pi^2*cos(pi*f(x,y,z))*pfz(x,y,z)/2;

pF2x = @(x,y,z)pgx(x,y,z) + pfx(x,y,z);
pF2y = @(x,y,z)pgy(x,y,z) + pfy(x,y,z);
pF2z = @(x,y,z)pgz(x,y,z) + pfz(x,y,z);

h11x = @(x,y,z)(x*(cosh(F2(x,y,z))*((x^2+y^2)*(cos(F1(x,y,z))*pF1x(x,y,z))-x*sin(F1(x,y,z)))+sinh(F2(x,y,z))*(x^2+y^2)*sin(F1(x,y,z))*pF2x(x,y,z))/(x^2+y^2)^(3/2));
h12x = @(x,y,z)(y/x)*h11x(x,y,z);
h12y = @(x,y,z)y*(cosh(F2(x,y,z))*((x^2+y^2)*(cos(F1(x,y,z))*pF1y(x,y,z))-y*sin(F1(x,y,z)))+sinh(F2(x,y,z))*(x^2+y^2)*sin(F1(x,y,z))*pF2y(x,y,z))/(x^2+y^2)^(3/2);
h11y = @(x,y,z)(x/y)*h12y(x,y,z);
h11z = @(x,y,z)(x/sqrt(x^2+y^2))*(cos(F1(x,y,z))*cosh(F2(x,y,z))*pF1z(x,y,z)-y*sin(F1(x,y,z))*sinh(F2(x,y,z))*pF2z(x,y,z));
h12z = @(x,y,z)(y/sqrt(x^2+y^2))*(cos(F1(x,y,z))*cosh(F2(x,y,z))*pF1z(x,y,z)-x*sin(F1(x,y,z))*sinh(F2(x,y,z))*pF2z(x,y,z));
h13x = @(x,y,z)(cos(F1(x,y,z))*cosh(F2(x,y,z))*pF1x(x,y,z)-sin(F1(x,y,z))*sinh(F2(x,y,z))*pF1x(x,y,z));
h13y = @(x,y,z)(cos(F1(x,y,z))*cosh(F2(x,y,z))*pF1y(x,y,z)-sin(F1(x,y,z))*sinh(F2(x,y,z))*pF1y(x,y,z));
h13z = @(x,y,z)(cos(F1(x,y,z))*cosh(F2(x,y,z))*pF1z(x,y,z)-sin(F1(x,y,z))*sinh(F2(x,y,z))*pF1z(x,y,z));

