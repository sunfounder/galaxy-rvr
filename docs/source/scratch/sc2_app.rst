.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 2: Iniziare con l'app Mammoth Coding
===========================================================

Immergiamoci nel mondo di Mammoth Coding e creiamo il tuo primo progetto! Per un'esperienza ottimale, si consiglia di utilizzare un dispositivo con uno schermo più grande.

Obiettivi di apprendimento
--------------------------

* Configurare l'ambiente di programmazione Mammoth Coding.
* Comprendere i concetti di base della programmazione in Mammoth Coding.
* Scrivere ed eseguire il tuo primo programma.


Installazione dell'APP
----------------------

1. Cerca **Mammoth Coding** su Google Play o sull'Apple App Store e installalo.

   .. image:: img/1_app_install.png
      :width: 600
      :align: center

2. Dopo l'installazione, puoi aprirlo. Ecco come appare l'interfaccia sugli schermi più grandi:

   .. image:: img/1_app_ui_001.png
      :width: 600
      :align: center

3. Per i dispositivi con schermi più piccoli, l'interfaccia appare come segue:

   .. image:: img/1_app_ui_002.png
      :width: 600
      :align: center

Comprendere l'APP
-----------------------------------

Mammoth Coding è progettato per essere divertente, educativo e facile da imparare. Fornisce strumenti per creare storie interattive, giochi, arte, simulazioni e altro ancora utilizzando la codifica a blocchi. Include anche editor di disegno e suoni integrati.

Sezione superiore
^^^^^^^^^^^^^^^^^

La sezione superiore di Mammoth Coding include diverse opzioni essenziali.

.. image:: img/1_app_ui_1.png
   :align: center

* **Impostazioni lingua**: La prima opzione a sinistra ti permette di scegliere diverse lingue. Attualmente sono disponibili inglese e cinese semplificato.
* **Menu File**: La seconda opzione è il menu **File**, dove puoi creare nuovi progetti, aprire quelli esistenti e salvare il progetto corrente.
* **Nome progetto**: La terza opzione ti permette di rinominare il tuo progetto.

Barra di navigazione
^^^^^^^^^^^^^^^^^^^^^

Appena sotto la sezione superiore c'è la barra di navigazione, che ti permette di passare tra diverse pagine di modifica.

.. image:: img/1_app_ui_3.png
   :align: center

Sugli schermi più piccoli:

* La barra di navigazione appare in alto con le opzioni per **Code**, **Costumes**, **Sounds** e **Stage**.

  .. image:: img/1_app_ui_2.png

* La pagina **Stage** è in realtà il lato destro dell'interfaccia sugli schermi più grandi, separata sui dispositivi più piccoli per evitare disordine.

  .. image:: img/1_app_ui_4.png
     :width: 600

Area Codice
^^^^^^^^^^^^^^

La pagina **Code** è dove si svolgerà la maggior parte delle tue attività di programmazione.

.. image:: img/1_app_ui_code.png
   :width: 600
   :align: center

Costumi
^^^^^^^^^^^^^^^

La pagina **Costumes** è usata per modificare sprite e sfondi, fornendo elementi visivi per i tuoi programmi.

.. image:: img/1_app_ui_custom.png
   :width: 600
   :align: center

Suoni
^^^^^^^^^^^^^

La pagina **Sounds** gestisce l'audio, fornendo elementi multimediali per i tuoi programmi.

.. image:: img/1_app_ui_sound.png
   :width: 600
   :align: center

Creare il tuo primo programma
----------------------------------------

1. Crea o apri un progetto
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


* Ogni volta che apri l'app Mammoth Coding, un nuovo progetto viene creato automaticamente.

  .. image:: img/1_open_new.png
     :width: 600

* Cambia il nome predefinito del progetto "My Project" in qualcosa di significativo.

  .. image:: img/1_new_name.png
     :width: 600

* Puoi anche aprire un progetto che hai precedentemente salvato sul tuo dispositivo.

  .. image:: img/1_new_save.png
     :width: 600

2. Scegli uno sprite
^^^^^^^^^^^^^^^^^^^^^^^^^

* Quando inizi un nuovo progetto, viene fornito uno sprite predefinito. Puoi:

  * Usare lo sprite predefinito.
  * Scegliere un nuovo sprite dalla libreria.
  * Disegnare il tuo sprite.
  * Caricare uno sprite dal tuo dispositivo.

  .. image:: img/1_choose_sprite.png

* Per scegliere un nuovo sprite: Tocca **"Choose a Sprite"** e seleziona **"GalaxyRVR"**.

  .. image:: img/1_choose_galaxyrvr.png

3. Scrivi il programma
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Nella barra laterale sinistra, troverai varie categorie contenenti diversi tipi di blocchi. Puoi trascinare i blocchi da queste categorie nell'area di scripting per costruire il tuo programma.

Ad esempio, per far avanzare lo sprite **GalaxyRVR** di 10 passi e poi passare al costume successivo quando si clicca la bandiera verde:

1. Dalla categoria **Events**, trascina il blocco **"When green flag clicked"** nell'area di scripting.

     .. image:: img/1_code_flag.png
        :width: 600

2. Dalla categoria **Motion**, trascina il blocco **"Move (10) steps"** e aggancialo sotto il blocco evento.

     .. image:: img/1_code_move10.png
        :width: 600

3. Dalla categoria **Looks**, trascina il blocco **"Next costume"** e attaccalo sotto il blocco di movimento.

     .. image:: img/1_code_next.png
        :width: 600

4. Esegui il programma
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ci sono due modi per eseguire il tuo programma:

1. Tocca semplicemente la pila di blocchi che hai assemblato nell'area di scripting. Apparirà un'evidenziazione gialla, che indica che lo script è in esecuzione.

     .. image:: img/1_code_run.png
        :width: 30%

2. Se il tuo script inizia con il blocco **"When green flag clicked"**, puoi cliccare la bandiera verde in alto a sinistra dello **Stage** per eseguire il tuo programma. Questo è consigliato per progetti con più sprite o codice più complesso.

     .. image:: img/1_code_green_flag.png
        :width: 70%

5. Salva il tuo progetto
^^^^^^^^^^^^^^^^^^^^^^^^^

Dopo aver testato il tuo codice e esserti assicurato che tutto funzioni correttamente, è importante salvare il tuo progetto.

1. Clicca l'icona di salvataggio situata a destra del nome del tuo progetto.

     .. image:: img/1_code_save.png
        :width: 600

2. Apparirà un messaggio "Project saved". Il progetto verrà salvato all'interno dell'app Mammoth Coding. Puoi accedere ai tuoi progetti salvati cliccando il pulsante del menu all'estrema destra.

     .. image:: img/1_code_save_app.png
        :width: 600

3. Per condividere il tuo codice o salvarlo sul tuo dispositivo, clicca **File > Save to your equipment**, quindi scegli un'applicazione con cui condividere o salva il progetto sul tuo dispositivo mobile.

     .. image:: img/1_code_save_device.png

**Congratulazioni!**

Hai creato ed eseguito con successo il tuo primo programma in Mammoth Coding. Continua a sperimentare ed esplorare per scoprire più funzionalità e liberare la tua creatività!
