// "INTERNAL" VARIABLES FOR PLAY_MELODY FUNCTION:
int melody[] = { NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
                 NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };
int melody_length = sizeof(melody) / 2; // Melody length, for looping.
// sizeof() returns the size of the array in bytes, and because 
// an int is 2 bytes, sizeof will return 2*(number of array elements)

int e = 0;        //loop variable
boolean reset_loop = true; 
int jump = 1;     // how many notes to jump in the melody array
int position = 0; // position in melody array

void play_melody()
{
  if(!(tone_maker.isPlaying())) // if the last tone has stopped
  {
    if(e<melody_length)
    {
      //tone_maker.stop();
      tone_maker.play(melody[position], 300);
      // A pause between notes...
      //delay(300); // replace with nonblocking.
       
      position += jump;
      //if position is bigger than the array, start from beginning of array:
      position = position%melody_length; 
      e++;
     }
     else
     {
       jump++;
       e = 0;
     }
  }
}
