byte valor_byte = 35; // variável tipo byte (35 --> caractere # na tabela ASCII)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  //inicia a porta serial

  pinMode(LED_BUILTIN, OUTPUT); //configura o LED interno para saída

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enviando informacao ");
  Serial.write(valor_byte);
  Serial.println(" , em decimal, hexadecimal e binario:");
  Serial.print(valor_byte, DEC); Serial.print(" ");
  Serial.print(valor_byte, HEX); Serial.print(" ");
  Serial.print(valor_byte, BIN); Serial.write(".");
  Serial.write("\n");

  Serial.println("Digite 1 para ligar o LED e 0 para desligar");

  while(true)
  { if (Serial.available() > 0)
    {
      valor_byte = Serial.read();
      if (valor_byte == '1'){
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("LED ligado");
      }
      if (valor_byte == '0'){
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("LED desligado");
      }
    }
  }

}
