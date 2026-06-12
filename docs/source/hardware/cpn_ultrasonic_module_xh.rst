.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Modulo a ultrasuoni
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Ingresso impulso di trigger
* **ECHO**: Uscita impulso echo
* **GND**: Massa
* **VCC**: Alimentazione 5V

Questo è il sensore di distanza a ultrasuoni HC-SR04, che fornisce misurazioni senza contatto da 2 cm a 400 cm con una precisione di portata fino a 3 mm. Sul modulo sono inclusi un trasmettitore a ultrasuoni, un ricevitore e un circuito di controllo.

Devi solo collegare 4 pin: VCC (alimentazione), Trig (trigger), Echo (ricezione) e GND (massa) per renderlo facile da usare nei tuoi progetti di misurazione.

**Caratteristiche**

* Tensione di lavoro: 5V CC
* Corrente di lavoro: 16mA
* Frequenza di lavoro: 40Hz
* Portata massima: 500cm
* Portata minima: 2cm
* Segnale di ingresso trigger: impulso TTL 10uS
* Segnale di uscita echo: Segnale TTL in ingresso e portata in proporzione
* Connettore: XH2.54-4P
* Dimensioni: 46x20,5x15 mm

**Principio**

I principi di base sono i seguenti:

* Utilizzo del trigger IO per almeno 10us di segnale ad alto livello.
* Il modulo invia un burst di 8 cicli di ultrasuoni a 40 kHz e rileva se viene ricevuto un segnale a impulsi.
* Echo emetterà un livello alto se viene restituito un segnale; la durata del livello alto è il tempo dall'emissione al ritorno.
* Distanza = (tempo di livello alto x velocità del suono (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800



**Note applicative**

* Questo modulo non dovrebbe essere collegato sotto tensione; se necessario, collegare prima il GND del modulo. Altrimenti, influirà sul funzionamento del modulo.
* L'area dell'oggetto da misurare dovrebbe essere di almeno 0,5 metri quadrati e il più piatta possibile. Altrimenti, influirà sui risultati.
