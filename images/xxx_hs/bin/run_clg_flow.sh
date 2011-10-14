#!/bin/sh

# Script que corre test_clg_flow usando las imágenes a.png y b.png del
# ejemplo "Blobs, half pixel" displacement.
# Guarda la salida en un TIFF de dos canales, y la convierte en un PNG.
# También guarda los componentes del flujo (u y v) en imágenes PNG separadas.

#echo -n "alpha (default 1.0): "
#read ALPHA
#echo -n "rho (default 0.0): "
#read RHO
#echo -n "sigma (default 0.0): "
#read SIGMA
#echo -n "numIt (default 50.0): "
#read NUMIT

#echo -n " "
#echo -n "first image: "
#read IM1
#echo -n "second image: "
#read IM2

ALPHA="1.0"
RHO="0.0"
SIGMA="0.0"
NUMIT="50"

IM1="../images/a.png"
IM2="../images/b.png"
TIFF_OUT="../images/flow.tiff"
PNG_OUT="../images/flow.png"

# run:
./test_clg_flow $IM1 $IM2 $ALPHA $RHO $SIGMA $NUMIT
./viewflow -1 $TIFF_OUT $PNG_OUT