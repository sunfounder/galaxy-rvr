.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci il tuo interesse per Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto tecnico**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime speciali.
    - **Sconti esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Servo
===========

Un servo è un motore specializzato noto per la sua precisione nel controllo di posizioni angolari specifiche.

.. image:: img/servo.png
    :align: center

* **Linea marrone**: GND
* **Linea arancione**: Pin del segnale, collegato al pin PWM della scheda principale.
* **Filo rosso**: VCC

A differenza dei motori normali che ruotano continuamente, un servo può muoversi in una posizione precisa e mantenerla con accuratezza. Ciò avviene attraverso una combinazione di ingranaggi, un potenziometro e circuiti di controllo. I servocomandi vengono utilizzati in molte applicazioni che richiedono un controllo preciso della posizione di oggetti o meccanismi.

**Caratteristiche**

* **Tipo di motore**: Motore a spazzole
* **Tensione di funzionamento**: 4.8~6V DC
* **Corrente di standby**: ≤4 mA
* **Corrente di consumo (a 4.8V senza carico)**: ≦50mA
* **Corrente di consumo (a 6V senza carico)**: ≦60mA
* **Corrente di stallo (a 4.8V bloccato)**: ≦550mA
* **Corrente di stallo (a 6V bloccato)**: ≦650mA
* **Coppia nominale**: 4.8V, ≥0.6 kgf·cm; 6V, ≥0.7 kgf·cm
* **Coppia massima**: 4.8V, ≥1.4 kgf.cm; 6V, ≥1.6 kgf.cm
* **Velocità senza carico**: 4.8V, ≦0.14 sec/60°; 6V, ≦0.12 sec/60°
* **Nota**: Protezione torsione: ≥0.9 kgf.cm; Protezione da interruzione di alimentazione dopo 5 secondi di uso continuo
* **Intervallo di temperatura di funzionamento**: -10℃~+50℃
* **Intervallo di temperatura di conservazione**: -20℃~+60℃
* **Intervallo di umidità operativa**: ≤ 90%RH
* **Intervallo di umidità di conservazione**: ≤ 90%RH
* **Peso**: 10± 0.5g
* **Materiale**: ABS
* **Angolo di funzionamento**: 180°±10°(500~2500us)
* **Angolo di limite meccanico**: 360°
* **Angolo di viaggio sinistra/destra**: ≤ 6°
* **Deviazione centrale**: ≤ 1°
* **Gioco**: ≤ 4 us
* **Tipo di amplificatore**: Digitale
* **Materiale del cavo**: Ф1.08,19 PVC
* **Lunghezza del cavo**: 245±5mm (senza spine)
* **Tipo di connettore**: JR2.54mm/3Pin

**Principio di funzionamento**

All'interno di un servo, componenti essenziali contribuiscono alla sua funzionalità unica. Alla base di un servo c'è un motore convenzionale, collegato a un grande ingranaggio che, a sua volta, si connette a un ingranaggio più piccolo sull'albero del motore. Questa configurazione di ingranaggi converte efficacemente il movimento circolare rapido del motore in movimenti più lenti ma potenti.

.. image:: img/servo_internal.png

La vera magia, però, accade grazie a un piccolo componente elettronico chiamato "potenziometro" e a un sofisticato circuito di controllo. Quando il servo si muove, il potenziometro ruota, modificando la sua resistenza elettrica. Il circuito di controllo rileva e interpreta questo cambiamento di resistenza con estrema precisione, determinando così la posizione esatta del servo. Questo dimostra l'ingegnosità del sistema.

Nel controllo del servo entra in gioco un metodo di segnalazione unico chiamato "modulazione di larghezza di impulso" o PWM. Regolando abilmente la larghezza di questi impulsi, gli operatori possono comandare al servo di muoversi con precisione e mantenerne la posizione. Questa è l'essenza della tecnologia dei servomotori, un ambito in cui precisione e controllo convergono per abilitare una vasta gamma di applicazioni.

