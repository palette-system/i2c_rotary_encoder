// ロータリーエンコーダーの入力をI2Cに流す

// 開発環境の作り方
// https://ameblo.jp/pta55/entry-12654450554.html

#include <Wire.h>
#include <avr/pgmspace.h> 

// ATTiny202 本体のアドレス
#define I2C_SLAVE_ADD 0x45

uint8_t key_input = 0x00;
uint8_t old_input = 0x00;
uint8_t send_input = 0x00;

// I2Cデータ要求を受け取った時の処理
void requestEvent();

void setup() {
    // ロータリーエンコーダ読み込みピンの初期化
    pinMode(A7, INPUT_PULLUP);
    pinMode(A6, INPUT_PULLUP);
    pinMode(A0, INPUT_PULLUP);
    pinMode(A3, INPUT_PULLUP);
  
    // I2C スレーブ初期化
    Wire.begin(I2C_SLAVE_ADD);
    Wire.onRequest(requestEvent);

}

// I2Cデータ要求を受け取った時の処理
void requestEvent() {
    Wire.write(send_input);
    send_input = 0x00;
}

void loop() {
  // key read
  old_input = key_input;

  // 今回分を読み取り
  key_input = 0x00;
  if (digitalRead(A6)) key_input |= 0x01;
  if (digitalRead(A7)) key_input |= 0x02;
  if (digitalRead(A0)) key_input |= 0x04;
  if (digitalRead(A3)) key_input |= 0x08;

  // ロータリーエンコーダー０
  if ((old_input & 0x03) == 0x03) { // 前の読み取りが AB両方ONだった
      if ((key_input & 0x01) && !(key_input & 0x02)) { // 今回Aのみ
          send_input |= 0x01;
      } else if (!(key_input & 0x01) && (key_input & 0x02)) { // 今回Bのみ
          send_input |= 0x02;
      }
  }

  // ロータリーエンコーダー１
  if ((old_input & 0x0c) == 0x0c) { // 前の読み取りが AB両方ONだった
      if ((key_input & 0x04) && !(key_input & 0x08)) { // 今回Aのみ
          send_input |= 0x04;
      } else if (!(key_input & 0x04) && (key_input & 0x08)) { // 今回Bのみ
          send_input |= 0x08;
      }
  }

  delay(2);
}
