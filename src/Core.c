#include "all.h"

void pr(char *);

void reset()
{
 pst=1 ;
 initvars();
 neworder();
 
// prepgame();
 
}



void initvars()
{
 
 vi1=0; vi2=n-1; 
 vj1=0; vj2=n-1;
 
}

void initgvars()
{
 int tx, ty, tw, th;
 GLUI_Master.get_viewport_area( &tx, &ty, &tw, &th );
//  glViewport( tx, ty, tw, th );

//  asr=(float)tw / (float)th;
 wd=(float)tw ; ht=(float)th;
 asr=wd/ht;
 px=0,py=0;
 gy=.3+(gx=bd=(2/(float)n)*.1);
 cw=((2-gx)/n)-bd ,ch=((2-gy)/n-bd);
 
 
  
// printf("%f,%f\n",wd,ht);
// wd=glutGet(GLUT_WINDOW_WIDTH);
// ht=glutGet(GLUT_WINDOW_HEIGHT);
// asr=wd/ht;
// myGlutReshape(0,0);
// pln=n-1 ;
}


void neworder()
{
 pst=1;
 sprintf(ttl,"Mega TicTacToe by PD of order %d x %d - %s",n,n,sgflg?me.name:"Local game");
 glutSetWindowTitle(ttl);
 
 free(s);
 while(!(s=(char *)malloc(n*n)));
 memset(s,'?',n*n);
   
 pr(s);
}


void prepgame()
{
 int i;
 
 
// for(i=0; gmplr && i<pln ;i++) 
//  free(gmplr[i]);  

 free(gmplr);
 gmplr=(player **)malloc(pln*sizeof(*gmplr));
   
 for(i=0;i<pln;i++) 
 {

  gmplr[i]=(player *)malloc(sizeof(player)); if(!gmplr[i]) exit(0);
  sprintf((*gmplr[i]).name,"gPlayer %d",i+1);

  gmplr[i]->sym=stdsyms[1+i%totalsym] ;
  printf("+%d+%c\n",i,gmplr[i]->sym);

  memcpy(gmplr[i]->color,stdcolor[1+i%totalclr].v, 3*sizeof(float));
   
 }

}





























void pr(char *p)
{
 register int i,j ;
 
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++) printf("%c ", ( (char (*)[n])p )[i][j] );
  printf("\n");
 }

}




/*
col  0 - n-1
row n - m*n
d1 -1
d2 -2
draw -3
Nothing -5
*/



int check(char *p)
{
 return check_org(p,n);
}






int check_org(char *p,int nn)
{
 register int i,j,k=0 ;
 
 
// pr(p);
 for(i=0;i<nn	;i++)
 {
  k=1;
  for(j=0;j<nn-1 && k;j++)
   k=((char (*)[nn])p)[i][j]==((char (*)[nn])p)[i][j+1]
   		&& ((char (*)[nn])p)[i][j]!='?' ? k : 0 ;
// printf("%d,%d,%d\nn",i,j,k);


  if(k){ vi1=vi2=i;  return nn*(i+1) ; }
  
 }
 
 
 
 for(j=0;j<nn;j++)
 {
  k=2;
  for(i=0;i<nn-1 && k;i++)
   k=((char (*)[nn])p)[i][j]==((char (*)[nn])p)[i+1][j]
   		&& ((char (*)[nn])p)[i][j]!='?' ? k : 0 ;
//  printf("%d,%d,%d\nn",i,j,k);
  if(k){  vj1=vj2=j; return j ; }
  
 }
 
 
 
 k=-1 ;
 
 for(i=j=0; i<nn-1 && j<nn-1 && k; i++,j++)
  k=((char (*)[nn])p)[i][j]==((char (*)[nn])p)[i+1][j+1]
   		&& ((char (*)[nn])p)[i][j]!='?' ? k : 0 ;
//  printf("%d,%d,%d\nn",i,j,k);

  if(k) return k ;
 
 
 
 
 
 k=-2 ;
 for(i=0,j=nn-1; i<nn-1 && j>0 && k; i++,j--)
  k=((char (*)[nn])p)[i][j]==((char (*)[nn])p)[i+1][j-1]
   		&& ((char (*)[nn])p)[i][j]!='?' ? k : 0 ;
//  printf("%d,%d,%d\nn",i,j,k);
  if(k){  vj1=nn-1; vj2=0;   return k ; }
 
 
 
 k=-3 ;
 for(i=0;i<nn*nn & k;i++)
  k= p[i]!='?' ? k:0 ;
 if(k) return k ;
 
// if(!strchr(s,'?'))return -3; 
 
 return -5;
}





void gmain()
{
 gmain_org(&pst,n);
}


void gmain_org(int *pstp,int nn)
{
 int c;
 
 
 pr(s);
 c=check_org(s,nn);
 
 
 printf("check returned as : %d\n",c);
 
 
 
 if(c!=-5)
 {
  (*pstp)--; (*pstp)*=-1 ;
  if(c<0)
  {
   if(c==-1) printf("d1\n"); 
   if(c==-2) printf("d2\n");	//ELSE part
   if(c==-3){ printf("Draw\n"); (*pstp)=0; }
  }
  else
  {
   if(c>n) printf("Row no : %d\n",c/4);
   if(c<=n) printf("Col no : %d\n",c+1);   //ELSE part
  }
 }
 else printf("Nothing Happened!\n\n");

 
}


void gmain_limit(int *pstp,int nn,int lim)
{
 int c,i,j;
 
 
 pr(s);
 
 for(i=0;i<nn-lim;i++)
  for(j=0;j<nn-lim;j++)
  {
	c=check_org(s,nn);

	printf("check returned as : %d\n",c);

	 if(c!=-5)
	 {
	  (*pstp)--; (*pstp)*=-1 ;
	  if(c<0)
	  {
	   if(c==-1) printf("d1\n"); 
	   if(c==-2) printf("d2\n");	//ELSE part
	   if(c==-3){ printf("Draw\n"); (*pstp)=0; }
	  }
	  else
	  {
	   if(c>n) printf("Row no : %d\n",c/4);
	   if(c<=n) printf("Col no : %d\n",c+1);   //ELSE part
	  }
	 }
	 else printf("Nothing Happened!\n\n");

 }
}


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
