#!/bin/bash

FAILED=0

for i in $(seq 0 32); do
    input="input$i.txt"
    expected="output$i.txt"
    actual="my_output$i.txt"

    # Run the program
    ./bfs-print.exe < "$input" > "$actual"

    # Compare output, ignoring whitespace and newlines
    if ! diff -wB "$expected" "$actual" > /dev/null; then
        echo "❌ Test case $i failed"
        FAILED=$((FAILED + 1))
    else
        echo "✅ Test case $i passed"
    fi
done

echo
if [ "$FAILED" -eq 0 ]; then
    echo "🎉 All tests passed!"
else
    echo "⚠️ $FAILED test(s) failed."
fi

