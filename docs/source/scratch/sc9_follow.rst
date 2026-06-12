.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

Lezione 9: Compagno di esplorazione marziana
====================================================

Ora che il nostro Rover può evitare abilmente gli ostacoli, insegniamogli un nuovo trucco: seguire un bersaglio! In questa missione, trasformeremo il nostro rover evita-ostacoli in un fedele compagno che può seguirti ovunque.

Qual è la differenza tra seguire ed evitare?

- **Evitare**: Allontanarsi dagli oggetti (come schivare rocce)
- **Seguire**: Muoversi verso gli oggetti (come seguire un amico)

Preparati a programmare il tuo compagno di esplorazione marziana!

Obiettivi di apprendimento
----------------------------

* Combinare sensori a ultrasuoni e infrarossi per creare un rover inseguitore
* Programmare il tuo Mars Rover per tracciare e seguire automaticamente un bersaglio in movimento

Creare il tuo rover inseguitore
-------------------------------------------------------

#. Prima, :ref:`app_connect`.

#. Ora, apri il tuo progetto salvato nella Lezione 8.

   .. image:: img/8_follow_open.png

#. Salva una copia per mantenere al sicuro il tuo progetto originale. Clicca "Save as a copy".

   .. image:: img/8_follow_save_copy.png

#. Dai al tuo nuovo progetto un nome divertente come "Mars Follower" o "Rover Buddy".

   .. image:: img/8_follow_save_rename.png

#. Rimuovi i blocchi "move forward" dalla fine di ogni evento del sensore. Il nostro inseguitore dovrebbe fermarsi e aspettare dopo ogni azione.

   .. image:: img/8_follow_save_remove_forward.png

#. Ora riprogrammiamo i sensori IR! Cambia le direzioni di rotazione in modo che il rover giri VERSO il bersaglio invece che lontano da esso.

   .. image:: img/8_follow_save_re_turn.png

#. Infine, aggiorna il comportamento del sensore a ultrasuoni. Invece di indietreggiare, fallo muovere IN AVANTI quando rileva un bersaglio di fronte.

   .. image:: img/8_follow_save_re_ultra.png


Fantastico! Il tuo GalaxyRVR è ora il tuo compagno di esplorazione marziana. Provalo:

- Cammina accanto ad esso → gira per affrontarti
- Stai di fronte → si muove verso di te
- Allontanati → si ferma e aspetta

Il tuo rover compagno è pronto a seguirti nella tua prossima avventura spaziale!