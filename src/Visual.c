#include "all.h"



float rndf(float ub=1,float lb=0,int accr=100)
{
 return lb + (ub-lb)*((float)(rand()%100)/100) ;
}





void text(float x, float y, GLfloat scale, char* format, ...)
{

    va_list args;
    char buffer[255], *p;
    GLfloat font_scale = 119.05 + 33.33;

    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);



 x*=wd*.5; 
 y=((1-y*.5)*ht) - (scale*.667) ;
 



    glMatrixMode(GL_PROJECTION);
    glPushMatrix();

   gluOrtho2D(0, wd, 0, ht);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(x, y, 0.0);
    glScalef(scale/font_scale, scale/font_scale, scale/font_scale);
// printf("%f,%f\a\n",x,y);

  glLineWidth(2.5);

    for(p = buffer; *p; p++)
     glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);


 //   glPopAttrib();

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}







void boldline(float x1, float y1,float x2, float y2,float pt)
{
  x1-=1 ; y1=1-y1; 
  x2-=1 ; y2=1-y2;
  pt/=2 ;
  
  
 glLineWidth(500*pt);
 glBegin(GL_LINES);
 glVertex2f(x1,y1);
 glVertex2f(x2,y2);
 glEnd();
 
/* 
 glBegin(GL_POLYGON);
 glVertex2f(x1-pt,y1-pt);
 glVertex2f(x1+pt,y1+pt);
 
 glVertex2f(x2+pt,y2+pt);
 glVertex2f(x2-pt,y2-pt);
 glEnd();
 */
}











void rect(float x,float y,float w,float h)
{
 x-=1 ; y=1-y; h*=-1;
 glBegin(GL_QUAD_STRIP);

 glVertex2f(x,y);
 glVertex2f(x+w,y);
 glVertex2f(x+w,y+h);
 glVertex2f(x,y+h);
 
 glEnd();
}




void grid(int m,int n,float x,float y,float w,float h,float b)
{
 register int i,j ;
 
 for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
   	rect(x+j*(w+b),   y+ i*(h+b) ,w,h);
   }
  }
}


void table(int m,int n,float x,float y,float sc,float sx,float sy)
{
 register float i,j ;
 int k;
 for(i=0;i<n;i++)
  {
   for(j=0;j<m;j++)
   {
  
    
    if(((char (*)[n])s)[(int)i][(int)j] == stdsyms[0])
		    glColor3fv(stdcolor[0].v);   
    else
     for(k=0;k<pln;k++)
	  if(((char (*)[n])s)[(int)i][(int)j]==gmplr[k]->sym)
	   {
	    glColor3fv(gmplr[k]->color);
	    break;
	   }

	text(x+j*sx,   y+ i*sy ,sc,"%c",((char (*)[n])s)[(int)i][(int)j]);
//   text(x+(j+.5)*(cw+bd),   y+ i*sy ,sc,"%c",((char (*)[n])s)[(int)i][(int)j]);
   }
  }
}











void gbdisplay()
{
 
 printf("display is Called\n"); 
 glClear( GL_COLOR_BUFFER_BIT);
 
 
 
 glColor3f(0, 0, 1);
 grid(n,n,gx,gy, cw, ch,bd);
 
 

 
 


 glColor3f(1, 1, 0);
  if(pst>0)
  text(0.1,0.1,25,"Turn for %s :",gmplr[(pst-1)%pln]->name ); 
 else
   if(pst==0){ text(0.1,0.1,25,"Its a Draw");  }
   else{
   	
        text(0.1,0.1,25,"%s won!!!",gmplr[(-pst-1)%pln]->name );
  
//  		printf("\a\a\a%d_%d_%d_%d\n",vj1,vi1,vj2,vi2);

	    glColor3f(.7, 1, 1);
  		boldline(gx+(vj1)*(cw+bd)+.5*cw,
		    	 gy+(vi1)*(ch+bd)+.5*ch,
				 gx+(vj2)*(cw+bd)+.5*cw,
			 	 gy+(vi2)*(ch+bd)+.5*ch,
				  .05*3/n ); 		
				 
       }
 
 
 
// glColor3f(0, 0, 0);
 table(n,n,
  	   gx+.35*cw,
	   gy+.27*ch,
	   50*(5/(float)n),
	   (cw+bd),
	   (ch+bd)			);
 

  
/**************/
 

 glutSwapBuffers();
}











void ttdisplay()
{
 glClear( GL_COLOR_BUFFER_BIT);
 
 
 GLubyte rasters[24] = {
 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
 0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
 0xff, 0xc0, 0xff, 0xc0};
 
 glColor3f (1.0, 1.0, 1.0);
 glRasterPos2i (0, 0);
 glBitmap(200,100,100,160,.5,.9,rasters);
 
 

  //glColor3f((float)(rand()%100)/100,(float)(rand()%100)/100,(float)(rand()%100)/100);
  glColor3f(rndf(),rndf(1,.5),rndf());
  sertext(.05,.6,60,"Mega Tic Tac Toe");
 
 
 
 
 glutSwapBuffers();

}

 
 
 
 
void display()
{
// printf("Display is called|\n");
// glutSetWindow(main_win);
 glShadeModel(GL_SMOOTH);
 initgvars();
 switch(gmflag)
 {
  case 0: glClearColor(0.7f, 0.7f, 0.7f, 1.0f); ttdisplay();  break;
  case 1: glClearColor(0.7f, 0.5f, 0.5f, 0.0f); gbdisplay() ; break;
  case 3: glClearColor(0.5f, 0.3f, 0.3f, 0.0f); sdis(); break;

 }
 
 if(!gmflag)
   GLUI_Master.set_glutIdleFunc(stidle);
 else GLUI_Master.set_glutIdleFunc(NULL);
}
 
 

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
