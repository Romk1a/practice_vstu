if(EXISTS "/Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/tests/test_parallelogramm[1]_tests.cmake")
  include("/Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/tests/test_parallelogramm[1]_tests.cmake")
else()
  add_test(test_parallelogramm_NOT_BUILT test_parallelogramm_NOT_BUILT)
endif()
