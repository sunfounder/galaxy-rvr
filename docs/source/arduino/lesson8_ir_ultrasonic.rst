.. include:: /index.rst
   :start-after: start_hello_message
   :end-before: end_hello_message


Lektion 8: Fortschrittliche Hindernisvermeidung und intelligentes Folgesystem
=============================================================================

In der heutigen Lektion werden wir unsere STEAM-Fähigkeiten noch einen Schritt weiterentwickeln. Wir kombinieren ein Hindernisvermeidungsmodul
mit einem Ultraschallsensor, um ein fortschrittliches Hindernisvermeidungssystem zu erstellen.
Außerdem werden wir ein intelligentes Folgesystem für unseren Rover implementieren.

Am Ende dieser Lektion wird unser Mars Rover nicht nur in der Lage sein, Hindernissen auf seinem Weg auszuweichen,
sondern auch beweglichen Objekten zu folgen. Stellen Sie sich vor, Sie hätten ein miniaturisiertes Roboter-Haustier, das Ihnen überallhin folgt!
Spannend, nicht wahr? Dann lassen Sie uns loslegen.

.. raw:: html

    <video width="600" loop autoplay muted>
        <source src="../_static/video/ultrasonic_ir_avoid.mp4" type="video/mp4">
        Ihr Browser unterstützt das Video-Tag nicht.
    </video>

.. note::

    Wenn Sie diesen Kurs nach der vollständigen Montage des GalaxyRVR lernen, müssen Sie diesen Schalter vor dem Hochladen des Codes nach rechts stellen.

    .. image:: ../img/camera_upload.png
        :width: 500
        :align: center

Lernziele
--------------------------
* Lernen, wie man Hindernisvermeidungsmodule mit einem Ultraschallmodul für eine verbesserte Navigation kombiniert.
* Die Prinzipien und Funktionsweisen eines fortschrittlichen Hindernisvermeidungssystems verstehen.
* Lernen, wie man ein intelligentes Folgesystem im Mars Rover implementiert.

Materialien
------------------------

* Mars Rover-Modell (das in den vorherigen Lektionen gebaute)
* USB-Kabel
* Arduino IDE
* Computer
* Und natürlich Ihr kreativer Geist!

Kursschritte
--------------------

**Schritt 1: Das Konzept verstehen**

Das Hindernisvermeidungsmodul hilft unserem Rover, Hindernissen auszuweichen.
Es erkennt Hindernisse, indem es ein Infrarotsignal aussendet und dann das vom Objekt
zurückgeworfene Signal empfängt. Befindet sich ein Hindernis vor dem Modul,
wird das Infrarotsignal zurückgeworfen und das Modul erkennt es.

Durch die Hinzunahme eines Ultraschallsensors wird dieses System verbessert. Ultraschallsensoren messen Entfernungen,
indem sie eine Schallwelle mit einer bestimmten Frequenz aussenden und auf das Zurückprallen dieser Schallwelle lauschen.
Durch die Aufzeichnung der Zeit zwischen dem Aussenden der Schallwelle und ihrem Zurückprallen
kann die Entfernung zwischen Sensor und Objekt berechnet werden.

Die Kombination dieser beiden ergibt ein zuverlässiges, effizientes und vielseitiges Hindernisvermeidungssystem!


**Schritt 2: Fortschrittliche Hindernisvermeidungssysteme aufbauen**

In unseren vorherigen Lektionen haben wir die Grundlagen der Hindernisvermeidung mit Infrarotsensoren kennengelernt. Wir haben auch erkundet, wie ein Ultraschallmodul funktioniert. Nun werden wir all diese Teile zusammenführen und ein fortschrittliches Hindernisvermeidungssystem bauen!

Unser verbesserter Mars Rover wird nun sowohl Ultraschall- als auch Infrarotsensoren nutzen, um seine Umgebung zu erkunden.

Stellen wir uns vor, wie die Infrarot- und Ultraschallmodule zusammenarbeiten sollten. Um unsere Logik zu verdeutlichen, verwenden wir ein Flussdiagramm. Das Erstellen von Flussdiagrammen ist ein unschätzbarer Schritt auf unserer Codierungsreise, da es hilft, Gedanken zu klären und Pläne systematisch zu skizzieren.

.. image:: img/ultrasonic_ir_avoid_flowchart.png
    :width: 800

Nun setzen wir dieses Flussdiagramm in tatsächlichen Code um, um unseren Rover zum Leben zu erwecken.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/53d72ee5-a4c8-4524-92f8-4b0f4760c015/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Beachten Sie, dass die Funktion ``handleForwardMovement()`` die Stelle ist, an der wir das Verhalten des Ultraschallsensors integriert haben. Wir lesen die Entfernungsdaten vom Sensor und basierend auf diesen Daten entscheiden wir über die Bewegung des Rovers.


Nach dem Hochladen des Codes auf Ihr R3-Board ist es Zeit, das System zu testen.
Stellen Sie sicher, dass der Rover Hindernisse effizient erkennen und vermeiden kann.
Denken Sie daran, dass Sie die Erkennungsdistanz im Code je nach Ihrer tatsächlichen Umgebung anpassen müssen, um das System zu perfektionieren.

**Schritt 3: Das intelligente Folgesystem codieren**

Nachdem unser Rover nun Hindernissen ausweichen kann, wollen wir ihn weiter verbessern, indem wir ihm beibringen, Objekten zu folgen. Unser Ziel ist es, unseren vorhandenen Code so zu ändern, dass sich der Rover auf ein sich bewegendes Objekt zubewegt.

Haben Sie sich je gefragt, was die Unterschiede zwischen einem Folgesystem und einem Hindernisvermeidungssystem sind?

Der Schlüssel liegt darin, dass wir bei einem Folgesystem möchten, dass sich unser Rover als Reaktion auf erkannte Objekte bewegt, während wir bei einem Hindernisvermeidungssystem erkannten Objekten ausweichen möchten.

Visualisieren wir den gewünschten Arbeitsablauf:

.. image:: img/ultrasonic_ir_follow_flowchart.png

* Wenn der Ultraschallsensor ein Objekt innerhalb von 5-30 cm erkennt, soll sich unser Rover darauf zubewegen.
* Wenn der linke IR-Sensor ein Objekt erkennt, soll unser Rover eine Linkskurve machen.
* Wenn der rechte IR-Sensor ein Objekt erkennt, soll unser Rover eine Rechtskurve machen.
* In allen anderen Fällen soll unser Rover stehen bleiben.

Nun ist es Zeit für uns, den Code zu vervollständigen.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/75662c17-4b0a-4494-b18b-089cc2b32311/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Sobald der Code fertig ist, testen Sie, ob der Rover Ihren Bewegungen folgt.

Wie beim Hindernisvermeidungssystem wird es entscheidend sein, unser Folgesystem zu testen und eventuell auftretende Probleme zu beheben. Bereit loszulegen?


**Schritt 4: Zusammenfassung und Reflexion**

Heute haben Sie etwas Erstaunliches erreicht. Sie haben verschiedene Module und Konzepte kombiniert, um ein fortschrittliches Hindernisvermeidungs- und Folgesystem für Ihren Mars Rover zu erstellen. Denken Sie daran, das Lernen endet hier nicht - erkunden, innovieren und wenden Sie Ihre neu erworbenen Fähigkeiten weiterhin auf andere Projekte an.

Denken Sie immer daran, über Ihren Lernprozess zu reflektieren. Überlegen Sie Folgendes:

* Warum haben wir unserem Hindernisvermeidungssystem Ihrer Meinung nach das Hindernisvermeidungsmodul vor dem Ultraschallsensor priorisiert und im Folgesystem umgekehrt?
* Wie würde sich das Ergebnis unterscheiden, wenn wir die Reihenfolge, in der diese Module im Code überprüft werden, vertauschen würden?

Herausforderungen und Probleme sind ein wesentlicher Bestandteil des STEAM-Lernprozesses und bieten wertvolle Gelegenheiten zur Verbesserung. Scheuen Sie sich nicht vor der Fehlersuche - sie ist ein mächtiges Lernwerkzeug!

Denken Sie auf Ihrer weiteren Reise daran, dass jedes überwundene Hindernis Sie Ihrem Ziel, Ihre STEAM-Fähigkeiten zu meistern, einen Schritt näher bringt. Machen Sie weiter und genießen Sie die Reise!
