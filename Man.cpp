#include<iostream>
#include<graphics.h>
#include<stdlib.h>

int main(){
	int gd=DETECT,gm;
	int rhx,rhy,i,j;
	char *drop=(char *)"|";
	
	initgraph(&gd,&gm,NULL);
			
		rhx=getmaxx();
		rhy=getmaxy();
	
	for (i=0;i<500;i+=5){
		line(0,380,rhx,380);
		
		if (i%2==0){
			line(25+i,380,35+i,340);
			line(45+i,380,35+i,340);
			line(35+i,310,25+i,330);
			delay(20);
			
		}
		else{
			line(35+i,380,35+i,340);
			line(35+i,310,40+i,330);
			delay(20);
			
			}
		line(35+i,340,35+i,310);
		circle(35+i,300,10);
		line(35+i,310,50+i,330);
		line(50+i,330,50+i,280);
		line(15+i,280,85+i,280);
		arc(50+i,280,180,0,35);

		
		for (j=0;j<5;j++){
			outtextxy(rand() % rhx , rand() % (rhy-50), drop);
			setcolor(WHITE);
			
			}
		delay(150);
		cleardevice();
		}
	getch();
}


