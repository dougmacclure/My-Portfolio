
import numpy
import math
from decimal import *
from scipy import weave
from scipy.weave import converters
import Image, ImageDraw

#######################################################################
#								      								  #
#		M	A	I	N	  ()	                                      #
#								                                      #
#######################################################################


zoom = input('Enter magnification: ')
scale = 1.0000000000/(zoom)

maxit = int(math.pow(zoom, 1/3))*1500

realcent = input('Enter real coordinate for center: ')
imagcent = input('Enter imag coordinate for center: ')


centre = complex(realcent, imagcent)

c = ((-2.0000000000 + 2.0000000000j)*scale + centre)

im = Image.new("RGB", (4000, 4000), (0,0,0))

draw = ImageDraw.Draw(im)



kay = input('Enter value for K: ') 
theta = input('Enter value for theta in e^(i*theta): ')

mndmtx = []
for i in xrange(4000):
	
	for j in xrange(4000):
		
		realval = c.real
		imagval = c.imag
		
		#Our support function will determine whether the fixed point is a 1-saddle point, 2-
		#2- repelling pt & 3- attracting pt
		support = """
					#include <complex>
					#include <math.h>
					using namespace std;
					
					int eigenvalue(double &X, double &Y, double &K, double &theta)
					
					{
					
					
																				
										complex<double>x = X;
										complex<double>y = Y;
										complex<double>Ux = 2.0*(K*K-1.0)*x*cos(2.0*theta)/2.0 + 2.0*(K+1.0)*(K+1.0)*x/4.0 + 2.0*(K-1.0)*(K-1.0)*(cos(4.0*theta))*x/4.0 + 2.0*(K-1.0)*(K-1.0)*y*sin(4.0*theta)/4.0;
										complex<double>Uy = 2.0*(K*K-1.0)*y*cos(2.0*theta)/2.0 - 2.0*(K+1.0)*(K+1.0)*y/4.0 - 2.0*(K-1.0)*(K-1.0)*(cos(4.0*theta))*y/4.0 + 2.0*(K-1.0)*(K-1.0)*x*sin(4.0*theta)/4.0;
										complex<double>Vx = 2.0*(K*K-1.0)*x*sin(2.0*theta)/2.0 + 2.0*(K+1.0)*(K+1.0)*y/4.0 + 2.0*(K-1.0)*(K-1.0)*(sin(4.0*theta))*x/4.0 - 2.0*(K-1.0)*(K-1.0)*y*cos(4.0*theta)/4.0;
										complex<double>Vy = 2.0*(K*K-1.0)*y*sin(2.0*theta)/2.0 + 2.0*(K+1.0)*(K+1.0)*x/4.0 - 2.0*(K-1.0)*(K-1.0)*(sin(4.0*theta))*y/4.0 - 2.0*(K-1.0)*(K-1.0)*x*cos(4.0*theta)/4.0;
										complex<double>e_1 = (Vy + Ux + sqrt((Vy + Ux)*(Vy + Ux) - 4.0*(Ux*Vy -Uy*Vx)))/2.0;
										complex<double>e_2 = (Vy + Ux - sqrt((Vy + Ux)*(Vy + Ux) - 4.0*(Ux*Vy -Uy*Vx)))/2.0;
										
										double eval1 = abs(e_1);
										double eval2 = abs(e_2);
										
										if(eval1 < 1 && eval2 < 1) return 3;
										else if(eval1 > 1 && eval2 > 1) return 2;
										else if(eval1 > 1 && eval2 < 1 || eval1 < 1 && eval2 > 1)  return 1;
										else return 0;
															
					}	
		
		
		"""
		
		code1 = """
					#include <math.h>
					#include <complex>
					using namespace std;
																			
					double K = kay;
										
					complex<double> odir(cos(2.0*theta), sin(2.0*theta));
					complex<double> dir(cos(4.0*theta), sin(4.0*theta));
					complex<double> val;
					complex<double> z;
					complex<double>Z = conj(z);
														
					double a = ((K*K - 1.0)*cos(2.0*theta)/2.0 + (K+1.0)*(K+1.0)/4.0 + (K-1.0)*(K-1.0)*cos(4.0*theta)/4.0);
					double d_0 = ((K-1.0)*(K-1.0)*sin(4.0*theta)/2.0);
					double d_1 = ((K*K-1.0)*cos(2.0*theta)/2.0 - (K+1.0)*(K+1.0)/4.0 - (K-1.0)*(K-1.0)*cos(4.0*theta)/4.0);
					double e = (((K*K-1.0)/2.0)*(1.0+((2.0*d_0*d_0-4.0*a*d_1)/(4.0*a*a))*sin(2.0*theta)) - ((K+1.0)*(K+1.0)*d_0)/(4.0*a) + (((K-1.0)*(K-1.0)/4.0)*(d_0*d_0-2.0*a*d_1)/(2.0*a*a))*sin(4.0*theta) + (d_0)*cos(4.0*theta)*(K-1.0)*(K-1.0)/4.0);
					double f = ((((K*K-1.0)/2.0)*((-d_0/(a*a))*sin(2.0*theta))) + ((K+1.0)*(K+1.0)/(2.0*a)) + ((K-1.0)*(K-1.0)/4.0)*(-d_0/(a*a))*sin(4.0*theta) - 1.0 - (K-1.0)*(K-1.0)*cos(4.0*theta)/a);
					double g = ((((K*K-1.0)/2.0)*(1.0-2.0*a*realval)/(2.0*a*a))*sin(2.0*theta) + ((K-1.0)*(K-1.0)/4.0)*((1.0-2.0*a*realval)/(2.0*a*a))*sin(4.0*theta) + imagval);
					double h = ((((-d_0)/(2.0*a*a))*((K*K-1.0)/2.0)*sin(2.0*theta)) + ((K+1.0)*(K+1.0))/(4.0*a) - ((K-1.0)*(K-1.0)/4.0)*(d_0/(2.0*a*a))*sin(4.0*theta) - (K-1.0)*(K-1.0)*cos(4.0*theta)/(4.0*a));
					double j = (((K*K-1.0)/2.0)*sin(2.0*theta)*(1.0/(2.0*a*a)) + ((K-1.0)*(K-1.0)/4.0)*(1.0/(2.0*a*a))*sin(4.0*theta));
					double l = (e*e - (d_0)*(d_0)*h*h + 4.0*a*(d_1)*h*h);
					double m = (2.0*e*f + 8.0*a*(d_1)*h*j- 2.0*d_0*d_0*h*j+2.0*d_0*h*h );
					double n = (2.0*e*g + f*f + 4.0*a*(d_1)*j*j +4.0*a*h*h*realval- d_0*d_0*j*j + 4.0*d_0*h*j - h*h);
					double o = (2.0*f*g + 8.0*a*h*j*realval + 2.0*d_0*j*j - 2.0*h*j);
					double p = (g*g + 4.0*a*j*j*realval - j*j);
					double q = (pow(2.0,1.0/3.0)*((n*n)/(l*l)-3.0*((m*o)/(k*l*l))+12.0*p/l));
					double s = (2.0*(n*n*n)/(l*l*l) - 9.0*(m*n*o)/(l*l*l)+27.0*(o*o)/(l*l) + 27.0*(m*m*p)/(l*l*l) - 72.0*(n*p)/(l*l));
					double r = (2.0*(n*n*n)/(l*l*l)-9.0*m*n*o/(l*l*l)+(27.0*o*o)/(l*l)+27.0*(m*m*p)/(l*l*l) - 72*((n*p)/(l*l))+sqrt(-4.0*pow(((n*n/(l*l))-3.0*(m*o)/(l*l)+12.0*(p/l)),3.0)+s*s));
					double B = (1.0/2.0)*(sqrt((m*m)/(4.0*l*l)-2.0*n/(3.0*l)+q/(3.0*pow(r, 1.0/3.0))+pow(r, 1.0/3.0)/(pow(54.0, 1.0/3.0))));
					double C = ((m*m)/(2.0*l*l) - 4.0*n/(3.0*l)-q/(3.0*pow(r, 1.0/3.0))-pow(r/54.0, 1.0/3.0));
					double D = (-(m*m*m)/(l*l*l)+4.0*(m*n)/(l*l)-8.0*(o/l));
					double E = (sqrt((m*m)/(4.0*l*l) - 2.0*n/(3.0*l)+q/(3*pow(r, 1.0/3.0))+(pow(r/54.0, 1.0/3.0))));
					
					double y_1 = -m/(4.0*l) - B - (1.0/2.0)*sqrt(C-D/(4.0*E));
					double y_2 = -m/(4.0*l) - B + (1.0/2.0)*sqrt(C-D/(4.0*E));
					double y_3 = -m/(4.0*l) + B - (1.0/2.0)*sqrt(C+D/(4.0*E));
					double y_4 = -m/(4.0*l) + B + (1.0/2.0)*sqrt(C+D/(4.0*E));
					double b_1 = ((K-1.0)*(K-1.0)*sin(4.0*theta)*(y_1)/2.0) - 1.0;
					double b_2 = ((K-1.0)*(K-1.0)*sin(4.0*theta)*(y_2)/2.0) - 1.0;
					double b_3 = ((K-1.0)*(K-1.0)*sin(4.0*theta)*(y_3)/2.0) - 1.0;
					double b_4 = ((K-1.0)*(K-1.0)*sin(4.0*theta)*(y_4)/2.0) - 1.0;
					double c_1 = (((K*K-1.0)*(y_1)*(y_1)*(cos(2*theta)))/2.0 - ((K+1.0)*(K+1.0)*(y_1)*(y_1))/4.0-((K-1.0)*(K-1.0)*(y_1)*(y_1)*cos(4.0*theta))/4.0 + realval);
					double c_2 = (((K*K-1.0)*(y_2)*(y_2)*(cos(2*theta)))/2.0 - ((K+1.0)*(K+1.0)*(y_2)*(y_2))/4.0-((K-1.0)*(K-1.0)*(y_2)*(y_2)*cos(4.0*theta))/4.0 + realval);
					double c_3 = (((K*K-1.0)*(y_3)*(y_3)*(cos(2*theta)))/2.0 - ((K+1.0)*(K+1.0)*(y_3)*(y_3))/4.0-((K-1.0)*(K-1.0)*(y_3)*(y_3)*cos(4.0*theta))/4.0 + realval);
					double c_4 = (((K*K-1.0)*(y_4)*(y_4)*(cos(2*theta)))/2.0 - ((K+1.0)*(K+1.0)*(y_4)*(y_4))/4.0-((K-1.0)*(K-1.0)*(y_4)*(y_4)*cos(4.0*theta))/4.0 + realval);
					
					double x_1_1 = (-b_1+sqrt((b_1)*(b_1)-4.0*a*(c_1)))/(2*a);
					double x_1_2 = (-b_1-sqrt((b_1)*(b_1)-4.0*a*(c_1)))/(2*a);
					double x_2_1 = (-b_2+sqrt((b_2)*(b_2)-4.0*a*(c_2)))/(2*a);
					double x_2_2 = (-b_2-sqrt((b_2)*(b_2)-4.0*a*(c_2)))/(2*a);
					double x_3_1 = (-b_3+sqrt((b_3)*(b_3)-4.0*a*(c_3)))/(2*a);
					double x_3_2 = (-b_3-sqrt((b_3)*(b_3)-4.0*a*(c_3)))/(2*a);
					double x_4_1 = (-b_4+sqrt((b_4)*(b_4)-4.0*a*(c_4)))/(2*a);
					double x_4_2 = (-b_4-sqrt((b_4)*(b_4)-4.0*a*(c_4)))/(2*a);
					
					int issaddle = 0;
					
					if(E == 0)
						{
						
						cout << "error";
											
						
						}
					
					
					if(!(isnan(x_1_1))&&!(isnan(y_1))) 
					
						{
						
						int retval = eigenvalue(x_1_1, y_1, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}
									
					if(!(isnan(x_1_2))&&!(isnan(y_1))) 
					
						{
						
						int retval = eigenvalue(x_1_2, y_1, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}
					if(!(isnan(x_2_1))&&!(isnan(y_2))) 
					
						{
						
						int retval = eigenvalue(x_2_1, y_2, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}	
					if(!(isnan(x_2_2))&&!(isnan(y_2))) 
					
						{
						
						int retval = eigenvalue(x_2_2, y_2, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}			
					if(!(isnan(x_3_1))&&!(isnan(y_3))) 
					
						{
						
						int retval = eigenvalue(x_3_1, y_3, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}
									
					if(!(isnan(x_3_2))&&!(isnan(y_3))) 
					
						{
						
						int retval = eigenvalue(x_3_2, y_3, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}
					if(!(isnan(x_4_1))&&!(isnan(y_4))) 
					
						{
						
						int retval = eigenvalue(x_4_1, y_4, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}							
						
					if(!(isnan(x_4_2))&&!(isnan(y_4))) 
					
						{
						
						int retval = eigenvalue(x_4_2, y_4, K, theta);		
						if(retval == 1) issaddle = 1;
						
						}							
						
					return_val = issaddle;
						
					"""
					
		checksaddle = weave.inline(code1, ['kay', 'theta', 'realval', 'imagval'], type_converters=converters.blitz, support_code=support)
		
					
					
		code2 = """
					#include <math.h>
					#include <complex>
					using namespace std;
					double lim;
					double K = kay;
					
					if(K >= 1.00)
						lim = 2;
						
					if(K < 1.00 && K > 0.00)
						lim = 2/(K*K);
					
					complex<double> odir(cos(2*theta), sin(2*theta));
					complex<double> dir(cos(4*theta), sin(4*theta));
					complex<double> val;
					complex<double> z;
					complex<double>Z = conj(z);
														
					val = complex<double>(realval, imagval);
					z = complex<double>(0.0, 0.0);
					int i = 0;
					if(abs(val) < lim)
					
						{
					
						for(i = 0; i < maxit; i++)
					
							{
						
								z = ((z*z*(K*K + 2.00*K + 1.00)/4.00) + (2.000*z*conj(z)*odir*(K*K - 1.00)/4.00) + (dir*conj(z)*conj(z)*(K*K-2.00*K+1.00)/4.00)) + val;
								i++;
								if(i ==maxit) break;
								if(abs(z) > lim) break;
						
							}
							
						}
					
					else i = 0;
					
					return_val = (i-maxit);
										
								
					"""
		
		checkset = int(weave.inline(code2, ['kay', 'theta', 'realval', 'imagval', 'maxit'], type_converters=converters.blitz))
		
					
		
		if checkset == 0:
			#pt = Point(j, i)
			#pt.setFill('black')
			#pt.draw(win)
			if checksaddle == 1:
				
				#print "saddle point at: ", c
				draw.point((j, i), fill=(255, 255, 255)) 

			else:
				
				draw.point((j,i), fill=(0,0,0))


		elif checkset == -maxit:
			
			if checksaddle == 1:
				
				#print "saddle point at: ", c
				draw.point((j,i), fill=(0,0,0))
			
			else:
			
				draw.point((j,i), fill =(0, 0, 255))

		else:
		
			r, g, b, = 0, 0, 0
			check = -1*checkset
			
			if checksaddle == 1:
				
				#print "saddle point at: ", c
				r = checkset%31 + checkset%41 + checkset%67 + checkset%109 + checkset%7
				b = checkset%79 + checkset%23 + checkset%29 + checkset%107 + checkset%17
				g = checkset%59 + checkset%53 + checkset%113 + checkset%17 + checkset%13
				
				
			else:
	
			
				r = checkset%139 + checkset%109 + checkset%7
				b = checkset%131 + checkset%107 + checkset%17
				g = checkset%23 + checkset%31 + checkset%53 + checkset%113 + checkset%2 + checkset%3 + checkset%17 + checkset%13
			draw.point((j, i), fill=(r,g,b)) 

		
			
			
		c = c + (0.0010000000+0.0000000000j)*scale
		
		#print c

	c = c - ((4000)*(scale)*0.001 + (scale)*(0.001j))


del draw

im.save("M(K,T)saddlepts4000x4000.png", "PNG")	




 


