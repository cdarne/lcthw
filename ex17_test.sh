#!/bin/sh

set -e -x

# Create database
./ex17 db.dat c

# Add entries
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 2 frank frank@zedshaw.com
./ex17 db.dat s 3 joe joe@zedshaw.com
./ex17 db.dat s 4 382be6c2f26884d21238316f26506db1894cf4c9785930da79a24af635e3cf7482ee7d8974ded07780d20aa007e44bb4005386f302008dbcf625f36a97ce567a41ebda0c2f3a584c43a2a21d3af6722e9d253b773707cc08b4750cb9a647ca5b4a120333b587286162f46336d13a85ac22d7b8ed70ff8f5993f6a7317856b0dd5fdd57eafcf9b01f7aa93a857394c235124f5df869a36fe91cd4408de4a18f07e3b8712f671ce1aa09f1b2dd73ed4cde461d860687d45717760fd1fcd16c438f44d22aae43bef49838499b94a9366a078561c13baaffc5de90f8a9d1867909a624ee1f030b54f4b3fa6a6e1214def6bd2a983f4d951b19e6a8eb016edb80822691c013d1 over@fl.ow

# List fields
./ex17 db.dat l

# Delete a entry
./ex17 db.dat d 3
./ex17 db.dat l

# Get an entry
./ex17 db.dat g 2

# Test failure
set +e

# Too few arguments
./ex17

# Too many records
./ex17 db.dat g 9999

# Get no id
./ex17 db.dat g

# Set too few arguments
./ex17 db.dat s 5 bob

# Del too few arguments
./ex17 db.dat d

# Invalid action
./ex17 db.dat trololo

# Database load fail
echo "trololo" > db.dat
./ex17 db.dat l

# Database fail file open
rm db.dat
./ex17 db.dat l

# Double set
./ex17 db.dat c
./ex17 db.dat s 1 zed zed@zedshaw.com
./ex17 db.dat s 1 zed zed@zedshaw.com

# Get on not set
./ex17 db.dat g 2

# Wrong ID
./ex17 db.dat g s

set -e
