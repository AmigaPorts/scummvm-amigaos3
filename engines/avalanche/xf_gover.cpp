


#include "graph.h"


void load()
{
    byte a;  /*absolute $A000:1200;*/ byte bit; untyped_file f;
;
 assign(f,"avagame.avd"); reset(f,1);
 seek(f,177);
 for( bit=0; bit <= 3; bit ++)
 {;
  port[0x3c4]=2; port[0x3ce]=4; port[0x3c5]=1 << bit; port[0x3cf]=bit;
  blockread(f,a,12080);
 }
 close(f);
 bit=getpixel(0,0);
}

void gfx()
{
    integer gd,gm;

 gd=3; gm=0; initgraph(gd,gm,"c:\\bp\\bgi");
}

void blit(integer x1,integer y1,integer x2,integer y2,integer x3,integer y3)
{
    pointer p,q; word s;

 mark(q);

 s=imagesize(x1,y1,x2,y2);
 getmem(p,s);
 getimage(x1,y1,x2,y2,p);
 putimage(x3,y3,p,0);

 release(q);
}

void copy_hammer()
{
 blit(274,47,311,67,92,10);
}

void do_text()
{
 settextjustify(1,1); setcolor(0);
 settextstyle(2,0,4);
 setusercharsize(120,100,100,100);
 outtextxy(112,32,"Thorsoft of Letchworth presents");
 blit(3,30,218,31,4,30);
 blit(4,35,219,38,3,35);
}

void dump_to_file(byte x1,byte y1,byte x2,byte y2, string fn)
{
 byte y,bit;
 untyped_file f;

 assign(f,fn);
 rewrite(f,1);

 for( y=y1; y <= y2; y ++)
  for( bit=0; bit <= 3; bit ++)
  {;
   port[0x3c4]=2; port[0x3ce]=4; port[0x3c5]=1 << bit; port[0x3cf]=bit;
   blockwrite(f,mem[0xa000*y*80+x1],x2-x1);
  }

 close(f);

}

int main(int argc, const char* argv[])
{
 pio_initialize(argc, argv);
 gfx();
 load();

 setfillstyle(1,7);
 bar(2,10,219,37);
 bar(0,0,1,200);
 bar(220,0,250, 88);
 bar(0,88,213,147);
 bar(622,88,640,147);
 copy_hammer();
 do_text();

 dump_to_file( 0,10,28,86,"about.avd");
 dump_to_file(26,88,78,147,"gameover.avd");
 return EXIT_SUCCESS;
}
