#! /usr/bin/python

import matplotlib.pyplot as plt


from matplotlib import cm
from pylab import *
import scipy as sp
import numpy

import math

from scipy import weave
from scipy.weave import converters
import Image, ImageDraw

#######################################################################
#								      								  #
#		M	A	I	N	  ()	                                      #
#								                                      #
#######################################################################
im = Image.new("RGB", (4000, 4000), (0,0,0))


draw = ImageDraw.Draw(im)

zoom = input('Enter magnification: ')
scale = 1.0000000000/(zoom)

#maxit = int(math.pow(zoom, 1/3))*1500

step = 4000
zval = input('Enter value for x3-slice: ')
uval = input('Enter value for x4-slice: ')
lim = input('Enter escape condition: ')
d = input('Enter d for A = dx: ')
k = input('Enter k for (z^k+1/z^k)/2: ')
maxit = input('Enter maximum number of iterations: ')

xcent = input('Enter x-coordinate center: ')
ycent = input('Enter y-coordinate center: ')


hmm = 0

xval = -2.00*scale + xcent	
yval = -2.00*scale + ycent

for i in xrange(int(step)):
	
	for j in xrange(int(step)):
		
	
			
				
		code2 = """
					#include <math.h>
					#include <complex>
					using namespace std;
					
					double xtemp;
					double ytemp;
					double ztemp;
					double utemp;
					double xhat;
					double yhat;
					double zhat;
					double uhat;
					double x;
					double y;
					double z;
					double u;
					double pi = 3.1415926535897932384626433;
					double alpha;
					int sign = 0;
					int asign = 0;
					
					double nasty;
					int i = 0;
					
					
					
					
								
					for(i = 0; i < maxit; i++)
					
							{
							
							
							if(abs(xval) >= abs(yval) && abs(xval) >= abs(zval) && abs(xval) > 0.0)
							
								{
							if(uval == 0.0)
								
									{
								
									xtemp = k*(0.5)*xval/abs(xval);
									ytemp = k*(0.5)*yval/abs(xval);
									ztemp = k*(0.5)*zval/abs(xval);
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								
								else
								
									{
								
									xtemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))/pi;
									ytemp = k*atan(sqrt((xval*xval + yval*yval+zval*zval)/(uval*uval)))*(abs(yval)/abs(xval))/pi;
									ztemp = k*atan(sqrt((xval*xval + yval*yval+zval*zval)/(uval*uval)))*(abs(zval)/abs(xval))/pi;
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
									
								}
								
							else if(abs(yval) > abs(xval) && abs(yval) >= abs(zval))
							
								{
								
								if(uval == 0.0)
								
									{
								
									xtemp = k*(0.5)*xval/abs(yval);
									ytemp = k*(0.5)*yval/abs(yval);
									ztemp = k*(0.5)*zval/abs(yval);
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								
								else
								
									{
								
									xtemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(xval/abs(yval))/pi;
									ytemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(yval/abs(yval))/pi;
									ytemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(zval/abs(yval))/pi;
									ztemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								}
								
							else if(abs(zval) > abs(yval) && abs(zval) >= abs(xval))
							{
								
								if(uval == 0.0)
								
									{
								
									xtemp = k*(0.5)*xval/abs(zval);
									ytemp = k*(0.5)*yval/abs(zval);
									ztemp = k*(0.5)*zval/abs(zval);
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									
									}
								
								else
								
									{
								
									xtemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(xval/abs(zval))/pi;
									ytemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(yval/abs(zval))/pi;
									ytemp = k*atan(sqrt((xval*xval + yval*yval + zval*zval)/(uval*uval)))*(zval/abs(zval))/pi;
									ztemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								}
							
							else if(xval == yval == zval == 0.0)
							
								{
								if(uval == 0.0)
									{
									xtemp = 0.0;
									ytemp = 0.0;
									ztemp = 0.0;
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								else
									{
									xtemp = 0.0;
									ytemp = 0.0;
									ztemp = 0.0;
									utemp = k*log(sqrt(xval*xval + yval*yval + zval*zval + uval*uval));
									}
								}
							
								
							xval = xtemp;
							yval = ytemp;
							zval = ztemp;
							uval = utemp;
							
							if(xval <-1.5 || yval < -1.5 || zval < -1.5 || xval > 1.5 || yval > 1.5 || zval > 1.5)
							
								{
							
								while(xval <-1.5 || yval < -1.5 || zval < -1.5 || xval > 1.5 || yval > 1.5 || zval > 1.5)
								
									{
									if(xval < -1.5)
								
										{
										xval = xval + 2.0;
										}
									
									else if(yval < -1.5)
								
										{
										yval = yval + 2.0;
										}
									else if(xval > 1.5)
								
										{
										xval = xval - 2.0;
										}
									
									else if(yval > 1.5)
								
										{
										yval = yval - 2.0;
										}
									if(zval < -1.5)
								
										{
										zval = zval + 2.0;
										}
									if(zval > 1.5)
								
										{
										zval = zval - 2.0;
										}
									
																																								
									}	
								}
						
						sign = 1;
								
						while( abs(xval) > 0.5 || abs(yval) > 0.5 || abs(zval) > 0.5)
						
							{
							if(xval >= -1.5 && xval < -0.5)
							
								{
								xval = -1.0*xval - 1.0;
								sign = -1*sign;
								}
							
							if(yval < -0.5 && yval >= -1.5)
							
								{
								sign = -1*sign;
								yval = -1.0*yval - 1.0;
								}
							
							
							if(yval > 0.5 && yval <= 1.5)
							
								{
								sign = -1*sign;
								yval = -1.0*yval +1.0;
								}
						
														
							if(xval >= 0.5 && xval <= 1.5)
							
								{
								sign = -1*sign;
								xval = -1.0*xval + 1.0;
							
								}
							
							if(zval >= 0.5 && zval <= 1.5)
							
								{
								sign = -1*sign;
								zval = -1.0*zval + 1.0;
							
								}
							
							if(zval <= 0.5 && zval >= -1.5)
							
								{
								
								sign = -1*sign;
								zval = -1.0*zval - 1.0;
							
								}
							
							
							}
							
							if(max(abs(xtemp),max(abs(ytemp),abs(ztemp)))+abs(utemp) < 0.5)
							
									{
								
																
										alpha = 2.0*(max(abs(xtemp),max(abs(ytemp),abs(ztemp)))+abs(utemp));
										xhat = xtemp/((2.0)*(max(abs(xtemp),max(abs(ytemp), abs(ztemp)))+abs(utemp)));
										yhat = ytemp/((2.0)*(max(abs(xtemp),max(abs(ytemp), abs(ztemp)))+abs(utemp)));
										zhat = ztemp/((2.0)*(max(abs(xtemp),max(abs(ytemp), abs(ztemp)))+abs(utemp)));
									if(utemp >= 0)
										{
										sign = 1;
										uhat = utemp/((2.0)*(max(abs(xtemp),max(abs(ytemp),abs(ztemp)))+abs(utemp)));
										}
									
									else
										{
										sign = -1;
										zhat = -1.0*utemp/((2.0)*(max(abs(xtemp),max(abs(ytemp),abs(ztemp)))+abs(utemp)));
										}
								
										//now do the Drasin-sine evaluation (make sure to normalize so h fixes S^2!)
									
										if(xhat == 0.0 & yhat == 0.0 & zhat == 0.0)
										
											{
											xval = 0.0;
											yval = 0.0;
											zval = 0.0;
											
											uval = uhat + max(abs(xhat), max(abs(yhat), abs(zhat))) -0.5 + log(1+sqrt(2));
											x = 0.0;
											y = 0.0;
											z = 0.0;
											if(sign == 1)
												{
												u = alpha*cos(sqrt(xval*xval+yval*yval + zval*zval))*sinh(uval)/sqrt(2.0);
												}
												
											if(sign == -1)
												{
												u = -1.0*alpha*cos(sqrt(xval*xval+yval*yval + zval*zval))*sinh(uval)/sqrt(2.0);
												}
											
											
											}
								
										else
										
											{
								
											xval = pi*xhat*sin(max(abs(pi*xhat),max(abs(pi*yhat), abs(pi*zhat))))/(2.0*sqrt(xhat*xhat + yhat*yhat + zhat*zhat));
											yval = pi*yhat*sin(max(abs(pi*xhat),max(abs(pi*yhat), abs(pi*zhat))))/(2.0*sqrt(xhat*xhat + yhat*yhat + zhat*zhat));
											zval = pi*zhat*sin(max(abs(pi*xhat),max(abs(pi*yhat), abs(pi*zhat))))/(2.0*sqrt(xhat*xhat + yhat*yhat + zhat*zhat));
											uval = uhat + max(abs(xhat),max(abs(yhat),abs(zhat))) -0.5 + log(1+sqrt(2));
										
											x = alpha*(sin(sqrt(xval*xval+yval*yval+ zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*xval/sqrt(2.0);
											y = alpha*(sin(sqrt(xval*xval+yval*yval+ zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*yval/sqrt(2.0);
											z = alpha*(sin(sqrt(xval*xval+yval*yval+ zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*zval/sqrt(2.0);
											if(sign == 1)
											{
											u = alpha*cos(sqrt(xval*xval+yval*yval +zval*zval))*sinh(uval)/sqrt(2.0);
											}
											else if(sign == -1)
											{
											z = -1.0*alpha*cos(sqrt(xval*xval+yval*yval + zval*zval))*sinh(uval)/sqrt(2.0);
											}
								
										xval = x;
										yval = y;
										zval = z;
										uval = u;
								
										}
									
									
								
									}
								
								else if(max(abs(xtemp),max(abs(ytemp), abs(ztemp)))+abs(utemp) >= 0.5)
							
									{
								
									if(utemp >= 0.0)
									
										{
										sign = 1;
										}
										
									else 
										{
										sign = -1;
										}
									
																	
										
								if(xtemp == 0.0 && ytemp == 0.0 && ztemp == 0.0)
										
											{
											xval = 0.0;
											yval = 0.0;
											zval = 0.0;
											if(sign == 1) 
												{
												uval = utemp -0.5 + log(1+sqrt(2));
												}
											else if(sign == -1)
												{ 
												uval = -1.0*utemp -0.5 + log(1+sqrt(2));
												}
											
											x = 0.0;
											y = 0.0;
											z = 0.0;
											if(sign == 1) {u = cos(sqrt(xval*xval+yval*yval + zval*zval))*sinh(uval)/sqrt(2.0);}
											else if(sign == -1) {u = -1.0*cos(sqrt(xval*xval+yval*yval+ zval*zval))*sinh(uval)/sqrt(2.0);}
											}
									
										else
										
											{
											xval = pi*xtemp*sin(max(abs(pi*xtemp),max(abs(pi*ytemp), abs(pi*ztemp))))/(2.0*sqrt(xtemp*xtemp + ytemp*ytemp + ztemp*ztemp));
											yval = pi*ytemp*sin(max(abs(pi*xtemp),max(abs(pi*ytemp), abs(pi*ztemp))))/(2.0*sqrt(xtemp*xtemp + ytemp*ytemp + ztemp*ztemp));
											zval = pi*ztemp*sin(max(abs(pi*xtemp),max(abs(pi*ytemp), abs(pi*ztemp))))/(2.0*sqrt(xtemp*xtemp + ytemp*ytemp + ztemp*ztemp));
											if(sign == 1) {uval = utemp + max(abs(xtemp),max(abs(ytemp), abs(ztemp))) -0.5 + log(1+sqrt(2.0));}
											else if (sign==-1) {uval = -1.0*utemp + max(abs(xtemp),max(abs(ytemp), abs(ztemp))) -0.5 + log(1+sqrt(2.0));}
											
											x = (sin(sqrt(xval*xval+yval*yval+zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*xval/sqrt(2.0);
											y = (sin(sqrt(xval*xval+yval*yval+zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*yval/sqrt(2.0);
											z = (sin(sqrt(xval*xval+yval*yval+zval*zval))/sqrt(xval*xval+yval*yval+zval*zval))*cosh(uval)*zval/sqrt(2.0);
											if(sign ==1) {u = cos(sqrt(xval*xval+yval*yval+zval*zval))*sinh(uval)/sqrt(2.0);}
											else if(sign == -1) {z = -1.0*cos(sqrt(xval*xval+yval*yval+zval*zval))*sinh(uval)/sqrt(2.0);}
											
											}
										xval = x;
										yval = y;
										zval = z;
										uval = u;
										
										
										}
						
						
							if(sqrt(xval*xval+yval*yval+zval*zval + uval*uval) > lim)
							
								{
								
								break;
																
								}
							}
								
							
									
							
						
								
					return_val = (i-maxit);
										
								
					"""
		
		checkset = int(weave.inline(code2, ['xval','yval','zval', 'uval', 'maxit','lim', 'd', 'k'], type_converters=converters.blitz))
		
		#print checkset
	
		if checkset == 0:
					
				
			draw.point((j,i), fill=(0,0,0))


		elif checkset == -maxit:
			
			draw.point((j,i), fill=(0,0,255))
			
		else:
		
			red, g, b, = 0, 0, 0
			check = -1*checkset
			
			
			red = checkset%139 + checkset%109 + checkset%7
			b = checkset%131 + checkset%107 + checkset%17
			g = checkset%23 + checkset%31 + checkset%53 + checkset%113 + checkset%2 + checkset%3 + checkset%17 + checkset%13
			draw.point((j, i), fill=(red,g,b)) 
			
			
		xval += 4.0*scale/step
		
		
	xval = -2.00*scale + xcent
	yval += 4.0*scale/step
	print yval
	
del draw

filename = "QRLattesX" + str(zoom) + "z=" + str(zval) + "lim=" + str(lim) +  "center=(" + str(xcent) + "," + str(ycent) + "," + str(zval) + ").png"

im.save(filename, "PNG")	
