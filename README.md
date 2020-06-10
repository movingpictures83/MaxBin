# Language: C++
# Input: TXT
# Output: prefix
# Tested with: PluMA 1.0, GCC 4.8.4

PluMA plugin that interfaces to MaxBin (Wu et al., 2014) software for binning reads.

The plugin takes as input a single TXT file of keyword-value pairs, whitespace delimited:
contigs: FAFSA file for contigs
reads_list: TXT file holding the list of files holding sequences, one per line

All output files of MaxBin will start with the provided output prefix.

This plugin assumes MaxBin and all auxiliaries are in the system PATH.
