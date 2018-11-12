options = optimset('Display','iter');

f = @(x)(1/sqrt(sqrt((x(1)^2+x(2)^2+x(3)^2))))*sqrt(cot(pi*sqrt(x(1)^2+x(2)^2)/sqrt(x(1)^2+x(2)^2+x(3)^2))*(1/sqrt(x(1)^2+x(2)^2+x(3)^2))*(pi^2*x(1)^2*abs(x(3))/(sqrt(x(1)^2+x(2)^2+x(3)^2))-(3*abs(x(1))/(x(1)^2+x(2)^2)))+tanh(0.5*log(x(1)^2+x(2)^2+x(3)^2)+atan(sqrt((x(1)^2+x(2)^2)/(x(3)^2)))/pi + asinh(1)-.5)*((6*x(1)^3)/((x(1)^2+x(2)^2+x(3)^2)^1.5)+pi^2*abs(x(1)*x(3))/(x(1)^2+x(2)^2+x(3)^2)))-abs(x(1));
x0 = [0.1,0.1,0.1];
x = fminsearch(f,x0,options);
disp(x);