#  Copyright (C) 2026 Aaron <communicate_aaron@outlook.com>
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.

# -- Project information -----------------------------------------------------

project = 'modern_cpp'
copyright = '2026, aaron'
author = 'aaron'
release = '0.02'

# -- General configuration ---------------------------------------------------

extensions = [
    "breathe",
]

templates_path = ['_templates']
exclude_patterns = []

language = 'zh_CN'

# -- Breathe configuration ---------------------------------------------------

breathe_projects = {
    "modern_cpp": "../../doxygen/xml",
}

breathe_default_project = "modern_cpp"

# -- Options for HTML output -------------------------------------------------

html_theme = "sphinx_rtd_theme"
html_static_path = ['_static']
