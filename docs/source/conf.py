# File di configurazione per il generatore di documentazione Sphinx.
#
# Questo file contiene solo una selezione delle opzioni più comuni. Per una
# lista completa consulta la documentazione:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Impostazione percorsi ----------------------------------------------------

# Se le estensioni (o i moduli da documentare con autodoc) si trovano in
# un'altra directory, aggiungi queste directory a sys.path qui. Se la
# directory è relativa alla root della documentazione, usa os.path.abspath
# per renderla assoluta, come mostrato qui.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
import time

# -- Informazioni sul progetto ------------------------------------------------

project = 'SunFounder GalaxyRVR Kit per Arduino'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# La versione completa, inclusi i tag alpha/beta/rc
release = '1.0'

# -- Opzioni tema sphinx_rtd_theme --------------------------------------------
html_theme_options = {
    'flyout_display': 'attached',
    'version_selector': False,
    'language_selector': False,
}

# -- Configurazione generale --------------------------------------------------

# Aggiungi qui i nomi dei moduli di estensione Sphinx, come stringhe.
# Possono essere estensioni fornite con Sphinx (chiamate 'sphinx.ext.*')
# o personalizzate.
extensions = [
    #'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
]

# Aggiungi qui i percorsi che contengono template, relativi a questa directory.
templates_path = ['_templates']

# Lista di pattern, relativi alla directory sorgente, che corrispondono a file
# e directory da ignorare durante la ricerca dei file sorgente.
# Questo pattern influisce anche su html_static/video_path e html_extra_path.
exclude_patterns = []


# -- Opzioni per l'output HTML ------------------------------------------------

# Il tema da usare per le pagine HTML e HTML Help. Consulta la documentazione
# per una lista dei temi predefiniti.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# Aggiungi qui i percorsi che contengono file statici personalizzati
# (come fogli di stile), relativi a questa directory. Vengono copiati dopo
# i file statici predefiniti, quindi un file chiamato "default.css" sovrascriverà
# il "default.css" predefinito.
html_static_path = ['_static']

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js', # new
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]

# Apri link in una nuova finestra

rst_epilog = """

.. |link_sf_facebook| raw:: html

    <a href="https://bit.ly/raphaelkit" target="_blank">qui</a>


.. |link_german_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/de/latest/" target="_blank">Deutsch Online-Kurs</a>

.. |link_jp_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/ja/latest/" target="_blank">日本語オンライン教材</a>

.. |link_en_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/" target="_blank">English Online-tutorials</a>

.. |link_fr_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/fr/latest/" target="_blank">Didacticiels en ligne en français</a>

.. |link_es_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/es/latest/" target="_blank">Tutoriales en línea en español</a>

.. |link_it_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/it/latest/" target="_blank">Tutorial online in italiano</a>

.. |link_cn_tutorials| raw:: html

    <a href="https://docs.sunfounder.com/projects/galaxy-rvr/zh-cn/latest/" target="_blank">中文在线教程</a>

.. |link_esp32cam_schematic| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/esp32_cam_sch.pdf" target="_blank">Schema elettrico ESP32-CAM</a>

.. |link_cam_ov2640| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/ov2640_ds_1.8_.pdf" target="_blank">ov2640_ds_1.8</a>


.. |link_aithiner| raw:: html

    <a href="https://docs.ai-thinker.com/en/esp32-cam" target="_blank">Ai-Thinker</a>


.. |link_qmc6310_datasheet| raw:: html

    <a href="https://www.qstcorp.com/upload/pdf/202202/%EF%BC%88%E5%B7%B2%E4%BC%A0%EF%BC%8913-52-17%20QMC6310%20Datasheet%20Rev.C(1).pdf" target="_blank">Scheda tecnica QMC6310</a>


.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Pagina Arduino IDE 2.0.0</a>

.. |link_arduino_linux| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux" target="_blank">Installa Arduino IDE su Linux</a>

.. |link_arduino_web| raw:: html

    <a href="https://www.arduino.cc/reference/en/" target="_blank">Sito ufficiale Arduino</a>

.. |link_sunfounder_controller| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/" target="_blank">SunFounder Controller</a>

.. |link_sc_widgets| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Elenco Widget</a>

.. |link_sc_page| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/page_introduction.html" target="_blank">Introduzione alla Pagina</a>

.. |link_ai_camera_library_api| raw:: html

    <a href="https://github.com/sunfounder/SunFounder_AI_Camera/blob/main/README.md" target="_blank">Utilizzo dei Widget</a>

.. |link_widgets_list| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Elenco Widget</a>

.. |link_ai_camera_firmware| raw:: html

    <a href="https://github.com/sunfounder/ai-camera-firmware" target="_blank">ai-camera-firmware</a>

.. |link_GalaxyRVR| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-galaxyrvr-mars-rover-kit?_pos=1&_sid=c7193042f&_ss=r" target="_blank">Link di acquisto per GalaxyRVR</a>

.. |link_Mars_Rover_Kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-galaxyrvr-mars-rover-kit?_pos=1&_sid=c7193042f&_ss=r" target="_blank">GalaxyRVR</a>

.. |link_github_galaxyrvr| raw:: html

    <a href="https://github.com/sunfounder/galaxy-rvr/tree/1.2.x" target="_blank">SunFounder GalaxyRVR Kit per Arduino - GitHub</a>

.. |download_galaxyrvr_code| replace:: :download:`File Codice GalaxyRVR <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

.. |download_galaxyrvr_filmware| replace:: :download:`File Firmware GalaxyRVR <https://github.com/sunfounder/galaxy-rvr/releases/latest/download/galaxy-rvr.ino.zip>`

"""
