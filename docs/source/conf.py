# Fichier de configuration pour le générateur de documentation Sphinx.
#
# Ce fichier contient uniquement une sélection des options les plus courantes.
# Pour une liste complète, consultez la documentation :
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Configuration des chemins -------------------------------------------------

# Si les extensions (ou les modules à documenter avec autodoc) se trouvent dans
# un autre répertoire, ajoutez ces répertoires à sys.path ici. Si le répertoire
# est relatif à la racine de la documentation, utilisez os.path.abspath
# pour le rendre absolu, comme montré ici.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
import time

# -- Informations sur le projet ------------------------------------------------

project = 'SunFounder GalaxyRVR Kit pour Arduino'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# La version complète, incluant les balises alpha/beta/rc
release = '1.0'

# -- Options du thème sphinx_rtd_theme -----------------------------------------
html_theme_options = {
    'flyout_display': 'attached',
    'version_selector': False,
    'language_selector': False,
}

# -- Configuration générale ----------------------------------------------------

# Ajoutez ici les noms des modules d'extension Sphinx, sous forme de chaînes.
# Il peut s'agir d'extensions fournies avec Sphinx (nommées 'sphinx.ext.*')
# ou personnalisées.
extensions = [
    #'sphinx.ext.autosectionlabel',
    'sphinx_copybutton',
    'sphinx_rtd_theme'
]

# Ajoutez ici les chemins contenant des modèles, relatifs à ce répertoire.
templates_path = ['_templates']

# Liste des motifs, relatifs au répertoire source, qui correspondent aux fichiers
# et répertoires à ignorer lors de la recherche des fichiers source.
# Ce motif affecte également html_static/video_path et html_extra_path.
exclude_patterns = []


# -- Options pour la sortie HTML -----------------------------------------------

# Le thème à utiliser pour les pages HTML et HTML Help. Consultez la
# documentation pour une liste des thèmes intégrés.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# Ajoutez ici les chemins contenant des fichiers statiques personnalisés
# (comme les feuilles de style), relatifs à ce répertoire. Ils sont copiés
# après les fichiers statiques intégrés, donc un fichier nommé "default.css"
# écrasera le "default.css" intégré.
html_static_path = ['_static']

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
    './lang.js', # new
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]

# Ouvrir les liens dans une nouvelle fenêtre

rst_epilog = """

.. |link_sf_facebook| raw:: html

    <a href="https://bit.ly/raphaelkit" target="_blank">ici</a>


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

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/esp32_cam_sch.pdf" target="_blank">Schéma de l'ESP32-CAM</a>

.. |link_cam_ov2640| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/ov2640_ds_1.8_.pdf" target="_blank">ov2640_ds_1.8</a>


.. |link_aithiner| raw:: html

    <a href="https://docs.ai-thinker.com/en/esp32-cam" target="_blank">Ai-Thinker</a>


.. |link_qmc6310_datasheet| raw:: html

    <a href="https://www.qstcorp.com/upload/pdf/202202/%EF%BC%88%E5%B7%B2%E4%BC%A0%EF%BC%8913-52-17%20QMC6310%20Datasheet%20Rev.C(1).pdf" target="_blank">Fiche technique QMC6310</a>


.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Page Arduino IDE 2.0.0</a>

.. |link_arduino_linux| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux" target="_blank">Installer Arduino IDE sur Linux</a>

.. |link_arduino_web| raw:: html

    <a href="https://www.arduino.cc/reference/en/" target="_blank">Site officiel Arduino</a>

.. |link_sunfounder_controller| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/" target="_blank">SunFounder Controller</a>

.. |link_sc_widgets| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Liste des widgets</a>

.. |link_sc_page| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/page_introduction.html" target="_blank">Introduction à la page</a>

.. |link_ai_camera_library_api| raw:: html

    <a href="https://github.com/sunfounder/SunFounder_AI_Camera/blob/main/README.md" target="_blank">Utilisation des widgets</a>

.. |link_widgets_list| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Liste des widgets</a>

.. |link_ai_camera_firmware| raw:: html

    <a href="https://github.com/sunfounder/ai-camera-firmware" target="_blank">ai-camera-firmware</a>

.. |link_GalaxyRVR| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-galaxyrvr-mars-rover-kit?_pos=1&_sid=c7193042f&_ss=r" target="_blank">Lien d'achat pour GalaxyRVR</a>

.. |link_Mars_Rover_Kit| raw:: html

    <a href="https://www.sunfounder.com/products/sunfounder-galaxyrvr-mars-rover-kit?_pos=1&_sid=c7193042f&_ss=r" target="_blank">GalaxyRVR</a>

.. |link_github_galaxyrvr| raw:: html

    <a href="https://github.com/sunfounder/galaxy-rvr/tree/1.2.x" target="_blank">SunFounder GalaxyRVR Kit pour Arduino - GitHub</a>

.. |download_galaxyrvr_code| replace:: :download:`Fichier Code GalaxyRVR <https://github.com/sunfounder/galaxy-rvr/archive/refs/heads/main.zip>`

.. |download_galaxyrvr_filmware| replace:: :download:`Fichier Firmware GalaxyRVR <https://github.com/sunfounder/galaxy-rvr/releases/latest/download/galaxy-rvr.ino.zip>`

"""
