//bluetooth 설정
//블루투스 설정코드
/**
  시리얼 모니터
  AT - OK
  AT+NAMEblue  -> OKsetName //bluetooth 이름설정 blue
  AT+PIN1234 -> OKsetPIN //bluetooth 핀번호 설정 1234

**/


//Library:SoftwareSerial
#include <SoftwareSerial.h>

SoftwareSerial btSerial(8, 9); // bluetooth  tx, rx

void setup(){
	Serial.begin(9600);
	btSerial.begin(9600);
}


void loop(){
	
	if(Serial.available()>0){
		btSerial.write(Serial.read());
	}
	
	if(btSerial.available()>0){
		
		char btValue= btSerial.read();
		
		Serial.write(btValue);
		
		if(btValue == 'a'){
			digitalWrite(13, HIGH);
			
		}else if(btValue =='b'){
			digitalWrite(13, LOW);
		}
		
		
		
	}
	
}
