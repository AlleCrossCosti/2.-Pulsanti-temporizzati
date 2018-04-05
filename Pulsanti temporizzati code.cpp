// Pin del pulsante 
const byte PIN_PULSANTE = 2;
// Pin deii due LED
const byte PIN_LEDVERDE = 13;
const byte PIN_LEDROSSO = 12;
// Variabile di stato del pulsante
byte statoPulsante;
byte statoPulsanteePrecedente;
// Variabili per la misura del tempo
unsigned long int intervallo = 0;
unsigned long int primoEvento = 0;

void setup () {
    // LED in OUTPUT
pinMode (PIN_LEDVERDE, OUTPUT) ;
pinMode (PIN_LEDROSSO, OUTPUT) ;
// pulsante in INPUT
pinMode (PIN_PULSANTE, INPUT) ;
// leggo il pulsante e memorizzo lo stato iniziale
statoPulsantePrecedente = digitalRead (PIN_PULSANTE) ;

}

void loop () {
    //Leggo il pulsante e memorizzo lo stato
    statoPulsante = digitalRead (PIN_PULSANTE) ;

    // se il pin è HIGH, ma prima non lo era...
    if (statoPulsante == HIGH && statoPulsantePrecedente == LOW) {
        // Memorizzo quando è stato premuto il pulsante
        primoEvento = millis () ;

        statoPulsantePrecedente = statoPulsante;

        }
        //se il pin è LOW ma prima non lo era...
        else if (statoPulsante == LOW && statoPulsantePrecedente == HIGH) {

            // Calcolo quanto tempo è stato premuto
            // il pulsante e lo memorizzo
            intervallo = millis () - primoEvento;

            // Se il tempo è inferiore ad un secondo...
            if (intervallo < 1000) {
                digitalWrite (PIN_LEDVERDE, !digitalRead (PIN_LEDVERDE) ) ;


         }   
         // altrimenti, se è maggiore...
         else   {
             digitalWrite (PIN_LEDROSSO, !digitalRead (PIN_LEDROSSO) );

         } 
         statoPulsantePrecedente = statoPulsante;

     } 

     delay (10) ;

  }              