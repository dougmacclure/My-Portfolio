#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <float.h>
#include <iostream>
#include <gl.h>
#include <glu.h>
#include <glaux.h>



#define MANDELBROT 0 // set
#define JULIA      1
#define ITERATIONS 2 // method
#define MAGNITUDE  3
#define REAL       4
#define IMAGINARY  5
#define RED        6 // color
#define YELLOW     7
#define GREEN      8
#define CYAN       9
#define BLUE       10
#define MAGENTA    11
#define WHITE      12
#define QUIT       13
#define ZOOM       14  // zoom
#define ZOOM_IN    15  // zoom in
#define ZOOM_OUT   16  // zoom out

#define KEY_ESC     27      /* ascii value for the escape key */


int set = MANDELBROT;
int nx, ny, imax=60, method=ITERATIONS, color=RED, hue=0, zoom = 1;
double x0=-0.5, y0a=0, dpi, power=2, xc=0.5, yc=0.05;
int ok=0;

double x1=-2.5, x2=1.5, y1f=-2, y2=2, zx, zy, ***screen;


double abs2(double x) {return (x>0)?x:(-x);}
double min(double x1, double x2) {return (x1<x2)?x1:x2;}
double max(double x1, double x2) {return (x1>x2)?x1:x2;}
double rem(double x1, double x2) {return x1-x2*(int)(x1/x2);}

void pixel(int x, int y, int r, int g, int b) {
        glColor3f(r/256.0, g/256.0, b/256.0);
        glVertex2i(x, y);
}



GLdouble xmin = -1.5, xmax = +1;      /* edges of world "window" */
GLdouble ymin = -1.25, ymax = +1.25;

GLint viewportWidth, viewportHeight;  /* size of "viewport" */

void reshape(int w, int h) {
        glViewport(0,0, w,h);
        viewportWidth = w;
        viewportHeight = h;
}

#define NUM_COLORS 1000
static GLfloat colorMap[NUM_COLORS+1][3];

void initColorMap(void) {
        GLfloat gray, dgray = 1.0/NUM_COLORS;
        int i;
        for (i = 0, gray = 1.0; i < NUM_COLORS; i++, gray -= dgray) {
                colorMap[i][0] = gray;
                colorMap[i][1] = gray*gray;
                colorMap[i][2] = gray*gray*gray;
        }
}

int escapeDistance(GLdouble x, GLdouble y, int maxDist) {
        int iters = 0;
        GLdouble a = x, b = y;
        while (a*a + b*b < 2*2 && iters < maxDist) {
                GLdouble a_old = a;
                a = a*a - b*b + x;
                b = 2*a_old*b + y;
                iters++;
        }
        return iters;;
}

#define DETAILED_QUAD_SIZE 1
#define FAST_QUAD_SIZE 10

#define DETAILED_ITERS 1000
#define FAST_ITERS 1000

void mandelbrot(int quadSize, int maxIters) {
        int W = viewportWidth/quadSize;
        int H = viewportHeight/quadSize;
        GLdouble dx = (xmax - xmin)/(W-1);
        GLdouble dy = (ymax - ymin)/(H-1);
        GLdouble x,y;
        int r, c;
        for (r = 0, y = ymax; r < H; r++, y -= dy) {
                glBegin(GL_QUAD_STRIP);
                for (c = 0, x = xmin; c < W; c++, x += dx) {
                        int dist = escapeDistance(x,y, maxIters);
                        glColor3fv(colorMap[dist*NUM_COLORS/maxIters]);
                        glVertex2d(x,y);
                        dist = escapeDistance(x,y-dy, maxIters);
                        glColor3fv(colorMap[dist*NUM_COLORS/maxIters]);
                        glVertex2d(x,y-dy);
                }
                glEnd();
        }
}

GLboolean fastDraw = GL_FALSE;

void display(void) {

        int unbounded = 0;
        int r=0, g=0, b=0, i, n=(int)power/2-((rem(power,2)!=0)?1:0);
        double x=0, y=0, xc1=xc, yc1=yc, dx=1/(dpi), x1=x0-0.5*nx/(dpi), x2=x0+0.5*nx/dpi, y1a=y0a-ny*dx/2, y2=y0a+ny*dx/2;
        double t1=max(abs2(x1),abs2(x2)), t2=max(abs2(y1a),abs2(y2)), zm=sqrt(t1*t1+t2*t2);
        int iy,ix,j; // supposed to go in for loop
        double r1, g1, b1;
        //char txt[100];





        switch(color) { // calculations
                case RED:     hue=0  ; break;
                case YELLOW:  hue=60 ; break;
                case GREEN:   hue=120; break;
                case CYAN:    hue=180; break;
                case BLUE:    hue=240; break;
                case MAGENTA: hue=300; break;
        }
        r1=max(0,min(1,abs2(rem(6-hue/60.0,6)-3)-1));
        g1=max(0,min(1,abs2(rem(8-hue/60.0,6)-3)-1));
        b1=max(0,min(1,abs2(rem(10-hue/60.0,6)-3)-1));
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);

        for (iy=0; iy<=ny; ++iy) {
                if (set==MANDELBROT) yc1=y2-iy*dx;
                for (ix=0; ix<=nx; ++ix) {
                        if (set==JULIA) {x=x1+ix*dx; y=y2-iy*dx;} else {xc1=x1+ix*dx; x=0; y=0;}
                        unbounded=0;
                        for (i=0; (i<imax)&&(!unbounded); ++i) {
                                if (power>=2 && power<=25 && rem(power,1)==0) {
                                        for (j=0; j<n; ++j) {t1=x*x-y*y; y=2*x*y; x=t1;}; // z^2
                                        if (rem(power,2)!=0) {t1=x*(x*x-3*y*y); y=y*(3*x*x-y*y); x=t1;} // z^3
                                }
                                else {t1= atan2(y,x); t2= pow(x*x+y*y,power/2.0); x=t2* cos(power*t1); y=t2* sin(power*t1);} // z^n

                                x+=xc1; y+=yc1;
                                if (x*x+y*y>=4.0) unbounded=1;
                        }
                        if (unbounded) {
                                if (method==ITERATIONS) t1=1.0*i/imax;
                                else if (method==MAGNITUDE) t1= min(1, sqrt(x*x+y*y)/zm);
                                else t1= min(1, abs2((method==REAL)?x:y)/zm);
                                if (color==WHITE) {r=255*t1; g=r; b=r;}
                                else { // Note: brightness=(int)t1*100;
                                        r = 255*((t1>0.5)?t1*r1+(1-t1*r1)*(2*t1-1):2*t1*r1);
                                        g = 255*((t1>0.5)?t1*g1+(1-t1*g1)*(2*t1-1):2*t1*g1); 
                                        b = 255*((t1>0.5)?t1*b1+(1-t1*b1)*(2*t1-1):2*t1*b1); 
                                }
                                pixel(ix,iy,r,g,b);
                        }
                }
        }

        glEnd();
        glColor3f(1,1,1);
        //sprintf(txt, "%s Set: %f", (set == JULIA) ? "Julia" : "Mandelbrot", t1);

        //text(10, 10, txt);
        glutSwapBuffers();

}

GLboolean dragMouse = GL_FALSE;  /* currently dragging mouse? */
GLboolean zoomMouse = GL_FALSE;  /* currently zoom mouse? */
int mousex, mousey;              /* last mouse position during drag */

void mouse(int button, int state, int x, int y) {
        if (state == GLUT_DOWN ) {
                if (button == GLUT_LEFT_BUTTON) {
                        dragMouse = fastDraw = GL_TRUE;
                        glutSetCursor(GLUT_CURSOR_CROSSHAIR);     
                        mousex = x;
                        mousey = y;
                } else if (button == GLUT_RIGHT_BUTTON) {
                        zoomMouse = fastDraw = GL_TRUE;
                        glutSetCursor(GLUT_CURSOR_UP_DOWN);       
                        mousey = y;
                }
        } else if (state == GLUT_UP && (dragMouse || zoomMouse)) {
                dragMouse = zoomMouse = fastDraw = GL_FALSE;
                glutPostRedisplay();   /* request a redisplay */
        }
}

#define UNITS_PER_PIXEL 0.01  /* translation per pixel at zoom scale = 1.0 */

GLdouble unitsPerPixel = UNITS_PER_PIXEL;
GLdouble zoomsPerPixel = 1.0/100;  /* scale = exp(z*zoomsPerPixel) */

void mouseMotion(int x, int y) {
        if (dragMouse) {
                GLdouble dx = (x - mousex)*unitsPerPixel;
                GLdouble dy = (y - mousey)*unitsPerPixel;
                xmin -= dx;
                xmax -= dx;
                ymin += dy;
                ymax += dy;
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                glOrtho(xmin, xmax, ymin, ymax, -1,+1);
                mousex = x;
                mousey = y;    
                glutPostRedisplay();   /* request a redisplay */      
        } else if (zoomMouse) {
                GLdouble scale = exp((y - mousey)*zoomsPerPixel);
                GLdouble cx = 0.5*(xmin + xmax);
                GLdouble cy = 0.5*(ymin + ymax);
                xmin = (xmin - cx)*scale + cx;
                xmax = (xmax - cx)*scale + cx;
                ymin = (ymin - cy)*scale + cy;
                ymax = (ymax - cy)*scale + cy;
                glMatrixMode(GL_PROJECTION);
                glLoadIdentity();
                glOrtho(xmin, xmax, ymin, ymax, -1,+1);
                mousey = y;
                unitsPerPixel *= scale;
                glutPostRedisplay();   /* request a redisplay */      
        }
}


#define ESC 27

void keyboard(unsigned char key, int x, int y) {
        if (key == ESC) exit(0);
}

int main(int argc, char *argv[]) {


        nx=1200; ny=nx*3/4;

        dpi=(nx/3);

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
        glutInitWindowSize(nx, ny);
        glutInitWindowPosition(550, 150);


        glutCreateWindow("Mandelbrot");
        gluOrtho2D(0, nx, 0, ny);
        glutKeyboardFunc( keyboard );
        glutMouseFunc(mouse);
        glutMotionFunc(mouseMotion);
        glutDisplayFunc(display);


        glMatrixMode(GL_MODELVIEW);           
        glMatrixMode(GL_PROJECTION);

        glClearColor(0, 0, 0, 1);



        glutMainLoop();
        return 0;
}
