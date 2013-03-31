int cyclemenu=0;
boolean onepress=true;
int cyclecursor=0;


void menu()
{
  if (select==HIGH && onepress==true)
  {
    cyclemenu++;
    if (cyclemenu==3) cyclemenu=0;
    onepress=false;
  }
  
  
  if (right==HIGH && onepress==true)
  {
    cyclecursor++;
    if (cyclecursor==2) cyclecursor=0;
    onepress=false;
  }
 
  
  if (down==HIGH && onepress==true)
  {
    cyclemenu--;
    if (cyclecursor==-1) cyclecursor=1;
    onepress=false;
  }
  onepress=true;
  
   
  
  switch (cyclemenu) {
    
    case 0:
    lcd.clear();
    while(cyclemenu==0){
       clock();
       update_buttons();
        if (select==HIGH && onepress==true)
    {
    cyclemenu++;
    if (cyclemenu==3) cyclemenu=0;
    onepress=false;
    }
    onepress=true;
       }
    
    break;  
   
    case 1:
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Set Alarm:");
    lcd.setCursor(5,1);
    if (alarm_hours < 10) lcd.print("0");
    lcd.print(alarm_hours);
    lcd.print(":");
    if (alarm_minutes < 10) lcd.print("0");
    lcd.print(alarm_minutes);
    update_buttons();
    
      
        //cycle hours
        if(cyclecursor==0){
        if(up==HIGH && onepress==true){
          onepress=false;
          alarm_hours++;
          if(alarm_hours>23) alarm_hours=0;
        }
        onepress=true;
          if (down==HIGH && onepress==true){
            onepress=false;
            alarm_hours--;
            if(alarm_hours<0) alarm_hours=23;
          }
          onepress=true;
        }
          //cycle minutes
         if(cyclecursor==1){
         if(up==HIGH && onepress==true){
          onepress=false;
          alarm_minutes++;
          if(alarm_minutes>59) alarm_minutes=0;
        }
        onepress=true;
          if (down==HIGH && onepress==true){
            onepress=false;
            alarm_minutes--;
            if(alarm_minutes<0) alarm_minutes=59;
          }
          onepress=true;
         }
          
      break;
      
      case 2:
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Alarm Status");
      if(up==HIGH && onepress==true){
        onepress=false;
        alarm_on != alarm_on;
      }
      onepress=true;
      if (down==HIGH && onepress==true){
        onepress=false;
        alarm_on != alarm_on;
      }
      if (alarm_on==true){
        lcd.setCursor(5,1);
        lcd.print("ON");
      }
      else if (alarm_on==false){
        lcd.setCursor(5,1);
        lcd.print("OFF");
      }
        break;
  }
 
}
      
    
    
