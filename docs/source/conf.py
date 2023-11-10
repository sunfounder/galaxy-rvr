# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))
import sphinx_rtd_theme
import time

# -- Project information -----------------------------------------------------

project = 'SunFounder GalaxyRVR Kit for Arduino'
copyright = f'{time.localtime().tm_year}, SunFounder'
author = 'www.sunfounder.com'


# The full version, including alpha/beta/rc tags
release = '1.0'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = ['sphinx.ext.autosectionlabel']

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static/video_path and html_extra_path.
exclude_patterns = []


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'sphinx_rtd_theme'
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]


# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

html_js_files = [
    'https://ezblock.cc/readDocFile/custom.js',
]
html_css_files = [
    'https://ezblock.cc/readDocFile/custom.css',
]

# pictures
rst_epilog = """

.. |app_connect| image:: /img/app/app_connect.jpg
    :width: 20

.. |app_save| image:: /img/app/app_save.jpg
    :width: 20

.. |app_run| image:: /img/app/app_run.png
    :width: 20

.. |app_edit| image:: /img/app/app_edit.jpg
    :width: 20

.. |app_set| image:: /img/app/app_set.png
    :width: 20

"""


# open link in a new window

rst_epilog += """

.. |link_esp32cam_schematic| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/esp32_cam_sch.pdf" target="_blank">ESP32-CAM schematic diagram</a>

.. |link_cam_ov2640| raw:: html

    <a href="https://docs.ai-thinker.com/_media/esp32/docs/ov2640_ds_1.8_.pdf" target="_blank">ov2640_ds_1.8</a>


.. |link_aithiner| raw:: html

    <a href="https://docs.ai-thinker.com/en/esp32-cam" target="_blank">Ai-Thinker</a>


.. |link_qmc6310_datasheet| raw:: html

    <a href="https://www.qstcorp.com/upload/pdf/202202/%EF%BC%88%E5%B7%B2%E4%BC%A0%EF%BC%8913-52-17%20QMC6310%20Datasheet%20Rev.C(1).pdf" target="_blank">QMC6310 Datasheet</a>


.. |link_download_arduino| raw:: html

    <a href="https://www.arduino.cc/en/software#future-version-of-the-arduino-ide" target="_blank">Arduino IDE 2.0.0 Page</a>

.. |link_arduino_linux| raw:: html

    <a href="https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux" target="_blank">Install Arduino IDE on Linux</a>

.. |link_arduino_web| raw:: html

    <a href="https://www.arduino.cc/reference/en/" target="_blank">Arduino official website</a>

.. |link_sunfounder_controller| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/" target="_blank">SunFounder Controller</a>

.. |link_sc_widgets| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Widgets List</a>

.. |link_sc_page| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/page_introduction.html" target="_blank">Page Introduction</a>

.. |link_ai_camera_library_api| raw:: html

    <a href="https://github.com/sunfounder/SunFounder_AI_Camera/blob/main/README.md" target="_blank">Widgets Usage</a>

.. |link_widgets_list| raw:: html

    <a href="https://docs.sunfounder.com/projects/sf-controller/en/latest/widgets_list.html" target="_blank">Widgets List</a>

.. |link_ai_camera_firmware| raw:: html

    <a href="https://github.com/sunfounder/ai-camera-firmware" target="_blank">ai-camera-firmware</a>

"""
