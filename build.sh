#!/usr/bin/bash

cmake --version
mkdir ./build
rm -rf ./build/*
cmake . -Bbuild
