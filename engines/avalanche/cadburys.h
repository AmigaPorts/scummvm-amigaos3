#ifndef __cadburys_h__
#define __cadburys_h__


const integer arraysize = 12000;

const array<1,44,char> chunkheader = 
string("Chunk-type AVD file, for an Avvy game.")+'\32'+'\261'+'\x30'+'\x1'+'\x75'+'\261';


enum flavourtype {ch_ega,ch_bgi, last_flavourtype};

struct chunkblocktype {
                  flavourtype flavour;
                  integer x,y;
                  integer xl,yl;
                  longint size;
                  boolean natural;

                  boolean memorise; /* Hold it in memory? */
};


#ifdef __cadburys_implementation__
#undef EXTERN
#define EXTERN
#endif

EXTERN array<0,arraysize,byte> aa;
EXTERN byte num_chunks,this_chunk;
EXTERN integer gd,gm;
EXTERN array<1,30,longint> offsets;
EXTERN untyped_file f;
#undef EXTERN
#define EXTERN extern


void grab(integer x1,integer y1,integer x2,integer y2,integer realx,integer realy, flavourtype flav,
 boolean mem,boolean nat);

#endif
