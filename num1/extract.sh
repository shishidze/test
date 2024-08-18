#!/bin/bash

find . -name "*.tar.xz" -type f -print0 | while IFS= read -r -d '' archive; do
tar -xJf "$archive" -C "$(dirname "$archive")"
done