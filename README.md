# I2C ロータリーエンコーダ

<img src="/images/pcb_front.png" height="200">
<br><br><br>


## 説明

I2CロータリエンコーダはATTiny202を利用したロータリエンコーダの操作をI2C越しに読み込みをするための基板です。<br>
(販売はDIP変換基板と、下記ファームウェアを書き込んだATTiny202を販売します)<br>
<br>

ファームウェアソース<br>
<a href="https://github.com/palette-system/i2c_rotary_encoder/edit/main/software/i2c_rotary_encorder/i2c_rotary_encorder.ino" target="_blank">software/i2c_rotary_encorder/i2c_rotary_encorder.ino</a>

<br><br>


## ATTiny202 ピン

<img src="/images/connect.png">

<table>
  <tr>
    <th>番号</th>
    <th>ピン</th>
    <th>接続</th>
    <td rowspan="5">　</td>
    <th>番号</th>
    <th>ピン</th>
    <th>接続</th>
  </tr>
  <tr>
    <td>1</td>
    <td>VDD</td>
    <td>VCC</td>
    <td>8</td>
    <td>GND</td>
    <td>GND</td>
  </tr>
  <tr>
    <td>2</td>
    <td>PA6</td>
    <td>rotary1_B</td>
    <td>7</td>
    <td>PA3</td>
    <td>rotary0_B</td>
  </tr>
  <tr>
    <td>3</td>
    <td>PA7</td>
    <td>rotary1_A</td>
    <td>6</td>
    <td>PA0</td>
    <td>rotary0_A</td>
  </tr>
  <tr>
    <td>4</td>
    <td>PA1</td>
    <td>I2C SDA</td>
    <td>5</td>
    <td>PA2</td>
    <td>I2C SCL</td>
  </tr>
</table>
<br><br>



## アドレス設定方法

プログラムの中に固定値でアドレスを指定しているため、ビルドして書込みを行わない限りアドレスの変更はできません。<br>
デフォルトで 0x45 が書き込まれています。<br>
<br><br>


## メリット、デメリット
■　メリット<br>
　・マイコンのI/Oを消費しない<br>
　・アドレス変えていけば割といっぱい付けられる<br>
<br>
■　デメリット<br>
　・実装するICと消費電力が増える<br>
　<br><br>

## 読み込み方
I2Cでアドレスを指定して1バイトリクエストするだけで取得できます。<br>
最後にデータ取得した時から現在までにロータリエンコーダの操作があった場合に該当のビットが１になって帰ってきます。<br>
一度取得するとまた０になり、ロータリエンコーダが操作されるまで０を取得します。<br>
```
  uint8_t r;
  Wire.requestFrom(0x45, 1); // 指定したアドレスのATTiny202に1バイト分データ取得要求
  r = Wire.read(); // 1バイトデータ受け取る
  if (r & 0x08) # ロータリエンコーダ０左回り
  if (r & 0x04) # ロータリエンコーダ０右回り
  if (r & 0x02) # ロータリエンコーダ１左回り
  if (r & 0x01) # ロータリエンコーダ１右回り
```
　<br><br>

## AZ-CORE、えむごっち等に接続する場合のAZTOOL手順

https://twitter.com/4py1/status/1559090793159458816
https://twitter.com/4py1/status/1559088312589365248

## ATTiny202 開発環境の作り方

<a href="https://ameblo.jp/pta55/entry-12654450554.html" target="_blank">https://ameblo.jp/pta55/entry-12654450554.html</a>
<br><br>


## 詳細情報

電圧：　1.8V　～　5.5V  
信号：　I2C　（～1.7MHz）
<br><br>


