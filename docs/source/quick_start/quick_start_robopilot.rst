.. note::

    Benvenuto/a nella community degli appassionati di Raspberry Pi, Arduino ed ESP32 di SunFounder su Facebook! Approfondisca le sue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolva problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impari e condivida**: Scambi suggerimenti e tutorial per migliorare le sue competenze.
    - **Anteprime esclusive**: Acceda in anteprima ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti speciali**: Goda di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipi a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicchi su |link_sf_facebook| e si unisca oggi stesso!

Gioco Rapido con l'APP
=========================

Pronto per iniziare la sua avventura su Marte?
Con la funzione di avvio rapido dell'app RoboPilot, può iniziare a esplorare non appena il suo GalaxyRVR è assemblato.

Con RoboPilot, può:

- Guidare il rover da una prospettiva in prima persona
- Passare tra tre modalità di controllo: **Remote**, **Avoid** e **Follow**


.. note::

    * Se ha sovrascritto il firmware e deve ripristinare la comunicazione, segua :ref:`update_r3_firmware`.

Guida rapida
---------------------

.. raw:: html


   <iframe width="600" height="400" src="https://www.youtube.com/embed/NwWjgP9ldZw?si=_3PADiRd-UlDvtHc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Avvii il GalaxyRVR.

   * Prima di utilizzare GalaxyRVR per la prima volta, carichi completamente la batteria con il cavo USB Type-C in dotazione.
   * Accenda l'interruttore di alimentazione.
   * Porti l'interruttore di modalità su **Run** e prema il pulsante **Reset** sulla scheda R3.
   * La striscia luminosa inferiore lampeggerà di **verde**, indicando un avvio riuscito.

   .. raw:: html

      <iframe width="600" height="400" src="https://www.youtube.com/embed/q_rDtYt1F6A?si=rnoaDgQPnb-y6wnK" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>


#. Installi **RoboPilot** da **APP Store (iOS)** o **Google Play (Android)**.

#. Connetta il suo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vede un avviso che indica "Nessun accesso a Internet", scelga l'opzione **"Resta connesso"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Apra RoboPilot. Faccia clic su 'Go into' per entrare nell'interfaccia di controllo.

   .. image:: img/rp1_inter.png



Modalità Remote
----------------------------------------------

Entrando nell'interfaccia di controllo, vedrà la seguente schermata.
Lo sfondo mostra la vista catturata dalla fotocamera del GalaxyRVR, con i widget di controllo remoto sovrapposti.

.. image:: img/rp2_page.png

Ecco i controlli:

A. Indietro
B. Impostazioni: Qui può cambiare il nome e la password dell'AP (hotspot), configurare il WiFi, capovolgere l'immagine e disconnettersi.

   .. image:: img/rp3_setting.jpg

C. Indicatore livello batteria
D. Pausa/Avvia l'APP
E. Selezione modalità: Qui può scegliere tra Modalità Remote, Modalità Avoid e Modalità Follow. L'impostazione predefinita è la **Modalità Remote**.

   .. image:: img/rp4_mode.jpg

F. Monitor ostacoli: Questo modulo è diviso in tre aree, con i lati sinistro e destro che mostrano i risultati dei moduli ostacoli, e l'area centrale che visualizza i risultati del sensore a ultrasuoni.
G. Selettore colore: Scelga qui il colore dell'illuminazione per il telaio.

   .. image:: img/rp5_color.png

H. Interruttore LED fotocamera.
I. Regola l'angolo del gimbal, che va da 0° a 130°. A 0°, guarda verso il cielo.
J. Muova il joystick per controllare il movimento di GalaxyRVR. Una spinta delicata farà muovere GalaxyRVR lentamente.


Modalità Avoid e Modalità Follow
----------------------------------------------

* **Modalità Avoid**: il GalaxyRVR avanzerà ed eviterà gli ostacoli sul suo percorso.
* **Modalità Follow**: il GalaxyRVR si muoverà verso un oggetto di fronte a sé o girerà a sinistra o a destra per seguire il movimento dell'oggetto.

Quando seleziona la **Modalità Avoid** o la **Modalità Follow**, vedrà l'interfaccia sottostante. La vista in diretta della fotocamera di GalaxyRVR forma lo sfondo, con le opzioni di controllo sovrapposte.

.. image:: img/rp6_avoid.png

**Controlli dell'interfaccia:**

A. **Controllo velocità** - Regola la velocità di movimento di GalaxyRVR
B. **Controllo motori** - Avvia o ferma il movimento di GalaxyRVR
C. **Controllo gimbal** - Regola l'angolo della fotocamera da 0° (rivolta verso il cielo) a 130°
D. **Monitor ostacoli** - Feedback visivo dai sensori:

   - Sezioni sinistra/destra: Rilevamento ostacoli a infrarossi
   - Sezione centrale: Misurazioni di distanza a ultrasuoni

**Regolazione della portata di rilevamento ostacoli**

Prima di utilizzare questa modalità, calibri la portata di rilevamento dei sensori per adattarla al suo ambiente. Le impostazioni di fabbrica potrebbero non essere ottimali.

- Troppo corta: Il rover potrebbe urtare gli ostacoli
- Troppo lunga: Il rover potrebbe sterzare inutilmente

Procedura di calibrazione:

1. **Inizi con il modulo destro**

   - Si assicuri che trasmettitore e ricevitore siano correttamente allineati
   - Raddrizzi se piegato durante il trasporto

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

2. **Testi e regoli la sensibilità**

   - Posizioni un ostacolo a 20 cm di distanza (usi la scatola del Rover)
   - Giri il potenziometro finché l'indicatore si illumina
   - Verifichi l'attivazione costante alla distanza desiderata
   - Usi il secondo potenziometro se necessario

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

3. **Ripeta per il modulo sinistro**


Riconnessione
-------------------------------

Se la rete si guasta o si disconnette, verrà indirizzato a questa pagina.

.. image:: img/rp7_reconnect.png

A questo punto, reimposti le impostazioni di rete, quindi faccia clic sull'IP corrispondente al suo GalaxyRVR per riconnettersi.
