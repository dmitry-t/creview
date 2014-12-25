cd contrib

POCO_REV="poco-1.6.0"
POCO_FILE="$POCO_REV.tar.gz"
if [ -d "$POCO_REV" ]; then
  echo "POCO seems to be already installed."
else
  echo "Installing POCO..."
  curl "http://pocoproject.org/releases/$POCO_REV/$POCO_FILE" -o "$POCO_FILE"
  if [ -f "$POCO_FILE" ]; then
    tar -xvf "$POCO_FILE"
    rm -f "$POCO_FILE"
    cd "$POCO_REV"
    ./configure
    make
  fi
  echo "POCO installed."
fi

echo "Done."
