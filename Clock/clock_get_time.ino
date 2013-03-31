void clock()

{
   //fetch the time from the RTC
    DateTime now = RTC.now();
    
    //Print date on LCD
    lcd.setCursor(3,0);
    lcd.print(now.year(), DEC);
    lcd.print('/');
    if(now.month() < 10) lcd.print("0");
    lcd.print(now.month(), DEC);
    lcd.print('/');
    if(now.day() < 10) lcd.print("0");
    lcd.print(now.day(), DEC);
    
    //Print hours on LCD
    lcd.setCursor(5,1);
    lcd.print(now.hour(),DEC);
    if(now.hour() < 10) lcd.print("0");
    hours=now.hour();
    

    
    
    lcd.setCursor(7,1);

  unsigned long currentMillis = millis();
 
  if(currentMillis - non > interval) {
    // save the last time you blinked the LED 
    non = currentMillis;   

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW){
      ledState = HIGH;
      lcd.print(":");
    }
    else{
      ledState = LOW;
      lcd.print(" ");
    }
  }
    //Print minutes on LCD
    lcd.setCursor(8,1);
    if(now.minute() < 10) lcd.print("0");
    lcd.print(now.minute(), DEC);
    minutes=now.minute();
    

    
}
