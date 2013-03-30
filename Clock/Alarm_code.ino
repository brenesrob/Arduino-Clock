/*
Taken and modified from njakol's Binary Clock on
instructables.com/id/Arduino-Binary-Alarm-Clock/#intro
*/

// "INTERNAL" VARIABLES FOR ALARM FUNCTION:
boolean first_time_signal_on = true; // used to make shure the signal is
                                    // only started once, so that you can
                                   // snooze without the alarm starting again
                                  // immediately.

Tone tone_maker;                                  


void alarm()
{
  if(alarm_on)
  {
    // Check if the time is same as alarm time:
    if(hours==alarm_hours && minutes==alarm_minutes && first_time_signal_on)
    {
      // if so, turn on the alarm signal:
      signal_on = true;
      first_time_signal_on = false;
    }
    
    if(signal_on)
    {
      play_melody();
    }
    
    // look in buttons() for snooze button and alarm off button
    
    if(snooze_on)
    {
      // Check if the time is same as snooze off time:
      if(hours==snooze_off_hours && minutes==snooze_off_minutes)
      {
        // if so, turn off snooze and restart alarm signal:
        snooze_on = false;
        signal_on = true;
      }
    }  
  }
  else
  {
    // reset so that the alarm will work next time:
    first_time_signal_on = true;
  }
  
    //Turn alarm off or snooze
    if(snooze_button_state==HIGH)
  {
    if(signal_on)
    {
      // set the time when the alarm signal will start again,
      // this will give 10 minutes snooze:
      if(minutes<50)
      {
        snooze_off_minutes = minutes+10; 
        snooze_off_hours = hours;
      }
      else //Adjust snooze time if time is above 50min
      {
        snooze_off_minutes = minutes - 50; 
        snooze_off_hours = hours + 1;
      }
      snooze_on = true;
      signal_on = false;
    }
    // if the snooze button has been held down for more than 3 seconds turn off/on the alarm
    if((millis() - snooze_button_timer) > 3000) 
    {
      if(alarm_on) // if on, turn off
      {
        signal_on = false; 
        alarm_on = false;
        snooze_on = false;
        // play tone so the user know the alarm turned off:
        tone_maker.play(NOTE_A3, 100);
      }
      else if(alarm_on==false) // if off, turn on
      {
        alarm_on = true;
        // play tone so the user know the alarm turned off:
        tone_maker.play(NOTE_A7, 100);
      }
      //reset the snooze button timer
      snooze_button_timer=millis();
    }
    
  }
  else
  {
    //reset the snooze button timer
    snooze_button_timer=millis();
  }
}
