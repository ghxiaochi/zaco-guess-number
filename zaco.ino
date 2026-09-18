int num = 0;
int numint = 0;
int cishu = 0;
const int jihui = 10;

int zaco = 0;

void setup(){
  Serial.begin(115200);
  randomSeed(analogRead(0));
  game();
}
void loop(){
  if(Serial.available() > 0){
    numint = Serial.parseInt();
    if(numint == 0)return;
    cishu++;
    if(numint > num){
      Serial.println("你牛大了");
      Serial.print("还有");
      Serial.print(jihui - cishu);
      Serial.println("次机会哟~~~");
    }
    else if(numint < num){
      Serial.println("你牛小了");
      Serial.print("还有");
      Serial.print(jihui - cishu);
      Serial.println("次机会哟~~~");
    }
    else {
      Serial.println("哇哦，恭喜你哦~~~");
      Serial.println("原来答案是");
      delay(1000);
      Serial.println("3");
      delay(1000);
      Serial.println("2");
      delay(1000);
      Serial.println("1");
      delay(1000);
      Serial.print("是");
      Serial.print(num);
      Serial.println("哦~~~");
      delay(600);
      Serial.println("再来一局吧~~~");
      game();
      return;
    }
    if(cishu >= jihui){
      Serial.println("机会用完了哦~~~");
      Serial.println("按est，再来一局吧");
      delay(700);
      Serial.print("我是绝对不会告诉你答案是");
      Serial.print(num);
      Serial.println("的哦~~~");


      while(1){
        if(Serial.available() > 0){
          zaco++; 
          Serial.parseInt();

          while(Serial.available() > 0) {Serial.read();}

          for(int a = 0;a < zaco;a++){
            Serial.println("zaco,不能再猜了哦~~~"); 
          }
          delay(100);
        }
      }
    }
  }
}
void game(){
  num = random(1,101);
  cishu = 0; 
  Serial.println("猜猜是1到100中的哪个呢~~~");  
  Serial.println("只给你十次机会哟~~~"); 
}