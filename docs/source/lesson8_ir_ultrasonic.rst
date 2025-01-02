.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Lektion 8: Fortgeschrittene Hindernisvermeidung und intelligentes Folgesystem
====================================================================================

In der heutigen Lektion werden wir unsere STEAM-Fähigkeiten weiterentwickeln. Wir kombinieren ein Hindernisvermeidungsmodul mit einem Ultraschallsensor, um ein fortgeschrittenes Hindernisvermeidungssystem zu erstellen. Außerdem implementieren wir ein intelligentes Folgesystem in unseren Rover.

Am Ende dieser Lektion wird unser Mars-Rover nicht nur in der Lage sein, Hindernisse auf seinem Weg zu vermeiden, sondern auch beweglichen Objekten zu folgen. Stellen Sie sich vor, Sie hätten ein kleines robotisches Haustier, das Ihnen folgt! Aufregend, nicht wahr? Also, lassen Sie uns beginnen.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn Sie diesen Kurs nach der vollständigen Montage des GalaxyRVR absolvieren, müssen Sie diesen Schalter nach rechts bewegen, bevor Sie den Code hochladen.

    .. image:: img/camera_upload.png
        :width: 500
        :align: center

Kursziele
--------------------------
* Lernen, wie man Hindernisvermeidungsmodule mit einem Ultraschallmodul für verbesserte Navigation kombiniert.
* Verstehen der Prinzipien und Funktionalitäten hinter einem fortgeschrittenen Hindernisvermeidungssystem.
* Erlernen der Implementierung eines intelligenten Folgesystems im Mars-Rover.

Kursmaterialien
------------------------

* Mars-Rover-Modell (das wir in den vorherigen Lektionen gebaut haben)
* USB-Kabel
* Arduino IDE
* Computer
* Und natürlich Ihren kreativen Geist!

Kursschritte
--------------------

**Schritt 1: Verständnis des Konzepts**

Das Hindernisvermeidungsmodul hilft unserem Rover, wie der Name schon sagt, Hindernisse zu vermeiden. 
Es erkennt Hindernisse, indem es ein Infrarotsignal aussendet und dann das vom Objekt 
reflektierte Signal empfängt. Ist ein Hindernis vor dem Modul, wird das Infrarotsignal 
zurückreflektiert, und das Modul erkennt es.

Wenn wir nun einen Ultraschallsensor hinzufügen, verbessert sich dieses System. Ultraschallsensoren messen Entfernungen, indem sie 
eine Schallwelle mit einer bestimmten Frequenz aussenden und auf das Zurückprallen dieser Schallwelle hören. 
Indem man die vergangene Zeit zwischen der Erzeugung der Schallwelle und dem Zurückprallen der Schallwelle aufzeichnet, 
kann man die Entfernung zwischen dem Sensor und dem Objekt berechnen.

Die Kombination dieser beiden Systeme ergibt ein zuverlässiges, effizientes und vielseitiges Hindernisvermeidungssystem!


**Schritt 2: Konstruktion fortgeschrittener Hindernisvermeidungssysteme**

In unseren vorherigen Lektionen haben wir die Grundlagen der Hindernisvermeidung mit Infrarotsensoren gelernt. Wir haben auch erforscht, wie ein Ultraschallmodul funktioniert. Jetzt werden wir all diese Teile zusammenbringen und ein fortgeschrittenes Hindernisvermeidungssystem bauen!

Unser verbesserter Mars-Rover wird nun sowohl Ultraschall- als auch Infrarotsensoren nutzen, um seine Umgebung zu navigieren.

Lassen Sie uns überlegen, wie die Infrarot- und Ultraschallmodule zusammenarbeiten sollten. Um unsere Logik zu verdeutlichen, verwenden wir ein Flussdiagramm. Das Erlernen der Erstellung von Flussdiagrammen ist ein wertvoller Schritt auf unserer Programmierreise, da es Ihnen helfen kann, Ihre Gedanken zu klären und Ihren Plan systematisch zu skizzieren.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Nun lassen Sie uns dieses Flussdiagramm in tatsächlichen Code umsetzen, um unseren Rover zum Leben zu erwecken.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Beachten Sie, dass die Funktion ``handleForwardMovement()`` der Ort ist, an dem wir das Verhalten des Ultraschallsensors integriert haben. Wir lesen die Entfernungsdaten vom Sensor und entscheiden auf Basis dieser Daten über die Bewegung des Rovers.

Nachdem Sie den Code auf Ihr R3-Board hochgeladen haben, ist es Zeit, das System zu testen.
Stellen Sie sicher, dass der Rover Hindernisse effizient erkennen und vermeiden kann.
Denken Sie daran, dass Sie die Erkennungsdistanz im Code basierend auf Ihrer tatsächlichen Umgebung anpassen müssen, um das System zu perfektionieren.

**Schritt 3: Programmierung des intelligenten Folgesystems**

Jetzt, da unser Rover in der Lage ist, Hindernissen auszuweichen, wollen wir ihn weiter verbessern, indem wir ihn Objekte verfolgen lassen. Unser Ziel ist es, unseren bestehenden Code zu modifizieren, damit der Rover sich auf ein sich bewegendes Objekt zubewegt.

Haben Sie sich jemals über die Unterschiede zwischen einem Folgesystem und einem Hindernisvermeidungssystem gewundert?

Der Schlüssel liegt darin, dass wir in einem Folgesystem möchten, dass unser Rover auf erkannte Objekte reagiert, während wir in einem Hindernisvermeidungssystem versuchen, erkannten Objekten auszuweichen.

Lassen Sie uns den gewünschten Arbeitsablauf visualisieren:

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Wenn der Ultraschallsensor ein Objekt im Bereich von 5-30 cm erkennt, sollte unser Rover sich darauf zubewegen.
* Wenn der linke IR-Sensor ein Objekt erkennt, sollte unser Rover nach links abbiegen.
* Wenn der rechte IR-Sensor ein Objekt erkennt, sollte unser Rover nach rechts abbiegen.
* In allen anderen Fällen sollte unser Rover stillstehen.

Jetzt ist es an der Zeit, den Code zu vervollständigen.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Sobald der Code fertiggestellt ist, testen Sie, ob der Rover Ihren Bewegungen folgt.

Wie bei dem Hindernisvermeidungssystem wird es entscheidend sein, unser Folgesystem zu testen und eventuell auftretende Probleme zu beheben. Sind Sie bereit zu beginnen?


**Schritt 4: Zusammenfassung und Reflexion**

Heute haben Sie etwas Erstaunliches erreicht. Sie haben verschiedene Module und Konzepte kombiniert, um ein fortgeschrittenes Hindernisvermeidungs- und Folgesystem für Ihren Mars-Rover zu erstellen. Denken Sie daran, das Lernen endet hier nicht - erkunden Sie weiter, innovieren Sie und wenden Sie Ihre neu erworbenen Fähigkeiten auf andere Projekte an.

Denken Sie immer daran, über Ihren Lernprozess zu reflektieren. Überlegen Sie folgendes:

* Warum denken Sie, haben wir im Hindernisvermeidungssystem das Hindernisvermeidungsmodul vor dem Ultraschallsensor priorisiert und umgekehrt im Folgesystem?
* Wie würde sich das Ergebnis ändern, wenn wir die Reihenfolge, in der diese Module im Code überprüft werden, tauschen würden?

Herausforderungen und Probleme sind ein integraler Bestandteil des STEAM-Lernprozesses und bieten wertvolle Möglichkeiten zur Verbesserung. Scheuen Sie sich nicht vor der Fehlersuche – sie ist an sich ein mächtiges Lernwerkzeug!

Auf Ihrem Weg wissen Sie, dass jede überwundene Hürde Sie einen Schritt näher an die Meisterung Ihrer STEAM-Fähigkeiten bringt. Machen Sie weiter und genießen Sie die Reise!

