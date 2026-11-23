// Definisi Pin Sensor IR (Kabel Hitam OUT)
const int sensorKiri = 2;  // OUT Sensor Kiri -> Pin 2
const int sensorKanan = 3; // OUT Sensor Kanan -> Pin 3

// Definisi Pin Driver Motor L298N (Susunan Pin 11 - 6)
const int ENA = 11; // Kabel Cokelat (Motor Kiri)
const int IN1 = 10; // Kabel Merah
const int IN2 = 9;  // Kabel Kuning
const int IN3 = 8;  // Kabel Oranye (Motor Kanan)
const int IN4 = 7;  // Kabel Hijau
const int ENB = 6;  // Kabel Biru

// Pengaturan Kecepatan Motor (0 - 255)
int kecepatanMaju = 140;  // Kecepatan jalan lurus
int kecepatanBelok = 230; // Kecepatan tinggi agar kuat memutar 4 ban saat belok

void setup() {
  Serial.begin(9600);

  pinMode(sensorKiri, INPUT);
  pinMode(sensorKanan, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  int bacaKiri = digitalRead(sensorKiri);
  int bacaKanan = digitalRead(sensorKanan);

  // Pantau status sensor di Serial Monitor (0 = Lantai Putih, 1 = Garis Hitam)
  Serial.print("Kiri: ");
  Serial.print(bacaKiri);
  Serial.print(" | Kanan: ");
  Serial.println(bacaKanan);

  // Kondisi 1: Kedua sensor di lantai putih (0 dan 0) -> Maju lurus
  if (bacaKiri == LOW && bacaKanan == LOW) {
    maju();
  }
  // Kondisi 2: Sensor kiri kena garis hitam (1) -> Belok kiri
  else if (bacaKiri == HIGH && bacaKanan == LOW) {
    belokKiri();
  }
  // Kondisi 3: Sensor kanan kena garis hitam (1) -> Belok kanan
  else if (bacaKiri == LOW && bacaKanan == HIGH) {
    belokKanan();
  }
  // Kondisi 4: Kedua sensor kena garis hitam (1 dan 1) -> Berhenti (garis finish/perempatan)
  else {
    berhenti();
  }
}

void maju() {
  analogWrite(ENA, kecepatanMaju);
  analogWrite(ENB, kecepatanMaju);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void belokKiri() {
  analogWrite(ENA, kecepatanBelok);
  analogWrite(ENB, kecepatanBelok);
  digitalWrite(IN1, LOW);   // Roda kiri mundur
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);  // Roda kanan maju
  digitalWrite(IN4, LOW);
}

void belokKanan() {
  analogWrite(ENA, kecepatanBelok);
  analogWrite(ENB, kecepatanBelok);
  digitalWrite(IN1, HIGH);  // Roda kiri maju
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);   // Roda kanan mundur
  digitalWrite(IN4, HIGH);
}

void berhenti() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
