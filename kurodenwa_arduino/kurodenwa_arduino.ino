int val=0, buf_val;

const int START_PIN = 8;
const int SIGNAL_PIN = 9;
int buf_signal = 1;
int count = 0;
bool state = false;
bool colling = true;
int calling_count, start_call_count;
int calling_Number, start_call_Number;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(11, INPUT);

  pinMode( START_PIN, INPUT_PULLUP );
  pinMode( SIGNAL_PIN, INPUT_PULLUP );

  calling_count = 0;
  start_call_count = 0;
  calling_Number = 700;
  start_call_Number = 12000;//6000 = 1minute

  digitalWrite(13, HIGH);
}

//180- rand(60) 000
//35 - rand(10) 000

void loop() {
  buf_val = val;
  int start = digitalRead( START_PIN );
  int signal = digitalRead( SIGNAL_PIN );

  val = digitalRead(11);

  if (colling == false) {
    start_call_count = start_call_count + 1;
    if (start_call_Number < start_call_count) {
      colling = true;
      start_call_count = 0;
      if (val == 1) {
        digitalWrite(13, HIGH);
      }
    }
  }else if (colling == true) {
    calling_count = calling_count + 1;
    if (calling_Number < calling_count) {
      colling = false;
      calling_count = 0;
      if (val == 1) {
        digitalWrite(13, LOW);
      }
    }
  }

  if (val == 1 && buf_val != val) {
    Serial.println(val);
  }else if(val == 0 && buf_val != val){
    digitalWrite(13, LOW);
    Serial.println(val);
  }

  if (start == 1) {
    if (state == true) {
      int send_data = count/2+2;
      Serial.println(send_data);
      count = 0;
      state = false;
    }
  } else if (start == 0) {
    state = true;
    if (buf_signal != signal){
      count = count+1 ;
    }
  }
  
  buf_signal = signal;
  delay(10);
}
