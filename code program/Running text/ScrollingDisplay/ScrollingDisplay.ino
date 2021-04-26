// Scrolling display Arduino by Sarjana Electro
// Jangan lupa like, comment dan subscribe ya!

#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Change following variables as per your need
char * LargeText = "    Like, Subscribe & Comment!    ";                               // Tulisan baris ke 2
int iLineNumber = 1;                                                                   // Line number to show your string (Either 0 or 1)
int iCursor = 0;

void setup() 
{
  lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Sarjana Electro");                                                      // Tulisan baris Pertama
}

void loop() 
{
  UpdateLCDDisplay();                                                                 // Scoll text by 1 character
  delay(400);                                                                         // Change delay to change speed for scrollig text. 
}

void UpdateLCDDisplay()
{
  int iLenOfLargeText = strlen(LargeText);                                            // Calculate lenght of string.
  if (iCursor == (iLenOfLargeText - 1) )                                              // Reset variable for rollover effect.
  {
    iCursor = 0;
  }
  //lcd.clear();
  lcd.setCursor(0,iLineNumber);
  
  if(iCursor < iLenOfLargeText - 16)                                                  // This loop exicuted for normal 16 characters.
  {
    for (int iChar = iCursor; iChar < iCursor + 16 ; iChar++)
    {
      lcd.print(LargeText[iChar]);
    }
  }
  else
  {
    for (int iChar = iCursor; iChar < (iLenOfLargeText - 1) ; iChar++)                //  This code takes care of printing charecters of current string.
    {
      lcd.print(LargeText[iChar]);
    }
    for (int iChar = 0; iChar <= 16 - (iLenOfLargeText - iCursor); iChar++)           //  Reamining charecter will be printed by this loop.
    {
      lcd.print(LargeText[iChar]);   
    }
  }
  iCursor++;
}
