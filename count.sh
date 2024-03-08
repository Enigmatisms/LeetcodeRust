#!/bin/bash

numeric_folder_count=0
for item in *; do
    if [ -d "$item" ]; then
        if [[ "$item" =~ ^[0-9]+_ ]]; then
            ((numeric_folder_count++))
        fi
    fi
done

echo "You have finished $numeric_folder_count coding problems."