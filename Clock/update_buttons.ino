boolean deb=true;
void update_buttons(){

  
  x = analogRead(A0); // the buttons are read from the analog0 pin
     currx=x;

      if (currx > 700 && currx < 800 && deb==true){
        select=HIGH;
        deb=false;
      
 
      } 
    

            
      if (currx > 500 && currx < 510 && deb==true){
   
          left=HIGH;
          deb=false;
      }
         
         deb=true;
         
       if (currx < 10 && deb==true){
       

    }

    
        if (currx > 140 && currx < 150 && deb==true){
       
       up=HIGH;
       deb=false;
       
        }  
     
        
          
          
         if (currx > 320 && currx < 365 && deb==true){
       
      down=HIGH;
      deb=false;
      }
      else down=LOW;
      deb=true;
  
  
 CapacitiveSensor   cs_A2_A3 = CapacitiveSensor(16,17);
  long total1 =  cs_A2_A3.capacitiveSensor(15);        
            
  if(total1 > 1000){ // adjust this value if needed
    snooze_button_state = HIGH;}
  else{
    snooze_button_state = LOW;}

          
}          
