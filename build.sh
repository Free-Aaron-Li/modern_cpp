#!/usr/bin/env bash
set -euo pipefail

# =========================
# Project requirements
# =========================
MIN_GCC=13
MIN_CLANG=16
MIN_CMAKE=3.31

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
VENV_DIR="$ROOT_DIR/.venv"

die() {
  echo "❌ $1" >&2
  exit 1
}

log() {
  echo "▶ $1"
}

# =========================
# Basic tools
# =========================
log "Checking basic tools..."
command -v python3 >/dev/null || die "python3 not found"
command -v doxygen >/dev/null || die "doxygen not found"
command -v cmake >/dev/null || die "cmake not found"
command -v ninja >/dev/null || die "ninja not found"

# =========================
# Compiler version check (C++ Modules)
# =========================
log "Checking compiler versions..."

if command -v gcc >/dev/null; then
  GCC_VER=$(gcc -dumpversion | cut -d. -f1)
  [ "$GCC_VER" -ge "$MIN_GCC" ] \
    || die "GCC >= $MIN_GCC required for C++ Modules (found $GCC_VER)"
fi

if command -v clang >/dev/null; then
  CLANG_VER=$(clang --version | sed -n 's/.*version \([0-9]*\).*/\1/p')
  [ "$CLANG_VER" -ge "$MIN_CLANG" ] \
    || die "Clang >= $MIN_CLANG required for C++ Modules (found $CLANG_VER)"
fi

CMAKE_VER=$(cmake --version | sed -n '1s/.* \([0-9.]*\)/\1/p')
printf '%s\n%s\n' "$MIN_CMAKE" "$CMAKE_VER" | sort -C -V \
  || die "CMake >= $MIN_CMAKE required (found $CMAKE_VER)"

# =========================
# Python venv (ALWAYS used)
# =========================
log "Preparing Python virtual environment..."

if [ ! -d "$VENV_DIR" ]; then
  log "Creating venv at .venv"
  python3 -m venv "$VENV_DIR"
fi

# shellcheck source=/dev/null
source "$VENV_DIR/bin/activate"

PYTHON="$VENV_DIR/bin/python"
PIP="$VENV_DIR/bin/pip"
SPHINX_BUILD="$VENV_DIR/bin/sphinx-build"

log "Using python: $PYTHON"

# =========================
# Python deps (idempotent)
# =========================
log "Installing Python dependencies..."
"$PIP" install --quiet --upgrade pip
"$PIP" install --quiet \
  sphinx \
  breathe \
  sphinx-rtd-theme

# =========================
# Doxygen → XML
# =========================
log "Running Doxygen (XML only)..."
doxygen "$ROOT_DIR/Doxyfile"

# =========================
# Sphinx → HTML (FORCED venv)
# =========================
log "Building Sphinx HTML..."
cd "$ROOT_DIR/docs"
"$SPHINX_BUILD" -b html source build/html

# =========================
# Done
# =========================
echo
echo "🎉 Documentation successfully built"
echo "📖 Open: docs/build/html/index.html"
