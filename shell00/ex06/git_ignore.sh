git status --ignored=traditional -s | grep '!!*' | awk '{print $2}'
