x = linspace(0.99, 1.01, 101);
y1 = x.^8-8.*x.^7 + 28.*x.^6-56.*x.^5+70.*x.^4-56.*x.^3 + 28.*x.^2 - 8.*x + 1;
y2 = (((((((x-8).*x+28).*x-56).*x+70).*x-56).*x+28).*x-8).*x+1;
y3 = (x-1).^8;

figure
plot(x,y2,x,y1)