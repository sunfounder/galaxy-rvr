.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message

﻿


Lektion 5: Interaktive Animation
===============================================

Zuvor haben wir das Ultraschallmodul verwendet, um den GalaxyRVR automatisch Hindernissen auf seinem Weg ausweichen zu lassen.

In dieser Aktivität kombinieren wir das Modul mit einer Buhne, um eine interaktive Animation eines Rovers zu erstellen, der freudig über die Marsoberflache fahrt.


.. raw:: html

   <video width="600" loop autoplay muted>
      <source src="../_static/video/sc_animate_jump.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Lernziele
-------------------------

* Lernen, Figuren zu zeichnen und Hintergrunde zu bearbeiten.
* Grundlegende Programmierkonzepte wie Ereignis-Listener und Schleifenstrukturen verstehen.
* Sich mit der Programmierumgebung der App und den grundlegenden Funktionen vertraut machen, um eine einfache Animation zu erstellen, die einen Mars Rover simuliert.

Neue Figuren hinzufugen
----------------------------

#. Stellen Sie zunachst eine :ref:`app_connect` her.

#. Loschen Sie alle nicht benotigten Figuren.

   .. image:: img/6_animate_delete.png

#. Tippen Sie in der unteren rechten Ecke der Oberflache auf die Schaltflache **Figur auswahlen**, um vier Optionen anzuzeigen.

   .. image:: img/5_create_sp.png

#. Auf kleineren Bildschirmen müssen Sie moglicherweise zu einem anderen Bildschirm wechseln, um diese Schaltflache zu sehen.

   .. image:: img/5_create_sp0.png

Die vier Optionen sind:

* **Figur hochladen** – Laden Sie eine Figur von Ihrem Gerat hoch.
* **Zufallig** – Wahlen Sie zufallig eine Figur aus der Bibliothek aus.
* **Malen** – Zeichnen Sie Ihre eigene Figur.
* **Figur auswahlen** – Wahlen Sie aus der Figurenbibliothek aus.

Als Nachstes verwenden wir **Figur auswahlen**, um eine Figur auszuwahlen, und **Malen**, um eine zu zeichnen.

**Figur auswahlen**

#. Tippen Sie auf **Figur auswahlen** (Lupensymbol), um die Figurenbibliothek zu öffnen.

   .. image:: img/5_sp_list.png

#. Suchen und wahlen Sie **GalaxyRVR** aus der Bibliothek aus.

   .. image:: img/1_choose_galaxyrvr.png


**Eine neue Figur malen**

#. Tippen Sie auf **Malen** (Pinselsymbol), um eine neue Figur zu erstellen. Wir zeichnen eine **Mars**-Figur.

   .. image:: img/5_create_custom.png

#. Verwenden Sie das **Kreiswerkzeug**, um einen Kreis zu zeichnen, der den Planeten darstellt.

   .. image:: img/5_create_custom1.png

#. Verwenden Sie das **Zeigerwerkzeug**, um den Kreis in die Mitte der Zeichenflache zu verschieben. Dieser Schritt ist wichtig, da die Koordinaten und Bewegungen der Figur auf ihrem Mittelpunkt basieren.

   .. image:: img/5_create_custom2.png

#. Verwenden Sie das **Fullwerkzeug**, um den Kreis mit Rot zu fullen.

   .. image:: img/5_create_custom3.png

#. Wahlen Sie das **Pinselwerkzeug**, vergro?ern Sie die Pinselgro?e und fugen Sie mit einer passenden Fullfarbe Textur hinzu.

   .. image:: img/5_create_custom_pen.png

#. Wenn die Farbe nicht richtig aussieht, andern Sie die Fullfarbe und verwenden Sie das **Fullwerkzeug** erneut.

   .. image:: img/5_create_custom5.png

#. Wahlen Sie erneut das **Pinselwerkzeug**, stellen Sie die Gro?e auf 2 ein, andern Sie die Farbe auf Schwarz und zeichnen Sie Krater auf dem Mars.

   .. image:: img/5_create_custom6.png

#. Verwenden Sie das **Fullwerkzeug**, um die Krater mit einer passenden Farbe zu fullen.

   .. image:: img/5_create_custom7.png

#. Wechseln Sie nach Abschluss zurück zur **Code-Oberflache**.

   .. image:: img/5_create_custom8.png

#. Klicken Sie auf kleineren Bildschirmen auf das Symbol, um zur Code-Oberflache zurückzukehren.

   .. image:: img/5_create_custom8.1.png

#. Sie sehen nun die Mars-Figur auf der Buhne. Vergessen Sie nicht, sie **umzubenennen**.

   .. image:: img/5_create_custom9.png


**Buhne**

#. Klicken Sie auf **Hintergrunde**, um den Hintergrund zu andern. Der wei?e Standardhintergrund wird geandert, um einen Nachthimmel zu simulieren.

   .. image:: img/6_jump_backdrop.png

#. Rufen Sie die **Hintergrund**-Oberflache auf.

   .. image:: img/6_jump_backdrop_page.png

#. Zeichnen Sie ein Rechteck auf der Zeichenflache.

   .. image:: img/6_jump_rect.png

#. Verwenden Sie das **Fullwerkzeug**, um es mit einer dunklen Farbe zu fullen.

   .. image:: img/6_jump_fill.png

#. Fugen Sie mit dem **Pinselwerkzeug** einige Sterne hinzu.

   .. image:: img/6_jump_paint.png


Die Animation erstellen
-------------------------------

Nachdem wir nun Mars und GalaxyRVR haben und wissen, wie man Figuren animiert, erstellen wir eine Animation von GalaxyRVR, der sich auf dem Mars bewegt.
Wir können die Figur scheinbar bewegen, indem wir den Mars in die entgegengesetzte Richtung drehen, wodurch der Effekt entsteht, dass GalaxyRVR über seine Oberflache fahrt.

#. Stellen Sie zunachst eine :ref:`app_connect` her.

#. Passen Sie die Gro?e und Position beider Figuren an.

   * Setzen Sie die GalaxyRVR-Figur auf **(0, 0)** und positionieren Sie Mars so, dass GalaxyRVR scheinbar auf seiner Oberflache steht.

   .. image:: img/6_jump_place.png


**Mars-Figur**

#. Wahlen Sie die Mars-Figur aus. Ihre Aufgabe ist es, sich gegen den Uhrzeigersinn zu drehen, wodurch die Illusion entsteht, dass GalaxyRVR sich vorwarts bewegt.

   .. image:: img/6_ssp_mars.png

#. Ziehen Sie einen grunen Flaggenblock. Jede Animation beginnt mit der grunen Flagge.

   .. image:: img/6_jump_mar_flag.png

#. Ziehen Sie einen ``forever``-Block, um die Animation kontinuierlich laufen zu lassen.

   .. image:: img/6_jump_mar_forever.png


#. Ziehen Sie einen ``turn``-Block und einen ``wait``-Block, um Mars kontinuierlich rotieren zu lassen.

   .. image:: img/6_jump_mar_turn.png

#. Klicken Sie nun auf die grune Flagge, und Sie werden sehen, wie Mars sich gegen den Uhrzeigersinn dreht.



**GalaxyRVR-Figur**

#. Wahlen Sie die GalaxyRVR-Figur aus. Ihre Aufgabe ist es, sich so zu animieren, als ob sie sich bewegt, obwohl sie sich tatsachlich nicht bewegt.

   .. image:: img/6_ssp_rvr.png
    
#. Ziehen Sie einen grunen Flaggenblock. Jede Animation beginnt mit der grunen Flagge.

   .. image:: img/6_jump_mar_flag.png

#. Ziehen Sie einen ``forever``-Block, um die Animation kontinuierlich laufen zu lassen.

   .. image:: img/6_jump_mar_forever.png

#. Ziehen Sie einen ``next costume``-Block und einen ``wait``-Block, um GalaxyRVR kontinuierlich zu animieren.

   .. image:: img/6_jump_mar_next.png

#. Ziehen Sie einen ``when distance``-Block. Dieser wird ausgelost, wenn das Ultraschallmodul ein Hindernis erkennt (z. B. Ihre Hand).

   .. image:: img/6_jump_when.png


#. Ziehen Sie zwei ``glide``-Blocke und andern Sie den y-Wert des ersten, um die Figur nach oben springen und dann wieder herunterkommen zu lassen, wodurch ein Springeffekt entsteht.

   .. image:: img/6_jump_glide.png

#. Der vollstandige Code für die GalaxyRVR-Figur sollte wie folgt aussehen:

   .. image:: img/6_jump_mar_rvr_all.png


Klicken Sie nun auf die grune Flagge, um die Animation zu starten. Simulieren Sie ein Hindernis, indem Sie Ihre Hand vor das Ultraschallmodul halten, und die GalaxyRVR-Figur wird springen, um ihm auszuweichen.

