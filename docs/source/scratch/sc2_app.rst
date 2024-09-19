.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme agli altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a concorsi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Lezione 2 Iniziamo con l'APP Mammoth Coding
======================================================

Immergiamoci nel mondo di Mammoth Coding e creiamo il tuo primo progetto! 
Per un'esperienza ottimale, si consiglia di utilizzare un dispositivo con uno schermo più grande.






Obiettivi di Apprendimento
------------------------------------

* Comprendere l'ambiente di programmazione dell'APP e le operazioni di base.
* Imparare a programmare eventi nei personaggi, utilizzare la bandiera verde, ripetere, scorrere e cambiare costumi.
* Creare una semplice animazione simulando un rover marziano.

Materiali
--------------

* Smartphone o tablet
* APP Mammoth Coding

Installazione dell'APP Mammoth Coding
------------------------------------------

Per prima cosa, cerca Mammoth Coding su Google Play o nell'Apple Store e scaricala.

.. image:: img/mammoth_download.jpg
    :align: center

Comprendere l'Interfaccia dell'APP Mammoth Coding
------------------------------------------------------------

Mammoth Coding è progettato per essere divertente, educativo e facile da imparare. 
Fornisce strumenti per creare storie interattive, giochi, arte, simulazioni e altro ancora utilizzando la programmazione a blocchi. 
Include anche editor di disegno e suoni integrati.

Ecco come appare l'interfaccia:

.. image:: img/2_app_ui_001.png
    :align: center

Per dispositivi con schermo più piccolo, l'interfaccia appare così:

.. image:: img/2_app_ui_002.png
    :align: center


**Sezione Superiore**

La sezione superiore di Mammoth Coding include diverse opzioni di base.

.. image:: img/2_app_ui_1.png
    :align: center

* La prima opzione a sinistra è l'impostazione della lingua, che ti consente di scegliere diverse lingue di programmazione.
* La seconda opzione è il menu file, dove puoi creare nuovi file, caricare file locali e salvare il file corrente.
* La terza opzione è per rinominare il tuo progetto.

**Navigazione**

Subito sotto la sezione superiore c'è la barra di navigazione, 
che consente di passare tra le pagine di Codice, Costumi 
e Suoni.

.. image:: img/2_app_ui_3.png
    :align: center

Su schermi più piccoli, la barra di navigazione si trova nella parte superiore.

.. image:: img/2_app_ui_2.png
    :align: center

Le opzioni sono Codice, Costumi, Suoni e Palcoscenico. 
La pagina Palcoscenico si trova a destra dell'interfaccia su schermi più grandi, 
separata su dispositivi più piccoli per evitare confusione.

.. image:: img/2_app_ui_4.png
    :align: center

**Codice**

.. image:: img/2_app_ui_code.png
    :align: center

La pagina Codice (e Palcoscenico) è dove avverranno la maggior parte delle attività di programmazione.

**Costumi**

.. image:: img/2_app_ui_custom.png
    :align: center

La pagina Costumi è utilizzata per modificare personaggi e scenari, 
fornendo elementi visivi per i tuoi programmi.

**Suoni**

.. image:: img/2_app_ui_sound.png
    :align: center

La pagina Suoni gestisce l'audio, offrendo elementi multimediali per i tuoi programmi.

Primo Utilizzo dell'APP Mammoth Coding
------------------------------------------------

Trascina un blocco nell'area centrale.

.. image:: img/2_drag.png
    :align: center

Clicca sul blocco e osserva cosa succede.

.. image:: img/2_click.png
    :align: center

Vedrai il personaggio al centro del palcoscenico muoversi un po'. 
Se continui a cliccare sul blocco, il personaggio continuerà a muoversi.

.. image:: img/2_show.png
    :align: center

Noterai come la forma di questi blocchi suggerisce che possono essere collegati, 
simile ai mattoncini LEGO. Quando colleghi i blocchi, 
il personaggio sul palcoscenico eseguirà i blocchi di codice collegati 
in sequenza (es., spostati e poi ruota).

.. image:: img/2_click2.png
    :align: center


.. note:: Questo è il processo base di programmazione nell'APP. Trascina i blocchi dall'area a sinistra, collegali e cliccali per far eseguire azioni al personaggio sul palcoscenico.



**Scegliere un Personaggio**


Nell'angolo in basso a destra dell'interfaccia, 
troverai il pulsante "scegli un personaggio". Toccalo per vedere quattro opzioni a comparsa.

.. image:: img/2_create_sp.png
    :align: center

Su schermi più piccoli, dovrai navigare per vedere questo pulsante.

.. image:: img/2_create_sp0.png
    :align: center

Le quattro opzioni sono:

* **Carica Personaggio**: Carica un personaggio dall'archivio del tuo dispositivo.
* **Sorpresa**: Seleziona un personaggio casuale dalla libreria di asset.
* **Disegna**: Disegna un personaggio.
* **Scegli un Personaggio**: Apri la libreria di asset per scegliere un personaggio.

Tocca "scegli un personaggio" per entrare nella libreria di asset, che offre una varietà di materiali per il tuo palcoscenico.

.. image:: img/2_sp_list.png
    :align: center

Trova e seleziona "GalaxyRVR".

.. image:: img/2_sprite_rvr.png
    :align: center

**Il Tuo Primo Esempio**

Creiamo una semplice animazione utilizzando l'APP per far muovere casualmente GalaxyRVR.

.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_app.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

**1. Inizia con la categoria gialla Eventi.**

Mentre abbiamo eseguito il codice cliccando sui blocchi nell'area centrale, la maggior parte delle volte il nostro codice deve essere attivato da eventi. Gli eventi agiscono come sentinelle, monitorando azioni come clic sui personaggi o pressione di tasti, e dicono al programma cosa fare quando si verificano questi eventi.

Trascina il blocco "quando si clicca la bandiera verde".

.. image:: img/2_first_flag.png

La bandiera verde funziona come lo starter, rappresentando l'inizio del programma. Questo blocco si attiva quando clicchi sulla bandiera verde accanto al palcoscenico, avviando tutti i personaggi e il codice.

**2. La categoria Controllo è il direttore del programma.**

Questi blocchi aiutano a controllare il flusso del programma, decidendo quando e quante volte le azioni devono verificarsi.

Trascina un blocco "ripeti 10" e collegalo sotto il blocco della bandiera verde.

.. image:: img/2_first_repeat.png

Questo significa che dopo aver cliccato la bandiera verde, qualcosa accadrà dieci volte.

**3. La categoria Movimento fornisce istruzioni agli attori del palcoscenico (personaggi).**

Trascina un blocco "scivola per 1 sec a posizione casuale" e inseriscilo all'interno del blocco "ripeti 10".

.. image:: img/2_first_glide.png

Questo farà scivolare il tuo personaggio verso una posizione casuale.

**4. La categoria Aspetto aggiunge animazione e interesse visivo ai tuoi personaggi.**

Trascina un blocco "passa al costume successivo" e posizionalo all'interno del blocco "ripeti 10".

.. image:: img/2_first_custom.png

Questo farà cambiare costume al tuo personaggio ad ogni azione, facendo sembrare che stia camminando.


Ora, clicca sulla bandiera verde accanto al palcoscenico e guarda il tuo GalaxyRVR muoversi casualmente.
