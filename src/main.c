#include "all.h"


int main_win;
int mainmenu,gmmenu,sermenu;

GLUI *glui[4]={NULL,NULL,NULL,NULL}  ;
GLUI *sui;

int gmflag=0;
int server=0;

int n=5,pln=3,K=3,pltrn=1;


float wd,ht,asr;

float gx=0.05,gy=0.35,bd=.05 ;
float cw,ch;
float px,py;
int pst,   vi1,vi2,vj1,vj2;


char *s;
char ttl[85];

char **plr;

player **gmplr ;

struct lscolor stdcolor[] = {
			     "Black",{0, 0, 0},
			     "Lime",{0, 1, 0},
		   	     "Orange",{1, .3, 0},
			     "Yellow",{1, 1, 0},
		   	     "Magenta",{1, 0, 1}
} ;

int totalclr=(sizeof(stdcolor)/sizeof(*stdcolor))-1;
char stdsyms[]="?OXZIABCDEFGHJKL";
int totalsym=(sizeof(stdsyms)/sizeof(*stdsyms))-2;



/*
char plr[][25]=
			{
			 "Player 1",
			 "Player 2"
			}			;
*/






int   main(int argc,char **argv)
{
// if(getchar()=='Y')sprintf(serroot,"http://localhost");
 
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE) ;
 
 
 glutInitWindowSize(512,512);
 main_win=glutCreateWindow(ttl);
 
  
   
  
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.7f, 0.5f, 0.5f, 0.0f);

  stgame();
  ginit();
// sermain(1);
// GLUI_Master.set_glutDisplayFunc(display);
// GLUI_Master.set_glutReshapeFunc(myGlutReshape);
// glutFullScreen();
// glutDisplayFunc(sdis);


 //glutKeyboardFunc(keyboard);
 GLUI_Master.set_glutKeyboardFunc(keyboard);
 GLUI_Master.set_glutMouseFunc(mouse);
 
 
 initmenu();
 

 
 music(1);
 
 
 glutMainLoop(); 
 return 0;
}










void ginit()
{
 
 glutSetWindowTitle("MEGA Tic Tac Toe by PPanda");
 int i;
// glui[0]=GLUI_Master.create_glui( "GLUI", 0,50,500 );
// GLUI_Master.set_glutReshapeFunc( myGlutReshape );

 
 glui[0]=GLUI_Master.create_glui_subwindow( main_win, GLUI_SUBWINDOW_BOTTOM ); 
 startwin(glui[0]);
 
 glui[1]=GLUI_Master.create_glui_subwindow( main_win, GLUI_SUBWINDOW_BOTTOM ); 
 gmsetwin(glui[1]); 
 
// glui[2]=GLUI_Master.create_glui_subwindow( main_win, GLUI_SUBWINDOW_BOTTOM ); 
// plrsetwin(glui[2]);
 
 glui[3]=GLUI_Master.create_glui_subwindow( main_win, GLUI_SUBWINDOW_RIGHT ); 
 pausewin(glui[3]);
 
 glui[3]->close();
 
 
 glui[1]->hide();
 //glui[3]->hide();
 
// serpausewin(&glui[3])->hide();
// serpausewin(&glui[3]);
  sui=GLUI_Master.create_glui("GLUI");
  sui->close();
  

  
 

}







/*

void gmidle()
{
 if(pst<=0){  GLUI_Master.set_glutIdleFunc(stidle); return;}
 int i;
 if(server && pst%pln!=1) 
 {
  for(i=0;i<pln-1;i++)
  {
   while(turn(rand()%n,rand()%n)<0);
   pltrn=0;
  }
  pltrn=1 ;
 }
 else pltrn=1;
 

}



void stidle()
{
 if(gmflag && pst>0)GLUI_Master.set_glutIdleFunc(gmidle);
 
 //if(pst<=0){ getchar(); reset(); }
 
// glutSetWindow(main_win);
 glutPostRedisplay();
}
*/




void stidle()
{
 glutSetWindow(main_win);
 //glui[0]->set_main_gfx_window( main_win );
 
 glutPostRedisplay();
}



void stgame()
{
 GLUI_Master.set_glutDisplayFunc(display);
 GLUI_Master.set_glutReshapeFunc(myGlutReshape);
 GLUI_Master.set_glutIdleFunc(stidle);
 
}














void initmenu()
{
 
 
 mainmenu=glutCreateMenu(menu);
 glutAddMenuEntry("Fullscreen\tF",'F');
 glutAddMenuEntry("Debug\tD",'D');
 glutAddMenuEntry("Exit\tESC",27); 
  glutAttachMenu(GLUT_RIGHT_BUTTON); 
 
 
 sermenu=glutCreateMenu(sergamemenu);
 glutAddMenuEntry("Resume\tESC",1011);
 glutAddMenuEntry("Leave Game",1012);
 glutAddMenuEntry("View Player List",1013);
 
 glutAddSubMenu("Extra",mainmenu);
 

 
 
 
 gmmenu=glutCreateMenu(gamemenu);
 glutAddMenuEntry("Resume\tESC",31);
 glutAddMenuEntry("Restart",32);
 glutAddMenuEntry("Change Player config",33);
 glutAddMenuEntry("Save",34);
 glutAddMenuEntry("Quit to menu",35);
 
 glutAddSubMenu("Extra",mainmenu);
 
 
/*
 glutSetMenu(sermenu);
glutAttachMenu(GLUT_RIGHT_BUTTON);
 */
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
