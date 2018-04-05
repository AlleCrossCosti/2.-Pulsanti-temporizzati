const byte LED = 13;
const byte PULSANTE = 2;

void setup () {
    pinMode (LED, OUTPUT) ;
    pinMode (PULSANTE, INPUT) ;

    // Adesso devo fermarsi qui se il pulsante non è premuto
    // (LOW) e rimanerci finché non è premuto
    while (digitalRead (PULSANTE) == LOW) {
      // non devo fare niente....
   }

}

// Una volta premuto, entra nel loop
// ed esegue un semplice Hello Blink
void loop ()  {
    digitalWrite (LED, HIGH) ;
    delay (1000) ;
    digitalWrite (LED, LOW) ;
    delay (1000) ;

}