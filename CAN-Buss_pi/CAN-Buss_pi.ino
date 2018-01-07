

int message[8];
int recievedId;
String toPi;
char Data[8];
int sendID;
String incomingByte;

void setup() {
 SetupCANBuss();

}

void loop() {
   if(messageAvalible()){
     getMessage(message);
     recievedId=getRecievedId();
     toPi=String(recievedId)+ ":"+ String(message[0])+":"+ String(message[1])+":"+ String(message[2])+":"+ String(message[3])+":"+ String(message[4])+":"+ String(message[5])+":"+ String(message[6])+":"+ String(message[7]);
     Serial.println(toPi);
     Serial.println();
     
   }

    if (Serial.available() > 0) {
         
         
          incomingByte = Serial.readStringUntil('\n');
          split(incomingByte);
          setSendId(sendID);
          setData(Data);
          SendData();
          
          
       
     }
       

}


void split(String Word){
  Serial.println(Word.length());
int index=0;
int tempindex=0;
char temp[8];
bool firstiteration=true;
byte Bytetest[8];
  
  for(int i=0;i<Word.length()+1;i++){

    if(Word.charAt(i)==':'){
        
      if(firstiteration){
        sendID=Word.substring(0,i).toInt();
        Serial.print("SendID: ");
        Serial.println(sendID);
        firstiteration=false;
      }    
      else{  
        temp[index++]=(char)Word.substring(tempindex+1,i).toInt();
        
      }
      
    tempindex=i;  
    }
    
   
    
    }
    temp[7]=(char)Word.substring(tempindex+1).toInt();

    for(int i=0;i<8;i++)
    Data[i]=temp[i];
}  

