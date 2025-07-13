#!/bin/bash

# Test script for the Advanced Linked List Demo
# This script provides automated input to test basic functionality

echo "🧪 Testing Advanced Linked List Demo Program"
echo "============================================"

# Create a test input sequence
# 1 = Insert at beginning
# 2 = Insert at end  
# 4 = Display list
# 7 = Show memory layout
# 8 = Show pointer relationships
# 0 = Exit

echo "📝 Running automated test sequence..."

# Test sequence: Insert some nodes and display information
echo -e "1\n10\n1\n20\n1\n30\n4\n7\n8\n0" | ./linked_list_demo

echo "\n✅ Basic test completed!"
echo "\n📚 To run the program interactively:"
echo "   ./linked_list_demo"
echo "\n📖 To see all available make targets:"
echo "   make help"

