


#include "graph.h"
/*#include "Crt.h"*/

integer gd,gm;

void flash(integer x1,integer y1,integer x2,integer y2)
{;
 setcolor(14); rectangle(x1,y1,x2,y2);
 sound(x1+x2); delay(100); nosound; delay(500);
 setcolor( 9); rectangle(x1,y1,x2,y2); delay(500);
}

boolean dropin(integer xc,integer yc,integer x1,integer y1,integer x2,integer y2)
/* Dropin returns True if the point xc,yc falls within the 1-2 rectangle. */
{boolean dropin_result;
;
 dropin_result=((xc>=x1) && (xc<=x2) && (yc>=y1) && (yc<=y2));
return dropin_result;
}

void test(integer x1,integer y1,integer x2,integer y2,integer x3,integer y3,integer x4,integer y4)
{;
 cleardevice();
 rectangle(x1,y1,x2,y2);
 rectangle(x3,y3,x4,y4);
 flash(x1,y1,x2,y2);
 flash(x3,y3,x4,y4);

 if (dropin(x3,y3,x1,y1,x2,y2)
 || dropin(x3,y4,x1,y1,x2,y2)
 || dropin(x4,y3,x1,y1,x2,y2)
 || dropin(x4,y4,x1,y1,x2,y2)) 
 {;     /* Overlaps */
  flash(x1,y1,x4,y4);
 } else
 {;     /* Doesn't overlap- flash 'em both again */
  flash(x3,y3,x4,y4); /* backwards- why not...? */
  flash(x1,y1,x2,y2);
 }
}

int main(int argc, const char* argv[])
{pio_initialize(argc, argv);
;
 gd=3; gm=1; initgraph(gd,gm,""); setcolor(9);
 test(100,50,200,100,400,200,600,250);
 test(100,50,200,100,120, 70,220,120);
 test(100,50,200,100,150, 50,250,100);
return EXIT_SUCCESS;
}