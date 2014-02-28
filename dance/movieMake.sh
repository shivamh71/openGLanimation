#! /bin/bash

# Fliiping and Converting all .ppm images to .jpg format
mogrify -flip -format jpg ./frames/frame_*.ppm

# Removing .ppm images
rm ./frames/*.ppm

# Convert .jpg images to movie
ffmpeg -i frames/frame_%4d.jpg -qscale 1 output.mp4