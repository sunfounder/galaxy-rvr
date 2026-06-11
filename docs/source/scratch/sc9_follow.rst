
Lektion 9: Mars-Erkundungspartner
==================================================

Nachdem unser Rover nun geschickt Hindernisse vermeiden kann, bringen wir ihm einen neuen Trick bei – das Verfolgen eines Ziels! In dieser Mission verwandeln wir unseren hindernisvermeidenden Rover in einen treuen Begleiter, der Ihnen folgen kann.

Was ist der Unterschied zwischen Vermeiden und Folgen?

- **Vermeiden**: Von Objekten wegsteuern (wie das Ausweichen vor Steinen)
- **Folgen**: Sich auf Objekte zubewegen (wie das Folgen eines Freundes)

Machen Sie sich bereit, Ihren eigenen Mars-Erkundungsbegleiter zu programmieren!

Lernziele
-------------------------

* Kombinieren von Ultraschall- und Infrarotsensoren zur Entwicklung eines Folge-Rovers
* Programmieren Sie Ihren Mars Rover so, dass er ein sich bewegendes Ziel automatisch erfasst und verfolgt

Ihren Folge-Rover erstellen
---------------------------------------------------

#. Zunächst: :ref:`app_connect`.

#. Öffnen Sie nun Ihr gespeichertes Projekt aus Lektion 8.

   .. image:: img/8_follow_open.png

#. Speichern Sie eine Kopie, um Ihr ursprüngliches Projekt zu sichern. Klicken Sie auf „Als Kopie speichern".

   .. image:: img/8_follow_save_copy.png

#. Geben Sie Ihrem neuen Projekt einen lustigen Namen wie „Mars Follower" oder „Rover Buddy".

   .. image:: img/8_follow_save_rename.png

#. Entfernen Sie die „move forward"-Blöcke am Ende jedes Sensor-Ereignisses. Unser Folgerover sollte nach jeder Aktion anhalten und warten.

   .. image:: img/8_follow_save_remove_forward.png

#. Programmieren wir nun die IR-Sensoren neu! Ändern Sie die Drehrichtungen so, dass der Rover sich AUF das Ziel zudreht, anstatt sich davon wegzudrehen.

   .. image:: img/8_follow_save_re_turn.png

#. Aktualisieren Sie schließlich das Verhalten des Ultraschallsensors. Anstatt zurückzusetzen, lassen Sie ihn sich VORWÄRTS bewegen, wenn er ein Ziel vor sich erkennt.

   .. image:: img/8_follow_save_re_ultra.png


Fantastisch! Ihr GalaxyRVR ist jetzt Ihr Mars-Erkundungspartner. Testen Sie es aus:

- Gehen Sie daneben → er dreht sich zu Ihnen
- Stellen Sie sich davor → er bewegt sich auf Sie zu
- Entfernen Sie sich → er hält an und wartet

Ihr Rover-Begleiter ist bereit, Ihnen auf Ihr nächstes Weltraumabenteuer zu folgen!