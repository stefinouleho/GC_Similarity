# GRAPH OF CYCLES SIMILARITY

This code is for similarity calculation on graph of cycles.

To run this code properly, you first need :

To download Chebi Database CHebi_Lite.pdf https://www.dropbox.com/s/7k0ef9rmxvao70q/ChEBI_lite.sdf?dl=0 et save it in the folder MCES.

You need to create folder "resultats" in the same branch as MCES.

this code use SCIP, a solver of mathematical programs, especially linear programs. To use it on Linux, you have to:

Download SCIP Optimization suite (http://scip.zib.de/#download)
Unpack the archive
Move in the folder scipoptsuite-X.X.X where X.X.X is the download version of SCIP
Install all the ddependencies : libpopt-dev, libncurses5-dev, libreadline-dev, libreadline6-dev, libtinfo-dev, zlib1g-dev, libgmp3-dev, libgmp-dev on debian or ubuntu
Run the command: make scipoptlib
Move in the folder MCES
Add two symbolic links in the folder helpers === ln -s LinkToScipoptsuite-X.X.X/scip-X.X.X/src/ scip === ln -s LinkToScipoptsuite-X.X.X/lib/libscipopt.a sciplib.a
Each molecule unique identifier is ChEBI number. For example : Water is 15377

To run the program: ./mesure_similarite MOL ( compute the similarity of molecule MOL with all the molecules of CHEBI database

- MOL : chebi id of the first molecule

HOW TO READ THE FILE OF RESULTS :

On each line there are 2 integers and 1 float ( MOL1 MOL2 similarity) :

                  similarity in [0 .. 1] : Exact value of similarity between MOL1 and MOLx. When the similariy is closed to 1.0, then the molecules are similar.
UP TO DATE.

