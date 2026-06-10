.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

Servo
===========

Un servo è un motore specializzato noto per la sua precisione nel controllare specifiche posizioni angolari.

.. image:: img/servo.png
    :align: center

* **Linea marrone**: GND
* **Linea arancione**: Pin di segnale, collegare al pin PWM della scheda principale.
* **Cavo rosso**: VCC

A differenza dei motori normali che girano continuamente, un servo può spostarsi in una posizione precisa e mantenerla accuratamente. Riesce a farlo grazie a una combinazione di ingranaggi, un potenziometro e un circuito di controllo. I servi sono comunemente utilizzati in varie applicazioni che richiedono un controllo preciso sulla posizione di oggetti o meccanismi.

**Caratteristiche**

* **Tipo motore**: Motore a nucleo
* **Tensione operativa**: 4,8~6V CC
* **Corrente di standby**: ≤4 mA
* **Corrente di consumo (a 4,8V senza carico)**: ≦50mA
* **Corrente di consumo (a 6V senza carico)**: ≦60mA
* **Corrente di stallo (a bloccaggio 4,8V)**: ≦550mA
* **Corrente di stallo (a bloccaggio 6V)**: ≦650mA
* **Coppia nominale**: 4,8V, ≥0,6 kgf·cm; 6V, ≥0,7 kgf·cm
* **Coppia massima**: 4,8V, ≥1,4 kgf.cm; 6V, ≥1,6 kgf.cm
* **Velocità senza carico**: 4,8V, ≦0,14sec/60°; 6V, ≦0,12sec/60°
* **Nota**: Protezione torsione:≥0,9 kgf.cm; Protezione interruzione alimentazione dopo 5 secondi di funzionamento continuo
* **Intervallo temperatura operativa**: -10℃~+50℃
* **Intervallo temperatura di stoccaggio**: -20℃~+60℃
* **Intervallo umidità operativa**: ≤ 90%UR
* **Intervallo umidità di stoccaggio**: ≤ 90%UR
* **Peso**: 10± 0,5g
* **Materiale**: ABS
* **Angolo operativo**: 180°±10°(500~2500us)
* **Angolo limite meccanico**: 360°
* **Angolo di escursione sinistra e destra**: ≤ 6°
* **Deviazione di centratura**: ≤ 1°
* **Gioco**: ≤ 4 us
* **Tipo amplificatore**: Digitale
* **Materiale cavo**: Ф1,08,19 PVC
* **Lunghezza cavo**: 245±5mm (escluso senza spine)
* **Tipo connettore**: JR2.54mm/3Pin

**Principio di funzionamento**

All'interno di un servo, componenti essenziali contribuiscono alla sua funzionalità unica. Al suo centro, un servo incorpora un motore convenzionale; questo motore è intricatamente collegato a un grande ingranaggio, che a sua volta si ingrana con un ingranaggio più piccolo sull'albero motore. Questa disposizione di ingranaggi converte efficientemente il rapido movimento circolare del motore in movimenti più lenti ma potenti.

.. image:: img/servo_internal.png

Ma la vera magia avviene all'interno del servo, grazie a una minuscola meraviglia elettronica nota come "potenziometro" e a un sofisticato "circuito di controllo". Quando il servo subisce un movimento, il potenziometro ruota, alterando la sua resistenza elettrica. Il circuito di controllo rileva e interpreta questo cambiamento di resistenza con notevole precisione, determinando così la posizione esatta del servo. Questa è una testimonianza della sua ingegnosità.

Nel campo del controllo dei servi, entra in gioco un metodo di segnalazione unico chiamato "modulazione a larghezza di impulso" o PWM. Regolando abilmente la larghezza di questi impulsi, gli operatori possono comandare al servo di muoversi con precisione e mantenere la sua posizione. Questa è l'essenza della tecnologia dei servomotori, un regno dove precisione e controllo convergono per abilitare una vasta gamma di applicazioni.
