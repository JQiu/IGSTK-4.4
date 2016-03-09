
This directory contains data used for the testing process.

Testing plays a fundamental role in the development and maintenance of IGSTK.

The subdirectory "Input" contains images and datastreams from trackers that are
used as input to the test ensuring that they are run in standarized conditions.

The subdirectory "Baseline" contains the 'accepted' results of the test. The
data there is used for regression testing on a nightly basis. Each time a test
is run, the result of its output are compared to the accepted results stored in
the Baseline directory. If the results differ by more than a reasonable
tolerance value, then the test is marked as failed and should be marked as an
issue to be resolved by the developers and maintainers of the toolkit.

