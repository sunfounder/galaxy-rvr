.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci la tua conoscenza di Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!



Gioco Rapido con l'APP
=========================

Pronto per iniziare la tua avventura su Marte?
Con la funzione di avvio rapido dell'App RoboPilot, puoi iniziare a esplorare non appena il tuo GalaxyRVR è assemblato.

Con RoboPilot, puoi:

- Guidare il rover da una prospettiva in prima persona
- Passare tra tre modalità di controllo: **Remote**, **Avoid** e **Follow**


.. note::

    * Se hai sovrascritto il firmware e devi ripristinare la comunicazione, segui :ref:`update_r3_firmware`.

Guida rapida
---------------------

#. Prima di utilizzare GalaxyRVR per la prima volta, carica completamente la batteria con il cavo USB Type-C in dotazione. Dopo la ricarica, accendi l'alimentazione.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_start.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Per avviare l'ESP32 CAM, porta l'interruttore di modalità su **Run** e premi il pulsante **Reset** sulla scheda R3. La striscia luminosa inferiore inizierà a lampeggiare per indicare un avvio riuscito.

   .. note::

      * Se la striscia luminosa inferiore mostra una **luce lampeggiante di qualsiasi colore diverso dal verde**, il tuo GalaxyRVR necessita di un aggiornamento del firmware. Consulta :ref:`update_firmware`.

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/play_reset_green.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>


#. Installa **RoboPilot** da **APP Store(iOS)** o **Google Play(Android)**.

#. Connetti il tuo dispositivo mobile alla rete WiFi del GalaxyRVR.

   * Il nome della rete (SSID) è ``GalaxyRVR`` e la password è ``12345678``.
   * Se vedi un avviso che indica "Nessun accesso a Internet", scegli l'opzione **"Resta connesso"**.

     .. image:: ../img/camera_lan.png
        :width: 500

#. Apri RoboPilot. Clicca 'Go into' per entrare nell'interfaccia di controllo.

   .. image:: img/rp1_inter.png



Modalità Remote
----------------------------------------------

Entrando nell'interfaccia di controllo, vedrai la seguente schermata.
Lo sfondo mostra la vista catturata dalla fotocamera del GalaxyRVR, con i widget di controllo remoto sovrapposti.

.. image:: img/rp2_page.png

Ecco i controlli:

A. Indietro
B. Impostazioni: Qui puoi cambiare il nome e la password dell'AP (hotspot), configurare il WiFi, capovolgere l'immagine e disconnetterti.

   .. image:: img/rp3_setting.jpg

C. Indicatore livello batteria
D. Pausa/Avvia l'APP
E. Selezione modalità: Qui puoi scegliere tra Modalità Remote, Modalità Avoid e Modalità Follow. L'impostazione predefinita è la **Modalità Remote**.

   .. image:: img/rp4_mode.jpg

F. Monitor ostacoli: Questo modulo è diviso in tre aree, con i lati sinistro e destro che mostrano i risultati dei moduli ostacoli, e l'area centrale che visualizza i risultati del sensore a ultrasuoni.
G. Selettore colore: Scegli qui il colore dell'illuminazione per il telaio.

   .. image:: img/rp5_color.png

H. Interruttore LED fotocamera.
I. Regola l'angolo del gimbal, che va da 0-130°. A 0°, guarda verso il cielo.
J. Muovi il joystick per controllare il movimento di GalaxyRVR. Una spinta delicata farà muovere GalaxyRVR lentamente.


Modalità Avoid e Modalità Follow
----------------------------------------------

* **Modalità Avoid**: il GalaxyRVR avanzerà ed eviterà gli ostacoli sul suo percorso.
* **Modalità Follow**: il GalaxyRVR si muoverà verso un oggetto di fronte a sé o girerà a sinistra o a destra per seguire il movimento dell'oggetto.

Quando selezioni la **Modalità Avoid** o la **Modalità Follow**, vedrai l'interfaccia sottostante. La vista in diretta della fotocamera di GalaxyRVR forma lo sfondo, con le opzioni di controllo sovrapposte.

.. image:: img/rp6_avoid.png

**Controlli dell'interfaccia:**

A. **Controllo velocità** - Regola la velocità di movimento di GalaxyRVR
B. **Controllo motori** - Avvia o ferma il movimento di GalaxyRVR
C. **Controllo gimbal** - Regola l'angolo della fotocamera da 0° (rivolta verso il cielo) a 130°
D. **Monitor ostacoli** - Feedback visivo dai sensori:

   - Sezioni sinistra/destra: Rilevamento ostacoli a infrarossi
   - Sezione centrale: Misurazioni di distanza a ultrasuoni

**Regolazione della portata di rilevamento ostacoli**

Prima di utilizzare questa modalità, calibra la portata di rilevamento dei sensori per adattarla al tuo ambiente. Le impostazioni di fabbrica potrebbero non essere ottimali.

- Troppo corta: Il rover potrebbe urtare gli ostacoli
- Troppo lunga: Il rover potrebbe sterzare inutilmente

Procedura di calibrazione:

1. **Inizia con il modulo destro**

   - Assicurati che trasmettitore/ricevitore siano correttamente allineati
   - Raddrizza se piegato durante il trasporto

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust1.mp4" type="video/mp4">
        </video>

2. **Testa e regola la sensibilità**

   - Posiziona un ostacolo a 20 cm di distanza (usa la scatola del Rover)
   - Gira il potenziometro finché l'indicatore si illumina
   - Verifica l'attivazione costante alla distanza desiderata
   - Usa il secondo potenziometro se necessario

   .. raw:: html

        <video width="600" loop autoplay muted>
            <source src="../_static/video/ir_adjust2.mp4" type="video/mp4">
        </video>

3. **Ripeti per il modulo sinistro**


Riconnessione
-------------------------------

Se la rete si guasta o si disconnette, verrai indirizzato a questa pagina.

.. image:: img/rp7_reconnect.png

A questo punto, reimposta le impostazioni di rete, quindi clicca sull'IP corrispondente al tuo GalaxyRVR per riconnetterti.
