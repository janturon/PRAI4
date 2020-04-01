int serial_putchar(char c, FILE* stream) {
  Serial.write(c);
  return 1;
}

int serial_getchar(FILE* stream) {
  while(!Serial.available());
  return Serial.read();
}

FILE serial_out;
FILE serial_in;

void setup() {
  Serial.begin(9600);
  fdev_setup_stream(&serial_out, serial_putchar, NULL, _FDEV_SETUP_WRITE);
  fdev_setup_stream(&serial_in, NULL, serial_getchar, _FDEV_SETUP_READ);
  stdout = &serial_out;
  stdin = &serial_in;
  int teplota = 27;
  char buffer[16];
  scanf("%s", buffer);
  printf("Teplota je %s", buffer);
}

void loop() {
  // put your main code here, to run repeatedly:

}