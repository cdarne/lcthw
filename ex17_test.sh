#!/bin/sh

set -e -x

# Create database
./ex17 db.dat c

# Add entries
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 2 frank frank@zedshaw.com
./ex17 db.dat s 3 joe joe@zedshaw.com

# List fields
./ex17 db.dat l

# Delete a entry
./ex17 db.dat d 3
./ex17 db.dat l

# Get an entry
./ex17 db.dat g 2
