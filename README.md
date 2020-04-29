# README

## Usage
Project is built with make. To run unit tests run `make test`. This will run the tests
contained in test_main.cpp and report the results. To run the main program which demonstrates
both of the classes written for this challenge, run `make runner`. This will output some values
from the Galois LFSR, and shuffle an example vector using the LFSR as a source of randomness.

After the test executable is built, an optional test to verify that the LFSR outputs the maximal
sequence may be run by running `make slow_test`. This may take a few minutes depending on your machine.
The test verifies that every number representable by a 32-bit integer is output before returning to the
seed value.

The output of the runner can be found in output.txt, and the test output in test_output.txt

## Sources
- https://en.wikipedia.org/wiki/Linear-feedback_shift_register#Galois_LFSRs
- http://courses.cse.tamu.edu/walker/csce680/lfsr_table.pdf
- https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
