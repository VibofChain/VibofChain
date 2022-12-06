 #!/usr/bin/env bash

 # Execute this file to install the vibofchain cli tools into your path on OS X

 CURRENT_LOC="$( cd "$(dirname "$0")" ; pwd -P )"
 LOCATION=${CURRENT_LOC%VibofChain-Qt.app*}

 # Ensure that the directory to symlink to exists
 sudo mkdir -p /usr/local/bin

 # Create symlinks to the cli tools
 sudo ln -s ${LOCATION}/VibofChain-Qt.app/Contents/MacOS/vibofchaind /usr/local/bin/vibofchaind
 sudo ln -s ${LOCATION}/VibofChain-Qt.app/Contents/MacOS/vibofchain-cli /usr/local/bin/vibofchain-cli
