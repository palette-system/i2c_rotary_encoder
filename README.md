# I2C ロータリーエンコーダ

<img src="/images/pcb_front.png" height="200">
<br><br><br>


## 説明

I2CロータリエンコーダはATTiny202を利用したロータリエンコーダの操作をI2C越しに読み込みをするための基板です。

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
    <td>rotary0_A</td>
    <td>7</td>
    <td>PA3</td>
    <td>rotary1_A</td>
  </tr>
  <tr>
    <td>3</td>
    <td>PA7</td>
    <td>rotary0_B</td>
    <td>6</td>
    <td>PA0</td>
    <td>rotary1_B</td>
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


## 開発環境の作り方

<a href="https://ameblo.jp/pta55/entry-12654450554.html" target="_blank">https://ameblo.jp/pta55/entry-12654450554.html</a>
<br><br>


## 詳細情報

電圧：　1.8V　～　5.5V  
信号：　I2C　（～1.7MHz）
<br><br>


