



struct markertype {
              word length;
              longint offset;
              byte checksum;
};

struct sezheader {
             array<1,2,char> initials;     /* should be "TT" */
             word gamecode;
             word revision; /* as 3- or 4-digit code (eg v1.00 = 100) */
             longint chains; /* number of scroll chains */
             longint size; /* total size of all chains */
};

untyped_file f;
longint number;
markertype marker;
sezheader sezhead;
array<0,1999,char> x;
word fv;
byte sum;

byte sumup()
{
    word fv; byte total;
byte sumup_result;
;
 total=0;
 for( fv=0; fv <= marker.length; fv ++)
 {;
  total += ord(x[fv]);
 }
 sumup_result=total;
return sumup_result;
}

int main(int argc, const char* argv[])
{pio_initialize(argc, argv);
;
 output << "READ-SEZ by TT." << NL; output << NL;
 assign(f,"avalot.sez"); reset(f,1);
 seek(f,255); blockread(f,sezhead,sizeof(sezhead));
 {;
  if (sezhead.initials!="TT") 
  {;
   output << "Not a valid Sez file!" << NL;
   exit(0);
  }
  output << "Number of chains in file = " << sezhead.chains << NL;
  output << "Total size of all chains = " << sezhead.size << " bytes." << NL;
 }
 output << NL;
 output << "Number of scrollchain to display?"; input >> number >> NL;
 seek(f,longint(262)+number*longint(7)); blockread(f,marker,7);
 {;
  output << "Scrollchain no. " << number << NL;
  output << "Length: " << marker.length << NL;
  output << "Offset: " << marker.offset << NL;
  output << NL;
  output << "Contents:" << NL;
  seek(f,longint(270)+sezhead.chains*longint(7)+marker.offset);
  blockread(f,x,marker.length+1);
  for( fv=0; fv <= marker.length; fv ++) x[fv] -= 3+177*fv*marker.length; /* unscramble */
  for( fv=0; fv <= marker.length; fv ++) output << x[fv];
  output << NL; sum=sumup();
  output << "Checksum in file: " << marker.checksum << ". Actual value: " << sum << '.' << NL;
  output << NL;
  if (sum!=marker.checksum) 
  {;
   output << "Bleargh! Checksum failed!" << NL;
   exit(0);
  }
 }
 close(f);
return EXIT_SUCCESS;
}