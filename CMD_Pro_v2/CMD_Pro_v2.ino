bool autocmd = 0, echo = 0;
char prefix = '/';
String Base_, storageA, storageB, storageC, storageD, storageE;
String tag = "[CMD]";
int example = 125;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  Serial.println(F("      ✹ CMD Pro by SaliFaro ✹"));
  Serial.print(String(tag));
  Serial.println(F(" use /help for more information"));
}
void loop() {
  SC();
}

//CMD Pro Code
//only go down to add and remove extras or to put in your variables
void Swrong(uint8_t count_ = 1) {

  Serial.print(String(tag) + F(" incorrect or incomplete command:\n") + String(tag) + F(" ") + char(prefix) + String(storageA));
  if (count_ > 1) {
    Serial.print("." + String(storageB));
  }
  if (count_ > 2) {
    Serial.print("." + String(storageC));
  }
  if (count_ > 3) {
    Serial.print("." + String(storageD));
  }
  Serial.println(F("<- here"));
}
/* [ADDON TEMPLATE]
  
  if (listmode_ == 1) {
    Serial.print(tag);
    Serial.println(F(" [name] addon: /extra.[your commands]"));
  }
  if (storageB == "[name]" or storageB == "[name short]") {
    found_ = 1;
    if(storageC=="[cmd1]" or storageC=="[cmd1 short]"){

    }
    else if(storageC=="[cmd2]" or storageC=="[cmd2 short]"){

    }
    else{
      Swrong(3);
      return;
    }
  }
  
*/
void extras(bool listmode_, bool found_ = 0) {
  //  V V V put your extras here V V V

  if (listmode_ == 0 && found_ == 0) {
    Serial.print(tag);
    Serial.println(F(" unknown extra"));
  }
}
/* [VARIABLE TEMPLATE] use .toInt() behind the last storageD if your variable is int

  else if(storageC=="[name]"){
    if(GorS==0){
      Serial.print(tag);
      Serial.print(F(" variable "));
      Serial.print(storageC);
      Serial.print(F(" is "));
      Serial.println([name]);
    }else {
      Serial.print(tag);
      Serial.print(F(" set variable "));
      Serial.print(storageC);
      Serial.print(F(" to "));
      Serial.println(storageD);
      [name] = storageD;
    }
  }

*/
//put your variables here
void VarCheck(bool GorS) {
  if (storageC == "example") {
    if (GorS == 0) {
      Serial.print(tag);
      Serial.print(F(" variable "));
      Serial.print(storageC);
      Serial.print(F(" is "));
      Serial.println(example);
    } else {
      Serial.print(tag);
      Serial.print(F(" set variable "));
      Serial.print(storageC);
      Serial.print(F(" to "));
      Serial.println(storageD);
      example = storageD.toInt();
    }
  }
  //  V V V paste the variable template here and fill out V V V

  else {
    Serial.print(tag);
    Serial.print(F(" variable "));
    Serial.print(storageC);
    Serial.println(F(" wasn't found"));
    Serial.print(tag);
    Serial.println(F(" maybe its missing or configurated wrong in VarCheck"));
  }
}
//reset info for arduino
#if defined(__AVR__)
void (*resetFunc)(void) = 0;
#endif
//main CMD
void SC() {
  if (Serial.available() > 0) {
    if (Serial.peek() != prefix) {
      if (autocmd == 0) {
        Serial.readStringUntil('\n');
        return;
      }
    }
    long longA, longB, longC;
    int intA, intB, intC, intD, intE;
    bool boolA, boolB;
    char charA;
    storageA = "";
    storageB = "";
    storageC = "";
    storageD = "";
    storageE = "";
    Base_ = Serial.readStringUntil('\n');
    Base_.trim();
    Base_.toLowerCase();
    if (echo == 1) {
      Serial.print(String(tag) + F("[RECEIVED:] "));
      Serial.println(Base_);
    }
    if (Base_.charAt(0) == prefix) {
      Base_.remove(0, 1);
    }
    storageA = Base_.substring(0, Base_.indexOf('.'));
    Base_.remove(0, storageA.length());
    if (Base_.charAt(0) == '.') {
      Base_.remove(0, 1);
    }
    storageB = Base_.substring(0, Base_.indexOf('.'));
    Base_.remove(0, storageB.length());
    if (Base_.charAt(0) == '.') {
      Base_.remove(0, 1);
    }
    storageC = Base_.substring(0, Base_.indexOf('.'));
    Base_.remove(0, storageC.length());
    if (Base_.charAt(0) == '.') {
      Base_.remove(0, 1);
    }
    storageD = Base_.substring(0, Base_.indexOf('.'));
    Base_.remove(0, storageD.length());
    if (Base_.charAt(0) == '.') {
      Base_.remove(0, 1);
    }
    storageE = Base_.substring(0, Base_.indexOf('.'));
    Base_.remove(0, storageE.length());
    if (Base_.charAt(0) == '.') {
      Base_.remove(0, 1);
    }
    if (storageA == "help" or storageA == "h") {
      if (storageB == "get" or storageB == "g") {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all get commands:"));
        Serial.print(tag);
        Serial.println(F(" /get.pm.{pin}  /get.pinmode.{pin} > get the pinmode of a pin"));
        Serial.print(tag);
        Serial.println(F(" /get.r.{pin}  /get.read.{pin} > get digitalread and analogread of a pin"));
        Serial.print(tag);
        Serial.println(F(" /get.m  /get.millis > get the millis value"));
        Serial.print(tag);
        Serial.println(F(" /get.v.{name}  /get.variable.{name} > get the content of a variable"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      } else if (storageB == "set" or storageB == "s") {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all set commands:"));
        Serial.print(tag);
        Serial.println(F(" /set.pm.{pin}.{o/i/ip}  /set.pinmode.{pin}.{o/i/ip} > set the pinmode of a pin (output/input/input_pullup)"));
        Serial.print(tag);
        Serial.println(F(" /set.dw.{pin}.{0/1}  /set.digitalwrite.{pin}.{0/1} > change the power of a pin (low/high or 0/1)"));
        Serial.print(tag);
        Serial.println(F(" /set.aw.{pin}.{0-255}  /set.analogwrite.{pin}.{0-255} > change the power of a pin (0-255)"));
        Serial.print(tag);
        Serial.println(F(" /set.v.{name}.{value/text}  /set.variable.{name}.{value/text} > change the content of a variable"));
        Serial.print(tag);
        Serial.println(F(" /set.lb  /set.ledbuildin > toggle build in arduino led"));
        Serial.print(tag);
        Serial.println(F(" /set.r  /set.restart > restarts the arduino"));
        Serial.print(tag);
        Serial.println(F(" /set.t{pin}.{frequency}  /set.tone{pin}.{frequency} > starts a tone at a pin with a custom frequency"));
        Serial.print(tag);
        Serial.println(F(" /set.nt{pin}  /set.notone{pin} > stops the tone at a pin"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      } else if (storageB == "manual" or storageB == "m") {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all get commands:"));
        Serial.print(tag);
        Serial.println(F(" /manual.ping > test the connection to the serial by getting it to send 'pong'"));
        Serial.print(tag);
        Serial.println(F(" /manual.b.{pin}.{delay}  /manual.blink.{pin}.{delay} > get a pin to blink in a custom delay"));
        Serial.print(tag);
        Serial.println(F(" /manual.d.{delay}  /manual.delay.{delay} > create a delay to pause your programm"));
        Serial.print(tag);
        Serial.println(F(" /manual.p  /manual.pause > pause your programm until you run /cancel"));
        Serial.print(tag);
        Serial.println(F(" /manual.w.a.{pin}.{delay}  /manual.watch.all.{pin}.{delay} > watch a pin and send its status with a custom delay"));
        Serial.print(tag);
        Serial.println(F(" /manual.w.c.{pin}  /manual.watch.change.{pin} > watch a pin and send its status when it changes"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      } else if (storageB == "settings" or storageB == "sg") {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all settings commands:"));
        Serial.print(tag);
        Serial.println(F(" /settings.acmd.{ON/OFF}  /settings.autocommand.{ON/OFF} > turn auto-command on or off"));
        Serial.print(tag);
        Serial.println(F(" /settings.e.{ON/OFF}  /settings.echo{ON/OFF} > turn echo mode on or off"));
        Serial.print(tag);
        Serial.println(F(" /settings.i  /settings.info > show the states of all settings"));
        Serial.print(tag);
        Serial.println(F(" /settings.prfx.{prefix}  /settings.prefix.{prefix} > change the command prefix"));
        Serial.print(tag);
        Serial.println(F(" /settings.t.{tag}  /settings.tag.{tag} > change the [CMD] tag to something else"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      } else if (storageB == "extra" or storageB == "e") {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all extra commands:"));
        Serial.print(tag);
        Serial.println(F(" /extra.{extras} > access extra features (addons)"));
        Serial.print(tag);
        Serial.println(F(" /extra.l  /extra.list > show the list of extras"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      } else {
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
        Serial.print(tag);
        Serial.println(F(" all help commands:"));
        Serial.print(tag);
        Serial.println(F(" /help.g  /help.get"));
        Serial.print(tag);
        Serial.println(F(" /help.s  /help.set"));
        Serial.print(tag);
        Serial.println(F(" /help.m  /help.manual"));
        Serial.print(tag);
        Serial.println(F(" /help.sg  /help.settings"));
        Serial.print(tag);
        Serial.println(F(" /help.e  /help.extra"));
        Serial.print(tag);
        Serial.println(F(" ----------------------------------------------------------"));
      }
    } else if (storageA == "get" or storageA == "g") {
      if (storageB == "pm" or storageB == "pinmode") {
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        intA = storageC.toInt();
        Serial.print(tag);
        Serial.print(F(" pinmode on pin "));
        Serial.print(intA);
        Serial.print(F(" is: "));
#if defined(__AVR__)
        intB = digitalPinToBitMask(intA);
        intC = digitalPinToPort(intA);
        volatile uint8_t *_a_ = portModeRegister(intC);
        volatile uint8_t *_b_ = portOutputRegister(intC);
        if (*_a_ & intB) {
          Serial.println(F("OUTPUT"));
        } else if (*_b_ & intB) {
          Serial.println(F("INPUT_PULLUP"));
        } else {
          Serial.println(F("INPUT"));
        }
#elif defined(ESP8266)
        if (GPE & (1 << pin)) {
          Serial.println(F("OUTPUT"));
        } else if (GPC(pin) & (1 << GPCI)) {
          Serial.println(F("INPUT_PULLUP"));
        } else {
          Serial.println(F("INPUT"));
        }
#elif defined(ESP32)
        longA = GPIO_PIN_MUX_REG[pin];
        intB = (pin < 32) ? (GPIO.enable & (1 << pin)) : (GPIO.enable1.val & (1 << (pin - 32)));
        if (intB) {
          Serial.println(F("OUTPUT"));
        } else if (REG_GET_BIT(longA, FUN_PU)) {
          Serial.println(F("INPUT_PULLUP"));
        } else {
          Serial.println(F("INPUT"));
        }
#else
        Serial.println(F("NOT SUPPORTED ON THIS BOARD"));
#endif #
      } else if (storageB == "read" or storageB == "r") {
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        Serial.print(tag);
        Serial.print(F(" pin: "));
        Serial.print(storageC.toInt());
        Serial.print(F("  digitalread: "));
        Serial.print(digitalRead(storageC.toInt()) == 1 ? F("HIGH") : F("LOW"));
        Serial.print(F("  analogread: "));
        Serial.println(analogRead(storageC.toInt()));
      } else if (storageB == "m" or storageB == "millis") {
        Serial.print(tag);
        Serial.print(F(" "));
        Serial.print(millis());
        Serial.print(F("ms  ("));
        Serial.print(millis() / 1000 / 60 / 60 / 24);
        Serial.print(F(" days  "));
        storageE = millis() / 1000 / 60 / 60 % 24;
        Serial.print(storageE.length() == 1 ? F("0") : F(""));
        Serial.print(storageE);
        Serial.print(F(":"));
        storageE = millis() / 1000 / 60 % 60;
        Serial.print(storageE.length() == 1 ? F("0") : F(""));
        Serial.print(storageE);
        Serial.print(F(":"));
        storageE = millis() / 1000 % 60;
        Serial.print(storageE.length() == 1 ? F("0") : F(""));
        Serial.print(storageE);
        Serial.println(F(")"));
      } else if (storageB == "v" or storageB == "var" or storageB == "variable") {
        VarCheck(0);
      } else {
        Swrong(2);
      }
    } else if (storageA == "set" or storageA == "s") {
      if (storageB == "pm" or storageB == "pinmode") {
        intA = storageC.toInt();
        if (storageC == "") {
          Swrong(3);
          return;
        }
        if (storageD == "i" or storageD == "input") {
          intB = 0;
        } else if (storageD == "o" or storageD == "output") {
          intB = 1;
        } else if (storageD == "ip" or storageD == "inputpullup" or storageD == "input_pullup") {
          intB = 2;
        } else {
          Swrong(4);
          return;
        }
        pinMode(intA, intB);
        Serial.print(tag);
        Serial.print(F(" set pinmode on pin "));
        Serial.print(intA);
        Serial.print(F(" to "));
        Serial.println(intB > 1 ? F("INPUT_PULLUP") : intB == 1 ? F("OUTPUT")
                                                                : F("INPUT"));
      } else if (storageB == "v" or storageB == "var" or storageB == "variable") {
        VarCheck(1);
      } else if (storageB == "dw" or storageB == "digitalwrite") {
        intA = storageC.toInt();
        if (storageD == "high" or storageD == "true" or storageD == "1") {
          boolA = 1;
        } else {
          boolA = 0;
        }
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        digitalWrite(intA, boolA);
        Serial.print(tag);
        Serial.print(F(" set power on pin "));
        Serial.print(intA);
        Serial.print(F(" to "));
        Serial.println(boolA == 1 ? F("high") : F("low"));
      } else if (storageB == "aw" or storageB == "analogwrite") {
        intA = storageC.toInt();
        intB = storageD.toInt();
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        if (intB > 255 or 0 > intB) {
          Serial.print(tag);
          Serial.println(F(" power has to be between 0 and 255"));
          return;
        }
        analogWrite(intA, intB);
        Serial.print(tag);
        Serial.print(F(" set power on pin "));
        Serial.print(intA);
        Serial.print(F(" to "));
        Serial.println(intB);
      } else if (storageB == "lb" or storageB == "ledbuildin") {
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        Serial.print(tag);
        Serial.print(F(" toggled the built in led "));
        Serial.println(digitalRead(LED_BUILTIN) == 1 ? F("on") : F("off"));
      } else if (storageB == "r" or storageB == "restart") {
        Serial.print(tag);
        Serial.println(F(" restarting..."));
        Serial.flush();
        delay(50);
#if defined(__AVR__)
        resetFunc();
#elif defined(ESP32) or defined(ESP8266)
        ESP.restart();
#else
        NVIC_SystemReset();
#endif
      } else if (storageB == "t" or storageB == "tone") {
        intA = storageC.toInt();
        intB = storageD.toInt();
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        if (storageD == "") {
          Serial.print(tag);
          Serial.println(F(" frequency is missing"));
          return;
        }
        tone(intA, intB);
        Serial.print(tag);
        Serial.print(F(" startet tone at pin "));
        Serial.print(intA);
        Serial.print(F(" with frequency "));
        Serial.println(intB);
      } else if (storageB == "nt" or storageB == "notone") {
        intA = storageC.toInt();
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        noTone(intA);
        Serial.print(tag);
        Serial.print(F(" stopped tone at pin "));
        Serial.print(intA);
      } else {
        Swrong(2);
      }
    } else if (storageA == "manual" or storageA == "m") {
      if (storageB == "p" or storageB == "pause") {
        Serial.print(tag);
        Serial.println(F(" paused arduino"));
        Serial.print(tag);
        Serial.println(F(" use /c or /cancel to resume"));
        intA = 0;
        longA = millis();
        while (intA == 0) {
          if (Serial.available() > 0) {
            if (Serial.peek() != prefix && autocmd == 0) {
              Serial.readStringUntil('\n');
            } else {
              storageE = Serial.readStringUntil('\n');
              storageE.trim();
              storageD = storageE.substring(0, storageE.indexOf('.'));
              if (echo == 1) {
                Serial.print(String(tag) + F("[RECEIVED:] "));
                Serial.println(storageE);
              }
              if (storageD.charAt(0) == prefix) {
                storageD.remove(0, 1);
              }
              if (storageD == "c" or storageD == "cancel") {
                break;
              }
            }
          }
        }
        Serial.print(tag);
        Serial.println(F(" arduino  resumed"));
        Serial.print(tag);
        Serial.print(F(" time paused: "));
        Serial.print(millis() - longA);
        Serial.println(F("ms"));
      } else if (storageB == "delay" or storageB == "d") {
        longB = storageC.toInt();
        if (longB > 100000000) {
          Serial.print(tag);
          Serial.println(F(" delay is too high"));
          return;
        }
        if (storageC == "" or storageC.toInt() == 0) {
          Serial.print(tag);
          Serial.println(F(" delay is missing or too low"));
          return;
        }
        Serial.print(tag);
        Serial.print(F(" created delay: "));
        Serial.print(longB);
        Serial.println(F("ms"));
        Serial.print(tag);
        Serial.println(F(" use /c or /cancel to resume"));
        longA = millis();
        while (longB > millis() - longA) {
          if (Serial.available() > 0) {
            if (Serial.peek() != prefix && autocmd == 0) {
              Serial.readStringUntil('\n');
            } else {
              storageE = Serial.readStringUntil('\n');
              storageE.trim();
              storageD = storageE.substring(0, storageE.indexOf('.'));
              if (echo == 1) {
                Serial.print(String(tag) + F("[RECEIVED:] "));
                Serial.println(storageE);
              }
              if (storageD.charAt(0) == prefix) {
                storageD.remove(0, 1);
              }
              if (storageD == "c" or storageD == "cancel") {
                Serial.print(tag);
                Serial.print(F(" canceled delay with time paused being: "));
                Serial.print(millis() - longA);
                Serial.println(F("ms"));
                return;
              }
            }
          }
        }
        Serial.print(tag);
        Serial.print(F(" delay with time: "));
        Serial.print(millis() - longA);
        Serial.println(F("ms finished"));
      } else if (storageB == "ping") {
        Serial.print(tag);
        Serial.println(F(" pong!"));
      } else if (storageB == "b" or storageB == "blink") {
        intA = storageC.toInt();
        if (storageD != "") {
          intB = storageD.toInt();
        } else {
          intB = 1000;
        }
        if (intB > 15000) {
          Serial.print(tag);
          Serial.print(F(" delay is too high"));
          return;
        }
        intC = 1;
        Serial.print(tag);
        Serial.print(F(" started blinking pin "));
        Serial.print(intA);
        Serial.print(F(" with delay: "));
        Serial.print(intB);
        Serial.println(F("ms"));
        Serial.print(tag);
        Serial.println(F(" use /c or /cancel to stop blinking"));
        while (1 == 1) {
          digitalWrite(intA, intC);
          if (intC == 1) {
            intC = 0;
          } else {
            intC = 1;
          }
          longA = millis();
          while (intB > longA - millis()) {
            if (Serial.available() > 0) {
              if (Serial.peek() != prefix && autocmd == 0) {
                Serial.readStringUntil('\n');
              } else {
                storageE = Serial.readStringUntil('\n');
                storageE.trim();
                storageD = storageE.substring(0, storageE.indexOf('.'));
                if (echo == 1) {
                  Serial.print(String(tag) + F("[RECEIVED:] "));
                  Serial.println(storageE);
                }
                if (storageD.charAt(0) == prefix) {
                  storageD.remove(0, 1);
                }
                if (storageD == "c" or storageD == "cancel") {
                  Serial.print(tag);
                  Serial.print(F(" stopped blinking pin "));
                  Serial.println(intA);
                  return;
                }
              }
            }
          }
        }
      } else if (storageB == "w" or storageB == "watch") {
        if (storageC == "") {
          Swrong(3);
        }
        if (storageD == "") {
          Serial.print(tag);
          Serial.println(F(" pin is missing"));
          return;
        }
        intA = storageD.toInt();
        if (storageC == "a" or storageC == "all") {
          intB = storageE.toInt();
          boolA = 0;
        } else if (storageC == "c" or storageC == "change") {
          intB = 20;
          boolA = 1;
          if (digitalRead(intA) == 1) {
            boolB = 0;
          } else {
            boolB = 1;
          }
        } else {
          Swrong(3);
          return;
        }
        Serial.print(tag);
        Serial.print(F(" startet watching pin "));
        Serial.println(intA);
        while (1 == 1) {
          if (boolA == 0) {
            Serial.print(tag);
            Serial.print(F(" pin: "));
            Serial.print(intA);
            Serial.print(F("  digitalread: "));
            Serial.print(digitalRead(intA) == 1 ? F("HIGH") : F("LOW "));
            Serial.print(F("  analogread: "));
            Serial.println(analogRead(intA));
          } else if (boolA == 1) {
            if (boolB != digitalRead(intA)) {
              Serial.print(tag);
              Serial.print(F(" pin: "));
              Serial.print(intA);
              Serial.print(F("  digitalread: "));
              Serial.print(digitalRead(intA) == 1 ? F("HIGH") : F("LOW "));
              Serial.print(F("  analogread: "));
              Serial.println(analogRead(intA));
              boolB = digitalRead(intA);
            }
          }
          longA = millis();
          while (intB > millis() - longA) {
            if (Serial.available() > 0) {
              if (Serial.peek() != prefix && autocmd == 0) {
                Serial.readStringUntil('\n');
              } else {
                storageE = Serial.readStringUntil('\n');
                storageE.trim();
                storageD = storageE.substring(0, storageE.indexOf('.'));
                if (echo == 1) {
                  Serial.print(String(tag) + F("[RECEIVED:] "));
                  Serial.println(storageE);
                }
                if (storageD.charAt(0) == prefix) {
                  storageD.remove(0, 1);
                }
                if (storageD == "c" or storageD == "cancel") {
                  Serial.print(tag);
                  Serial.print(F(" stopped watching pin "));
                  Serial.println(intA);
                  return;
                }
              }
            }
          }
        }
      } else {
        Swrong(2);
      }
    } else if (storageA == "settings" or storageA == "sg") {
      if (storageB == "acmd" or storageB == "autocommand") {
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" mode is missing (on/off)"));
          return;
        }
        if (storageC == "on" or storageC == "true" or storageC == "1") {
          boolA = 1;
        } else if (storageC == "off" or storageC == "false" or storageC == "0") {
          boolA = 0;
        } else {
          Swrong(3);
          return;
        }
        if (boolA == autocmd) {
          Serial.print(tag);
          Serial.print(F(" auto-command is already "));
          Serial.println(boolA == 1 ? F("ON") : F("OFF"));
        } else {
          Serial.print(tag);
          Serial.print(F(" turned auto-command "));
          Serial.println(boolA == 1 ? F("ON") : F("OFF"));
          autocmd = boolA;
        }
      } else if (storageB == "prfx" or storageB == "prefix") {
        if (storageC.length() != 1) {
          Serial.print(tag);
          Serial.println(F(" prefix has to be one character/symbol"));
          return;
        }
        prefix = storageC.charAt(0);
        Serial.print(tag);
        Serial.print(F(" changed prefix to "));
        Serial.println(prefix);
      } else if (storageB == "tag" or storageB == "t") {
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" tag is missing"));
          return;
        }
        tag = "[" + storageC + "]";
        tag.toUpperCase();
        Serial.print(tag);
        Serial.print(F(" changed tag to "));
        Serial.println(tag);
      } else if (storageB == "e" or storageB == "echo") {
        if (storageC == "") {
          Serial.print(tag);
          Serial.println(F(" mode is missing (on/off)"));
          return;
        }
        if (storageC == "on" or storageC == "true" or storageC == "1") {
          boolA = 1;
        } else if (storageC == "off" or storageC == "false" or storageC == "0") {
          boolA = 0;
        } else {
          Swrong(3);
          return;
        }
        if (boolA == echo) {
          Serial.print(tag);
          Serial.print(F(" echo mode is already "));
          Serial.println(boolA == 1 ? F("ON") : F("OFF"));
        } else {
          Serial.print(tag);
          Serial.print(F(" turned echo mode "));
          Serial.println(boolA == 1 ? F("ON") : F("OFF"));
          echo = boolA;
        }
      } else if (storageB == "i" or storageB == "info") {
        Serial.print(tag);
        Serial.print(F(" autocommand: "));
        Serial.print(autocmd == 1 ? F("ON") : F("OFF"));
        Serial.print(F("   echo mode: "));
        Serial.print(echo == 1 ? F("ON") : F("OFF"));
        Serial.print(F("   prefix: "));
        Serial.print(prefix);
        Serial.print(F("   tag: "));
        Serial.print(tag);
      } else {
        Swrong(2);
      }
    } else if (storageA == "extra" or storageA == "e") {
      if (storageB == "l" or storageB == "list") {
        Serial.print(tag);
        Serial.println(F(" all extras:"));
        extras(1);
      } else {
        extras(0);
      }
    } else if (storageA == "c" or storageA == "cancel") {
      Serial.print(tag);
      Serial.print(F(" there is no action that can be canceled"));
    } else {
      Swrong(1);
    }
  }
}