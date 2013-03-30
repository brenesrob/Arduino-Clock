void update_buttons(){

  
  
  
 CapacitiveSensor   cs_A2_A3 = CapacitiveSensor(16,17);
  long total1 =  cs_A2_A3.capacitiveSensor(15);        
            
  if(total1 > 1000){ // adjust this value if needed
    snooze_button_state = HIGH;}
  else{
    snooze_button_state = LOW;}

          
}          
