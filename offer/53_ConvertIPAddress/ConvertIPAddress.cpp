#include <stdio.h>

typedef unsigned char uchar;

int ipstrtoint(const char *ip)
{
    int   result = 0;
    int   tmp = 0;
    int   shift = 24;
    const char *pEnd = ip;
    const char *pStart = ip;

    while(*pEnd != '\0')
    {
        while(*pEnd != '.' && *pEnd != '\0')
        pEnd++;
        tmp = 0;

        while(pStart < pEnd) {
            tmp = tmp * 10 + (*pStart - '0');
            pStart++;
        }
            
        result += (tmp << shift);
        shift -= 8;
        if (*pEnd == '\0')
        break;
        pStart = pEnd + 1;
        pEnd++;
    }
    
    return result;
}

char * int2ipstr (const int ip, char *buf)
{
sprintf (buf, "%u.%u.%u.%u",
(uchar) * ((char *) &ip + 0),
(uchar) * ((char *) &ip + 1),
(uchar) * ((char *) &ip + 2), (uchar) * ((char *) &ip + 3));
return buf;
}

int main(){
 unsigned int num=0xABCDABCD;    // 这个是你的那串数
 unsigned int mask = 0xff000000; // ip是8bit一段，mask用来把1个字节取出来
 int i;
 unsigned int val;

 for(i=0; i<4; i++){
  val = num & mask;  // mask掉其他位
  val = (val >> 8*(3-i) ); // 如果在高位平移到最右端
  printf("%x ", val);
  mask = mask >> 8;  // mask下一个8位
 }
 return 0;
}
