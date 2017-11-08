#include <main.h>
#include <lcd.h>

#define COT_1 PIN_D0
#define COT_2 PIN_D1
#define COT_3 PIN_D2
#define COT_4 PIN_D3

#define HANG_1 input(PIN_D4)
#define HANG_2 input(PIN_D5)
#define HANG_3 input(PIN_D6)
#define HANG_4 input(PIN_D7)


char phimnhan[16]=
               {
                  'c','1','4','7', 
                  '0','2','5','8',
                  '=','3','6','9',
                  '+','-','x','/'
               };
//--------------------------------------------
void dieuKhienCot(char tencot, int trangthai)
{
   switch(tencot)
   {
      case 1:
      {
         output_bit(COT_1,trangthai);
         break;
      }
      case 2:
      {
         output_bit(COT_2,trangthai);
         break;
      }
      case 3:
      {
         output_bit(COT_3,trangthai);
         break;
      }
      case 4:
      {
         output_bit(COT_4,trangthai);
         break;
      }
   }
}

void khoiDongPhim(void)
{
   int i;
   for(i=1;i<=4;i++)
   {
      dieuKhienCot(i,1); //bat het cac cot.
   }
}

char quetPhim(void)
{
   char Key = 0;
   
   //quet cot 1
   dieuKhienCot(1,0); // tat cot 1.
   if(HANG_1 == 0)
   {
      Key = 1;
   }
   if(HANG_2 == 0)
   {
      Key = 2;
   }
   if(HANG_3 == 0)
   {
      Key = 3;
   }
   if(HANG_4 == 0)
   {
      Key = 4;
   }
   dieuKhienCot(1,1);
   
   //quet cot 2
   dieuKhienCot(2,0); // tat cot 1.
   if(HANG_1 == 0)
   {
      Key = 5;
   }
   if(HANG_2 == 0)
   {
      Key = 6;
   }
   if(HANG_3 == 0)
   {
      Key = 7;
   }
   if(HANG_4 == 0)
   {
      Key = 8;
   }
   dieuKhienCot(2,1);
   
   //quet cot 3
   dieuKhienCot(3,0); // tat cot 1.
   if(HANG_1 == 0)
   {
      Key = 9;
   }
   if(HANG_2 == 0)
   {
      Key = 10;
   }
   if(HANG_3 == 0)
   {
      Key = 11;
   }
   if(HANG_4 == 0)
   {
      Key = 12;
   }
   dieuKhienCot(3,1);
   
   //quet cot 4
   dieuKhienCot(4,0); // tat cot 1.
   if(HANG_1 == 0)
   {
      Key = 13;
   }
   if(HANG_2 == 0)
   {
      Key = 14;
   }
   if(HANG_3 == 0)
   {
      Key = 15;
   }
   if(HANG_4 == 0)
   {
      Key = 16;
   }
   dieuKhienCot(4,1);
   
   return Key; // tra ve gia tri phim cho ham quet phim.
}

void lcd()
{
   lcd_init();
   lcd_putc('\f');
}

void main()
{
   char Key=0, tam=0, index1=1,index2=3;
   lcd();
   khoiDongPhim();
   lcd_gotoxy(1,1);//tai cot 1, hang 2
   printf(lcd_putc,"BAN PHIM MA TRAN");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"KEYPAD 4x4");
   while(1)
   {
      Key = quetPhim();
      if(Key!=0)
      {
         tam=Key;
         lcd_gotoxy(index1,index2);
         printf(lcd_putc,"%c",phimnhan[tam-1]); // hien thi phim nhan
         index1 ++;
         while(quetPhim()!=0)
         {delay_ms(5);}
      }
   }
}
