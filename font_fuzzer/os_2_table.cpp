#include "os_2_table.h"
void os_2_table::printTable(char* path){
      ofstream file;
      file.open(path,ios::binary|ios::app);
      file<<(char)0<<(char)4;//version
      file<<(char)(xAvgCharWidth>>8)<<(char)(xAvgCharWidth%256);
      file<<(char)(usWeightClass>>8)<<(char)(usWeightClass%256);
      file<<(char)(usWidthClass>>8)<<(char)(usWidthClass%256);
      file<<(char)(fsType>>8)<<(char)(fsType%256);
      file<<(char)(ySubscriptXSize>>8)<<(char)(ySubscriptXSize%256);
      file<<(char)(ySubscriptYSize>>8)<<(char)(ySubscriptYSize%256);
      file<<(char)(ySubscriptXOffset>>8)<<(char)(ySubscriptXOffset%256);
      file<<(char)(ySubscriptYOffset>>8)<<(char)(ySubscriptYOffset%256);
      file<<(char)(ySuperscriptXSize>>8)<<(char)(ySuperscriptXSize%256);
      file<<(char)(ySuperscriptYSize>>8)<<(char)(ySuperscriptYSize%256);
      file<<(char)(ySuperscriptXOffset>>8)<<(char)(ySuperscriptXOffset%256);
      file<<(char)(ySuperscriptYOffset>>8)<<(char)(ySuperscriptYOffset%256);
      file<<(char)(yStrikeoutSize>>8)<<(char)(yStrikeoutSize%256);
      file<<(char)(yStrikeoutPosition>>8)<<(char)(yStrikeoutPosition%256);
      file<<(char)(sFamilyClass>>8)<<(char)(sFamilyClass%256);
      for(int i=0;i<10;i++) file<<panose[i];
      file<<(char)0<<(char)0<<(char)0<<(char)0;
      file<<(char)0<<(char)0<<(char)0<<(char)0;
      file<<(char)0<<(char)0<<(char)0<<(char)0;
      file<<(char)0<<(char)0<<(char)0<<(char)0;
      for(int i=0;i<4;i++) file<<achVendID[i];
      file<<(char)(fsSelection>>8)<<(char)(fsSelection%256);
      file<<(char)(fsFirstCharIndex>>8)<<(char)(fsFirstCharIndex%256);
      file<<(char)(fsLastCharIndex>>8)<<(char)(fsLastCharIndex%256);
      //for version 4
      file<<(char)(sTypoAscender>>8)<<(char)(sTypoAscender%256);
      file<<(char)(sTypoDescender>>8)<<(char)(sTypoDescender%256);
      file<<(char)(sTypoLineGap>>8)<<(char)(sTypoLineGap%256);
      file<<(char)(usWinAscent>>8)<<(char)(usWinAscent%256);
      file<<(char)(usWinDescent>>8)<<(char)(usWinDescent%256);
      file<<(char)(ulCodePageRange1>>24)<<(char)((ulCodePageRange1>>16)&255);
      file<<(char)((ulCodePageRange1>>8)&255)<<(char)(ulCodePageRange1%256); 
      file<<(char)(ulCodePageRange2>>24)<<(char)((ulCodePageRange2>>16)&255);
      file<<(char)((ulCodePageRange2>>8)&255)<<(char)(ulCodePageRange2%256); 
      file<<(char)(sxHeight>>8)<<(char)(sxHeight%256);
      file<<(char)(sCapHeight>>8)<<(char)(sCapHeight%256);
      file<<(char)(usDefaultChar>>8)<<(char)(usDefaultChar%256);
      file<<(char)(usBreakChar>>8)<<(char)(usBreakChar%256);
      file<<(char)(usMaxContext>>8)<<(char)(usMaxContext%256);
      file.close();
}
uint32 os_2_table::getSize(){
       return 96;
}
void gener_os_2_table(os_2_table &ost){
     ost.version=0;
     ost.xAvgCharWidth=20+(rand()%20);
     ost.usWeightClass=rand()%10;
     ost.usWidthClass=rand()%10;
     ost.fsType=rand()%2;
     ost.ySubscriptXSize=rand()%2048;
     ost.ySubscriptYSize=rand()%2048;
     ost.ySubscriptXOffset=rand()%128;
     ost.ySubscriptYOffset=rand()%128;
     ost.ySuperscriptXSize=rand()%128;
     ost.ySuperscriptYSize=rand()%128;
     ost.ySuperscriptXOffset=rand()%128;  
     ost.ySuperscriptYOffset=rand()%128;
     ost.yStrikeoutSize=rand()%64;
     ost.yStrikeoutPosition=(rand()%128)-64;
     ost.sFamilyClass=rand()%65536;
     ost.panose[0]=(char)(rand()%6);
     ost.panose[1]=(char)(rand()%16);
     ost.panose[2]=(char)(rand()%12);
     ost.panose[3]=(char)(rand()%10);
     ost.panose[4]=(char)(rand()%10);
     ost.panose[5]=(char)(rand()%9);
     ost.panose[6]=(char)(rand()%12);
     ost.panose[7]=(char)(rand()%16);
     ost.panose[8]=(char)(rand()%14);
     ost.panose[9]=(char)(rand()%8);
     for(int i=0;i<4;i++) ost.ulCharRange[i]=0;//not completed yet
     ost.achVendID[0]='n';ost.achVendID[1]='o';ost.achVendID[2]='n';ost.achVendID[3]='e';
     //vendor name, unnecessary
     ost.fsSelection=rand()%6;
     ost.fsFirstCharIndex=rand()%64;
     ost.fsLastCharIndex=ost.fsFirstCharIndex+rand()%256;
     //for ver. 4
     ost.sTypoAscender=rand()%64;
     ost.sTypoDescender=rand()%64;
     ost.sTypoLineGap=rand()%64;
     ost.usWinAscent=rand()%64;
     ost.usWinDescent=rand()%64;
     ost.ulCodePageRange1=((rand()%64)<<16)+(rand()%256); 
     ost.ulCodePageRange2=(rand()%65535)<<16;
     ost.sxHeight=rand()%64;	 
     ost.sCapHeight=rand()%64;	
     ost.usDefaultChar=rand()%0xffff; //<0xffff
     ost.usBreakChar=rand()%0xffff;	 //<0xffff
     ost.usMaxContext=rand()%10; 
}