//  アナログ入力端子の電圧値を計算



const int INPUT_PIN = A0;   // 入力ピンをA0に固定
int VOLUME;                 // 変数を整数型で宣言
float VOLTAGE;              // 変数を浮動小数点型で宣言

boolean number[10][7] = {
  {0,0,0,0,0,0,1},  // 0
  {1,0,0,1,1,1,1},  // 1
  {0,0,1,0,0,1,0},  // 2
  {0,0,0,0,1,1,0},  // 3
  {1,0,0,1,1,0,0},  // 4
  {0,1,0,0,1,0,0},  // 5
  {0,1,0,0,0,0,0},  // 6
  {0,0,0,1,1,1,1},  // 7
  {0,0,0,0,0,0,0},  // 8
  {0,0,0,0,1,0,0}   // 9
  };

 




void setup(){

  Serial.begin(9600);  // シリアル通信の開始
  int i = 0;
  for (int i=2; i<=8; i++){
    pinMode(i, OUTPUT);          // D2~D8を出力に
    //delay(500);
  }
  
}


void loop(){

  VOLUME = analogRead(INPUT_PIN);  // アナログ値の読み取り
  VOLTAGE = VOLUME * 5.0/1024.0;   // 読み取ったアナログ値を電圧(V)に変換 

  Serial.print("Volume: ");
  Serial.print(VOLUME);            // シリアルモニタに出力
  Serial.print("   Volt: ");
  Serial.print(VOLTAGE);
  Serial.println(" V");

  if(4.3<=VOLTAGE && VOLTAGE<=5.0){
    NumberPrint(0);
    delay(500);
  }else if(3.3<=VOLTAGE && VOLTAGE<=3.7){
    NumberPrint(1);
    delay(500);
  }else if(2.7<=VOLTAGE && VOLTAGE<=3.2){
    NumberPrint(2);
    delay(500);
  }else if(2.3<=VOLTAGE && VOLTAGE<=2.7){
    NumberPrint(3);
    delay(500);
  }else if(1.7<=VOLTAGE && VOLTAGE<=2.2){
    NumberPrint(4);
    delay(500);
  }else if(1.3<=VOLTAGE && VOLTAGE<=1.7){
    NumberPrint(5);
    delay(500);
  }else if(0.7<=VOLTAGE && VOLTAGE<=0.2){
    NumberPrint(6);
    delay(500);
  }else{
    NumberPrint(0);
    delay(500);
  }

  delay(100);

}


//数字を表示させる関数
void NumberPrint(int j){
  for(int i = 0; i <= 6; i++){
    digitalWrite(i + 2, !number[j][i]);
  }
}