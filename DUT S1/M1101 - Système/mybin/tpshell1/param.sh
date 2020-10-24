#!/bin/bash

if [ $# -lt 2 ]; then
  echo "Arguments missing: $(( 2 - $# ))"
fi
